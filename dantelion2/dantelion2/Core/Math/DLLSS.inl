#pragma once
#include "DLLSS.h"
#include "DLDistance.h"

#include <cmath>

namespace DLMT
{
    inline DL_LSS::DL_LSS(DL_SEGMENT_PARAMTYPE seg, dl_float32 fRadius) {
        SetValue(seg, fRadius);
    }

    inline DL_LSS::DL_LSS(DL_LSS_PARAMTYPE lss) {
        SetOrigin(lss.GetOrigin());
        SetDirection(lss.GetDirection());
        SetRadius(lss.GetRadius());
    }

    inline DL_LSS::DL_LSS(const DL_VECTOR3* pVerts, dl_uint32 uiNum) {
        SetValue(pVerts, uiNum);
    }

    inline DL_LSS::DL_LSS(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum) {
        SetValue(pVerts, uiNum);
    }

    inline void DL_LSS::SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum) {
        if (uiNum < 2) return;

        // 1. Find AABB extremes to define the initial segment
        DL_VECTOR4AL minPt(pVerts[0].x, pVerts[0].y, pVerts[0].z, 1.0f);
        DL_VECTOR4AL maxPt = minPt;
        for (dl_uint32 i = 1; i < uiNum; ++i) {
            const DL_VECTOR3& v = pVerts[i];
            minPt.x = std::fmin(minPt.x, v.x); minPt.y = std::fmin(minPt.y, v.y); minPt.z = std::fmin(minPt.z, v.z);
            maxPt.x = std::fmax(maxPt.x, v.x); maxPt.y = std::fmax(maxPt.y, v.y); maxPt.z = std::fmax(maxPt.z, v.z);
        }

        // 2. Set segment
        SetOrigin(minPt);
        SetDirection(maxPt - minPt);

        // 3. Find max distance from segment to all points to determine radius
        dl_float32 fMaxDistSq = 0.0f;
        for (dl_uint32 i = 0; i < uiNum; ++i) {
            DL_VECTOR4AL pt(pVerts[i].x, pVerts[i].y, pVerts[i].z, 1.0f);
            dl_float32 fDistSq = GetDistanceSq(pt);
            if (fDistSq > fMaxDistSq) fMaxDistSq = fDistSq;
        }

        SetRadius(sqrtf(fMaxDistSq));
    }

    inline void DL_LSS::SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum) {
        if (uiNum < 2) return;

        // 1. Find AABB extremes
        DL_VECTOR4AL minPt = pVerts[0];
        DL_VECTOR4AL maxPt = minPt;
        for (dl_uint32 i = 1; i < uiNum; ++i) {
            const DL_VECTOR4AL& pt = pVerts[i];
            minPt.x = std::fmin(minPt.x, pt.x); minPt.y = std::fmin(minPt.y, pt.y); minPt.z = std::fmin(minPt.z, pt.z);
            maxPt.x = std::fmax(maxPt.x, pt.x); maxPt.y = std::fmax(maxPt.y, pt.y); maxPt.z = std::fmax(maxPt.z, pt.z);
        }

        // 2. Set segment
        SetOrigin(minPt);
        SetDirection(maxPt - minPt);

        // 3. Find max distance from segment to all points
        dl_float32 fMaxDistSq = 0.0f;
        for (dl_uint32 i = 0; i < uiNum; ++i) {
            dl_float32 fDistSq = GetDistanceSq(pVerts[i]);
            if (fDistSq > fMaxDistSq) fMaxDistSq = fDistSq;
        }

        SetRadius(sqrtf(fMaxDistSq));
    }

    inline void DL_LSS::SetValue(DL_SEGMENT_PARAMTYPE seg, dl_float32 fRadius) {
        SetOrigin(seg.GetOrigin());
        SetDirection(seg.GetDirection());
        SetRadius(fRadius);
    }

    inline dl_bool DL_LSS::Contains(DL_VECTOR4AL_PARAMTYPE pt) const {
        return GetDistanceSq(pt) < GetRadiusSq();
    }

    inline dl_bool DL_LSS::Contains(DL_SPHERE_PARAMTYPE sphere) const {
        const dl_float32 fDiffRadius = GetRadius() - sphere.GetRadius();
        if (fDiffRadius < 0.0f) return false;

        const dl_float32 fDistSq = GetDistanceSq(sphere.GetCenter());
        return fDistSq <= (fDiffRadius * fDiffRadius);
    }

    inline dl_bool DL_LSS::Contains(DL_LSS_PARAMTYPE lss) const {
        const dl_float32 fDiffRadius = GetRadius() - lss.GetRadius();
        if (fDiffRadius < 0.0f) return false;

        const dl_float32 fDiffRadiusSq = fDiffRadius * fDiffRadius;

        if (GetDistanceSq(lss.GetOrigin()) > fDiffRadiusSq) return false;
        if (GetDistanceSq(lss.GetEndPoint()) > fDiffRadiusSq) return false;

        return true;
    }

    inline dl_float32 DL_LSS::GetRadius() const {
        return m_Radius;
    }

    inline dl_float32 DL_LSS::GetRadiusSq() const {
        return m_Radius * m_Radius;
    }

    inline void DL_LSS::SetRadius(dl_float32 Radius) {
        m_Radius = Radius;
    }

	inline dl_float32 DL_LSS::GetDistanceSq(DL_VECTOR4AL_PARAMTYPE pt) const {
		DL_SEGMENT seg;
		seg.SetOriginDirection(m_Origin, m_Direction);
		dl_float32 t;
		return seg.GetDistanceSq(pt, &t);
	}
}