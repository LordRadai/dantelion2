#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"
#include "dantelion2/Core/Kernel/DLLightMutex.h"

namespace DLRS
{
	class DLResourceHandle
	{
		void** _vfptr;
	public:
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>* m_pMutex;
	};
}
