#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"

namespace DLUID
{
	class DynamicBitset
	{
		void** _vfptr;
		dl_size m_byteSize;
		dl_uint* m_pData;
		DLKR::DLAllocator* m_pAllocator;
	};
}