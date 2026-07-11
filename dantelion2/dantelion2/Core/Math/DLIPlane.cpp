#include "DLIPlane.h"
#include "DLDistance.h"

namespace DLMT
{
	dl_bool DLIPlane::IntersectPlanes(
		DL_PLANE_PARAMTYPE Plane0,
		DL_PLANE_PARAMTYPE Plane1,
		DL_PLANE_PARAMTYPE Plane2,
		DL_VECTOR4AL& vOut
	)
	{
		// Compute the determinant of the matrix formed by the normals of the planes
		DL_VECTOR4AL n0 = Plane0.m_Plane;
		DL_VECTOR4AL n1 = Plane1.m_Plane;
		DL_VECTOR4AL n2 = Plane2.m_Plane;
		DL_VECTOR4AL cross_n1_n2 = n1.Cross(n2);
		dl_float32 det = n0.Dot(cross_n1_n2);
		if (fabs(det) < 1e-6f) // Check for near-zero determinant
			return false; // The planes do not intersect at a single point
		dl_float32 invDet = 1.0f / det;
		vOut = (cross_n1_n2 * DLIDist::GetDistance(Plane0, Plane1) +
			n2.Cross(n0) * DLIDist::GetDistance(Plane1, Plane2) +
			n0.Cross(n1) * DLIDist::GetDistance(Plane2, Plane0)) * invDet;
		return true;
	}
}