#pragma once
#include "DLLogManager.h"

namespace DLLG
{
	class DLLogManagerImpl : public DLLogManager
	{
		struct DLLogMessageMutex
		{
			DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
			DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_messageMutex;
			dl_uint8 m_flags;
		};

		struct LogMemoryManager
		{
			dl_char m_data[1192];
		};

		DLLoggingStrategy* m_pLoggingStrategy;
		DLCategoryRepository* m_pCategoryRepository;
		DLKR::DLAllocator* m_pRootAllocator;
		DLKR::DLAllocator* m_pMessageAllocator;
		dl_uint m_totalBufferSize;
		dl_uint m_messageBufferSize;
		dl_bool m_bInitialized;
		DLLogMessageMutex m_logMessageMutex;
		LogMemoryManager m_logMemory0;
		LogMemoryManager m_logMemory1;
		DLKR::DLAllocator* m_pUnknownAllocator;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_unknownMutex;

	public:
		virtual dl_bool SetRootAllocator(DLKR::DLAllocator* pAllocator) override;
		virtual DLKR::DLAllocator* GetRootAllocator() override;
		virtual DLKR::DLAllocator* GetAllocator() override;
		virtual DLKR::DLAllocator* GetMessageAllocator() override;
		virtual void ProcessAllLogEvents() override;
		virtual void ResetConfiguration() override;
		virtual dl_bool ApplyConfiguration(DLLoggingConfiguration& config) override;
		virtual void GetConfiguration(DLLoggingConfiguration& config) override;
		virtual dl_uint GetTotalBufferSize() override;
		virtual void SetTotalBufferSize(dl_uint size) override;
		virtual dl_uint GetMessageBufferSize() override;
		virtual void SetMessageBufferSize(dl_uint size) override;
		virtual DLCategoryRepository* GetCategoryRepository() override;
		virtual DLLoggingStrategy* GetLoggingStrategy() override;
		virtual void Log(DLLogEvent& pLE) override;
		virtual DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>& GetMutex() override;
		virtual ~DLLogManagerImpl();

		static DLLogManagerImpl* GetInstance();
	};
}
