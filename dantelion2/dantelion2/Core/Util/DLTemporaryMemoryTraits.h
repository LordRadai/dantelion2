#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"

namespace DLUT
{
	class DLTemporaryMemoryTraits
	{
		static DLKR::DLAllocator* GetDefaultHost();
	};
}