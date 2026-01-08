#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"

namespace DLSY
{
	class DLRealTimeServiceManager
	{
		void** _vfptr;
	};

	class DLRealTimeServiceManagerImpl : public DLRealTimeServiceManager
	{
	public:
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
		dl_pointer m_pVar40;
		dl_pointer m_pVar48;
		dl_pointer m_pVar50;
		dl_pointer m_pVar58;
		dl_pointer m_pVar60;
		dl_pointer m_pVar68;
		dl_pointer m_pVar70;
		dl_pointer m_pVar78;
		dl_bool m_bVar80;
		dl_bool m_bVar81;
		dl_uint m_iVar84;
	};
}
