#pragma once
#include "DLRay.h"
#include "DLDistance.h"

namespace DLMT
{
    inline void DL_RAY::SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection)
    {
        m_Origin = vOrigin;
        m_Dir = vDirection;
    }

    inline DL_VECTOR4AL DL_RAY::ComputePoint(dl_float32 t) const
    {
        // Enforce t >= 0 for a Ray
        dl_float32 clampedT = (t < 0.0f) ? 0.0f : t;
        return m_Origin + (m_Dir * clampedT);
    }

    inline DL_RAY& DL_RAY::operator *= (const DL_MATRIX44& mtx)
    {
        // Transforming Ray: Origin transformed as a point, Direction as a normal
        m_Origin = m_Origin * mtx;
        m_Dir = m_Dir * mtx;
        return *this;
    }

    inline DL_RAY DL_RAY::operator * (const DL_MATRIX44& mtx) const
    {
        return DL_RAY(m_Origin * mtx, m_Dir * mtx);
    }

    inline dl_float32 DL_RAY::GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT) const
    {
        return DLIDist::GetDistanceSq(pt, *this, pT);
    }

    inline dl_float32 DL_RAY::GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT) const
    {
        return DLIDist::GetDistance(pt, *this, pT);
    }
}