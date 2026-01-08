#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "DLStdInputStream.h"
#include "DLStdOutputStream.h"
#include "DLAssertEventManager.h"
#include "DLRealTimeServiceManager.h"
#include "dantelion2/Core/Util/DLProperties.h"
#include "dantelion2/Core/Util/DLVector.h"

namespace DLSY
{
	class DLRuntime
	{
		void** _vfptr;
	public:
		static void InvokeDebugger();
		DLKR::DLAllocator* GetDefaultAllocator();
		const dl_wchar* GetVersionString();

		static DLRuntime* GetDLRuntime();
	};

	class DLRuntimeImpl : public DLRuntime
	{
	public:
		struct SysPropFilePath
		{
			const dl_wchar* m_path;
			dl_bool m_bInitialized;
		};

		struct UnkList
		{
			DLUT::DLVector<dl_pointer> m_unkList;
			dl_bool m_bVar20;
			dl_bool m_bVar21;
			dl_bool m_bVar22;
			dl_bool m_bVar23;
			dl_bool m_bVar24;
			dl_bool m_bVar25;
			dl_bool m_bVar26;
			dl_bool m_bInitialized;
		};

		UnkList m_unkList;
		UnkList m_unkList2;
		DLStdOutputStreamImpl m_stdout;
		DLStdOutputStreamImpl m_stderr;
		DLStdInputStreamImpl m_stdin;
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
		dl_bool m_bMountedInstall;

		static DLRuntimeImpl* GetDLRuntime();

		typedef void(_fastcall* oLoadSystemProperties)(DLRuntimeImpl*, SysPropFilePath*, dl_pointer);
	};

#define DEFAULT_ALLOCATOR *(DLKR::DLAllocator**)(MODULE_ADDR + 0x16681a8);
}
