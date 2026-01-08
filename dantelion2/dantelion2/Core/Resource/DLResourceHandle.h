#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"

namespace DLRS
{
	class DLResourceHandle
	{
		void** _vfptr;
	public:
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>* m_pMutex;
	};
}
