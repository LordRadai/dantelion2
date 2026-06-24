#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLMap.h"
#include "DLFontData.h"

namespace DLGR
{
	class DLFontSet
	{
		DLUT::DLMap<dl_uint, dl_uint> m_FontMap;
		dl_int m_iVar18;
		dl_int m_iVar1C;
		DLKR::DLAllocator* m_pAllocator;
	public:
		dl_bool RegisterFont(dl_uint id, DLFontData* pFontData);
	};
}