#pragma once
#include "DLAllocator.h"
#include "Core/Platform/Platform.h"

namespace DLKR
{
	dl_pointer AllocateAligned(size_t blockSize, size_t alignment, DLAllocator* pAllocator);
	void Free(dl_pointer pMem, DLAllocator* pAllocator);
}

void* operator new[](size_t size, DLKR::DLAllocator* pAllocator);
void operator delete[](void* p, DLKR::DLAllocator* pAllocator);

#define ALLOCATE_NEW(type, allocator) new (allocator->AllocateAligned(sizeof(type), __alignof(type))) type