#pragma once
#include "Core/Platform/Platform.h"
#include "DLFontSet.h"
#include "Core/Graphics/DLDrawDevice.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Util/DLVector.h"

namespace DLGR
{
	class DLGlyphVectorRenderer
	{
		DLDrawDevice* m_pDrawDevice;
		DLKR::DLAllocator* m_pAllocator;
		DLUT::DLVector<dl_pointer> m_GlyphVector;
		DLFontSet* m_pFontSet;
		dl_int m_iVar40;
		dl_pointer m_pVar48;
		dl_pointer m_pVar50;
		dl_uint8 m_UnkData[72];
		dl_uint m_iVarA0;
		dl_uint m_iVarA4;
		dl_pointer m_pVarA8;
	public:
		virtual ~DLGlyphVectorRenderer() {}
	};
}