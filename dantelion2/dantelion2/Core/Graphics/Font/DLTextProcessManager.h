#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLDummySyncObject.h"
#include "DLFontAttribute.h"
#include "DLFontSet.h"
#include "DLTaggedTextProcessor.h"

namespace DLGR
{
	class DLTextProcessManager : public DLKR::DLDummySyncObject
	{
		DLFontSet m_FontSet;
		DLFontAttribute m_FontAttribute;
		DLTaggedTextProcessor m_TaggedTextProcessor;
		DLKR::DLAllocator* m_pAllocator;
		dl_pointer m_pFont;
	public:
		DLFontSet* GetFontSet() { return &m_FontSet; }
	};
}