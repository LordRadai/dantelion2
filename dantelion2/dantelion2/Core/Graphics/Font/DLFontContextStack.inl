#pragma once
#include "DLFontContextHolder.inl"

namespace DLGR
{
	template<class Ctx>
	class DLFontContextStack : DLFontContextHolder<Ctx>
	{
		dl_pointer m_pVar8;
		dl_uint8 m_Data[88];
	};
}