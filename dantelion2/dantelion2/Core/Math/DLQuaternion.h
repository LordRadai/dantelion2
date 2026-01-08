#pragma once
#include "DLVector.h"
#include <SimpleMath.h>

using namespace DirectX::SimpleMath;

namespace DLMT
{
	typedef Quaternion DL_QUATERNION;

	DL_QUATERNION* CreateAxisAngleTransform(DL_QUATERNION& out, const DL_VECTOR4& axis, dl_float32 angle);
	void CreateReflection(DL_QUATERNION& out, const DL_VECTOR4& plane);
}