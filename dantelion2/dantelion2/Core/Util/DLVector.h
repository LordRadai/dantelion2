#pragma once
#include <vector>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"

namespace DLUT
{
    template<class T>
    class DLVector : public std::vector<T, DLKR::DLStdAllocator<T, DLKR::DLAllocator>>
    {
        typedef DLKR::DLStdAllocator<T, DLKR::DLAllocator> Allocator;
        typedef std::vector<T, Allocator> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLVector(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(Allocator(host)), m_Allocator(host) {}

        DLVector(dl_size n, const T& value = T(), DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(n, value, Allocator(host)), m_Allocator(host) {}

        template<class InputIterator>
        DLVector(InputIterator first, InputIterator last, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last, Allocator(host)), m_Allocator(host) {}

        DLVector(const DLVector<T>& x)
            : SuperClass(x), m_Allocator(x.m_Allocator) {}

        DLVector(const Allocator& a)
            : SuperClass(a), m_Allocator(a.get_host()) {}

        DLVector(dl_size n, const T& value, const Allocator& a)
            : SuperClass(n, value, a), m_Allocator(a.get_host()) {}

        template<class InputIterator>
        DLVector(InputIterator first, InputIterator last, const Allocator& a)
            : SuperClass(first, last, a), m_Allocator(a.get_host()) {}
    };
}