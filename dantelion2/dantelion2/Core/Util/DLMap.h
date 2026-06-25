#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"

#include <map>

namespace DLUT
{
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
    template<class Key, class T, class Compare = ::std::less<Key>, class AllocHost = DLKR::DLAllocator>
    class DLMap : public ::std::map<Key, T, Compare, DLKR::DLStdAllocator<std::pair<const Key, T>, AllocHost>>
    {
        typedef DLKR::DLStdAllocator<std::pair<const Key, T>, AllocHost> Allocator;
        typedef ::std::map<Key, T, Compare, DLKR::DLStdAllocator<std::pair<const Key, T>, AllocHost>> SuperClass;
    public:
        DLMap(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(Compare(), Allocator(host)) {}

        DLMap(const Compare& comp, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) :
            SuperClass(comp, Allocator(host)) {}

        DLMap(AllocHost* host, const Compare& comp) :
            SuperClass(comp, Allocator(host)) {}

        template<class InputIterator>
        DLMap(InputIterator first, InputIterator last, const Compare& comp, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) :
            SuperClass(first, last, comp, Allocator(host)) {}

        template<class InputIterator>
        DLMap(InputIterator first, InputIterator last, AllocHost* host, const Compare& comp) :
            SuperClass(first, last, comp, Allocator(host)) {}

        DLMap(const DLMap<Key, T, Compare, AllocHost>& x, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) :
            SuperClass(x.begin(), x.end(), x.key_comp(), Allocator(host)) {}
    };
#else
    template<class Key, class T, class Compare = ::std::less<Key>>
    class DLMap : public ::std::map<Key, T, Compare>
    {
        typedef DLKR::DLStdAllocator<std::pair<const Key, T>, DLKR::DLAllocator> Allocator;
        typedef ::std::map<Key, T, Compare> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLMap(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(Compare()), m_Allocator(host) {}

        DLMap(const Compare& comp, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(comp), m_Allocator(host) {}

        DLMap(DLKR::DLAllocator* host, const Compare& comp)
            : SuperClass(comp), m_Allocator(host) {}

        template<class InputIterator>
        DLMap(InputIterator first, InputIterator last, const Compare& comp, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last, comp), m_Allocator(host) {}

        template<class InputIterator>
        DLMap(InputIterator first, InputIterator last, DLKR::DLAllocator* host, const Compare& comp)
            : SuperClass(first, last, comp, Allocator(host)), m_Allocator(host) {}

        DLMap(const DLMap<Key, T, Compare>& x, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(x.begin(), x.end(), x.key_comp(), Allocator(host)), m_Allocator(host) {}
    };
#endif
}