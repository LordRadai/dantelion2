#include "DLVertexTypes.h"

namespace DLGR
{
	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_F4 color)
		: Position(position.x, position.y, position.z), Color(color) {}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_32 color)
		: Position(position.x, position.y, position.z), Color(static_cast<DLMT::DL_COLOR_F4>(color)) {}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT2::DL_COLOR_U8 color)
		: Position(position.x, position.y, position.z), Color(static_cast<DLMT::DL_COLOR_F4>(color)) {}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_F4 color, DLMT::DL_VECTOR3 normal)
		: Position(position.x, position.y, position.z), Color(color), Normal(normal.x, normal.y, normal.z) {}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_COLOR_32 color, DLMT::DL_VECTOR3 normal)
		: Position(position.x, position.y, position.z), Color(static_cast<DLMT::DL_COLOR_F4>(color)), Normal(normal.x, normal.y, normal.z) {}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT2::DL_COLOR_U8 color, DLMT::DL_VECTOR3 normal)
		: Position(position.x, position.y, position.z), Color(static_cast<DLMT::DL_COLOR_F4>(color)), Normal(normal.x, normal.y, normal.z) {}
}