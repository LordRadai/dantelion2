#pragma once
#include "DLLinear.h"

namespace DLMT
{
	class DLIPlane
	{
	public:
		static dl_bool IntersectPlanes(
			DL_PLANE_PARAMTYPE Plane0,
			DL_PLANE_PARAMTYPE Plane1,
			DL_PLANE_PARAMTYPE Plane2,
			DL_VECTOR4AL& vOut
		);
	};
}