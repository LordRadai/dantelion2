#pragma once
#include <type_traits>
#include <utility>
#include "DLRuntimeClass.h"
#include "Core/Util/DLMethodTypeConstructor.h"
#include "Core/Util/DLTypeManipulation.h"

namespace DLRF
{
    template<class _ClassType, typename _MethodReturnType = void,
        typename ParamList = DLUT::DLNullType, dl_bool isConst = true>
    class DLConcreteMethodInvoker : public DLMethodInvoker<DLMethodInvokeContext> 
    {
        typedef typename DLUT::DLMethodTypeConstructor<_ClassType, _MethodReturnType, ParamList>::ConstResult ConstResultType;
        typedef typename DLUT::DLMethodTypeConstructor<_ClassType, _MethodReturnType, ParamList>::Result ResultType;
        typedef DLUT::DLSelect< isConst, ConstResultType, ResultType > MethodTypeSelector;

    public:
        typedef typename MethodTypeSelector::Result MethodType;
        typedef _ClassType ClassType;
        typedef _MethodReturnType MethodReturnType;

    private:
        MethodType m_mt;

        dl_uint32 _CheckRuntimeType(DLMethodInvokeContext* ctx) const
        {
            return 1;
        }

        template<typename T>
        struct _ParamTypeIDOf
        {
            static DLRF::DLTypeID Get() { return DLRF::DLStaticGetTypeID<T>(); }
        };

        template<typename T>
        struct _ReturnTypeIDOf
        {
            static DLRF::DLTypeID Get() { return DLRF::DLStaticGetTypeID<T>(); }
        };

        template<>
        struct _ParamTypeIDOf<DLUT::DLNullType>
        {
            static DLRF::DLTypeID Get() { return 0; }
        };

        template<>
        struct _ReturnTypeIDOf<DLUT::DLNullType>
        {
            static DLRF::DLTypeID Get() { return 0; }
        };

        template<typename PL, int Index>
        struct _ParamIdFiller
        {
            static void Fill(DLParameterInfo* pArray)
            {
                typedef typename DLUT::TypeList::TypeAtNonStrict<PL, Index>::Result ParamType;
                pArray->id[Index] = _ParamTypeIDOf<ParamType>::Get();
                _ParamIdFiller<PL, Index + 1>::Fill(pArray);
            }
        };

        template<typename PL>
        struct _ParamIdFiller<PL, 15>
        {
            static void Fill(DLParameterInfo*) {}
        };

        template<typename T>
        struct _ReturnTypeIDOf
        {
            static DLTypeID Get() { return DLRF::DLStaticGetTypeID<T>(); }
        };

        template<typename ContextType, typename RType>
        void _Invoke(ContextType* ctx, DLUT::DLTypeToType<RType>) const
        {
            _MethodReturnType rt = _Invoke(ctx, DLUT::DLIntToType<DLUT::TypeList::Length<ParamList>::Size>());
            ctx->template SetReturnValue<_MethodReturnType>(rt);
        }

        template<typename ContextType>
        void _Invoke(ContextType* ctx, DLUT::DLTypeToType<void>) const
        {
            _Invoke(ctx, DLUT::DLIntToType<DLUT::TypeList::Length<ParamList>::Size>());
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<15>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result>(9),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result>(10),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result>(11),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 12>::Result>(12),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 13>::Result>(13),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 14>::Result>(14)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<14>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result>(9),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result>(10),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result>(11),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 12>::Result>(12),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 13>::Result>(13)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<13>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result>(9),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result>(10),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result>(11),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 12>::Result>(12)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<12>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result>(9),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result>(10),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 11>::Result>(11)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<11>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result>(9),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 10>::Result>(10)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<10>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 9>::Result>(9)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<9>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 8>::Result>(8)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<8>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 7>::Result>(7)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<7>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 6>::Result>(6)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<6>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 5>::Result>(5)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<5>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 4>::Result>(4)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<4>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2),
				ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 3>::Result>(3)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<3>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 2>::Result>(2)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<2>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0),
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 1>::Result>(1)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<1>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt)(
                ctx->template GetArg<typename DLUT::TypeList::TypeAtNonStrict<ParamList, 0>::Result>(0)
                );
        }

        template<typename ContextType> MethodReturnType _Invoke(ContextType* ctx, DLUT::DLIntToType<0>) const
        {
            DLRawDynamicPtr obj = ctx->GetObject();
            _ClassType* o = static_cast<_ClassType*>(obj.Get());

            return (o->*m_mt) ();
        }

        virtual dl_bool _Invoke(DLMethodInvokeContext* ctx) const override
        { 
            if (_CheckRuntimeType(ctx)) 
            {
                _Invoke(ctx, DLUT::DLTypeToType<_MethodReturnType>());
                return true;
            }

            return false;
        }
    public:
		DLConcreteMethodInvoker(MethodType mt, const dl_char* pName, const dl_wchar* pWName) : m_mt(mt)
        {
			_ClassType::GetRuntimeClass()->AddInvoker(this, pName, pWName);
        }

        virtual dl_size GetParameterSize(void) const override
        {
            return DLUT::TypeList::Length<ParamList>::Size;
        }

        virtual dl_size GetStrictParameterInfo(DLParameterInfo* pArray) const override
        {
            _ParamIdFiller<ParamList, 0>::Fill(pArray);
            pArray->pData = (void*)this;
            return DLUT::TypeList::Length<ParamList>::Size;
        }

        virtual dl_size GetLooseParameterInfo(DLParameterInfo* pArray) const override
        {
            _ParamIdFiller<ParamList, 0>::Fill(pArray);
            pArray->pData = (void*)this;
            return DLUT::TypeList::Length<ParamList>::Size;
        }

        virtual DLTypeID GetReturnType(void) const override
        {
            return _ReturnTypeIDOf<MethodReturnType>::Get();
        }
    };
}