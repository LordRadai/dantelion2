#pragma once
#include "Core/Platform/Platform.h"
#include "DLTypeID.h"
#include "DLParameterInfo.h"
#include "DLMethodInvokeContext.h"
#include "FRPG2Call.h"

namespace DLRF
{
	template<class _DedicatedContextType>
	class DLMethodInvoker
	{
	public:
		typedef dl_bool(_fastcall* oInvoke)(DLMethodInvoker*, _DedicatedContextType*);
		typedef void(_fastcall* oDestructor)(DLMethodInvoker*);
		typedef dl_size(_fastcall* oGetParameterSize)(DLMethodInvoker*);
		typedef dl_size(_fastcall* oGetStrictParameterInfo)(DLMethodInvoker*, DLParameterInfo*);
		typedef dl_size(_fastcall* oGetLooseParameterInfo)(DLMethodInvoker*, DLParameterInfo*);
		typedef DLTypeID(_fastcall* oGetReturnType)(DLMethodInvoker*);

		typedef _DedicatedContextType DedicatedContextType;

		virtual dl_bool Invoke(_DedicatedContextType* pContext) = 0;

		virtual ~DLMethodInvoker() 
		{
			FRPG2_CALL(oDestructor, 0x530760, this);
		}

		virtual dl_size GetParameterSize() = 0;
		virtual dl_size GetStrictParameterInfo(DLParameterInfo* pPI) = 0;
		virtual dl_size GetLooseParameterInfo(DLParameterInfo* pPI) = 0;
		virtual DLTypeID GetReturnType() = 0;
	};
}
