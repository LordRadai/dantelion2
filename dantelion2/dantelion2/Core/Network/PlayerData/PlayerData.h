#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLReferenceCountObject.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"
#include "dantelion2/Core/Kernel/DLLightMutex.h"

namespace DLNRD
{
	class PlayerData : public DLUT::DLReferenceCountObject
	{
	public:
		dl_bool m_bInitialised;
		dl_pointer m_pOnlineIDData;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
	};
}
