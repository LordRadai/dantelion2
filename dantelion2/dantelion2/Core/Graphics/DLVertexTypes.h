#pragma once
#include "Core/Math/Math.h"

namespace DLGR
{
	class DLVertexPositionColor
	{
	public:
		DLMT::DL_VECTOR3 m_position = DLMT::DL_VECTOR3_ZERO;
		DLMT::DL_VECTOR4 m_color = DLMT::DL_VECTOR4_ZERO;

		DLVertexPositionColor() {}
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_F4 color);
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_32 color);
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT2::DL_COLOR_U8 color);
	};

	class DLVertexPositionColorNormal
	{
	public:
		DLMT::DL_VECTOR3AL m_position = DLMT::DL_VECTOR3_ZERO;
		DLMT::DL_VECTOR4AL m_color = DLMT::DL_VECTOR4_ZERO;
		DLMT::DL_VECTOR3AL m_normal = DLMT::DL_VECTOR3_UNITZ;

		DLVertexPositionColorNormal() {}

		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_F4 color, DLMT::DL_VECTOR3 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_32 color, DLMT::DL_VECTOR3 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT2::DL_COLOR_U8 color, DLMT::DL_VECTOR3 normal);
	};
}