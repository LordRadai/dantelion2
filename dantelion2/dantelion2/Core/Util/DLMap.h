#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Kernel/DLStdAllocator.inl"
#include <functional>
#include <map>

namespace DLUT
{
    template<class Key, class T, class Compare = ::std::less<Key>>
    class DLMap : public ::std::map<Key, T, Compare>
    {
		DLKR::DLAllocator* m_pAllocator;
    public:
    };
}