#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include <set>

namespace DLUT
{
	template<class T, class Compare = ::std::less<T>, class AllocHost = DLKR::DLAllocator>
	class DLSet : public std::set<T, Compare, DLKR::DLStdAllocator<T, AllocHost>>
	{
		typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
		typedef ::std::set<T, Compare, DLKR::DLStdAllocator<T, AllocHost>> SuperClass;
	public:
		DLSet(AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Compare(), Allocator(host)) {}

		DLSet(const Compare& comp, AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(comp, Allocator(host)) {}
		
		template<class InputIterator>
		DLSet(InputIterator first, InputIterator last, const Compare& comp = Compare(), AllocHost* host = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(first, last, comp, Allocator(host)) {}
		
		DLSet(const DLSet<T, Compare, AllocHost>& x) : SuperClass(x.begin(), x.end(), x.key_comp(), Allocator(x)) {}
	};
}
