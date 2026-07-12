#pragma once
#include "DLLinear.h"

namespace DLMT
{
    class DLIPlane
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE; 
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE; 
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE; 
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE; 
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE; 
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE; 
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE; 
        typedef const DL_MATRIX34 DL_MATRIX34_PARAMTYPE; 
        typedef const DL_MATRIX43 DL_MATRIX43_PARAMTYPE; 
        typedef const DL_MATRIX44 DL_MATRIX44_PARAMTYPE; 
        typedef const DL_QUATERNION DL_QUATERNION_PARAMTYPE; 
        typedef const DL_SEGMENT& DL_SEGMENT_PARAMTYPE; 
        typedef const DL_LINE& DL_LINE_PARAMTYPE; 
        typedef const DL_RAY& DL_RAY_PARAMTYPE; 
        typedef const DL_RECTANGLE& DL_RECTANGLE_PARAMTYPE; 
        typedef const DL_PLANE DL_PLANE_PARAMTYPE; 
        typedef const DL_SPHERE DL_SPHERE_PARAMTYPE; 
        typedef const DL_AABB& DL_AABB_PARAMTYPE; 
        typedef const DL_OBB& DL_OBB_PARAMTYPE; 
        typedef const DL_LSS& DL_LSS_PARAMTYPE; 
        typedef const DL_RSS& DL_RSS_PARAMTYPE; 
        typedef const DL_TRIANGLE& DL_TRIANGLE_PARAMTYPE; 
        typedef const DL_TRIANGLE3& DL_TRIANGLE3_PARAMTYPE; 
        typedef const DL_FRUSTUM& DL_FRUSTUM_PARAMTYPE;

    public:
        static dl_bool Equal(
            DL_PLANE_PARAMTYPE pP0,
            DL_PLANE_PARAMTYPE pP1
        );

        static dl_bool NearEqual(
            DL_PLANE_PARAMTYPE P0,
            DL_PLANE_PARAMTYPE P1,
            DL_VECTOR4AL_PARAMTYPE Epsilon
        );

        static dl_bool NotEqual(
            DL_PLANE_PARAMTYPE P0,
            DL_PLANE_PARAMTYPE P1
        );

        static dl_bool IsNaN(
            DL_PLANE_PARAMTYPE Plane
        );

        static dl_bool IsInfinite(
            DL_PLANE_PARAMTYPE Plane
        );

        static dl_float32 Dot(
            DL_PLANE_PARAMTYPE Plane,
            DL_VECTOR4AL_PARAMTYPE Vec
        );

        static dl_float32 DotCoord(
            DL_PLANE_PARAMTYPE Plane,
            DL_VECTOR4AL_PARAMTYPE Vec
        );

        static dl_float32 DotNormal(
            DL_PLANE_PARAMTYPE Plane,
            DL_VECTOR4AL_PARAMTYPE Vec
        );

        static DL_PLANE NormalizeEst(
            DL_PLANE_PARAMTYPE In
        );

        static DL_PLANE Normalize(
            DL_PLANE_PARAMTYPE In
        );

        static DL_PLANE Transform(
            DL_PLANE_PARAMTYPE Plane,
            DL_MATRIX44_PARAMTYPE Mtx
        );

        static DL_PLANE FromPointNormal(
            DL_VECTOR4AL_PARAMTYPE Point,
            DL_VECTOR4AL_PARAMTYPE Normal
        );

        static DL_PLANE FromPoints(
            DL_VECTOR4AL_PARAMTYPE Point0,
            DL_VECTOR4AL_PARAMTYPE Point1,
            DL_VECTOR4AL_PARAMTYPE Point2
        );

        static dl_bool IntersectPlanes(
            DL_PLANE_PARAMTYPE Plane0,
            DL_PLANE_PARAMTYPE Plane1,
            DL_LINE& Line
        );

        static dl_bool IntersectPlanes(
            DL_PLANE_PARAMTYPE Plane0,
            DL_PLANE_PARAMTYPE Plane1,
            DL_PLANE_PARAMTYPE Plane2,
            DL_VECTOR4AL& Point
        );
    };
}

#include "DLLinearIntrinsic.inl"