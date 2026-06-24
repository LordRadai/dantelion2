#pragma once
#include "Core/Kernel/DLAllocator.h"
#include <deque>
namespace DLUT
{
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
}
