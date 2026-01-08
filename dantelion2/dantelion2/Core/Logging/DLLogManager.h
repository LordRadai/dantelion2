#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLLightMutex.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "DLLoggingConfiguration.h"
#include "DLCategoryRepository.h"
#include "DLLoggingStrategy.h"
#include "DLLogEvent.h"

namespace DLLG
{
	class DLLogManager
	{
	public:
		virtual dl_bool SetRootAllocator(DLKR::DLAllocator* pAllocator) = 0;
		virtual DLKR::DLAllocator* GetRootAllocator() = 0;
		virtual DLKR::DLAllocator* GetAllocator() = 0;
		virtual DLKR::DLAllocator* GetMessageAllocator() = 0;
		virtual void ProcessAllLogEvents() = 0;
		virtual void ResetConfiguration() = 0;
		virtual dl_bool ApplyConfiguration(DLLoggingConfiguration& config) = 0;
		virtual void GetConfiguration(DLLoggingConfiguration& config) = 0;
		virtual dl_uint GetTotalBufferSize() = 0;
		virtual void SetTotalBufferSize(dl_uint size) = 0;
		virtual dl_uint GetMessageBufferSize() = 0;
		virtual void SetMessageBufferSize(dl_uint size) = 0;
		virtual DLCategoryRepository* GetCategoryRepository() = 0;
		virtual DLLoggingStrategy* GetLoggingStrategy() = 0;
		virtual void Log(DLLogEvent& pLE) = 0;
		virtual DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>& GetMutex() = 0;
		virtual ~DLLogManager();
	};
}
