#pragma once
#include "DLVector.h"
#include "DLSegment.h"

namespace DLMT
{
    struct DL_RAY;
    struct DL_LINE;
    struct DL_RECTANGLE;
    struct DL_PLANE;
    struct DL_TRIANGLE;
    struct DL_TRIANGLE3;

    class DLIDist {
        // Parameter types for interface consistency
        typedef const DL_VECTOR4AL& DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_SEGMENT& DL_SEGMENT_PARAMTYPE;
        typedef const DL_RAY& DL_RAY_PARAMTYPE;
        typedef const DL_LINE& DL_LINE_PARAMTYPE;
        typedef const DL_RECTANGLE& DL_RECTANGLE_PARAMTYPE;
        typedef const DL_PLANE& DL_PLANE_PARAMTYPE;
        typedef const DL_TRIANGLE& DL_TRIANGLE_PARAMTYPE;
        typedef const DL_TRIANGLE3& DL_TRIANGLE3_PARAMTYPE;

    public:
        // --- Point to Primitive Distances ---
        static dl_float32 GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_SEGMENT_PARAMTYPE Seg, dl_float32* pfSegP);
        static dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_SEGMENT_PARAMTYPE Seg, dl_float32* pfSegP);

        static dl_float32 GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_RAY_PARAMTYPE Ray, dl_float32* pfRayP);
        static dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_RAY_PARAMTYPE Ray, dl_float32* pfRayP);

        static dl_float32 GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_LINE_PARAMTYPE Line, dl_float32* pfLineP);
        static dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_LINE_PARAMTYPE Line, dl_float32* pfLineP);

        static dl_float32 GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_RECTANGLE_PARAMTYPE Rect, dl_float32* pfRectP0, dl_float32* pfRectP1);
        static dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_RECTANGLE_PARAMTYPE Rect, dl_float32* pfRectP0, dl_float32* pfRectP1);

        static dl_float32 GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_PLANE_PARAMTYPE Plane, DL_VECTOR4AL* pClosestP);
        static dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_PLANE_PARAMTYPE Plane, DL_VECTOR4AL* pClosestP);

        static dl_float32 GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_TRIANGLE_PARAMTYPE Tri, dl_float32* pfTriP0, dl_float32* pfTriP1);
        static dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_TRIANGLE_PARAMTYPE Tri, dl_float32* pfTriP0, dl_float32* pfTriP1);

        // --- Segment to Primitive Distances ---
        static dl_float32 GetDistance(DL_SEGMENT_PARAMTYPE Seg0, DL_SEGMENT_PARAMTYPE Seg1, dl_float32* pfSeg0P, dl_float32* pfSeg1P);
        static dl_float32 GetDistanceSq(DL_SEGMENT_PARAMTYPE Seg0, DL_SEGMENT_PARAMTYPE Seg1, dl_float32* pfSeg0P, dl_float32* pfSeg1P);

        static dl_float32 GetDistance(DL_SEGMENT_PARAMTYPE Seg, DL_RAY_PARAMTYPE Ray, dl_float32* pfSegP, dl_float32* pfRayP);
        static dl_float32 GetDistanceSq(DL_SEGMENT_PARAMTYPE Seg, DL_RAY_PARAMTYPE Ray, dl_float32* pfSegP, dl_float32* pfRayP);

        static dl_float32 GetDistance(DL_SEGMENT_PARAMTYPE Seg, DL_PLANE_PARAMTYPE Plane, dl_float32* pfSegP, DL_VECTOR4AL* pClosestP);
        static dl_float32 GetDistanceSq(DL_SEGMENT_PARAMTYPE Seg, DL_PLANE_PARAMTYPE Plane, dl_float32* pfSegP, DL_VECTOR4AL* pClosestP);

        // --- Ray and Line to Primitive Distances ---
        static dl_float32 GetDistance(DL_RAY_PARAMTYPE Ray0, DL_RAY_PARAMTYPE Ray1, dl_float32* pfRay0P, dl_float32* pfRay1P);
        static dl_float32 GetDistanceSq(DL_RAY_PARAMTYPE Ray0, DL_RAY_PARAMTYPE Ray1, dl_float32* pfRay0P, dl_float32* pfRay1P);

        static dl_float32 GetDistance(DL_LINE_PARAMTYPE Line0, DL_LINE_PARAMTYPE Line1, dl_float32* pfLine0P, dl_float32* pfLine1P);
        static dl_float32 GetDistanceSq(DL_LINE_PARAMTYPE Line0, DL_LINE_PARAMTYPE Line1, dl_float32* pfLine0P, dl_float32* pfLine1P);

        // --- Complex Primitive Inter-Distances ---
        static dl_float32 GetDistance(DL_TRIANGLE_PARAMTYPE Tri0, DL_TRIANGLE_PARAMTYPE Tri1, dl_float32* pfTri0P0, dl_float32* pfTri0P1, dl_float32* pfTri1P0, dl_float32* pfTri1P1);
        static dl_float32 GetDistanceSq(DL_TRIANGLE_PARAMTYPE Tri0, DL_TRIANGLE_PARAMTYPE Tri1, dl_float32* pfTri0P0, dl_float32* pfTri0P1, dl_float32* pfTri1P0, dl_float32* pfTri1P1);
    };
}