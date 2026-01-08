#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLStdAllocator.inl"
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