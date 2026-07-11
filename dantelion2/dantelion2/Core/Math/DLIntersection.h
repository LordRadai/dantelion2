#pragma once
#include "DLVector.h"
#include "DLMatrix.h"
#include "DLLinear.h"
#include "DLFrustum.inl"
#include "DLColor.h"

namespace DLMT
{
    class DLIIntersection
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
        typedef const DL_COLOR_F4 DL_COLOR_F4_PARAMTYPE; 
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
        typedef const DL_FRUSTUM& DL_FRUSTUM_PARAMTYPE;;

    public:
        enum DLIntersectResult
        {
            RESULT_OUTSIDE,
            RESULT_INTERSECT,
            RESULT_INSIDE,
        };

        static inline dl_bool Test(
            DL_VECTOR4AL_PARAMTYPE Vec,
            DL_SPHERE_PARAMTYPE Sphere
        );

        static inline dl_bool Test(
            DL_VECTOR4AL_PARAMTYPE Vec,
            DL_AABB_PARAMTYPE AABB
        );

        static inline dl_bool Test(
            DL_VECTOR4AL_PARAMTYPE Vec,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_VECTOR4AL_PARAMTYPE Vec,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_VECTOR4AL_PARAMTYPE Vec,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_RECTANGLE_PARAMTYPE Rect
        );

