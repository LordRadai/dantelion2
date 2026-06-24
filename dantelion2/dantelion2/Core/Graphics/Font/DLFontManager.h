#pragma once
#include "DLGlyphVectorRenderer.h"
#include "DLStringCollection.h"
#include "DLTextProcessManager.h"
#include "Core/Kernel/DLDummySyncObject.h"

namespace DLGR
{
	class DLFontManager
	{
	protected:
		DLTextProcessManager m_TextProcessMgr;
		DLGlyphVectorRenderer m_GlyphVectorRenderer;
		DLStringCollection m_StringCollection;
		DLDrawDevice* m_pDrawDevice;
		DLKR::DLAllocator* m_pAllocator;
		DLKR::DLDummySyncObject m_SyncObject0;
		DLKR::DLDummySyncObject m_SyncObject1;
		dl_uint m_iVar3A0;
		dl_pointer m_pVar3A8;
	};
}