#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLReferenceCountObject.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"

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
