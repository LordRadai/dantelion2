#include "DLRuntime.h"
#include "dantelion2/FRPG2Call.h"

namespace DLSY
{
#define DL_RUNTIME *(DLSY::DLRuntime**)(MODULE_ADDR + 0x16681b8);

	typedef const dl_wchar*(_fastcall* oGetVersionString)(DLRuntime*);
	typedef DLKR::DLAllocator* (_fastcall* oGetDefaultAllocator)(DLRuntime*);

	void DLRuntime::InvokeDebugger()
	{
		__debugbreak();
	};

	const dl_wchar* DLRuntime::GetVersionString()
	{
		return FRPG2_VCALL(this, 5, oGetVersionString, this);
	}

	DLKR::DLAllocator* DLRuntime::GetDefaultAllocator()
	{
		return DEFAULT_ALLOCATOR;
	}

	DLRuntime* DLRuntime::GetDLRuntime()
	{
		return DL_RUNTIME;
	}

	DLRuntimeImpl* DLRuntimeImpl::GetDLRuntime()
	{
		return static_cast<DLRuntimeImpl*>(DLRuntime::GetDLRuntime());
	}
}