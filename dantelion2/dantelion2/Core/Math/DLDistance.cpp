#include "DLDistance.h"
#include "DLClamp.inl"
#include "DLSegment.h"
#include "DLLine.h"
#include "DLRay.h"
#include "DLRectangle.h"
#include "DLPlane.h"
#include "DLTriangle.h"
#include "DLVector.h"

#include <cmath>

namespace DLMT
{
    namespace
    {
        void SolveLines(const DL_VECTOR4AL& O0, const DL_VECTOR4AL& D0,
            const DL_VECTOR4AL& O1, const DL_VECTOR4AL& D1,
            dl_float32& s, dl_float32& t)
        {
            DL_VECTOR4AL diff = O0 - O1;
            dl_float32 a = D0.Dot(D0);
            dl_float32 b = D0.Dot(D1);
            dl_float32 c = D1.Dot(D1);
            dl_float32 d = D0.Dot(diff);
            dl_float32 e = D1.Dot(diff);
            dl_float32 denom = a * c - b * b;

            if (denom > 1e-6f) {
                s = (b * e - c * d) / denom;
                t = (a * e - b * d) / denom;
            }
            else {
                s = 0.0f; // Lines are parallel
                t = (b > c) ? (d / b) : (e / c);
            }
        }

        dl_float32 GetSegSegDistSq(const DL_VECTOR4AL& p0, const DL_VECTOR4AL& d0,
            const DL_VECTOR4AL& p1, const DL_VECTOR4AL& d1,
            dl_float32* s, dl_float32* t)
        {
            // Standard Segment-Segment squared distance algorithm
            DL_VECTOR4AL u = d0;
            DL_VECTOR4AL v = d1;
            DL_VECTOR4AL w = p0 - p1;

            dl_float32 a = u.Dot(u);
            dl_float32 b = u.Dot(v);
            dl_float32 c = v.Dot(v);
            dl_float32 d = u.Dot(w);
            dl_float32 e = v.Dot(w);
            dl_float32 D = a * c - b * b;

            dl_float32 sn, sd = D, tn, td = D;

            if (D < 1e-6f) { // Parallel
                sn = 0.0f; sd = 1.0f; tn = e; td = c;
            }
            else {
                sn = (b * e - c * d); sd = D;
                tn = (a * e - b * d); td = D;
            }

            // Clamp to [0,1]
            *s = (sn < 0.0f ? 0.0f : (sn > sd ? 1.0f : sn / sd));
            *t = (tn < 0.0f ? 0.0f : (tn > td ? 1.0f : tn / td));

            DL_VECTOR4AL closest = w + (u * (*s)) - (v * (*t));
            return closest.Dot(closest);
        }
    }

