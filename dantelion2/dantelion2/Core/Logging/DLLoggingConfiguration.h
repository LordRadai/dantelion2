#pragma once
#include "Core/Kernel/DLAllocator.h"

namespace DLLG
{
	class DLLoggingConfiguration
	{
		DLKR::DLAllocator* m_pRootAllocator;
		const char* m_pRepositoryClassName;
		const char* m_pStrategyClassName;
		dl_uint8 m_szMQueue;
		dl_uint32 m_szMBuf;
		dl_uint32 m_szTB;
		DLKR::DLAllocator* m_pMessageAllocator;

	public:
		DLLoggingConfiguration(DLKR::DLAllocator* pRootAllocator = 0, dl_uint32 szTB = 0, dl_uint32 szMBuf = 0, dl_uint8 szMQueue = 0,
			const char* pRepositoryClassName = nullptr,
			const char* pStrategyClassName = nullptr,
			DLKR::DLAllocator* pMessageAllocator = nullptr) : m_pRootAllocator(pRootAllocator), 
			m_szTB(szTB), m_szMBuf(szMBuf), m_szMQueue(szMQueue),
			m_pRepositoryClassName(pRepositoryClassName), m_pStrategyClassName(pStrategyClassName), 
			m_pMessageAllocator(pMessageAllocator) 
		{}

		const char* GetCategoryRepositoryClassName() const { return m_pRepositoryClassName; }
		const char* GetLoggingStrategyClassName() const { return m_pStrategyClassName; }

		DLKR::DLAllocator* GetRootAllocator() const { return m_pRootAllocator; }
		dl_uint32 GetTotalBufferSize() const { return m_szTB; }
		dl_uint32 GetMessageBufferSize() const { return m_szMBuf; }
		dl_uint8 GetMessageQueueSize() const { return m_szMQueue; }
	};
}