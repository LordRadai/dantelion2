#include "DLIntersection.h"

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
        DL_VECTOR4AL vRelVert = Vec - OBB.GetCenter();


        DL_VECTOR4AL V = DLIVec3AL::MultMat34Vec((DL_MATRIX34&)OBB.GetXform(), vRelVert);
        dl_uint32 uCR;
        DLIVec4AL::InBoundsR(&uCR, V, OBB.GetExtents());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return false;
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
            if (vDiff.LengthSq3() >= fRadiusSq)
                return true;
            vDiff = Sphere.GetCenter() - Seg.GetEndPoint();
            if (vDiff.LengthSq3() >= fRadiusSq)
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

    inline dl_bool DLIIntersection::Test(
        DL_SEGMENT_PARAMTYPE Seg,
        DL_RSS_PARAMTYPE RSS
    )
    {
        dl_float32 fDistSq = DLIDist::GetDistanceSq(Seg, RSS, nullptr);
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
        dl_float32 fDist = (Sphere0.GetCenter() - Sphere1.GetCenter()).LengthSq3();
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


        const DL_IVECTOR4AL Mask =
        {
         DL_MATH_CMP_TRUE,
         DL_MATH_CMP_TRUE,
         DL_MATH_CMP_TRUE,
         DL_MATH_CMP_FALSE
        };

        DL_VECTOR4AL vLT = DLIVec4AL::Less(AABB0.GetMax(), AABB1.GetMin());
        DL_VECTOR4AL vGT = DLIVec4AL::Greater(AABB0.GetMin(), AABB1.GetMax());
        DL_VECTOR4AL vLG = DLIVec4AL::OrInt(vLT, vGT);
        DL_VECTOR4AL vLG3 = DLIVec4AL::AndInt(vLG, *(DL_VECTOR4AL*)Mask);

        return DLIVec4AL::AllFalse(vLG3);
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

    inline DLIIntersection::DLIntersectResult
    DLIIntersection::Test(
        DL_FRUSTUM_PARAMTYPE Frustum,
        DL_VECTOR4AL_PARAMTYPE Vertex
    )
    {
        DL_VECTOR4AL vDist;
        dl_uint32 uCR;


        vDist = DLIPlane::DotCoord(Frustum.GetPlane(DL_FRUSTUM::FRUSTUM_PLANE_LEFT), Vertex);
        DLIVec4AL::LessR(&uCR, vDist, DLIVec4AL::Zero());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return RESULT_OUTSIDE;

        vDist = DLIPlane::DotCoord(Frustum.GetPlane(DL_FRUSTUM::FRUSTUM_PLANE_RIGHT), Vertex);
        DLIVec4AL::LessR(&uCR, vDist, DLIVec4AL::Zero());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return RESULT_OUTSIDE;

        vDist = DLIPlane::DotCoord(Frustum.GetPlane(DL_FRUSTUM::FRUSTUM_PLANE_TOP), Vertex);
        DLIVec4AL::LessR(&uCR, vDist, DLIVec4AL::Zero());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return RESULT_OUTSIDE;

        vDist = DLIPlane::DotCoord(Frustum.GetPlane(DL_FRUSTUM::FRUSTUM_PLANE_BOTTOM), Vertex);
        DLIVec4AL::LessR(&uCR, vDist, DLIVec4AL::Zero());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return RESULT_OUTSIDE;

        vDist = DLIPlane::DotCoord(Frustum.GetPlane(DL_FRUSTUM::FRUSTUM_PLANE_FAR), Vertex);
        DLIVec4AL::LessR(&uCR, vDist, DLIVec4AL::Zero());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return RESULT_OUTSIDE;

        vDist = DLIPlane::DotCoord(Frustum.GetPlane(DL_FRUSTUM::FRUSTUM_PLANE_NEAR), Vertex);
        DLIVec4AL::LessR(&uCR, vDist, DLIVec4AL::Zero());
        if (DLIVecUtil::ComparisonAnyFalse(uCR)) return RESULT_OUTSIDE;


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
    */
}