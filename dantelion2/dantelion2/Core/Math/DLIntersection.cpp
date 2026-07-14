#include "DLIntersection.h"
#include "DLDistance.h"
#include "Core/Assert/DLAssert.h"

namespace DLMT
{
    /*
    inline dl_bool DLIIntersection::Test(
        DL_VECTOR4AL_PARAMTYPE Vec,
        DL_SPHERE_PARAMTYPE Sphere
    )
    {
        dl_float32 fRad2 = Sphere.GetRadiusSq();
        if ((Vec - Sphere.GetCenter()).LengthSq() < fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_VECTOR4AL_PARAMTYPE Vec,
        DL_AABB_PARAMTYPE AABB
    )
    {
        if (Vec.x > AABB.GetMax(DL_AABB::AXIS_X) ||
            Vec.x < AABB.GetMin(DL_AABB::AXIS_X)) return false;
        if (Vec.y > AABB.GetMax(DL_AABB::AXIS_Y) ||
            Vec.y < AABB.GetMin(DL_AABB::AXIS_Y)) return false;
        if (Vec.z > AABB.GetMax(DL_AABB::AXIS_Z) ||
            Vec.z < AABB.GetMin(DL_AABB::AXIS_Z)) return false;

        return true;
    }

    inline dl_bool DLIIntersection::Test(
        DL_VECTOR4AL_PARAMTYPE Vec,
        DL_OBB_PARAMTYPE OBB
    )
    {
        // 1. Calculate the vector from the OBB center to the point
        DLMT::DL_VECTOR4 relVert = Vec - OBB.GetCenter();

        // 2. Transform the point into the OBB's local coordinate space
        // The OBB's transform matrix (Xform) aligns the box axes to world axes
        DLMT::DL_VECTOR4 localPos = OBB.GetXform() * relVert;

        // 3. Get the half-extents (dimensions of the box from center)
        DLMT::DL_VECTOR4 extents = OBB.GetExtents();

        // 4. Check if the local position is within the box bounds
        // A point is inside if |x| <= extent.x, |y| <= extent.y, and |z| <= extent.z
        // We check using absolute values to see if it fits within the box's boundaries
        if (std::abs(localPos.x) > extents.x) return false;
        if (std::abs(localPos.y) > extents.y) return false;
        if (std::abs(localPos.z) > extents.z) return false;

        return true;
    }

    inline dl_bool DLIIntersection::Test(
        DL_VECTOR4AL_PARAMTYPE Vec,
        DL_LSS_PARAMTYPE LSS
    )
    {
        dl_float32 fRad2 = LSS.GetRadiusSq();
        if (DLIDist::GetDistanceSq(Vec, LSS, 0) < fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_VECTOR4AL_PARAMTYPE Vec,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fRad2 = RSS.GetRadiusSq();
        if (DLIDist::GetDistanceSq(Vec, RSS, 0, 0) < fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_SEGMENT_PARAMTYPE Seg,
        DL_PLANE_PARAMTYPE Plane
    )
    {
        dl_float32 fLen0, fLen1;
        fLen0 = Plane.GetDistance(Seg.GetOrigin());
        fLen1 = Plane.GetDistance(Seg.GetEndPoint());
        if (fLen0 * fLen1 < 0.0f)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_SEGMENT_PARAMTYPE Seg,
        DL_SPHERE_PARAMTYPE Sphere
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Sphere.GetCenter(), Seg, 0);
        dl_float32 fRadiusSq = Sphere.GetRadiusSq();
        if (fDistSq < fRadiusSq)
        {
            DL_VECTOR4AL vDiff = Sphere.GetCenter() - Seg.GetOrigin();
            if (vDiff.LengthSq() >= fRadiusSq)
                return true;
            vDiff = Sphere.GetCenter() - Seg.GetEndPoint();
            if (vDiff.LengthSq() >= fRadiusSq)
                return true;
            return false;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_SEGMENT_PARAMTYPE Seg,
        DL_LSS_PARAMTYPE LSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Seg, LSS, 0, 0);
        if (fDistSq < LSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /*
    inline dl_bool DLIIntersection::Test(
        DL_SEGMENT_PARAMTYPE Seg,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Seg, RSS, nullptr, nullptr, nullptr);
        if (fDistSq < RSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RAY_PARAMTYPE Ray,
        DL_PLANE_PARAMTYPE Plane
    )
    {
        dl_float32 fLen0, fLen1;
        fLen0 = Plane.GetDistance(Ray.GetOrigin());
        fLen1 = Plane.GetNormal().Dot(Ray.GetDirection());
        if (fLen0 >= 0.0f && fLen1 < 0.0f ||
            fLen0 < 0.0f && fLen1 > 0.0f)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RAY_PARAMTYPE Ray,
        DL_SPHERE_PARAMTYPE Sphere
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Sphere.GetCenter(), Ray, 0);
        dl_float32 fRadiusSq = Sphere.GetRadiusSq();
        if (fDistSq < fRadiusSq)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RAY_PARAMTYPE Ray,
        DL_LSS_PARAMTYPE LSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(LSS, Ray, 0, 0);
        if (fDistSq < LSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /*
    inline dl_bool DLIIntersection::Test(
        DL_RAY_PARAMTYPE Ray,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Ray, RSS, 0, 0, 0);
        if (fDistSq < RSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_LINE_PARAMTYPE Line,
        DL_PLANE_PARAMTYPE Plane
    )
    {
        dl_float32 fDenom = Line.GetDirection().Dot(Plane.GetNormal());
        if (std::abs(fDenom) >= FLT_EPSILON)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_LINE_PARAMTYPE Line,
        DL_SPHERE_PARAMTYPE Sphere
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Sphere.GetCenter(), Line, 0);
        if (fDistSq < Sphere.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /*
    inline dl_bool DLIIntersection::Test(
        DL_LINE_PARAMTYPE Line,
        DL_LSS_PARAMTYPE LSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(LSS, Line, 0, 0);
        if (fDistSq < LSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_LINE_PARAMTYPE Line,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Line, RSS, 0, 0, 0);
        if (fDistSq < RSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RECTANGLE_PARAMTYPE Rect,
        DL_SPHERE_PARAMTYPE Sphere
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(Sphere.GetCenter(), Rect, 0, 0);
        if (fDist < Sphere.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /*
    inline dl_bool DLIIntersection::Test(
        DL_RECTANGLE_PARAMTYPE Rect,
        DL_LSS_PARAMTYPE LSS
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(LSS, Rect, 0, 0, 0);
        if (fDist < LSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RECTANGLE_PARAMTYPE Rect,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(Rect, RSS, 0, 0, 0, 0);
        if (fDist < RSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_PLANE_PARAMTYPE Plane0,
        DL_PLANE_PARAMTYPE Plane1
    )
    {
        dl_float32 fDot = DLAbs(Plane0.GetNormal().Dot(Plane1.GetNormal()));

        if (DLAbs(fDot - 1.0f) <= DL_MATH_EPSILON)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_PLANE_PARAMTYPE Plane,
        DL_SPHERE_PARAMTYPE Sphere
    )
    {
        dl_float32 fDist = DLIDist::GetDistance(Sphere.GetCenter(), Plane, 0);
        if (fDist < Sphere.GetRadius())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_PLANE_PARAMTYPE Plane,
        DL_LSS_PARAMTYPE LSS
    )
    {

        dl_float32 fDist = DLIDist::GetDistanceSq(LSS, Plane, 0, 0);

        if (fDist < LSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /*
    inline dl_bool DLIIntersection::Test(
        DL_PLANE_PARAMTYPE Plane,
        DL_RSS_PARAMTYPE RSS
    )
    {

        dl_float32 fDist = DLIDist::GetDistanceSq(RSS, Plane, 0, 0, 0);

        if (fDist < RSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_SPHERE_PARAMTYPE Sphere0,
        DL_SPHERE_PARAMTYPE Sphere1
    )
    {
        dl_float32 fDist = (Sphere0.GetCenter() - Sphere1.GetCenter()).LengthSq();
        dl_float32 fRad2 = Sphere0.GetRadius() + Sphere1.GetRadius();
        if (fDist < fRad2 * fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_SPHERE_PARAMTYPE Sphere,
        DL_LSS_PARAMTYPE LSS
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(Sphere.GetCenter(), LSS, 0);
        dl_float32 fRad2 = Sphere.GetRadius() + LSS.GetRadius();
        if (fDist < fRad2 * fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_SPHERE_PARAMTYPE Sphere,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(Sphere.GetCenter(), RSS, 0, 0);
        dl_float32 fRad2 = Sphere.GetRadius() + RSS.GetRadius();
        if (fDist < fRad2 * fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_AABB_PARAMTYPE AABB0,
        DL_AABB_PARAMTYPE AABB1
    )
    {
        // AABB overlap test: boxes intersect if they are NOT separated on any axis.

        // Separation on X-axis?
        if (AABB0.GetMax().x < AABB1.GetMin().x || AABB0.GetMin().x > AABB1.GetMax().x)
            return false;

        // Separation on Y-axis?
        if (AABB0.GetMax().y < AABB1.GetMin().y || AABB0.GetMin().y > AABB1.GetMax().y)
            return false;

        // Separation on Z-axis?
        if (AABB0.GetMax().z < AABB1.GetMin().z || AABB0.GetMin().z > AABB1.GetMax().z)
            return false;

        // If no separation found on any axis, they must be intersecting
        return true;
    }

    inline dl_bool DLIIntersection::Test(
        DL_LSS_PARAMTYPE LSS0,
        DL_LSS_PARAMTYPE LSS1
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(LSS0, LSS1, 0, 0);
        dl_float32 fRad2 = LSS0.GetRadius() + LSS1.GetRadius();
        if (fDist < fRad2 * fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_LSS_PARAMTYPE LSS,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(LSS, RSS, 0, 0, 0);
        dl_float32 fRad2 = LSS.GetRadius() + RSS.GetRadius();
        if (fDist < fRad2 * fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_LSS_PARAMTYPE LSS,
        DL_TRIANGLE_PARAMTYPE Tri
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(LSS, Tri, 0, 0, 0);
        if (fDist < LSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RSS_PARAMTYPE RSS0,
        DL_RSS_PARAMTYPE RSS1
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(RSS0, RSS1, 0, 0, 0, 0);
        dl_float32 fRad2 = RSS0.GetRadius() + RSS1.GetRadius();
        if (fDist < fRad2 * fRad2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    inline dl_bool DLIIntersection::Test(
        DL_RSS_PARAMTYPE RSS,
        DL_TRIANGLE_PARAMTYPE Tri
    )
    {
        dl_float32 fDist = DLIDist::GetDistanceSq(RSS, Tri, 0, 0, 0, 0);
        if (fDist < RSS.GetRadiusSq())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    */

