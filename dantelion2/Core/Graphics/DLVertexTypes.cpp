#include "DLVertexTypes.h"

namespace DLGR
{
	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color)
	{
		this->m_position = Vector4(position);
		this->m_color = color;
	}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color)
	{
		this->m_position = Vector4(position);
		this->m_color = color;
	}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color)
	{
		this->m_position = position;
		this->m_color = color;
	}

	DLVertexPositionColor::DLVertexPositionColor(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color)
	{
		this->m_position = position;
		this->m_color = color;
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR3 normal)
	{
		this->m_position = Vector4(position);
		this->m_color = color;
		this->m_normal = Vector4(normal);
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR3 normal)
	{
		this->m_position = Vector4(position);
		this->m_color = color;
		this->m_normal = Vector4(normal);
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR3 normal)
	{
		this->m_position = position;
		this->m_color = color;
		this->m_normal = Vector4(normal);
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR3 normal)
	{
		this->m_position = position;
		this->m_color = color;
		this->m_normal = Vector4(normal);
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR4 normal)
	{
		this->m_position = Vector4(position);
		this->m_color = color;
		this->m_normal = normal;
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR4 normal)
	{
		this->m_position = Vector4(position);
		this->m_color = color;
		this->m_normal = normal;
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color, DLMT::DL_VECTOR4 normal)
	{
		this->m_position = position;
		this->m_color = color;
		this->m_normal = normal;
	}

	DLVertexPositionColorNormal::DLVertexPositionColorNormal(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color, DLMT::DL_VECTOR4 normal)
	{
		this->m_position = position;
		this->m_color = color;
		this->m_normal = normal;
	}
}