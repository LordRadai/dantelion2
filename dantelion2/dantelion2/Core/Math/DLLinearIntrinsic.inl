#include "DLLinearIntrinsic.h"

#include <math.h>

namespace DLMT
{
    inline dl_bool DLIPlane::Equal(
        DL_PLANE_PARAMTYPE pP0,
        DL_PLANE_PARAMTYPE pP1
    )
    {
        return (*reinterpret_cast<const DL_VECTOR4AL*>(&pP0) == *reinterpret_cast<const DL_VECTOR4AL*>(&pP1));
    }

    inline dl_bool DLIPlane::NearEqual(
        DL_PLANE_PARAMTYPE P0,
        DL_PLANE_PARAMTYPE P1,
        DL_VECTOR4AL_PARAMTYPE Epsilon
    )
    {
        // Normalize the planes
        DL_PLANE P0normal = DLIPlane::Normalize(P0);
        DL_PLANE P1normal = DLIPlane::Normalize(P1);

        // Cast to SIMD vectors
        DL_VECTOR4AL v0 = *reinterpret_cast<const DL_VECTOR4AL*>(&P0normal);
        DL_VECTOR4AL v1 = *reinterpret_cast<const DL_VECTOR4AL*>(&P1normal);

        // Manual implementation of: abs(v0 - v1) <= Epsilon
        // 1. Calculate difference
        DL_VECTOR4AL diff = v0 - v1;

        // 2. Calculate absolute value
        DL_VECTOR4AL absDiff(fabs(diff.x), fabs(diff.y), fabs(diff.z), fabs(diff.w));

        dl_bool result = absDiff <= Epsilon;

        return result;
    }

    inline dl_bool DLIPlane::NotEqual(
        DL_PLANE_PARAMTYPE P0,
        DL_PLANE_PARAMTYPE P1
    )
    {
        return !DLIPlane::Equal(P0, P1);
    }

    inline dl_bool DLIPlane::IsNaN(
        DL_PLANE_PARAMTYPE Plane
    )
    {
        dl_bool isNan = Plane.m_Plane.IsNaN();
        return isNan;
    }

    inline dl_bool DLIPlane::IsInfinite(
        DL_PLANE_PARAMTYPE Plane
    )
    {
		dl_bool isInfinite = Plane.m_Plane.IsInfinite();
        return isInfinite;
    }

    inline dl_float32 DLIPlane::Dot(
        DL_PLANE_PARAMTYPE Plane,
        DL_VECTOR4AL_PARAMTYPE Vec
    )
    {
		dl_float32 dotProduct = Plane.m_Plane.Dot(Vec);

        return dotProduct;
    }

    inline dl_float32 DLIPlane::DotCoord(
        DL_PLANE_PARAMTYPE Plane,
        DL_VECTOR4AL_PARAMTYPE Vec
    )
    {
        // A coordinate dot product is: Plane.x*Vec.x + Plane.y*Vec.y + Plane.z*Vec.z + Plane.w*1.0
            // We create a temporary vector where W is forced to 1.0
        DLMT::DL_VECTOR4 V(Vec.x, Vec.y, Vec.z, 1.0f);
		dl_float32 dotProduct = Plane.m_Plane.Dot(V);

        return dotProduct;
    }

    inline dl_float32 DLIPlane::DotNormal(
        DL_PLANE_PARAMTYPE Plane,
        DL_VECTOR4AL_PARAMTYPE Vec
    )
    {
		dl_float32 dotProduct = Plane.m_Plane.Dot(Vec);

		return dotProduct;
    }

