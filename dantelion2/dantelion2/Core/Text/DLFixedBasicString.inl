#pragma once
#include "Core/Platform/Platform.h"

namespace DLTX
{
	template<typename _Elem>
	class DLFixedBasicString
	{
		_Elem* m_pBuffer;
		dl_pointer m_pVar8;
		dl_size m_size;
		dl_size m_capacity;
		_Elem m_name[32];
		dl_pointer m_pVar40;
		dl_pointer m_pVar48;
		dl_pointer m_pVar50;
		dl_pointer m_pVar58;
		_Elem m_bVar60;
		dl_int m_iVar64;
		dl_int m_iVar68;

	public:
		_Elem* c_str() const { return m_pBuffer; }
	};
}