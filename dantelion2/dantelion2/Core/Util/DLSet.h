#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"
#include <set>

namespace DLUT
{
    template<class T, class Compare = ::std::less<T>>
    class DLSet : public std::set<T, Compare>
    {
        typedef DLKR::DLStdAllocator<T, DLKR::DLAllocator> Allocator;
        typedef ::std::set<T, Compare> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLSet(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(Compare()), m_Allocator(host) {}

        DLSet(const Compare& comp, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(comp), m_Allocator(host) {}

        template<class InputIterator>
        DLSet(InputIterator first, InputIterator last, const Compare& comp = Compare(), DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last, comp), m_Allocator(host) {}

        DLSet(const DLSet<T, Compare>& x, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(x.begin(), x.end(), x.key_comp()), m_Allocator(host) {}
    };
}