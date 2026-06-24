#pragma once
#include <list>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"

namespace DLUT
{
    template<class T>
    class DLList : public std::list<T, DLKR::DLStdAllocator<T, DLKR::DLAllocator>>
    {
        typedef DLKR::DLStdAllocator<T, DLKR::DLAllocator> Allocator;
        typedef std::list<T, Allocator> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLList(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(Allocator(host)), m_Allocator(host) {}

        DLList(dl_size n, const T& value = T(), DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(n, value, Allocator(host)), m_Allocator(host) {}

        template<class InputIterator>
        DLList(InputIterator first, InputIterator last, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last, Allocator(host)), m_Allocator(host) {}

        DLList(const DLList<T>& x)
            : SuperClass(x), m_Allocator(x.m_Allocator) {}
    };
}