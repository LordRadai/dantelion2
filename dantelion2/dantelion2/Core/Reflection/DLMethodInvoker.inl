#pragma once
#include "Core/Platform/Platform.h"
#include "DLTypeID.h"
#include "DLParameterInfo.h"
#include "DLMethodInvokeContext.h"
#include "Call.h"

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

	protected:
		virtual dl_bool _Invoke(_DedicatedContextType* pContext) const = 0;

	public:
		virtual ~DLMethodInvoker() 
		{
			CALL(oDestructor, 0x530760, this);
		}

		virtual dl_size GetParameterSize() const = 0;
		virtual dl_size GetStrictParameterInfo(DLParameterInfo* pPI) const = 0;
		virtual dl_size GetLooseParameterInfo(DLParameterInfo* pPI) const = 0;
		virtual DLTypeID GetReturnType() const = 0;
	};
}
