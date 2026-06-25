#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"
#include <set>

namespace DLUT
{
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
    template<class T, class Compare = ::std::less<T>, class AllocHost = DLKR::DLAllocator>
    class DLSet : public std::set<T, Compare, DLKR::DLStdAllocator<T, AllocHost>>
    {
        typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
        typedef ::std::set<T, Compare, DLKR::DLStdAllocator<T, AllocHost>> SuperClass;
    public:
        DLSet(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Compare(), Allocator(host)) {}

        DLSet(const Compare& comp, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(comp, Allocator(host)) {}

        template<class InputIterator>
        DLSet(InputIterator first, InputIterator last, const Compare& comp = Compare(), AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(first, last, comp, Allocator(host)) {}

        DLSet(const DLSet<T, Compare, AllocHost>& x) : SuperClass(x.begin(), x.end(), x.key_comp(), Allocator(x)) {}
    };
#else
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
#endif
}