#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLReferenceCountObject.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"

namespace DLNRD
{
	class OnlineIDData : public DLUT::DLReferenceCountObject
	{
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
	};
}
