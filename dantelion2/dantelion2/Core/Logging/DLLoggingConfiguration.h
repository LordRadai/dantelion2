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
	};
}
