#pragma once
#include "Core/Kernel/DLAllocator.h"

namespace DLKRD
{
    template<class H = DLKR::DLAllocator>
    class AllocationSupporter
    {
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
