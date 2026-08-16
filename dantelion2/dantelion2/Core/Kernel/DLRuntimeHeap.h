#pragma once
#include "DLAllocator.h"

namespace DLKR
{
	class DLRuntimeHeap
	{
	public:
		static DLKR::DLAllocator* GetAllocator();
	};
}