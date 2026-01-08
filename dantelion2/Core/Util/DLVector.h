#pragma once
#include <vector>
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Kernel/DLStdAllocator.inl"

namespace DLUT
{
	template<class T, class AllocHost = DLKR::DLAllocator>
	class DLVector : public std::vector<T>
	{
		typedef DLKR::DLStdAllocator<T, AllocHost> Allocator;
		typedef ::std::vector<T> SuperClass;

		DLKR::DLAllocator* m_pAllocator;
	public:
		DLVector() : SuperClass(), m_pAllocator(DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) {}
		DLVector(AllocHost* pAllocator) : SuperClass(), m_pAllocator(pAllocator) {}

		DLVector(size_t size, AllocHost* pAllocator) : SuperClass(size, Allocator(pAllocator))
		{
			this->reserve(size);
		}

		DLVector(const DLVector& other, AllocHost* pAllocator) : SuperClass(other, Allocator(pAllocator))
		{
		}

		DLVector& operator=(const DLVector& other)
		{
			if (this != &other)
				SuperClass::operator=(other);

			return *this;
		}
	};
}