    dl_bool DLIIntersection::Test(
        DL_LINE_PARAMTYPE Line,
        DL_TRIANGLE_PARAMTYPE Tri
    )
    {
        // Define triangle vertices
        DLMT::DL_VECTOR4AL v0 = Tri.GetOrigin();
        DLMT::DL_VECTOR4AL v1 = v0 + Tri.GetEdge(0);
        DLMT::DL_VECTOR4AL v2 = v0 + Tri.GetEdge(1);

        DLMT::DL_VECTOR4AL dir = Line.GetDirection();
        DLMT::DL_VECTOR4AL orig = Line.GetOrigin();

        // Calculate vectors for barycentric coordinates
        DLMT::DL_VECTOR4AL edge1 = v1 - v0;
        DLMT::DL_VECTOR4AL edge2 = v2 - v0;

        // Cross product to find normal (n = edge1 x edge2)
        DLMT::DL_VECTOR4AL pvec = dir.Cross(edge2);
        dl_float32 det = edge1.Dot(pvec);

        // If determinant is near zero, line is parallel to the triangle
        const dl_float32 epsilon = 1e-6f;
        if (std::abs(det) < epsilon) return false;

        dl_float32 invDet = 1.0f / det;

        // Calculate distance from v0 to line origin
        DLMT::DL_VECTOR4AL tvec = orig - v0;
        dl_float32 u = tvec.Dot(pvec) * invDet;
        if (u < 0.0f || u > 1.0f) return false;

        DLMT::DL_VECTOR4AL qvec = tvec.Cross(edge1);
        dl_float32 v = dir.Dot(qvec) * invDet;
        if (v < 0.0f || u + v > 1.0f) return false;

        // If we reach here, the line intersects the triangle
        return true;
    }

