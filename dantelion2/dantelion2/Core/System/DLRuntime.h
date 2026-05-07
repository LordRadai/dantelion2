#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "DLStdInputStream.h"
#include "DLStdOutputStream.h"
#include "DLAssertEventManager.h"
#include "DLRealTimeServiceManager.h"
#include "Core/Util/DLProperties.h"
#include "Core/Util/PODVector.h"
#include "DLExitEventListener.h"

namespace DLSY
{
	class DLRuntime
	{
	public:
		virtual dl_bool AddExitEventListener(DLExitEventListener* pListener, DLExitEventPriority priority) = 0;
		virtual dl_bool AddExitEventProc(DLExitEventProc pFn, DLExitEventPriority priority) = 0;
		virtual DLAssertEventManager* GetAssertEventManager() const = 0;
		virtual DLRealTimeServiceManager* GetRealTimeServiceManager() const = 0;
		virtual DLUT::DLProperties* GetProperties() const = 0;
		virtual const dl_wchar* GetVersionString() const = 0;
		virtual DLStdOutputStream* GetStdOutputStream() = 0;
		virtual DLStdOutputStream* GetStdErrorStream() = 0;
		virtual DLStdInputStream* GetStdInputStream() = 0;
		virtual void Exit(dl_int8 exitCode) = 0;
		virtual void SetDefaultAllocator(DLKR::DLAllocator* pAllocator) = 0;
		virtual dl_bool MountInstalledDisk2(dl_pointer pMountParam) const = 0;
		virtual dl_bool UnmountInstalledDisk2(dl_pointer pUnmountParam) const = 0;
		virtual dl_bool MountCacheDisk(dl_bool param_1) const = 0;
		virtual dl_bool UnmountCacheDisk() const = 0;
		virtual dl_bool DoesCacheDiskMount() const = 0;
		virtual dl_bool BeginInstall2(dl_pointer pMountParam) const = 0;
		virtual dl_bool EndInstallAndMountDisk2(dl_pointer pMountParam) const = 0;
		virtual dl_int GetInstallDirectoryState(const dl_wchar* path) const = 0;
		virtual dl_bool IsReadyToShutdown() const = 0;
		virtual dl_bool IsBootByInvitation() const = 0;
		virtual ~DLRuntime() {}

		static void InvokeDebugger();
		DLKR::DLAllocator* GetDefaultAllocator();

		static DLRuntime* GetRuntime();

		typedef dl_bool(_fastcall* AddExitEventListener_t)(DLRuntime*, DLExitEventListener*, DLExitEventPriority);
		typedef dl_bool(_fastcall* AddExitEventProc_t)(DLRuntime*, DLExitEventProc, DLExitEventPriority);
		typedef DLAssertEventManager* (_fastcall* GetAssertEventManager_t)(const DLRuntime*);
		typedef DLRealTimeServiceManager* (_fastcall* GetRealTimeServiceManager_t)(const DLRuntime*);
		typedef DLUT::DLProperties* (_fastcall* GetProperties_t)(const DLRuntime*);
		typedef const dl_wchar* (_fastcall* GetVersionString_t)(const DLRuntime*);
		typedef DLStdOutputStream* (_fastcall* GetStdOutputStream_t)(const DLRuntime*);
		typedef DLStdOutputStream* (_fastcall* GetStdErrorStream_t)(const DLRuntime*);
		typedef DLStdInputStream* (_fastcall* GetStdInputStream_t)(const DLRuntime*);
		typedef void(_fastcall* Exit_t)(DLRuntime*, dl_int8);
		typedef void(_fastcall* SetDefaultAllocator_t)(DLRuntime*, DLKR::DLAllocator*);
		typedef dl_bool(_fastcall* MountInstalledDisk2_t)(DLRuntime*, dl_pointer);
		typedef dl_bool(_fastcall* UnmountInstalledDisk2_t)(DLRuntime*, dl_pointer);
		typedef dl_bool(_fastcall* MountCacheDisk_t)(DLRuntime*, dl_bool);
		typedef dl_bool(_fastcall* UnmountCacheDisk_t)(DLRuntime*);
		typedef dl_bool(_fastcall* DoesCacheDiskMount_t)(DLRuntime*);
		typedef dl_bool(_fastcall* BeginInstall2_t)(DLRuntime*, dl_pointer);
		typedef dl_bool(_fastcall* EndInstallAndMountDisk2_t)(DLRuntime*, dl_pointer);
		typedef dl_int(_fastcall* GetInstallDirectoryState_t)(DLRuntime*, const dl_wchar*);
		typedef dl_bool(_fastcall* IsReadyToShutdown_t)(DLRuntime*);
		typedef dl_bool(_fastcall* IsBootByInvitation_t)(DLRuntime*);
		typedef void(_fastcall* Destructor_t)(DLRuntime*);
	};

