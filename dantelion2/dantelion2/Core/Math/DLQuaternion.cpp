#include "DLQuaternion.h"
#include "DLMatrix.h"
#include "Call.h"

typedef DLMT::DL_QUATERNION* (_fastcall* oCreateAxisAngleTransform)(DLMT::DL_QUATERNION& out, const DLMT::DL_VECTOR4& axis, dl_float32 angle);

namespace DLMT
{
	DL_QUATERNION* CreateAxisAngleTransform(DL_QUATERNION& out, const DL_VECTOR4& axis, dl_float32 angle)
	{
		return CALL(oCreateAxisAngleTransform, 0x16e310, out, axis, angle);
	}

	void CreateReflection(DL_QUATERNION& out, const DL_VECTOR4& plane)
	{
		DLMT::DL_MATRIX44 reflection = DLMT::DL_MATRIX44::CreateReflection(plane);
		DLMT::DL_VECTOR3 reflectTransl;
		DLMT::DL_VECTOR3 reflectScale;
		reflection.Decompose(reflectTransl, out, reflectScale);
	}
}
