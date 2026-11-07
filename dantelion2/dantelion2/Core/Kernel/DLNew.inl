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

template<class T, class H>
inline void DLDelete(T* p, H* allocator)
{
    if (p)
    {
        p->~T();
        DLKRD::AllocationSupporter<H>::Deallocate(const_cast<typename std::remove_cv<T>::type*>(p), allocator);
    }
}

#define DL_NEW(type, allocator) new(__alignof(type), allocator) type
#define DL_DELETE(p, allocator) DLDelete(p, allocator)