#include "DLDistance.h"
#include "DLClamp.inl"
#include "DLSegment.h"
#include "DLVector.h"

#include <cmath>

namespace DLMT
{
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
}