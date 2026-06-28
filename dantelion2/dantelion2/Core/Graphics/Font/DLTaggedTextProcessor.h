#pragma once
#include "DLTextProcessor.h"
#include "DLFontContextStack.inl"
#include "DLTaggedContext.h"
#include "Core/Math/DLColor.h"

namespace DLGR
{
	class DLTaggedTextProcessor : public DLTextProcessor
	{
		DLFontContextStack<DLTaggedContext> m_ContextStack;
		dl_uint m_iVarC8;
		DLFontContextStack<DLMT::DL_COLOR_32> m_ColorContextStack;
		DLFontContextStack<dl_uint> m_FontIDContextStack;

	public:
		DLTaggedTextProcessor() {}

		virtual ~DLTaggedTextProcessor() override;
	};
}