        static inline dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_PLANE_PARAMTYPE Plane
        );

        static inline dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_SPHERE_PARAMTYPE Sphere
        );

        static dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_AABB_PARAMTYPE AABB
        );

        static dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_RECTANGLE_PARAMTYPE Rect
        );

        static inline dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_PLANE_PARAMTYPE Plane
        );

        static inline dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_SPHERE_PARAMTYPE Sphere
        );

        static dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_AABB_PARAMTYPE AABB
        );

        static dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_RAY_PARAMTYPE Ray,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_RECTANGLE_PARAMTYPE Rect
        );

        static inline dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_PLANE_PARAMTYPE Plane
        );

        static inline dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_SPHERE_PARAMTYPE Sphere
        );

        static dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_AABB_PARAMTYPE AABB
        );

        static dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_LINE_PARAMTYPE Line,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect0,
            DL_RECTANGLE_PARAMTYPE Rect1
        );

        static dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_PLANE_PARAMTYPE Plane
        );

        static inline dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_SPHERE_PARAMTYPE Sphere
        );

        static dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_AABB_PARAMTYPE AABB
        );

        static dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static inline dl_bool Test(
            DL_PLANE_PARAMTYPE Plane0,
            DL_PLANE_PARAMTYPE Plane1
        );

        static inline dl_bool Test(
            DL_PLANE_PARAMTYPE Plane,
            DL_SPHERE_PARAMTYPE Sphere
        );

        static dl_bool Test(
            DL_PLANE_PARAMTYPE Plane,
            DL_AABB_PARAMTYPE AABB
        );

        static dl_bool Test(
            DL_PLANE_PARAMTYPE Plane,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_PLANE_PARAMTYPE Plane,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_PLANE_PARAMTYPE Plane,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_PLANE_PARAMTYPE Plane,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static inline dl_bool Test(
            DL_SPHERE_PARAMTYPE Sphere0,
            DL_SPHERE_PARAMTYPE Sphere1
        );

        static dl_bool Test(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_AABB_PARAMTYPE AABB
        );

        static dl_bool Test(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_OBB_PARAMTYPE OBB
        );

        static inline dl_bool Test(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_LSS_PARAMTYPE LSS
        );

        static inline dl_bool Test(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static inline dl_bool Test(
            DL_AABB_PARAMTYPE AABB0,
            DL_AABB_PARAMTYPE AABB1
        );

        static dl_bool Test(
            DL_AABB_PARAMTYPE AABB0,
            DL_OBB_PARAMTYPE OBB
        );

        static dl_bool Test(
            DL_AABB_PARAMTYPE AABB,
            DL_LSS_PARAMTYPE LSS
        );

        static dl_bool Test(
            DL_AABB_PARAMTYPE AABB,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_AABB_PARAMTYPE AABB,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static dl_bool Test(
            DL_OBB_PARAMTYPE OBB0,
            DL_OBB_PARAMTYPE OBB1
        );

        static dl_bool Test(
            DL_OBB_PARAMTYPE OBB,
            DL_LSS_PARAMTYPE LSS
        );

        static dl_bool Test(
            DL_OBB_PARAMTYPE OBB,
            DL_RSS_PARAMTYPE RSS
        );

        static dl_bool Test(
            DL_OBB_PARAMTYPE OBB,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static inline dl_bool Test(
            DL_LSS_PARAMTYPE LSS0,
            DL_LSS_PARAMTYPE LSS1
        );

        static inline dl_bool Test(
            DL_LSS_PARAMTYPE LSS,
            DL_RSS_PARAMTYPE RSS
        );

        static inline dl_bool Test(
            DL_LSS_PARAMTYPE LSS,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static inline dl_bool Test(
            DL_RSS_PARAMTYPE RSS0,
            DL_RSS_PARAMTYPE RSS1
        );

        static inline dl_bool Test(
            DL_RSS_PARAMTYPE RSS,
            DL_TRIANGLE_PARAMTYPE Tri
        );

        static dl_bool Test(
            DL_TRIANGLE_PARAMTYPE Tri0,
            DL_TRIANGLE_PARAMTYPE Tri1
        );

        static inline DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_VECTOR4AL_PARAMTYPE Vertex
            );

        static inline DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_SEGMENT_PARAMTYPE Segment
            );

        static inline DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_RAY_PARAMTYPE Ray
            );

        static inline DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_LINE_PARAMTYPE Line
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_RECTANGLE_PARAMTYPE Rectangle
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_PLANE_PARAMTYPE Plane
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_SPHERE_PARAMTYPE Sphere
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_AABB_PARAMTYPE Aabb
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_OBB_PARAMTYPE Obb
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_LSS_PARAMTYPE Lss
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_RSS_PARAMTYPE Rss
            );

        static DLIntersectResult
            Test(
                DL_FRUSTUM_PARAMTYPE Frustum,
                DL_TRIANGLE_PARAMTYPE Triangle
            );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_RECTANGLE_PARAMTYPE Rect,
            dl_float32* pfSegP,
            dl_float32* pfRectP0,
            dl_float32* pfRectP1
        );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_PLANE_PARAMTYPE Plane,
            dl_float32* pfSegP,
            DL_VECTOR4AL* pXP
        );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_SPHERE_PARAMTYPE Sphere,
            dl_float32 afSegP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_AABB_PARAMTYPE AABB,
            dl_float32 fSegP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_OBB_PARAMTYPE OBB,
            dl_float32 afSegP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_LSS_PARAMTYPE LSS,
            dl_float32 afSegP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_TRIANGLE_PARAMTYPE Tri,
            dl_float32* pfSegP,
            dl_float32* pfTriP0,
            dl_float32* pfTriP1
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_RECTANGLE_PARAMTYPE Rect,
            dl_float32* pfRayP,
            dl_float32* pfRectP0,
            dl_float32* pfRectP1
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_PLANE_PARAMTYPE Plane,
            dl_float32* pfRayP,
            DL_VECTOR4AL* pXP
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_SPHERE_PARAMTYPE Sphere,
            dl_float32 afRayP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_AABB_PARAMTYPE AABB,
            dl_float32 fRayP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_OBB_PARAMTYPE OBB,
            dl_float32 afRayP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_LSS_PARAMTYPE LSS,
            dl_float32 afRayP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_RAY_PARAMTYPE Ray,
            DL_TRIANGLE_PARAMTYPE Tri,
            dl_float32* pfRayP,
            dl_float32* pfTriP0,
            dl_float32* pfTriP1
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_RECTANGLE_PARAMTYPE Rect,
            dl_float32* pfLineP,
            dl_float32* pfRectP0,
            dl_float32* pfRectP1
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_PLANE_PARAMTYPE Plane,
            dl_float32* pfLineP,
            DL_VECTOR4AL* pXP
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_SPHERE_PARAMTYPE Sphere,
            dl_float32 afLineP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_AABB_PARAMTYPE AABB,
            dl_float32 afLineP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_OBB_PARAMTYPE OBB,
            dl_float32 afLineP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_LSS_PARAMTYPE LSS,
            dl_float32 afLineP[2],
            dl_uint32* puQuantity
        );

        static dl_bool Find(
            DL_LINE_PARAMTYPE Line,
            DL_TRIANGLE_PARAMTYPE Tri,
            dl_float32* pfLineP,
            dl_float32* pfTriP0,
            dl_float32* pfTriP1
        );

        static dl_bool Find(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_SPHERE_PARAMTYPE Sphere,
            dl_float32* pfRectP0,
            dl_float32* pfRectP1,
            DL_VECTOR4AL* pDepth
        );

        static dl_bool Find(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_LSS_PARAMTYPE LSS,
            dl_float32* pfRectP0,
            dl_float32* pfRectP1,
            dl_float32* pfLssP,
            DL_VECTOR4AL* pDepth
        );

        static dl_bool Find(
            DL_RECTANGLE_PARAMTYPE Rect,
            DL_TRIANGLE_PARAMTYPE Tri,
            DL_VECTOR4AL* pXP0,
            DL_VECTOR4AL* pXP1
        );

        static dl_bool Find(
            DL_PLANE_PARAMTYPE Plane,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL* pXP,
            DL_VECTOR4AL* pDepth
        );

        static dl_bool Find(
            DL_PLANE_PARAMTYPE Plane,
            DL_LSS_PARAMTYPE LSS,
            DL_VECTOR4AL* pXP,
            dl_float32* pfLssP,
            DL_VECTOR4AL* pDepth
        );

        static dl_bool Find(
            DL_PLANE_PARAMTYPE Plane,
            DL_TRIANGLE_PARAMTYPE Tri,
            DL_VECTOR4AL* pXP0,
            DL_VECTOR4AL* pXP1
        );

        static dl_bool Find(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_AABB_PARAMTYPE AABB,
            DL_VECTOR4AL* pDepth,
            DL_VECTOR4AL* pXP
        );

        static dl_bool Find(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_OBB_PARAMTYPE OBB,
            DL_VECTOR4AL* pDepth,
            DL_VECTOR4AL* pXP
        );

        static dl_bool Find(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_TRIANGLE_PARAMTYPE Tri,
            DL_VECTOR4AL* pDepth,
            dl_float32* pfTriP0,
            dl_float32* pfTriP1
        );

        static dl_bool Find(
            DL_TRIANGLE_PARAMTYPE Tri0,
            DL_TRIANGLE_PARAMTYPE Tri1,
            DL_VECTOR4AL* pXP0,
            DL_VECTOR4AL* pXP1,
            dl_bool* bCoplanar
        );

        static dl_bool FindDynamic(
            DL_PLANE_PARAMTYPE Plane,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_PLANE_PARAMTYPE Plane,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            dl_float32 fMaxTime,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SEGMENT_PARAMTYPE Seg,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            dl_float32 fMaxTime,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_LINE_PARAMTYPE Line,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_LINE_PARAMTYPE Line,
            DL_SPHERE_PARAMTYPE Sphere,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            dl_float32 fMaxTime,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SPHERE_PARAMTYPE Sphere0,
            DL_SPHERE_PARAMTYPE Sphere1,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SPHERE_PARAMTYPE Sphere0,
            DL_SPHERE_PARAMTYPE Sphere1,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            dl_float32 fMaxTime,
            DL_VECTOR4AL* pContactPt,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_AABB_PARAMTYPE AABB,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            DL_VECTOR4AL* pContactP,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_AABB_PARAMTYPE AABB,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            dl_float32 fTime,
            DL_VECTOR4AL* pContactP,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_OBB_PARAMTYPE OBB,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            DL_VECTOR4AL* pContactP,
            dl_float32* pfTime
        );

        static dl_bool FindDynamic(
            DL_SPHERE_PARAMTYPE Sphere,
            DL_OBB_PARAMTYPE OBB,
            DL_VECTOR4AL_PARAMTYPE Velocity0,
            DL_VECTOR4AL_PARAMTYPE Velocity1,
            dl_float32 fTime,
            DL_VECTOR4AL* pContactP,
            dl_float32* pfTime
        );

    private:
        static dl_float32 __GetVertexIntersection(
            DL_VECTOR4AL_PARAMTYPE vD,
            DL_VECTOR4AL_PARAMTYPE vV,
            dl_float32 fRadiusSq
        );
        static dl_float32 __GetEdgeIntersection(
            dl_float32 fDx,
            dl_float32 fDz,
            dl_float32 fVx,
            dl_float32 fVz,
            dl_float32 fVSq,
            dl_float32 fRSq
        );
        static dl_int32 __FindDynFaceRegionIntersection(
            DL_VECTOR4AL_PARAMTYPE vE,
            DL_VECTOR4AL_PARAMTYPE vC,
            DL_VECTOR4AL_PARAMTYPE vV,
            dl_float32 fRadius,
            dl_bool bAboveFace,
            DL_VECTOR4AL* pvI,
            dl_float32* pfTime
        );
        static dl_int32 __FindJustEdgeIntersection(
            DL_VECTOR4AL_PARAMTYPE vC,
            DL_VECTOR4AL_PARAMTYPE vE,
            DL_VECTOR4_PARAMTYPE vD,
            DL_VECTOR4AL_PARAMTYPE vV,
            dl_float32 fRadius,
            DL_VECTOR4AL* pvI,
            dl_float32* pfTime
        );
        static dl_int32 __FindDynEdgeRegionIntersection(
            DL_VECTOR4AL_PARAMTYPE vE,
            DL_VECTOR4AL_PARAMTYPE vC,
            DL_VECTOR4AL_PARAMTYPE vV,
            dl_float32 fRadius,
            dl_bool bAboveEdge,
            DL_VECTOR4AL* pvI,
            dl_float32* pfTime
        );
        static dl_int32 __FindDynVertexRegionIntersection(
            DL_VECTOR4AL_PARAMTYPE vE,
            DL_VECTOR4AL_PARAMTYPE vC,
            DL_VECTOR4AL_PARAMTYPE vV,
            dl_float32 fRadius,
            DL_VECTOR4AL* pvI,
            dl_float32* pfTime
        );

        static dl_bool __AnyInFrontOfFrustumPlanes(
            DL_FRUSTUM::DLFrustumPlaneIndex Plane0,
            DL_FRUSTUM::DLFrustumPlaneIndex Plane1,
            DL_FRUSTUM::DLFrustumPlaneIndex Plane2,
            DL_FRUSTUM::DLFrustumPlaneIndex Plane3,
            DL_FRUSTUM_PARAMTYPE Frustum,
            DL_VECTOR4AL_PARAMTYPE vPt
        );
    };
}