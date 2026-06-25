#pragma once
#include "DLLogManager.h"
#include "Core/Util/DLProperties.h"

namespace DLLG
{
	class DLPropertyConfigurator
	{
	public:
		static dl_bool Configure(const DLUT::DLProperties& properties, DLKR::DLAllocator* pAllocator);
	};
}