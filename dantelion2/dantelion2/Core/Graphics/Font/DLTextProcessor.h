#pragma once
#include "DLFontSet.h"
#include "DLFontAttribute.h"
#include "Core/Kernel/DLAllocator.h"

namespace DLGR
{
	class DLTextProcessor
	{
		void** _vfptr;
		dl_float32 m_fVar8;
		dl_float32 m_fVarC;
		dl_uint m_iVar10;
		dl_float32 m_fVar14;
		dl_float32 m_fVar18;
		dl_float32 m_fVar1C;
		dl_float32 m_fVar20;
		dl_float32 m_fVar24;
		dl_float32 m_fVar28;
		dl_float32 m_fVar2C;
		dl_uint m_iVar30;
		dl_uint m_iVar34;
		dl_uint m_iVar38;
		dl_uint m_iVar3C;
		DLFontSet* m_pFontSet;
		DLFontAttribute* m_pFontAttribute;
		DLKR::DLAllocator* m_pAllocator;
		dl_uint16 m_iVar58;
	};
}