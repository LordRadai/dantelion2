#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"

namespace DLSY
{
	class DLAssertEventManager
	{
		void** _vfptr;
	};

	class DLAssertEventManagerImpl : public DLAssertEventManager
	{
	public:
		dl_pointer m_pVar8;
		dl_pointer m_pVar10;
		dl_pointer m_pVar18;
		dl_pointer m_pVar20;
		dl_pointer m_pVar28;
		dl_pointer m_pVar30;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
	};
}
