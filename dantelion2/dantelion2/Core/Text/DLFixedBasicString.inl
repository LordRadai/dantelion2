#pragma once
#include "Core/Platform/Platform.h"

namespace DLTX
{
	template<typename _Elem, dl_size N = 32>
	class DLFixedBasicString
	{
		union
		{
			_Elem* m_pPtr;
			_Elem m_sso[16 / sizeof(_Elem)];
		};
		dl_size m_size;
		dl_size m_capacity;

		_Elem m_buffer[N];
		dl_uint8 m_allocatorState[8];
		dl_bool m_bFixed;

	public:
		const _Elem* c_str() const { return m_capacity >= (16 / sizeof(_Elem)) ? m_pPtr : m_sso; }
		dl_size size() const { return m_size; }
	};
}