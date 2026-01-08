#pragma once
#include "DLVector.h"
#include "DLQuaternion.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;

namespace DLMT
{
	typedef DirectX::XMFLOAT3X3 DL_MATRIX33;
	typedef Matrix DL_MATRIX44;

	_declspec(align(16))
	class DL_MATRIX34 : public DirectX::XMFLOAT3X4
	{
	public:
		DL_MATRIX34() = default;
		DL_MATRIX34(DL_QUATERNION rotation, DL_VECTOR3 translation, DL_VECTOR3 scale);
		DL_MATRIX34(DL_MATRIX44 matrix);
	};

	DL_MATRIX44 GetRotationFrom2Vectors(const DL_VECTOR3& v1, const DL_VECTOR3& v2);
	void RotateMatrix(DL_MATRIX44* pMatrix, const DL_VECTOR4& rot);
}