    dl_bool DLIIntersection::Test(
        DL_RAY_PARAMTYPE Ray,
        DL_TRIANGLE_PARAMTYPE Tri
    )
    {
        // 1. Get triangle vertices
        DLMT::DL_VECTOR4AL v0 = Tri.GetOrigin();
        DLMT::DL_VECTOR4AL v1 = v0 + Tri.GetEdge(0);
        DLMT::DL_VECTOR4AL v2 = v0 + Tri.GetEdge(1);

        DLMT::DL_VECTOR4AL dir = Ray.GetDirection();
        DLMT::DL_VECTOR4AL orig = Ray.GetOrigin();

        // 2. Prepare for Möller-Trumbore
        DLMT::DL_VECTOR4AL edge1 = v1 - v0;
        DLMT::DL_VECTOR4AL edge2 = v2 - v0;

        DLMT::DL_VECTOR4AL pvec = dir.Cross(edge2);
        dl_float32 det = edge1.Dot(pvec);

        // 3. Back-face culling / Parallel check
        // If det is near zero, ray is parallel to triangle
        // (Optional: If you want back-face culling, return false if det < epsilon)
        const dl_float32 epsilon = 1e-6f;
        if (std::abs(det) < epsilon) return false;

        dl_float32 invDet = 1.0f / det;

        // 4. Calculate Barycentric U coordinate
        DLMT::DL_VECTOR4AL tvec = orig - v0;
        dl_float32 u = tvec.Dot(pvec) * invDet;
        if (u < 0.0f || u > 1.0f) return false;

        // 5. Calculate Barycentric V coordinate
        DLMT::DL_VECTOR4AL qvec = tvec.Cross(edge1);
        dl_float32 v = dir.Dot(qvec) * invDet;
        if (v < 0.0f || u + v > 1.0f) return false;

        // 6. Calculate T (the distance along the ray)
        // Ray intersection must be in the positive direction (t >= 0)
        dl_float32 t = edge2.Dot(qvec) * invDet;
        if (t < 0.0f) return false;

        return true;
    }

