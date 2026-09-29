#pragma once
#include <new>
#include "Core/Platform/Platform.h"

namespace DLUT
{
	template<typename T, size_t nSize>
	class DLFixedVector
	{
		dl_uint8 m_Storage[nSize * sizeof(T) + __alignof(T) - 1];
		dl_size  m_Count;

	public:
		DLFixedVector() : m_Count(0) {}

		T* Data()
		{
			dl_pointer_int p = reinterpret_cast<dl_pointer_int>(m_Storage);
			return reinterpret_cast<T*>(p + ((0 - p) & (__alignof(T) - 1)));
		}

		const T* Data() const { return const_cast<DLFixedVector*>(this)->Data(); }

		T* GetAt(size_t index)
		{
			if (index >= m_Count)
				return nullptr;

			return &Data()[index];
		}

		void PushBack(const T& value)
		{
			if (m_Count >= nSize)
				DL_PANIC("out of memory");

			new (&Data()[m_Count]) T(value);

			m_Count++;
		}

		T& operator[](size_t index) { return Data()[index]; }

		T* Begin() { return Data(); }
		T* End() { return Data() + m_Count; }

		dl_size Size() const { return m_Count; }

		void Clear()
		{
			for (size_t i = 0; i < m_Count; ++i)
				Data()[i].~T();

			m_Count = 0;
		}
	};
}