    inline DL_PLANE DLIPlane::NormalizeEst(
        DL_PLANE_PARAMTYPE In
    )
    {
        // 1. Calculate squared length of the normal (x, y, z)
            // We treat the plane as a DL_VECTOR4 where (x, y, z) is the normal
        dl_float32 lengthSq = (In.m_Plane.x * In.m_Plane.x) + (In.m_Plane.y * In.m_Plane.y) + (In.m_Plane.z * In.m_Plane.z);

        // 2. Estimated Inverse Square Root (1 / sqrt(x))
        // In pre-C++11, if you don't have a SIMD ReciprocalSqrt intrinsic,
        // we use the standard math library 1.0f / sqrtf().
        // If you need the actual 'Fast Inverse Square Root' (Quake style),
        // let me know and I can provide that bit-manipulation version.
        dl_float32 invLength = 1.0f / sqrtf(lengthSq);

        // 3. Multiply and return
        return DLMT::DL_PLANE(
            In.m_Plane.x * invLength,
            In.m_Plane.y * invLength,
            In.m_Plane.z * invLength,
            In.m_Plane.w * invLength
        );
    }

    inline DL_PLANE DLIPlane::Normalize(
        DL_PLANE_PARAMTYPE In
    )
    {
        // 1. Calculate squared length of the normal (x, y, z)
        dl_float32 lenSq = (In.m_Plane.x * In.m_Plane.x) + (In.m_Plane.y * In.m_Plane.y) + (In.m_Plane.z * In.m_Plane.z);

        // 2. Define a small epsilon to detect "Zero" length
        const dl_float32 epsilon = 1e-8f;

        // 3. Handle Zero length case
        // If the length is essentially zero, we cannot normalize. 
        // Returning the input or zero is standard; here we return the input.
        if (lenSq < epsilon)
        {
            return In;
        }

        // 4. Calculate normalization factor
        dl_float32 invLen = 1.0f / sqrtf(lenSq);

        // 5. Scale all 4 components (A, B, C, D)
        return DLMT::DL_PLANE(
            In.m_Plane.x * invLen,
            In.m_Plane.y * invLen,
            In.m_Plane.z * invLen,
            In.m_Plane.w * invLen
        );
    }

    inline DL_PLANE DLIPlane::Transform(
        DL_PLANE_PARAMTYPE Plane,
        DL_MATRIX44_PARAMTYPE Mtx
    )
    {
        return DLMT::DL_PLANE(Plane.m_Plane * Mtx);
    }

    inline DL_PLANE DLIPlane::FromPointNormal(
        DL_VECTOR4AL_PARAMTYPE Point,
        DL_VECTOR4AL_PARAMTYPE Normal
    )
    {
        // 1. Calculate the dot product of the normal and the point (Ax + By + Cz)
            // We only care about the XYZ components for the dot product
        dl_float32 dot = (Normal.x * Point.x) + (Normal.y * Point.y) + (Normal.z * Point.z);

        // 2. The plane equation is Ax + By + Cz + D = 0
        // Therefore, D = -(Ax + By + Cz)
        dl_float32 d = -dot;

        // 3. Return the plane as a DL_VECTOR4 (A, B, C, D)
        // The normal components (x, y, z) remain the same, w becomes D
        return DLMT::DL_PLANE(Normal.x, Normal.y, Normal.z, d);
    }

    inline DL_PLANE DLIPlane::FromPoints(
        DL_VECTOR4AL_PARAMTYPE Point0,
        DL_VECTOR4AL_PARAMTYPE Point1,
        DL_VECTOR4AL_PARAMTYPE Point2
    )
    {
        // 1. Convert to Vector3 for vector math (ignoring W)
        DLMT::DL_VECTOR3 p0 = Point0.ToVector3();
        DLMT::DL_VECTOR3 p1 = Point1.ToVector3();
        DLMT::DL_VECTOR3 p2 = Point2.ToVector3();

        // 2. Create two vectors representing edges of the plane
        DLMT::DL_VECTOR3 v01 = p1 - p0;
        DLMT::DL_VECTOR3 v02 = p2 - p0;

        // 3. Find the normal using the Cross Product
        // The Cross product gives a vector perpendicular to the triangle
        DLMT::DL_VECTOR3 n = v01.Cross(v02);

        // 4. Normalize the normal
        n = n.Normalize();

        // 5. Calculate D component: D = -(n dot p0)
        dl_float32 d = -n.Dot(p0);

        // 6. Return as a DL_PLANE (A, B, C, D)
        return DLMT::DL_PLANE(n.x, n.y, n.z, d);
    }

