#pragma once
#include "DLAllocator.h"

namespace DLKR
{
	class DLDebugAllocator : public DLAllocator
	{
		DLAllocator* m_pA;
		DLAllocatorIdentifier m_id;

	public:
		DLDebugAllocator(DLAllocator* pAllocator, DLAllocatorIdentifier id = 0) : m_pA(pAllocator), m_id(id) {}
	};
}
