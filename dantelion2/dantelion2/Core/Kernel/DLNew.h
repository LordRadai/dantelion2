#pragma once
#include "DLAllocator.h"
#include "Core/Platform/Platform.h"

namespace DLKR
{
    class AllocationSupporter
    {
    public:
		static dl_pointer Allocate(size_t blockSize, dl_size align, DLAllocator* pAllocator);
        static void Deallocate(void* p, DLAllocator* pAllocator);
    };
}

inline void* operator new(dl_size size, dl_size align, DLKR::DLAllocator* allocator) 
{
    return DLKR::AllocationSupporter::Allocate(size, align, allocator);
}

inline void operator delete(void* p, dl_size align, DLKR::DLAllocator* allocator)
{
    DLKR::AllocationSupporter::Deallocate(p, allocator);
}

#define DL_NEW(type, allocator) new (__alignof(type), allocator) type