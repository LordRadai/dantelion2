#pragma once
#include <list>
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace DLUT
{
	template<class T>
	class DLList : public std::list<T>
	{
		typedef ::std::list<T> SuperClass;

		DLKR::DLAllocator* m_pAllocator;
	public:
		DLList() : SuperClass() {}
		DLList(DLKR::DLAllocator* pAllocator) : SuperClass(), m_pAllocator(pAllocator) {}
		DLList(const DLList& other) : SuperClass(other), m_pAllocator(other.m_pAllocator) {}

		DLList& operator=(const DLList& other)
		{
			if (this != &other)
			{
				SuperClass::operator=(other);
				m_pAllocator = other.m_pAllocator;
			}

			return *this;
		}
	};
}
