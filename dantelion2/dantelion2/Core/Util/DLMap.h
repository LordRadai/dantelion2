#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"
#include <functional>
#include <map>

namespace DLUT
{
    template<class Key, class T, class Compare = ::std::less<Key>>
    class DLMap : public ::std::map<Key, T, Compare, DLKR::DLStdAllocator<std::pair<const Key, T>, DLKR::DLAllocator>>
    {
        typedef DLKR::DLStdAllocator<std::pair<const Key, T>, DLKR::DLAllocator> Allocator;
        typedef ::std::map<Key, T, Compare, Allocator> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLMap(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(Compare(), Allocator(host)), m_Allocator(host) {}

        DLMap(const Compare& comp, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(comp, Allocator(host)), m_Allocator(host) {}

        DLMap(DLKR::DLAllocator* host, const Compare& comp)
            : SuperClass(comp, Allocator(host)), m_Allocator(host) {}

        template<class InputIterator>
        DLMap(InputIterator first, InputIterator last, const Compare& comp, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last, comp, Allocator(host)), m_Allocator(host) {}

        template<class InputIterator>
        DLMap(InputIterator first, InputIterator last, DLKR::DLAllocator* host, const Compare& comp)
            : SuperClass(first, last, comp, Allocator(host)), m_Allocator(host) {}

        DLMap(const DLMap<Key, T, Compare>& x, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(x.begin(), x.end(), x.key_comp(), Allocator(host)), m_Allocator(host) {}
    };
}