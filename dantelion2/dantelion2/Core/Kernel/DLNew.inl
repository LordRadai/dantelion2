#pragma once
#include <type_traits>

#include "detail/AllocationSupporter.inl"
#include "Core/Platform/Platform.h"

template<class H>
inline void* operator new(dl_size size, dl_size align, H* allocator) 
{
    return DLKRD::AllocationSupporter<H>::Allocate(size, align, allocator);
}

template<class H>
inline void operator delete(void* p, dl_size align, H* allocator)
{
    DLKRD::AllocationSupporter<H>::Deallocate(p, allocator);
}

#define DL_NEW(type, allocator) new(__alignof(type), allocator) type