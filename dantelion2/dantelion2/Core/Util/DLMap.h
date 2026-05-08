#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"
#include <functional>
#include <map>

namespace DLUT
{
    template<class Key, class T, class Compare = ::std::less<Key>, class AllocHost = DLKR::DLAllocator>
    class DLMap : public ::std::map<Key, T, Compare, DLKR::DLStdAllocator<std::pair<const Key, T>, AllocHost>>
    {
		typedef DLKR::DLStdAllocator<std::pair<const Key, T>, AllocHost> Allocator;
		typedef ::std::map<Key, T, Compare, DLKR::DLStdAllocator<std::pair<const Key, T>, AllocHost>> SuperClass;
    public:
		DLMap(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Compare(), Allocator(host)) {}

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
}