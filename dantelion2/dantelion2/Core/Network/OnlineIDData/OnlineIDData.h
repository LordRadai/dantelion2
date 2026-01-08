#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLReferenceCountObject.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"
#include "dantelion2/Core/Kernel/DLLightMutex.h"

namespace DLNRD
{
	class OnlineIDData : public DLUT::DLReferenceCountObject
	{
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
	};
}
