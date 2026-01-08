#pragma once
#include "DLMethodInvoker.inl"
#include "DLMethodInvokeContext.h"
#include "FRPG2Call.h"

namespace DLRF
{
	template <class _ClassType, typename _MethodReturnType = void, 
		typename ParamList = DLUT::DLNullType, dl_bool isConst = true>
	class DLConcreteMethodInvoker : public DLMethodInvoker<DLMethodInvokeContext>
	{
	public:
		typedef _MethodReturnType(_ClassType::* MethodType)(ParamList);

		MethodType m_mt;

		DLConcreteMethodInvoker(MethodType pMethod) : m_mt(pMethod) {}

		virtual bool Invoke(DLMethodInvokeContext* pContext) override
		{
			return FRPG2_VCALL(this, 0, oInvoke, this, pContext);
		}

		virtual ~DLConcreteMethodInvoker() override
		{
			FRPG2_VCALL(this, 1, oDestructor, this);
		}

		virtual dl_size GetParameterSize() override
		{
			return FRPG2_VCALL(this, 2, oGetParameterSize, this);
		}

		virtual dl_size GetStrictParameterInfo(DLParameterInfo* pPI) override
		{
			return FRPG2_VCALL(this, 3, oGetStrictParameterInfo, this, pPI);
		}

		virtual dl_size GetLooseParameterInfo(DLParameterInfo* pPI) override
		{
			return FRPG2_VCALL(this, 4, oGetLooseParameterInfo, this, pPI);
		}

		virtual DLTypeID GetReturnType() override
		{
			return FRPG2_VCALL(this, 5,	oGetReturnType, this);
		}
	};
}