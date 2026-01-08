#pragma once
#include "DLAllocator.h"

namespace DLKR
{
	class DLBackAllocator : public DLAllocator
	{
		DLKR::DLAllocator* m_pAllocator;

	public:
		DLBackAllocator(DLKR::DLAllocator* pAllocator) : m_pAllocator(pAllocator) {}
	};
}