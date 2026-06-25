#pragma once
#include "Core/Kernel/DLAllocator.h"
#include <deque>
namespace DLUT
{
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
	template<class T, class AllocHost = DLKR::DLAllocator>
	class DLDeque : public std::deque<T, DLKR::DLStdAllocator<T, AllocHost>>
	{
		typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
		typedef ::std::deque<T, DLKR::DLStdAllocator<T, AllocHost>> SuperClass;
	public:
		DLDeque(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Allocator(host)) {}

		DLDeque(dl_size n, const T& value = T(), AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(n, value, Allocator(host)) {}

		template<class InputIterator>
		DLDeque(InputIterator first, InputIterator last, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(first, last, Allocator(host)) {}

		DLDeque(const DLDeque<T, AllocHost>& x) : SuperClass(x) {}
	};
#else
	template<class T, class AllocHost = DLKR::DLAllocator>
	class DLDeque : public std::deque<T>
	{
		typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
		typedef ::std::deque<T> SuperClass;
	public:
		DLDeque(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass() {}

		DLDeque(dl_size n, const T& value = T(), AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(n, value) {}

		template<class InputIterator>
		DLDeque(InputIterator first, InputIterator last, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(first, last) {}

		DLDeque(const DLDeque<T, AllocHost>& x) : SuperClass(x) {}
	};
#endif
}
