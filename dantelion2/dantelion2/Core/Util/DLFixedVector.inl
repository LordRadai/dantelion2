#pragma once
#include <vector>
#include "Core/Platform/Platform.h"

namespace DLUT
{
	template<typename T, size_t nSize, size_t align>
	class DLFixedVector
	{
		T m_data[nSize];
		dl_uint m_count;

	public:
		T* GetAt(size_t index)
		{
			if (index >= m_count)
				return nullptr;

			return &m_data[index];
		}

		dl_uint Size() const { return m_count; }
	};
}