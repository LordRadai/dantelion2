#pragma once
#include <new>
#include "Core/Platform/Platform.h"

namespace DLUT
{
	template<typename T, size_t nSize>
	class DLFixedVector
	{
		// Raw storage with alignof(T)-1 bytes of slack; the start is aligned at runtime.
		// For T = dl_int, nSize = 5: 20 + 3 = 23 bytes, padded to 24 → m_Count at +0x18, sizeof = 0x20.
		dl_uint8 m_Storage[nSize * sizeof(T) + alignof(T) - 1];
		dl_size  m_Count;

		T* Data()
		{
			dl_uintptr p = reinterpret_cast<dl_uintptr>(m_Storage);
			return reinterpret_cast<T*>(p + ((0 - p) & (alignof(T) - 1)));
		}
		const T* Data() const { return const_cast<DLFixedVector*>(this)->Data(); }

	public:
		DLFixedVector() : m_Count(0) {}

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

		dl_uint Size() const { return static_cast<dl_uint>(m_Count); }

		void Clear()
		{
			for (size_t i = 0; i < m_Count; ++i)
				Data()[i].~T();
			m_Count = 0;
		}
	};
}

static_assert(sizeof(DLUT::DLFixedVector<dl_int, 5>) == 0x20, "DLFixedVector layout mismatch");