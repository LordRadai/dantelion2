#pragma once
#include <list>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"

namespace DLUT
{
#if defined(_MSC_VER) && (_MSC_VER == 1700)
    template<class T, class AllocHost = DLKR::DLAllocator>
    class DLList : public std::list<T, DLKR::DLStdAllocator<T, AllocHost>>
    {
        typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
        typedef ::std::list<T, DLKR::DLStdAllocator<T, AllocHost>> SuperClass;
    public:
        DLList(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Allocator(host)) {}

        DLList(dl_size n, const T& value = T(), AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(n, value, Allocator(host)) {}

        template<class InputIterator>
        DLList(InputIterator first, InputIterator last, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(first, last, Allocator(host)) {}

        DLList(const DLList<T, AllocHost>& x) : SuperClass(x) {}
    };
#else
    template<class T>
    class DLList : public std::list<T>
    {
        typedef DLKR::DLStdAllocator<T, DLKR::DLAllocator> Allocator;
        typedef std::list<T> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLList(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(), m_Allocator(host) {}

        DLList(dl_size n, const T& value = T(), DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(n, value), m_Allocator(host) {}

        template<class InputIterator>
        DLList(InputIterator first, InputIterator last, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last), m_Allocator(host) {}

        DLList(const DLList<T>& x)
            : SuperClass(x), m_Allocator(x.m_Allocator) {}
    };
#endif
}