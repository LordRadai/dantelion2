#pragma once
#include "Core/Kernel/detail/HeapAllocator.inl"
#include "Core/Kernel/DLLightMutex.h"

namespace DLKR
{
	class DLWin32RuntimeHeapImpl
	{
		void** _vfptr;
		DLKRD::HeapAllocator<DLWin32RuntimeHeapImpl>* m_pAllocator;
		DLKR::DLPlainLightMutex m_sync;
	};
}