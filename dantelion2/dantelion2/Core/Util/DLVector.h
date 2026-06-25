#pragma once
#include <vector>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"

namespace DLUT
{
#if defined(_MSC_VER) && (_MSC_VER == 1700)
    template<class T, class AllocHost = DLKR::DLAllocator>
    class DLVector : public std::vector<T, DLKR::DLStdAllocator<T, AllocHost>>
    {
        typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
        typedef ::std::vector<T, DLKR::DLStdAllocator<T, AllocHost>> SuperClass;
    public:
        DLVector(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Allocator(host)) {}
        DLVector(dl_size n, const T& value = T(), AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(n, value, Allocator(host)) {}

        template<class InputIterator>
        DLVector(InputIterator first, InputIterator last, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(first, last, Allocator(host)) {}

        DLVector(const DLVector<T, AllocHost>& x) : SuperClass(x) {}

        DLVector(const Allocator& a) : SuperClass(a) {}
        DLVector(dl_size n, const T& value, Allocator& a) : SuperClass(n, value, a) {}

        template<class InputIterator>
        DLVector(InputIterator first, InputIterator last, Allocator& a) : SuperClass(first, last, a) {}
    };
#else
    template<class T>
    class DLVector : public std::vector<T>
    {
        typedef DLKR::DLStdAllocator<T, DLKR::DLAllocator> Allocator;
        typedef std::vector<T> SuperClass;

        DLKR::DLAllocator* m_Allocator;
    public:
        DLVector(DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(), m_Allocator(host) {}

        DLVector(dl_size n, const T& value = T(), DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(n, value), m_Allocator(host) {}

        template<class InputIterator>
        DLVector(InputIterator first, InputIterator last, DLKR::DLAllocator* host = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(first, last), m_Allocator(host) {}

        DLVector(const DLVector<T>& x)
            : SuperClass(x), m_Allocator(x.m_Allocator) {}

        DLVector(const Allocator& a)
            : SuperClass(), m_Allocator(a.get_host()) {}

        DLVector(dl_size n, const T& value, const Allocator& a)
            : SuperClass(n, value), m_Allocator(a.get_host()) {}

        template<class InputIterator>
        DLVector(InputIterator first, InputIterator last, const Allocator& a)
            : SuperClass(first, last), m_Allocator(a.get_host()) {}
    };
#endif
}