#pragma once
#include <functional>
#include <type_traits>
#include <utility>
#include "DLMethodInvoker.inl"
#include "DLMethodInvokeContext.h"
#include "DLRuntimeClass.h"
#include "Core/Util/DLMethodTypeConstructor.h"

namespace DLRF
{
    template<class _ClassType, typename _MethodReturnType = void,
        typename ParamList = DLUT::DLNullType, dl_bool isConst = true >
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

        virtual dl_bool _Invoke(DLMethodInvokeContext* ctx) const override { return true; }
    public:
		DLConcreteMethodInvoker(MethodType mt, const dl_char* pName, const dl_wchar* pWName) : m_mt(mt)
        {
			_ClassType::GetRuntimeClass()->AddInvoker(this, pName, pWName);
        }

        virtual dl_size GetParameterSize(void) const override { return 0; }

        virtual dl_size GetStrictParameterInfo(DLParameterInfo* pArray) const override { return 0; }
        virtual dl_size GetLooseParameterInfo(DLParameterInfo* pArray) const override { return 0; }

		virtual DLTypeID GetReturnType(void) const override { return 0; }
    };
}