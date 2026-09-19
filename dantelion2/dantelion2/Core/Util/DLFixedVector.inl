#pragma once
#include <vector>
#include "Core/Platform/Platform.h"

namespace DLUT
{
	template<typename T, size_t nSize>
	class DLFixedVector
	{
		T m_Data[nSize];
		dl_pointer m_UnkPtr;
		dl_size m_Count;

	public:
		T* GetAt(size_t index)
		{
			if (index >= m_Count)
				return nullptr;

			return &m_Data[index];
		}

		void PushBack(const T& value)
		{
			if (m_Count >= nSize)
				DL_PANIC("out of memory");

			m_Data[m_Count] = value;
			m_Count++;
		}

		T& operator[](size_t index)
		{
			return *GetAt(index);
		}

		dl_uint Size() const { return m_Count; }

		void Clear()
		{
			m_Count = 0;
		}
	};
}