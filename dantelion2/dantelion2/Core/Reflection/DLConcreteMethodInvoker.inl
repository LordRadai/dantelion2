#pragma once
#include <functional>
#include <type_traits>
#include <utility>
#include "DLMethodInvoker.inl"
#include "DLMethodInvokeContext.h"

namespace DLRF
{
	namespace detail
	{
		// VS2012 (error C2059 '<tag>::*') fails to parse a cv-qualified
		// pointer-to-member-function type when it appears as a bare
		// template argument (e.g. inside std::conditional<...>). Naming
		// the same type as a typedef target inside a partial
		// specialization is fine, so both the const/non-const choice and
		// the has-parameters/no-parameters choice are routed through
		// selector structs instead of std::conditional.
		//
		// hasParams distinguishes ParamList == DLUT::DLNullType (a
		// genuinely zero-argument method, e.g. void Foo::Bar()) from any
		// other ParamList (a method taking that one argument). Without
		// this axis, the DLNullType case previously produced a method
		// signature with one DLNullType parameter instead of none, which
		// doesn't match the real method pointer and breaks std::function
		// construction (VS2012 accepts the mismatch at overload
		// resolution due to weak SFINAE, then hard-errors later trying to
		// generate the call thunk - error C2064).
		template <class _ClassType, typename _MethodReturnType, typename ParamList, dl_bool isConst,
			bool hasParams = !std::is_same<ParamList, DLUT::DLNullType>::value>
		struct RawMethodTypeSelector;

		template <class _ClassType, typename _MethodReturnType, typename ParamList>
		struct RawMethodTypeSelector<_ClassType, _MethodReturnType, ParamList, true, true>
		{
			typedef _MethodReturnType(_ClassType::* Type)(ParamList) const;
		};

		template <class _ClassType, typename _MethodReturnType, typename ParamList>
		struct RawMethodTypeSelector<_ClassType, _MethodReturnType, ParamList, false, true>
		{
			typedef _MethodReturnType(_ClassType::* Type)(ParamList);
		};

		template <class _ClassType, typename _MethodReturnType, typename ParamList>
		struct RawMethodTypeSelector<_ClassType, _MethodReturnType, ParamList, true, false>
		{
			typedef _MethodReturnType(_ClassType::* Type)() const;
		};

		template <class _ClassType, typename _MethodReturnType, typename ParamList>
		struct RawMethodTypeSelector<_ClassType, _MethodReturnType, ParamList, false, false>
		{
			typedef _MethodReturnType(_ClassType::* Type)();
		};

		// Same hasParams split for the type-erased std::function signature.
		template <class _ClassType, typename _MethodReturnType, typename ParamList,
			bool hasParams = !std::is_same<ParamList, DLUT::DLNullType>::value>
		struct InvokerFunctionTypeSelector;

		template <class _ClassType, typename _MethodReturnType, typename ParamList>
		struct InvokerFunctionTypeSelector<_ClassType, _MethodReturnType, ParamList, true>
		{
			typedef std::function<_MethodReturnType(_ClassType*, ParamList)> Type;
		};

		template <class _ClassType, typename _MethodReturnType, typename ParamList>
		struct InvokerFunctionTypeSelector<_ClassType, _MethodReturnType, ParamList, false>
		{
			typedef std::function<_MethodReturnType(_ClassType*)> Type;
		};
	}

	template <class _ClassType, typename _MethodReturnType = void,
		typename ParamList = DLUT::DLNullType, dl_bool isConst = true>
	class DLConcreteMethodInvoker : public DLMethodInvoker<DLMethodInvokeContext>
	{
	public:
		// Raw pointer-to-member-function type, selected based on isConst
		// and on whether ParamList means "one real parameter" or "none".
		typedef typename detail::RawMethodTypeSelector<
			_ClassType, _MethodReturnType, ParamList, isConst
		>::Type RawMethodType;

		// Type-erased storage, matching RawMethodType's arity.
		typedef typename detail::InvokerFunctionTypeSelector<
			_ClassType, _MethodReturnType, ParamList
		>::Type MethodType;

		MethodType m_mt;

		explicit DLConcreteMethodInvoker(RawMethodType pMethod)
			: m_mt(std::mem_fn(pMethod))
		{}

		// Also allow construction from any compatible callable (lambda, bind, etc).
		explicit DLConcreteMethodInvoker(MethodType fn)
			: m_mt(std::move(fn))
		{}

		virtual bool Invoke(DLMethodInvokeContext* pContext) override
		{
			_ClassType* pObj = static_cast<_ClassType*>(pContext->m_pObj.m_pObject);
			if (!pObj || !m_mt)
				return false;

			InvokeAndStore(pContext, pObj);
			return true;
		}

		virtual ~DLConcreteMethodInvoker() override
		{}

		virtual dl_size GetParameterSize() override
		{
			return HasParams() ? static_cast<dl_size>(sizeof(ParamList)) : 0;
		}

		virtual dl_size GetStrictParameterInfo(DLParameterInfo* pPI) override
		{
			return GetStrictParameterInfoImpl(pPI,
				std::integral_constant<bool, !std::is_same<ParamList, DLUT::DLNullType>::value>());
		}

