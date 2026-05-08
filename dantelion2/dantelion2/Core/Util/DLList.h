#pragma once
#include <list>
#include "Core/Kernel/DLAllocator.h"

namespace DLUT
{
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
}
