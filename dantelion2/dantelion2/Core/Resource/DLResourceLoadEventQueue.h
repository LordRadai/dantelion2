#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"
#include "Core/Kernel/DLAllocator.h"

namespace DLRS
{
	class DLResourceLoadEventQueue
	{
		void** _vfptr;
	public:
		DLKR::DLAllocator* m_pAllocator;
		dl_pointer m_pVar10;
		dl_pointer m_pFileTransferTaskManager;
		dl_uint m_iVar20;
	};
}