		virtual dl_size GetLooseParameterInfo(DLParameterInfo* pPI) override
		{
			return GetLooseParameterInfoImpl(pPI,
				std::integral_constant<bool, !std::is_same<ParamList, DLUT::DLNullType>::value>());
		}

		virtual DLTypeID GetReturnType() override
		{
			return GetReturnTypeImpl(std::is_void<_MethodReturnType>());
		}

	private:
		static bool HasParams()
		{
			return !std::is_same<ParamList, DLUT::DLNullType>::value;
		}

		// hasParams == false: no reference to DLStaticGetTypeID<ParamList>
		// at all, so DLStaticGetTypeID<DLUT::DLNullType> is never
		// instantiated/emitted for the zero-parameter case. That matters
		// because nothing in the codebase defines a
		// StaticTypeIDResolver<DLUT::DLNullType> specialization (it isn't
		// meant to be a reflected type), and a runtime-only guard (an
		// `if`) still forces the compiler to instantiate and emit a call
		// to the template either way - it has to be excluded at compile
		// time via tag dispatch, not runtime branching.
		dl_size GetStrictParameterInfoImpl(DLParameterInfo* /*pPI*/, std::false_type /* hasParams */)
		{
			return 0;
		}
		dl_size GetStrictParameterInfoImpl(DLParameterInfo* pPI, std::true_type /* hasParams */)
		{
			// NOTE: DLStaticGetConstTypeID<T>() is broken upstream in
			// DLTypeID.h - it references DLTypeTraits/DLSelect/DLNullType
			// unqualified with no include that declares them, so it fails
			// to parse the moment anything actually instantiates it (which
			// nothing did until this file called it). Using
			// DLStaticGetTypeID here as a working substitute until that
			// header is fixed upstream. ASSUMPTION: "strict" == const-
			// qualified type id - revisit once DLStaticGetConstTypeID works.
			pPI->id[0] = DLStaticGetTypeID<ParamList>();
			return 1;
		}

		dl_size GetLooseParameterInfoImpl(DLParameterInfo* /*pPI*/, std::false_type /* hasParams */)
		{
			return 0;
		}
		dl_size GetLooseParameterInfoImpl(DLParameterInfo* pPI, std::true_type /* hasParams */)
		{
			// ASSUMPTION: "loose" == non-const type id.
			pPI->id[0] = DLStaticGetTypeID<ParamList>();
			return 1;
		}

		void InvokeAndStore(DLMethodInvokeContext* pContext, _ClassType* pObj)
		{
			// Tag dispatch instead of enable_if: InvokeAndStore is an
			// ordinary member function of an already-instantiated class
			// template, not itself a function template, so there is no
			// substitution step for enable_if to fail gracefully during -
			// std::enable_if<false, void> just hard-errors (C2039). Tag
			// dispatch sidesteps that; only the branch actually called
			// gets its body instantiated. Dispatches on both return-type
			// (void vs not) and arity (has params vs not) so m_mt is
			// always invoked with exactly the arguments its signature has.
			InvokeAndStoreImpl(pContext, pObj, std::is_void<_MethodReturnType>(),
				std::integral_constant<bool, !std::is_same<ParamList, DLUT::DLNullType>::value>());
		}

		// Non-void return, has parameters.
		void InvokeAndStoreImpl(DLMethodInvokeContext* pContext, _ClassType* pObj,
			std::false_type /* isVoid */, std::true_type /* hasParams */)
		{
			ParamList& params = *reinterpret_cast<ParamList*>(pContext->m_pM);
			_MethodReturnType result = m_mt(pObj, params);
			// ASSUMPTION: MightyType is assignable from the return value.
			pContext->m_return = result;
		}

		// Non-void return, no parameters.
		void InvokeAndStoreImpl(DLMethodInvokeContext* pContext, _ClassType* pObj,
			std::false_type /* isVoid */, std::false_type /* hasParams */)
		{
			_MethodReturnType result = m_mt(pObj);
			// ASSUMPTION: MightyType is assignable from the return value.
			pContext->m_return = result;
		}

		// Void return, has parameters.
		void InvokeAndStoreImpl(DLMethodInvokeContext* pContext, _ClassType* pObj,
			std::true_type /* isVoid */, std::true_type /* hasParams */)
		{
			ParamList& params = *reinterpret_cast<ParamList*>(pContext->m_pM);
			m_mt(pObj, params);
		}

		// Void return, no parameters.
		void InvokeAndStoreImpl(DLMethodInvokeContext* pContext, _ClassType* pObj,
			std::true_type /* isVoid */, std::false_type /* hasParams */)
		{
			m_mt(pObj);
		}

		static DLTypeID GetReturnTypeImpl(std::true_type /* isVoid */)
		{
			return DL_INVALID_TYPEID;
		}
		static DLTypeID GetReturnTypeImpl(std::false_type /* isVoid */)
		{
			return DLStaticGetTypeID<_MethodReturnType>();
		}
	};
}