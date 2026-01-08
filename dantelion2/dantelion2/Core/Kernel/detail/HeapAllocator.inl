#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"

namespace DLKRD
{
	template<class _Heap>
	class HeapAllocator : public DLKR::DLAllocator
	{
		_Heap m_pHeap;
	};
}