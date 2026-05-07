#include "DLVertexTypes.h"

namespace DLGR
{
	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_F4 color)
		: m_position(position.x, position.y, position.z, 1.0f), m_color(color) {}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_32 color)
		: m_position(position.x, position.y, position.z, 1.0f), m_color(static_cast<DLMT::DL_COLOR_F4>(color)) {}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT2::DL_COLOR_U8 color)
		: m_position(position.x, position.y, position.z, 1.0f), m_color(static_cast<DLMT::DL_COLOR_F4>(color)) {}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_F4 color, DLMT::DL_VECTOR3 normal)
		: m_position(position.x, position.y, position.z, 1.0f), m_color(color), m_normal(normal.x, normal.y, normal.z, 0.0f) {}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_32 color, DLMT::DL_VECTOR3 normal)
		: m_position(position.x, position.y, position.z, 1.0f), m_color(static_cast<DLMT::DL_COLOR_F4>(color)), m_normal(normal.x, normal.y, normal.z, 0.0f) {}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT2::DL_COLOR_U8 color, DLMT::DL_VECTOR3 normal)
		: m_position(position.x, position.y, position.z, 1.0f), m_color(static_cast<DLMT::DL_COLOR_F4>(color)), m_normal(normal.x, normal.y, normal.z, 0.0f) {}
}