#pragma once
#include "Core/Platform/Platform.h"
#include "DLVector.h"

namespace DLMT
{
	struct DL_PLANE;

	class DLIPlane
	{
		typedef const DL_PLANE& DL_PLANE_PARAMTYPE;

	public:
		static dl_bool IntersectPlanes(
			DL_PLANE_PARAMTYPE Plane0,
			DL_PLANE_PARAMTYPE Plane1,
			DL_PLANE_PARAMTYPE Plane2,
			DL_VECTOR4AL& vOut
		);
	};
}