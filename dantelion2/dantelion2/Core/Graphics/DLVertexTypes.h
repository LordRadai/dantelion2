#pragma once
#include "Core/Math/Math.h"
#include <DirectXColors.h>

using namespace DirectX::SimpleMath;

namespace DLGR
{
	class DLVertexPositionColor
	{
	public:
		DLMT::DL_VECTOR4 m_position = DLMT::DL_VECTOR4::Zero;
		DLMT::DL_VECTOR4 m_color = DLMT::DL_VECTOR4(DirectX::Colors::White);

		DLVertexPositionColor() {}
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color);
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color);
		DLVertexPositionColor(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color);
		DLVertexPositionColor(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color);
	};

	class DLVertexPositionColorNormal
	{
	public:
		DLMT::DL_VECTOR4 m_position = DLMT::DL_VECTOR4::Zero;
		DLMT::DL_VECTOR4 m_color = DLMT::DL_VECTOR4(DirectX::Colors::White);
		DLMT::DL_VECTOR4 m_normal = DLMT::DL_VECTOR4::UnitZ;

		DLVertexPositionColorNormal() {}
		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR3 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR3 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR3 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR3 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR4 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR4 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR4 normal);
		DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR4 normal);
	};
}