#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"
#include "dantelion2/Core/Kernel/DLLightMutex.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"

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