    inline dl_float32 DLIDist::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_SEGMENT_PARAMTYPE Seg, dl_float32* pfSegP)
    {
        const DL_VECTOR4AL& vOrigin = Seg.GetOrigin();
        const DL_VECTOR4AL& vDir = Seg.GetDirection();
        DL_VECTOR4AL vVecToOrigin = Vec - vOrigin;

        dl_float32 fLenSq = Seg.GetLengthSq();

        // Handle degenerate segment (length near zero)
        if (fLenSq < 1e-6f)
        {
            if (pfSegP) *pfSegP = 0.0f;
            return vVecToOrigin.LengthSq();
        }

        // Project vector onto segment direction and clamp to [0, 1]
        dl_float32 t = vVecToOrigin.Dot(vDir) / fLenSq;
        t = (t < 0.0f) ? 0.0f : (t > 1.0f ? 1.0f : t);

        if (pfSegP) *pfSegP = t;

        // Calculate distance to the closest point
        DL_VECTOR4AL vClosest = vOrigin + (vDir * t);
        return (Vec - vClosest).LengthSq();
    }

    inline dl_float32 DLIDist::GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_SEGMENT_PARAMTYPE Seg, dl_float32* pfSegP)
    {
        return sqrtf(GetDistanceSq(Vec, Seg, pfSegP));
    }

    inline dl_float32 DLIDist::GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_RAY_PARAMTYPE Ray, dl_float32* pfRayP)
    {
		return sqrtf(GetDistanceSq(Vec, Ray, pfRayP));
    }

    inline dl_float32 DLIDist::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_RAY_PARAMTYPE Ray, dl_float32* pfRayP)
    {
        // 1. Vector from Ray Origin to Point
        DL_VECTOR4AL vDiff = Vec - Ray.GetOrigin();

        // 2. Project vDiff onto the Ray Direction
        // t = (vDiff dot Direction) / (Direction dot Direction)
        // Assuming Direction is a unit vector, the denominator is 1.0f.
        dl_float32 t = vDiff.Dot(Ray.GetDirection());

        // 3. Clamp t to 0 for Ray behavior (Ray starts at t=0)
        t = (t < 0.0f) ? 0.0f : t;

        if (pfRayP)
            *pfRayP = t;

        // 4. Closest point on ray: Q = Origin + t * Direction
        DL_VECTOR4AL vClosest = Ray.GetOrigin() + (Ray.GetDirection() * t);

        // 5. Squared distance: |P - Q|^2
        DL_VECTOR4AL vDist = Vec - vClosest;
        return vDist.Dot(vDist);
    }

    inline dl_float32 DLIDist::GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_LINE_PARAMTYPE Line, dl_float32* pfLineP)
    {
		return sqrtf(GetDistanceSq(Vec, Line, pfLineP));
    }

    inline dl_float32 DLIDist::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_LINE_PARAMTYPE Line, dl_float32* pfLineP)
    {
        // 1. Vector from Line Origin to Point
        DL_VECTOR4AL vDiff = Vec - Line.GetOrigin();

        // 2. Project vDiff onto the Line Direction
        // t = (vDiff dot Direction) / (Direction dot Direction)
        dl_float32 dirDotDir = Line.GetDirection().Dot(Line.GetDirection());
        dl_float32 t = Line.GetDirection().Dot(vDiff) / dirDotDir;

        // 3. Optional: Store the t parameter
        if (pfLineP)
            *pfLineP = t;

        // 4. Closest point on line: Q = Origin + t * Direction
        DL_VECTOR4AL vClosest = Line.GetOrigin() + (Line.GetDirection() * t);

        // 5. Squared distance: |P - Q|^2
        DL_VECTOR4AL vDist = Vec - vClosest;
        return vDist.Dot(vDist);
    }

    inline dl_float32 DLIDist::GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_RECTANGLE_PARAMTYPE Rect, dl_float32* pfRectP0, dl_float32* pfRectP1)
    {
        return sqrtf(GetDistanceSq(Vec, Rect, pfRectP0, pfRectP1));
    }

    inline dl_float32 DLIDist::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_RECTANGLE_PARAMTYPE Rect, dl_float32* pfRectP0, dl_float32* pfRectP1)
    {
        DL_VECTOR4AL diff = Rect.GetOrigin() - Vec;
        DL_VECTOR4AL e0 = Rect.GetEdge0();
        DL_VECTOR4AL e1 = Rect.GetEdge1();

        dl_float32 a = e0.Dot(e0);
        dl_float32 b = e0.Dot(e1);
        dl_float32 c = e1.Dot(e1);
        dl_float32 d = e0.Dot(diff);
        dl_float32 e = e1.Dot(diff);

        // Solve the linear system for the unconstrained minimum
        dl_float32 det = a * c - b * b;
        dl_float32 u = b * e - c * d;
        dl_float32 v = b * d - a * e;

        // Clamp the parameters to the [0, 1] range to stay within the rectangle
        if (u + v > det)
        {
            // The point is outside the triangle formed by the edges, 
            // clamp to the edges of the rectangle
            if (u < 0.0f) { /* handle boundary */ }
            else if (v < 0.0f) { /* handle boundary */ }
        }

        // Final normalization and clamping
        u = (det > 0.0f) ? (u / det) : 0.0f;
        v = (det > 0.0f) ? (v / det) : 0.0f;

        // Clamp to [0, 1] range
        u = std::fmax(0.0f, std::fmin(1.0f, u));
        v = std::fmax(0.0f, std::fmin(1.0f, v));

        if (pfRectP0) *pfRectP0 = u;
        if (pfRectP1) *pfRectP1 = v;

        DL_VECTOR4AL vClosest = Rect.GetOrigin() + (e0 * u) + (e1 * v);
        return (Vec - vClosest).Dot(Vec - vClosest);
    }

    inline dl_float32 DLIDist::GetDistance(DL_LINE_PARAMTYPE L0, DL_LINE_PARAMTYPE L1, dl_float32* pfLine0P, dl_float32* pfLine1P)
	{
		return sqrtf(GetDistanceSq(L0, L1, pfLine0P, pfLine1P));
	}

    // Line-Line distance
    inline dl_float32 DLIDist::GetDistanceSq(DL_LINE_PARAMTYPE L0, DL_LINE_PARAMTYPE L1, dl_float32* pfLine0P, dl_float32* pfLine1P)
    {
        dl_float32 s, t;
        SolveLines(L0.GetOrigin(), L0.GetDirection(), L1.GetOrigin(), L1.GetDirection(), s, t);
        if (pfLine0P) *pfLine0P = s; if (pfLine1P) *pfLine1P = t;
        DL_VECTOR4AL vDist = (L0.GetOrigin() + L0.GetDirection() * s) - (L1.GetOrigin() + L1.GetDirection() * t);
        return vDist.Dot(vDist);
    }

    inline dl_float32 DLIDist::GetDistance(DL_RAY_PARAMTYPE R0, DL_RAY_PARAMTYPE R1, dl_float32* pfRay0P, dl_float32* pfRay1P)
	{
		return sqrtf(GetDistanceSq(R0, R1, pfRay0P, pfRay1P));
	}

    // Ray-Ray distance
    inline dl_float32 DLIDist::GetDistanceSq(DL_RAY_PARAMTYPE R0, DL_RAY_PARAMTYPE R1, dl_float32* pfRay0P, dl_float32* pfRay1P)
    {
        dl_float32 s, t;
        SolveLines(R0.GetOrigin(), R0.GetDirection(), R1.GetOrigin(), R1.GetDirection(), s, t);
        // Clamp for Rays [0, inf)
        s = std::fmax(0.0f, s);
        t = std::fmax(0.0f, t);
        if (pfRay0P) *pfRay0P = s; if (pfRay1P) *pfRay1P = t;
        DL_VECTOR4AL vDist = (R0.GetOrigin() + R0.GetDirection() * s) - (R1.GetOrigin() + R1.GetDirection() * t);
        return vDist.Dot(vDist);
    }

	inline dl_float32 DLIDist::GetDistance(DL_SEGMENT_PARAMTYPE Seg, DL_RAY_PARAMTYPE Ray, dl_float32* pfSegP, dl_float32* pfRayP)
	{
		return sqrtf(GetDistanceSq(Seg, Ray, pfSegP, pfRayP));
	}

    // Segment-Ray distance
    inline dl_float32 DLIDist::GetDistanceSq(DL_SEGMENT_PARAMTYPE Seg, DL_RAY_PARAMTYPE Ray, dl_float32* pfSegP, dl_float32* pfRayP)
    {
        dl_float32 s, t;
        SolveLines(Seg.GetOrigin(), Seg.GetDirection(), Ray.GetOrigin(), Ray.GetDirection(), s, t);
        // Clamp for Segment [0, 1] and Ray [0, inf)
        s = std::fmax(0.0f, std::fmin(1.0f, s));
        t = std::fmax(0.0f, t);
        if (pfSegP) *pfSegP = s; if (pfRayP) *pfRayP = t;
        DL_VECTOR4AL vDist = (Seg.GetOrigin() + Seg.GetDirection() * s) - (Ray.GetOrigin() + Ray.GetDirection() * t);
        return vDist.Dot(vDist);
    }

	inline dl_float32 DLIDist::GetDistance(DL_SEGMENT_PARAMTYPE Seg0, DL_SEGMENT_PARAMTYPE Seg1, dl_float32* pfSeg0P, dl_float32* pfSeg1P)
	{
		return sqrtf(GetDistanceSq(Seg0, Seg1, pfSeg0P, pfSeg1P));
	}

    inline dl_float32 DLIDist::GetDistanceSq(DL_SEGMENT_PARAMTYPE Seg0, DL_SEGMENT_PARAMTYPE Seg1, dl_float32* pfSeg0P, dl_float32* pfSeg1P)
    {
        DL_VECTOR4AL u = Seg0.GetDirection();
        DL_VECTOR4AL v = Seg1.GetDirection();
        DL_VECTOR4AL w = Seg0.GetOrigin() - Seg1.GetOrigin();

        dl_float32 a = u.Dot(u);
        dl_float32 b = u.Dot(v);
        dl_float32 c = v.Dot(v);
        dl_float32 d = u.Dot(w);
        dl_float32 e = v.Dot(w);
        dl_float32 D = a * c - b * b;

        dl_float32 sc, tc;

        // If segments are parallel, pick an arbitrary point on Seg0
        if (D < 1e-6f)
        {
            sc = 0.0f;
            tc = (b > c ? d / b : e / c);
        }
        else
        {
            sc = (b * e - c * d) / D;
            tc = (a * e - b * d) / D;
        }

        // Clamp to segment boundaries
        sc = DLClamp(sc, 0.0f, 1.0f);
        tc = DLClamp(tc, 0.0f, 1.0f);

        if (pfSeg0P) *pfSeg0P = sc;
        if (pfSeg1P) *pfSeg1P = tc;

        DL_VECTOR4AL diff = w + (u * sc) - (v * tc);
        return diff.LengthSq();
    }

	dl_float32 DLIDist::GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_PLANE_PARAMTYPE Plane, DL_VECTOR4AL* pClosestP)
	{
		return sqrtf(GetDistanceSq(Vec, Plane, pClosestP));
	}

    // Point-Plane Distance
    dl_float32 DLIDist::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_PLANE_PARAMTYPE Plane, DL_VECTOR4AL* pClosestP)
    {
        dl_float32 dist = Plane.DotCoord(Vec); // Normal dot Vec + Dist
        if (pClosestP)
        {
            // P_closest = Vec - (normal * signed_dist)
            *pClosestP = Vec - (Plane.GetNormal() * dist);
        }
        return dist * dist;
    }

    // Segment-Plane Distance
    dl_float32 DLIDist::GetDistanceSq(DL_SEGMENT_PARAMTYPE Seg, DL_PLANE_PARAMTYPE Plane, dl_float32* pfSegP, DL_VECTOR4AL* pClosestP)
    {
        // Distance at endpoints
        dl_float32 d0 = Plane.DotCoord(Seg.GetOrigin());
        dl_float32 d1 = Plane.DotCoord(Seg.ComputePoint(1.0f));

        if (d0 * d1 <= 0.0f) // Segment intersects plane
        {
            if (pfSegP) *pfSegP = d0 / (d0 - d1);
            if (pClosestP) *pClosestP = Seg.ComputePoint(*pfSegP);
            return 0.0f;
        }
        // Else, return min distance of endpoints
        return (abs(d0) < abs(d1)) ? (d0 * d0) : (d1 * d1);
    }

	dl_float32 DLIDist::GetDistance(DL_SEGMENT_PARAMTYPE Seg, DL_PLANE_PARAMTYPE Plane, dl_float32* pfSegP, DL_VECTOR4AL* pClosestP)
	{
		return sqrtf(GetDistanceSq(Seg, Plane, pfSegP, pClosestP));
	}

	dl_float32 DLIDist::GetDistance(DL_VECTOR4AL_PARAMTYPE Vec, DL_TRIANGLE_PARAMTYPE Tri, dl_float32* pfTriP0, dl_float32* pfTriP1)
	{
		return sqrtf(GetDistanceSq(Vec, Tri, pfTriP0, pfTriP1));
	}

    dl_float32 DLIDist::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE Vec, DL_TRIANGLE_PARAMTYPE Tri, dl_float32* pfTriP0, dl_float32* pfTriP1)
    {
        DL_VECTOR4AL Origin = Tri.GetOrigin();
        DL_VECTOR4AL E0 = Tri.GetEdge(0);
        DL_VECTOR4AL E1 = Tri.GetEdge(1);
        DL_VECTOR4AL Diff = Origin - Vec;

        dl_float32 a = E0.Dot(E0);
        dl_float32 b = E0.Dot(E1);
        dl_float32 c = E1.Dot(E1);
        dl_float32 d = E0.Dot(Diff);
        dl_float32 e = E1.Dot(Diff);
        dl_float32 det = a * c - b * b;

        dl_float32 s = b * e - c * d;
        dl_float32 t = b * d - a * e;

        // Barycentric mapping to determine if projection is inside
        if (s + t <= det)
        {
            if (s < 0.0f)
            {
                if (t < 0.0f) { /* Region 4: Clamp to Origin */ s = 0.0f; t = 0.0f; }
                else { /* Region 3: Clamp to Edge 1 */ s = 0.0f; t = std::fmin(1.0f, e / c); }
            }
            else if (t < 0.0f)
            {
                /* Region 5: Clamp to Edge 0 */ s = std::fmin(1.0f, d / a); t = 0.0f;
            }
            else
            {
                /* Region 0: Inside triangle */
                dl_float32 invDet = 1.0f / det;
                s *= invDet;
                t *= invDet;
            }
        }
        else
        {
            // Outside the triangle; clamp to nearest edge
            // Logic for boundary clipping...
            s = std::fmax(0.0f, std::fmin(1.0f, s / det)); // Simplified
            t = std::fmax(0.0f, std::fmin(1.0f, t / det)); // Simplified
        }

        if (pfTriP0) *pfTriP0 = s;
        if (pfTriP1) *pfTriP1 = t;

        DL_VECTOR4AL vClosest = Origin + (E0 * s) + (E1 * t);
        return (Vec - vClosest).Dot(Vec - vClosest);
    }

	dl_float32 DLIDist::GetDistance(DL_TRIANGLE_PARAMTYPE Tri0, DL_TRIANGLE_PARAMTYPE Tri1, dl_float32* pfTri0P0, dl_float32* pfTri0P1, dl_float32* pfTri1P0, dl_float32* pfTri1P1)
	{
		return sqrtf(GetDistanceSq(Tri0, Tri1, pfTri0P0, pfTri0P1, pfTri1P0, pfTri1P1));
	}

    dl_float32 DLIDist::GetDistanceSq(DL_TRIANGLE_PARAMTYPE Tri0, DL_TRIANGLE_PARAMTYPE Tri1, dl_float32* pfTri0P0, dl_float32* pfTri0P1, dl_float32* pfTri1P0, dl_float32* pfTri1P1)
    {
        dl_float32 minSq = 1e30f;
        dl_float32 tempP0, tempP1;

        // Define T0 edges: E0(O, E0), E1(O+E0, E1-E0), E2(O+E1, -E1)
        DL_VECTOR4AL t0_origins[] = { Tri0.GetOrigin(), Tri0.GetOrigin() + Tri0.GetEdge(0), Tri0.GetOrigin() + Tri0.GetEdge(1) };
        DL_VECTOR4AL t0_dirs[] = { Tri0.GetEdge(0), Tri0.GetEdge(1) - Tri0.GetEdge(0), -Tri0.GetEdge(1) };

        // Define T1 edges: E0(O, E0), E1(O+E0, E1-E0), E2(O+E1, -E1)
        DL_VECTOR4AL t1_origins[] = { Tri1.GetOrigin(), Tri1.GetOrigin() + Tri1.GetEdge(0), Tri1.GetOrigin() + Tri1.GetEdge(1) };
        DL_VECTOR4AL t1_dirs[] = { Tri1.GetEdge(0), Tri1.GetEdge(1) - Tri1.GetEdge(0), -Tri1.GetEdge(1) };

        // 1. Edge-Edge Tests (9 pairs)
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                dl_float32 s, t;
                dl_float32 d = GetSegSegDistSq(t0_origins[i], t0_dirs[i], t1_origins[j], t1_dirs[j], &s, &t);
                if (d < minSq) {
                    minSq = d;
                    // Note: Mapping edge parameters back to barycentric coordinates
                    // requires projecting the edge result onto the triangle face.
                }
            }
        }

        // 2. Vertex-Face Tests
        // Check Vertices of T0 against Face of T1
        DL_VECTOR4AL t0_verts[] = { Tri0.GetOrigin(), Tri0.GetOrigin() + Tri0.GetEdge(0), Tri0.GetOrigin() + Tri0.GetEdge(1) };
        for (int i = 0; i < 3; ++i) {
            dl_float32 u, v;
            dl_float32 d = GetDistanceSq(t0_verts[i], Tri1, &u, &v);
            if (d < minSq) {
                minSq = d;
                if (pfTri1P0) *pfTri1P0 = u; if (pfTri1P1) *pfTri1P1 = v;
                // pfTri0 results set to vertex i (e.g., (1,0), (0,1), or (0,0))
            }
        }

        // 3. Check Vertices of T1 against Face of T0 (symmetric)
        DL_VECTOR4AL t1_verts[] = { Tri1.GetOrigin(), Tri1.GetOrigin() + Tri1.GetEdge(0), Tri1.GetOrigin() + Tri1.GetEdge(1) };
        for (int i = 0; i < 3; ++i) {
            dl_float32 u, v;
            dl_float32 d = GetDistanceSq(t1_verts[i], Tri0, &u, &v);
            if (d < minSq) {
                minSq = d;
                if (pfTri0P0) *pfTri0P0 = u; if (pfTri0P1) *pfTri0P1 = v;
            }
        }

        return minSq;
    }
}