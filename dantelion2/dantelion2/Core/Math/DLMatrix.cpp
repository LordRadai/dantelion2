#include "DLMatrix.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oMatrixRotate)(DLMT::DL_MATRIX44* pThis, const DLMT::DL_VECTOR4& rot);

namespace DLMT
{
	DL_MATRIX34::DL_MATRIX34(DL_QUATERNION rotation, DL_VECTOR3 translation, DL_VECTOR3 scale)
	{
		DLMT::DL_MATRIX44 S = DL_MATRIX44::CreateScale(scale.x, scale.y, scale.z);
		DLMT::DL_MATRIX44 R = DL_MATRIX44::CreateFromQuaternion(rotation);
		DLMT::DL_MATRIX44 T = DL_MATRIX44::CreateTranslation(translation.x, translation.y, translation.z);
		DLMT::DL_MATRIX44 M = S * R * T;
		XMStoreFloat3x4(this, M);
	}

	DL_MATRIX34::DL_MATRIX34(DL_MATRIX44 matrix)
	{
        // Copy rotation / scale
        m[0][0] = matrix._11; // r1.x
        m[0][1] = matrix._12; // r1.y
        m[0][2] = matrix._13; // r1.z

        m[1][0] = matrix._21; // r2.x
        m[1][1] = matrix._22; // r2.y
        m[1][2] = matrix._23; // r2.z

        m[2][0] = matrix._31; // r3.x
        m[2][1] = matrix._32; // r3.y
        m[2][2] = matrix._33; // r3.z

        // Copy translation
        m[0][3] = matrix._41; // tx
        m[1][3] = matrix._42; // ty
        m[2][3] = matrix._43; // tz
	}

	DL_MATRIX44 GetRotationFrom2Vectors(const DL_VECTOR3& v1, const DL_VECTOR3& v2)
	{
		DL_MATRIX44 result = DL_MATRIX44::Identity;

		DL_VECTOR3 euler = DL_VECTOR3::Zero;
		DL_VECTOR3 diff = v2 - v1;

		if (diff.x == 0 && diff.z == 0)
		{
			if (diff.y >= 0)
				result = DL_MATRIX44::CreateRotationZ(DirectX::XM_PI);
			else
				result = DL_MATRIX44::CreateRotationZ(0);

			return result;
		}

		dl_float32 distance = diff.Length();

		euler.y = asin(diff.y / distance);

		dl_float32 distance_xz = distance * cos(euler.y);

		euler.x = acos(diff.x / distance_xz);
		euler.z = acos(diff.z / distance_xz);

		DL_MATRIX44 rot_x = DL_MATRIX44::CreateRotationX(-euler.x);
		DL_MATRIX44 rot_y = DL_MATRIX44::CreateRotationY(-euler.y);
		DL_MATRIX44 rot_z = DL_MATRIX44::CreateRotationZ(-euler.z);

		result = rot_x * result;
		result = rot_y * result;
		result = rot_z * result;

		return result;
	}

	void RotateMatrix(DL_MATRIX44* pMatrix, const DL_VECTOR4& rot)
	{
		FRPG2_CALL(oMatrixRotate, 0xb0e0b0, pMatrix, rot);
	}
}
