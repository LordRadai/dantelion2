#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include <set>

namespace DLUT
{
	template<class T>
	class DLSet : public std::set<T>
	{
		DLKR::DLAllocator* m_pAllocator;
	};
}
