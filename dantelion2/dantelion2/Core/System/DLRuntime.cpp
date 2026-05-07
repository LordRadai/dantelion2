#include "DLRuntime.h"
#include "Call.h"

namespace DLSY
{
#define DL_RUNTIME (DLRuntime*)(MODULE_ADDR + 0x16681d0);

	typedef DLRuntimeImpl* (__fastcall* GetRuntimeImpl_t)();

	void DLRuntime::InvokeDebugger()
	{
		__debugbreak();
	};

	DLRuntime* DLRuntime::GetRuntime()
	{
		return DL_RUNTIME;
	}

	dl_bool DLRuntime::AddExitEventListener(DLExitEventListener* pListener, DLExitEventPriority priority)
	{
		return CALL(AddExitEventListener_t, 0x846140, this, pListener, priority);
	}

	dl_bool DLRuntime::AddExitEventProc(DLExitEventProc pFn, DLExitEventPriority priority)
	{
		return CALL(AddExitEventProc_t, 0x846170, this, pFn, priority);
	}

	DLAssertEventManager* DLRuntimeImpl::GetAssertEventManager() const
	{
		return CALL(GetAssertEventManager_t, 0x8461a0, this);
	}

	DLRealTimeServiceManager* DLRuntimeImpl::GetRealTimeServiceManager() const
	{
		return CALL(GetRealTimeServiceManager_t, 0x846220, this);
	}

	DLUT::DLProperties* DLRuntimeImpl::GetProperties() const
	{
		return CALL(GetProperties_t, 0x8462f0, this);
	}

	const dl_wchar* DLRuntimeImpl::GetVersionString() const
	{
		return CALL(GetVersionString_t, 0x846270, this);
	}

	void DLRuntimeImpl::Exit(dl_int8 exitCode)
	{
		CALL(Exit_t, 0x8462b0, this, exitCode);
	}

	void DLRuntimeImpl::SetDefaultAllocator(DLKR::DLAllocator* pAllocator)
	{
		CALL(SetDefaultAllocator_t, 0x8462d0, this, pAllocator);
	}

	dl_bool DLRuntimeImpl::MountCacheDisk(dl_bool param_1)
	{
		this->m_bMountedCacheDisk = true;
		return true;
	}

	DLRuntimeImpl::~DLRuntimeImpl()
	{
		CALL(Destructor_t, 0x846870, this);
	}

	DLKR::DLAllocator* DLRuntime::GetDefaultAllocator()
	{
		return RUNTIME_ALLOCATOR;
	}

	DLRuntimeImpl* DLRuntimeImpl::GetRuntimeImpl()
	{
		return CALL(GetRuntimeImpl_t, 0x846370);
	}
}