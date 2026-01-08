#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include <deque>
namespace DLUT
{
	template<class T>
	class DLDeque : public std::deque<T>
	{
		DLKR::DLAllocator* m_pAllocator;
	public:
	};
}
