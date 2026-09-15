#pragma once
#include <type_traits>

#include "DLAllocator.h"
#include "Core/Platform/Platform.h"

namespace DLKR
{
    template<class H>
    class AllocationSupporter
    {
        static_assert(std::is_base_of<DLKR::DLAllocator, H>::value,
            "AllocationSupporter requires H to derive from DLKR::DLAllocator");

    public:
        static dl_pointer Allocate(size_t blockSize, dl_size align, H* a)
        {
            if (!((align & (align - 1)) == 0)) DL_PANIC("Alignment size must be 2^n size");

            return a->AllocateAligned(blockSize, align);
        }

        static void Deallocate(void* p, H* a)
        {
            if (!a)
                DL_PANIC("Heap not found for releasing buffer.");

            a->Free(p);
        }
    };
}

template<class H>
inline void* operator new(dl_size size, dl_size align, H* allocator) 
{
    return DLKR::AllocationSupporter<H>::Allocate(size, align, allocator);
}

template<class H>
inline void operator delete(void* p, dl_size align, H* allocator)
{
    DLKR::AllocationSupporter<H>::Deallocate(p, allocator);
}

#define DL_NEW(type, allocator) new(__alignof(type), allocator) type