    inline DLIIntersection::DLIntersectResult
    DLIIntersection::Test(
        DL_FRUSTUM_PARAMTYPE Frustum,
        DL_VECTOR4AL_PARAMTYPE Vertex
    )
    {
        for (int i = 0; i < 6; ++i)
        {
			DL_FRUSTUM::DLFrustumPlaneIndex index = static_cast<DL_FRUSTUM::DLFrustumPlaneIndex>(i);
            // 1. Get the plane from the frustum
            const DL_PLANE& plane = Frustum.GetPlane(index);

            // 2. DotCoord: (Normal.x * Vertex.x + Normal.y * Vertex.y + Normal.z * Vertex.z + D)
            // Using the DotCoord function we adapted earlier:
            dl_float32 vDist = DLIPlane::DotCoord(plane, Vertex);

            // 3. If the distance is negative, the point is on the "outside" of this plane
            if (vDist > 0.0f)
            {
                return RESULT_OUTSIDE;
            }
        }

        // If it passed all plane checks, it is inside the frustum
        return RESULT_INSIDE;
    }

    inline DLIIntersection::DLIntersectResult
    DLIIntersection::Test(
        DL_FRUSTUM_PARAMTYPE Frustum,
        DL_SEGMENT_PARAMTYPE Segment
    )
    {
        DL_TRIANGLE Triangles[12];
        DL_VECTOR4AL vE;


        vE = Segment.GetEndPoint();
        DLIntersectResult IsInsideS = Test(Frustum, Segment.GetOrigin());
        DLIntersectResult IsInsideE = Test(Frustum, vE);
        if (IsInsideS == RESULT_INSIDE &&
            IsInsideE == RESULT_INSIDE) return RESULT_INSIDE;
        if (IsInsideS == RESULT_INSIDE ||
            IsInsideE == RESULT_INSIDE) return RESULT_INTERSECT;

        Frustum.ComputeTriangles(Triangles);
        for (dl_int32 i = 0; i < 12; i++)
        {
            if (Test(Segment, Triangles[i]))
                return RESULT_INTERSECT;
        }

        return RESULT_OUTSIDE;
    }