    inline dl_bool DLIPlane::IntersectPlanes(
        DL_PLANE_PARAMTYPE Plane0,
        DL_PLANE_PARAMTYPE Plane1,
        DL_LINE& Line
    )
    {
        // 1. Get normals (A, B, C)
        DLMT::DL_VECTOR3 n0(Plane0.m_Plane.x, Plane0.m_Plane.y, Plane0.m_Plane.z);
        DLMT::DL_VECTOR3 n1(Plane1.m_Plane.x, Plane1.m_Plane.y, Plane1.m_Plane.z);

        // 2. Direction of the intersection line (n0 x n1)
        DLMT::DL_VECTOR3 dir = n0.Cross(n1);
        dl_float32 dirLenSq = dir.LengthSquared();

        // 3. Parallel check (if cross product is near zero, planes don't intersect)
        const dl_float32 epsilon = 1e-6f;
        if (dirLenSq < epsilon)
        {
            return false;
        }

        // 4. Calculate a point on the line
        // Formula: p = ( (n0 x n1) x (n1*d0 - n0*d1) ) / |n0 x n1|^2
        // Simplified using the cross-product components:
        DLMT::DL_VECTOR3 origin = (dir.Cross((n1 * Plane0.m_Plane.w) - (n0 * Plane1.m_Plane.w))) * (1.0f / dirLenSq);

        // 5. Populate Line structure
        Line.SetOrigin(DL_VECTOR4(origin.x, origin.y, origin.z, 1.0f));
        Line.SetDirection(DL_VECTOR4(dir.x, dir.y, dir.z, 0.0f));

        return true;
    }

    inline dl_bool DLIPlane::IntersectPlanes(
        DL_PLANE_PARAMTYPE Plane0,
        DL_PLANE_PARAMTYPE Plane1,
        DL_PLANE_PARAMTYPE Plane2,
        DL_VECTOR4AL& Point
    )
    {
        // Extract normals (n0, n1, n2) and distances (d0, d1, d2)
        DLMT::DL_VECTOR3 n0(Plane0.m_Plane.x, Plane0.m_Plane.y, Plane0.m_Plane.z);
        DLMT::DL_VECTOR3 n1(Plane1.m_Plane.x, Plane1.m_Plane.y, Plane1.m_Plane.z);
        DLMT::DL_VECTOR3 n2(Plane2.m_Plane.x, Plane2.m_Plane.y, Plane2.m_Plane.z);

        dl_float32 d0 = Plane0.m_Plane.w;
        dl_float32 d1 = Plane1.m_Plane.w;
        dl_float32 d2 = Plane2.m_Plane.w;

        // Calculate cross products of normals
        DLMT::DL_VECTOR3 n1_x_n2 = n1.Cross(n2);
        DLMT::DL_VECTOR3 n2_x_n0 = n2.Cross(n0);
        DLMT::DL_VECTOR3 n0_x_n1 = n0.Cross(n1);

        // Calculate the denominator: n0 . (n1 x n2)
        dl_float32 denom = n0.Dot(n1_x_n2);

        // Check for parallel planes (denom near 0)
        if (fabs(denom) < 1e-6f)
        {
            return false;
        }

        // Solve for point using the triple scalar product formula
        // Point = (-d0 * (n1 x n2) - d1 * (n2 x n0) - d2 * (n0 x n1)) / denom
        DLMT::DL_VECTOR3 intersection = (n1_x_n2 * -d0 + n2_x_n0 * -d1 + n0_x_n1 * -d2) * (1.0f / denom);

        // Set point result (W = 1.0f for a coordinate)
        Point = DLMT::DL_VECTOR4(intersection.x, intersection.y, intersection.z, 1.0f);

        return true;
    }
}