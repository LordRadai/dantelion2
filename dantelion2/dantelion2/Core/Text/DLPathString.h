#pragma once
#include "Core/Text/DLString.inl"

namespace DLTX
{
	class DLPathString
	{
	public:
		DLPathString();
		DLPathString(DLKR::DLAllocator* allocator) : m_String(allocator), m_CharacterSet(1) {}

		const dl_wchar* c_str() const { return m_String.c_str(); }
		dl_size size() const { return m_String.size(); }
		dl_bool empty() const { return m_String.empty(); }

		DLString m_String;
		dl_uint8 m_CharacterSet;
	};
}