    inline DLIIntersection::DLIntersectResult
    DLIIntersection::Test(
        DL_FRUSTUM_PARAMTYPE Frustum,
        DL_RAY_PARAMTYPE Ray
    )
    {
        DL_TRIANGLE Triangles[12];


        DLIntersectResult IsInsideS = Test(Frustum, Ray.GetOrigin());
        if (IsInsideS == RESULT_INSIDE) return RESULT_INTERSECT;

        Frustum.ComputeTriangles(Triangles);
        for (dl_int32 i = 0; i < 12; i++)
        {
            if (Test(Ray, Triangles[i]))
                return RESULT_INTERSECT;
        }

        return RESULT_OUTSIDE;
    }

    inline DLIIntersection::DLIntersectResult
    DLIIntersection::Test(
        DL_FRUSTUM_PARAMTYPE Frustum,
        DL_LINE_PARAMTYPE Line
    )
    {
        DL_TRIANGLE Triangles[12];

        Frustum.ComputeTriangles(Triangles);
        for (dl_int32 i = 0; i < 12; i++)
        {
            if (Test(Line, Triangles[i]))
                return RESULT_INTERSECT;
        }

        return RESULT_OUTSIDE;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_RECTANGLE_PARAMTYPE Rectangle
        )
    {
        // A rectangle's 4 corners: Origin, Origin+Edge0, Origin+Edge1, Origin+Edge0+Edge1
        DLMT::DL_VECTOR4 corners[4];
        corners[0] = Rectangle.GetOrigin();
        corners[1] = corners[0] + Rectangle.GetEdge0();
        corners[2] = corners[0] + Rectangle.GetEdge1();
        corners[3] = corners[0] + Rectangle.GetEdge0() + Rectangle.GetEdge1();

        bool allInside = true;

        // For each of the 6 frustum planes
        for (int i = 0; i < 6; ++i)
        {
            const DLMT::DL_PLANE& plane = Frustum.GetPlane((DLMT::DL_FRUSTUM::DLFrustumPlaneIndex)i);

            int outsideCount = 0;
            for (int j = 0; j < 4; ++j)
            {
                // If distance > 0, the point is outside this plane
                if (plane.GetDistance(corners[j]) > 0.0f)
                {
                    outsideCount++;
                }
            }

            // If all 4 corners are outside this single plane, the entire rectangle is outside
            if (outsideCount == 4)
            {
                return RESULT_OUTSIDE;
            }

            // If any corner is outside a plane, the rectangle is at least partially intersecting
            if (outsideCount > 0)
            {
                allInside = false;
            }
        }

        return allInside ? RESULT_INSIDE : RESULT_INTERSECT;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_PLANE_PARAMTYPE Plane
        )
    {
        DLMT::DL_VECTOR4AL frustumVerts[8];
        if (!Frustum.ComputeVertices(frustumVerts))
        {
            return RESULT_OUTSIDE;
        }

        int positiveCount = 0;
        int negativeCount = 0;

        for (int i = 0; i < 8; ++i)
        {
            dl_float32 dist = Plane.GetDistance(frustumVerts[i]);

            if (dist > 0.0f)
            {
                positiveCount++;
            }
            else if (dist < 0.0f)
            {
                negativeCount++;
            }
        }

        // Since normals point OUTWARD:
        // If all vertices are on the negative side, the frustum is fully INSIDE the half-space
        if (positiveCount == 0) return RESULT_INSIDE;

        // If all vertices are on the positive side, the frustum is fully OUTSIDE the half-space
        if (negativeCount == 0) return RESULT_OUTSIDE;

        // Otherwise, the plane cuts through the frustum
        return RESULT_INTERSECT;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(DL_FRUSTUM_PARAMTYPE Frustum, DL_SPHERE_PARAMTYPE Sphere)
    {
        DL_VECTOR4AL sphereCenter = Sphere.GetCenter();
        dl_float32 sphereRadius = Sphere.GetRadius();

        bool bIntersecting = false;

        for (dl_uint32 i = 0; i < DL_FRUSTUM::FRUSTUM_PLANE_NUM; ++i)
        {
            DL_PLANE plane = Frustum.GetPlane(static_cast<DL_FRUSTUM::DLFrustumPlaneIndex>(i)).Normalize();

            // Calculate signed distance
            dl_float32 signedDistance = plane.GetNormal().Dot(sphereCenter) + plane.GetDist();

            // Since normals point OUTWARD:
            // 1. If distance > radius, the sphere is completely on the "outside" of this plane.
            if (signedDistance > sphereRadius)
            {
                return RESULT_OUTSIDE;
            }

            // 2. If distance > -radius (but < radius), it is crossing the plane.
            // We use -radius because if the distance is, for example, -0.5 and radius is 1.0,
            // the sphere is still partially "outside" the plane's boundary.
            if (signedDistance > -sphereRadius)
            {
                bIntersecting = true;
            }
        }

        return bIntersecting ? RESULT_INTERSECT : RESULT_INSIDE;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_AABB_PARAMTYPE Aabb
        )
    {
        DLMT::DL_VECTOR4AL vMin = Aabb.GetMin();
        DLMT::DL_VECTOR4AL vMax = Aabb.GetMax();
        bool isIntersecting = false;

        for (int i = 0; i < 6; ++i)
        {
            const DLMT::DL_PLANE& plane = Frustum.GetPlane((DLMT::DL_FRUSTUM::DLFrustumPlaneIndex)i);
            DLMT::DL_VECTOR4AL planeNormal = plane.GetNormal();

            // 1. P-Vertex (furthest along normal)
            // If this point is on the POSITIVE side of the plane, the whole AABB is outside.
            DLMT::DL_VECTOR4AL p = vMin;
            if (planeNormal.x >= 0.0f) p.x = vMax.x;
            if (planeNormal.y >= 0.0f) p.y = vMax.y;
            if (planeNormal.z >= 0.0f) p.z = vMax.z;

            if (plane.GetDistance(p) > 0.0f) // Changed from < 0.0f
            {
                return RESULT_OUTSIDE;
            }

            // 2. N-Vertex (furthest AGAINST normal)
            // If this point is on the POSITIVE side, it means the AABB crosses the plane.
            DLMT::DL_VECTOR4AL n = vMax;
            if (planeNormal.x >= 0.0f) n.x = vMin.x;
            if (planeNormal.y >= 0.0f) n.y = vMin.y;
            if (planeNormal.z >= 0.0f) n.z = vMin.z;

            if (plane.GetDistance(n) > 0.0f) // Changed from < 0.0f
            {
                isIntersecting = true;
            }
        }

        return isIntersecting ? RESULT_INTERSECT : RESULT_INSIDE;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_OBB_PARAMTYPE Obb
        )
    {
        const DLMT::DL_MATRIX44& xform = Obb.GetXform();
        const DLMT::DL_VECTOR4AL& extents = Obb.GetExtents();
        bool isIntersecting = false;

        for (int i = 0; i < 6; ++i)
        {
            const DLMT::DL_PLANE& plane = Frustum.GetPlane((DLMT::DL_FRUSTUM::DLFrustumPlaneIndex)i);

            // ... [Your existing Normal transformation code is fine] ...
            DLMT::DL_VECTOR4AL normal = plane.GetNormal();
            DLMT::DL_VECTOR4AL localNormal;
            localNormal.x = normal.x * xform.m[0][0] + normal.y * xform.m[1][0] + normal.z * xform.m[2][0];
            localNormal.y = normal.x * xform.m[0][1] + normal.y * xform.m[1][1] + normal.z * xform.m[2][1];
            localNormal.z = normal.x * xform.m[0][2] + normal.y * xform.m[1][2] + normal.z * xform.m[2][2];

            dl_float32 r = extents.x * std::abs(localNormal.x) +
                extents.y * std::abs(localNormal.y) +
                extents.z * std::abs(localNormal.z);

            dl_float32 dist = plane.GetDistance(Obb.GetCenter());

            // 4. Corrected Test against outward-pointing plane
            // If dist > r, the entire OBB is on the positive (outside) side of the plane
            if (dist > r)
            {
                return RESULT_OUTSIDE;
            }

            // If dist > -r, the OBB is straddling the plane boundary
            if (dist > -r)
            {
                isIntersecting = true;
            }
        }

        return isIntersecting ? RESULT_INTERSECT : RESULT_INSIDE;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_LSS_PARAMTYPE Lss
        )
    {
        const dl_float32 radius = Lss.GetRadius();
        bool isIntersecting = false;

        DLMT::DL_VECTOR4AL p0 = Lss.GetOrigin();
        DLMT::DL_VECTOR4AL p1 = Lss.GetEndPoint();

        for (int i = 0; i < 6; ++i)
        {
            const DLMT::DL_PLANE& plane = Frustum.GetPlane((DLMT::DL_FRUSTUM::DLFrustumPlaneIndex)i);

            dl_float32 dist0 = plane.GetDistance(p0);
            dl_float32 dist1 = plane.GetDistance(p1);

            // With outward normals, the capsule is completely OUTSIDE if 
            // both endpoints are further along the normal than the radius.
            if (dist0 > radius && dist1 > radius)
            {
                return RESULT_OUTSIDE;
            }

            // If either endpoint is on the positive side of the plane 
            // (dist > -radius), the capsule is crossing the boundary.
            if (dist0 > -radius || dist1 > -radius)
            {
                isIntersecting = true;
            }
        }

        return isIntersecting ? RESULT_INTERSECT : RESULT_INSIDE;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_RSS_PARAMTYPE Rss
        )
    {
        DLMT::DL_VECTOR4AL origin = Rss.GetOrigin();
        DLMT::DL_VECTOR4AL edge0 = Rss.GetEdge0();
        DLMT::DL_VECTOR4AL edge1 = Rss.GetEdge1();
        dl_float32 radius = Rss.GetRadius();

        DLMT::DL_VECTOR4AL corners[4];
        corners[0] = origin;
        corners[1] = origin + edge0;
        corners[2] = origin + edge1;
        corners[3] = origin + edge0 + edge1;

        bool isIntersecting = false;

        for (int i = 0; i < 6; ++i)
        {
            const DLMT::DL_PLANE& plane = Frustum.GetPlane((DLMT::DL_FRUSTUM::DLFrustumPlaneIndex)i);

            int positiveCount = 0; // Corners in the "Outside" positive space
            bool anyCornerInsideBuffer = false;

            for (int j = 0; j < 4; ++j)
            {
                dl_float32 dist = plane.GetDistance(corners[j]);

                // If distance > radius, the corner is definitely in the "Outside" positive space
                if (dist > radius)
                {
                    positiveCount++;
                }
                // If distance is between -radius and +radius, it's touching/crossing the boundary
                else if (dist > -radius)
                {
                    anyCornerInsideBuffer = true;
                }
            }

            // If all 4 corners are in the "Outside" positive space, the whole RSS is outside
            if (positiveCount == 4)
            {
                return RESULT_OUTSIDE;
            }

            // If any corner is in the buffer zone, it's intersecting
            if (anyCornerInsideBuffer)
            {
                isIntersecting = true;
            }
        }

        return isIntersecting ? RESULT_INTERSECT : RESULT_INSIDE;
    }

    DLIIntersection::DLIntersectResult
        DLIIntersection::Test(
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_TRIANGLE_PARAMTYPE Triangle
        )
    {
        DLMT::DL_VECTOR4AL v0 = Triangle.GetOrigin();
        DLMT::DL_VECTOR4AL v1 = v0 + Triangle.GetEdge(0);
        DLMT::DL_VECTOR4AL v2 = v0 + Triangle.GetEdge(1);

        bool isIntersecting = false;

        for (int i = 0; i < 6; ++i)
        {
            const DLMT::DL_PLANE& plane = Frustum.GetPlane((DLMT::DL_FRUSTUM::DLFrustumPlaneIndex)i);

            dl_float32 d0 = plane.GetDistance(v0);
            dl_float32 d1 = plane.GetDistance(v1);
            dl_float32 d2 = plane.GetDistance(v2);

            // With outward normals, the triangle is completely OUTSIDE if 
            // all three vertices are on the positive side of the plane (dist > 0).
            if (d0 > 0.0f && d1 > 0.0f && d2 > 0.0f)
            {
                return RESULT_OUTSIDE;
            }

            // If any vertex is on the positive side (d > 0), the triangle 
            // is crossing or outside the boundary.
            if (d0 > 0.0f || d1 > 0.0f || d2 > 0.0f)
            {
                isIntersecting = true;
            }
        }

        return isIntersecting ? RESULT_INTERSECT : RESULT_INSIDE;
    }
}