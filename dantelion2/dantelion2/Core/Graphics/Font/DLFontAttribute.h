#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Math/DLColor.h"
#include "Core/Graphics/DLRect.h"

namespace DLGR
{
	class DLTextProcessManager;

	class DLFontAttribute
	{
		DLGR::DL_FRECT m_Rect;
		dl_float32 m_fVar10;
		dl_float32 m_fVar14;
		dl_int m_Width;
		dl_int m_Height;
		dl_float32 m_fVar20;
		dl_float32 m_fVar24;
		dl_float32 m_fVar28;
		dl_float32 m_fVar2C;
		dl_float32 m_fVar30;
		dl_float32 m_fVar34;
		DLMT::DL_VECTOR2 m_Scale;
		dl_float32 m_fVar40;
		dl_float32 m_fVar44;
		dl_float32 m_fVar48;
		dl_float32 m_fVar4C;
		dl_float32 m_fVar50;
		dl_float32 m_fVar54;
		dl_float32 m_fVar58;
		dl_float32 m_fVar5C;
		DLMT::DL_VECTOR2 m_ShadowOffset;
		DLMT::DL_COLOR_32 m_Color;
		DLMT::DL_COLOR_32 m_ShadowColor;
		dl_float32 m_fVar70;
		dl_uint m_AlignX;
		dl_uint m_AlignY;
		dl_float32 m_fVar7C;
		dl_float32 m_fVar80;
		dl_int m_iVar84;
		dl_float32 m_fVar88;
		dl_float32 m_fVar8C;
		dl_float32 m_fVar90;
		dl_float32 m_fVar94;
		dl_uint m_FontID;
		dl_float32 m_fVar9C;
		dl_float32 m_fVarA0;
		DLTextProcessManager* m_pTextProcessManager;
	public:
	};
}