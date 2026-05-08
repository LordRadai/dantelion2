#pragma once
#include <vector>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"

namespace DLUT
{
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
}