	class DLRuntimeImpl : public DLRuntime
	{
	public:
		struct SysPropFilePath
		{
			const dl_wchar* m_path;
			dl_bool m_bInitialized;
		};

		virtual dl_bool AddExitEventListener(DLExitEventListener* pListener, DLExitEventPriority priority);
		virtual dl_bool AddExitEventProc(DLExitEventProc pFn, DLExitEventPriority priority);
		virtual DLAssertEventManager* GetAssertEventManager() const;
		virtual DLRealTimeServiceManager* GetRealTimeServiceManager() const;
		virtual DLUT::DLProperties* GetProperties() const;
		virtual const dl_wchar* GetVersionString() const;
		virtual DLStdOutputStream* GetStdOutputStream() { return &m_stdOutputStream; }
		virtual DLStdOutputStream* GetStdErrorStream() { return &m_stdErrorStream; }
		virtual DLStdInputStream* GetStdInputStream() { return &m_stdInputStream; }
		virtual void Exit(dl_int8 exitCode);
		virtual void SetDefaultAllocator(DLKR::DLAllocator* pAllocator);
		virtual dl_bool MountInstalledDisk2(dl_pointer pMountParam) const { return true; }
		virtual dl_bool UnmountInstalledDisk2(dl_pointer pUnmountParam) const { return false; }
		virtual dl_bool MountCacheDisk(dl_bool param_1);
		virtual dl_bool UnmountCacheDisk() const { return false; }
		virtual dl_bool DoesCacheDiskMount() const { return m_bMountedCacheDisk; }
		virtual dl_bool BeginInstall2(dl_pointer pMountParam) const { return true; }
		virtual dl_bool EndInstallAndMountDisk2(dl_pointer pMountParam) const { return true; }
		virtual dl_int GetInstallDirectoryState(const dl_wchar* path) const { return 1; }
		virtual dl_bool IsReadyToShutdown() const { return false; }
		virtual dl_bool IsBootByInvitation() const { return false; }
		virtual ~DLRuntimeImpl();

	private:
		DLUT::PODVectorBase m_unkVector;
		DLUT::PODVectorBase m_unkVector2;
		DLStdOutputStreamImpl m_stdErrorStream;
		DLStdInputStreamImpl m_stdInputStream;
		DLStdOutputStreamImpl m_stdOutputStream;
		DLAssertEventManagerImpl m_assertEventManager;
		dl_bool m_bVar1A0;
		dl_bool m_bVar1A1;
		dl_bool m_bVar1A2;
		dl_bool m_bVar1A3;
		dl_bool m_bVar1A4;
		dl_bool m_bVar1A5;
		dl_bool m_bVar1A6;
		dl_bool m_bAssertEventManagerInitialized;
		DLRealTimeServiceManagerImpl* m_pRSMgr;
		DLUT::DLProperties m_systemProperties;
		dl_bool m_bVar1C8;
		dl_bool m_bVar1C9;
		dl_bool m_bVar1CA;
		dl_bool m_bVar1CB;
		dl_bool m_bVar1CC;
		dl_bool m_bVar1CD;
		dl_bool m_bVar1CE;
		dl_bool m_bPropertiesInitialized;
		dl_bool m_bRealTimeServiceManagerInitialized;
		dl_bool m_bMountedCacheDisk;

		static DLRuntimeImpl* GetRuntimeImpl();

		typedef void(_fastcall* oLoadSystemProperties)(DLRuntimeImpl*, SysPropFilePath*, dl_pointer);
	};

#define RUNTIME_CLASS_ALLOCATOR *(DLKR::DLAllocator**)(MODULE_ADDR + 0x16681a0)
#define RUNTIME_ALLOCATOR *(DLKR::DLAllocator**)(MODULE_ADDR + 0x16681a8)
}
