#pragma once
#include "Core/Platform/Platform.h"
#include "DLAllocator.h"

namespace DLKR
{
	class DLHeapManager
	{
	public:
		static DLKR::DLAllocator* FindHeap(dl_pointer pData);
	};
}