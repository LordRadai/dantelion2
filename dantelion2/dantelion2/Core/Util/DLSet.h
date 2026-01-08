#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include <set>

namespace DLUT
{
	template<class T>
	class DLSet : public std::set<T>
	{
		DLKR::DLAllocator* m_pAllocator;
	};
}
