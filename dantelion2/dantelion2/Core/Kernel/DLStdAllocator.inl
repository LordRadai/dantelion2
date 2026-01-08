#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLTypeManipulation.h"
#include "detail/DLAllocationHelper.h"
#include "DLAllocator.h"

namespace DLKR
{
    template<class T, class AllocationHostType = DLAllocator, class _HostPossessionType = AllocationHostType*>
    class DLStdAllocator
    {
        typedef _HostPossessionType HostPossessionType;
        typedef HostPossessionType HostType;

        HostType m_host;
    public:
        typedef dl_size size_type;
        typedef T* pointer;
        typedef const T* const_pointer;
        typedef dl_pointer_int ptrdiff_t;
        typedef dl_pointer_int difference_type;
        typedef T& reference;
        typedef const T& const_reference;
        typedef T value_type;
        typedef AllocationHostType host_type;
        typedef HostPossessionType possession_type;

        template<class U>
        struct rebind
        {
            typedef DLStdAllocator<U, host_type, possession_type> other;
        };

		DLStdAllocator(host_type* host = DLKRD::DLAllocationHelper<AllocationHostType>::GetDefaultHost()) : m_host(host)
        {
        }

		DLStdAllocator(const DLStdAllocator<T, host_type, possession_type>& dest) : m_host(dest.m_host)
        {
        }

        template<class U>
		DLStdAllocator(const DLStdAllocator<U, host_type, possession_type>& dest) : m_host(dest.get_host())
        {
        }

        const HostType& get_host(void) const { return m_host; }
        HostType& get_host(void) { return m_host; }

        DLAllocator* GetAllocator(void) { return m_host; }
        const DLAllocator* GetAllocator(void) const { return m_host; }

		pointer address(reference r) const { return &r; }
		const_pointer address(const_reference r) const { return &r; }

        pointer allocate(size_type n)
        {
            if (n > max_size())
                throw std::bad_alloc();
            void* p = m_host->Allocate(n);

            if (p == nullptr)
                throw std::bad_alloc();

            return static_cast<pointer>(p);
		}

        template<typename _Other>
        _Other* allocate(size_type n, const _Other* hint)
        {
            (void)hint;
			return allocate(n);
        }

        pointer allocate_aligned(size_type n, size_type align)
        {
            if (n > max_size())
                throw std::bad_alloc();

            void* p = m_host->AllocateAligned(n, align);
            if (p == nullptr)
                throw std::bad_alloc();

			return static_cast<pointer>(p);
        }

        template < typename _Other >
        _Other* allocate_aligned(size_type n, size_type align, const _Other* hint)
        {
			(void)hint;
			return allocate_aligned(n, align);
        }

        void deallocate(pointer p, size_type n)
        {
			m_host->Free(p);
        }

        size_type max_size(void) const
        {
			return static_cast<size_type>(-1) / sizeof(T);
        }

        void construct(pointer p, const T& val) 
        {
			new ((void*)p) T(val);
        }

        void destroy(pointer p)
        {
			p->~T();
        }
    };
}