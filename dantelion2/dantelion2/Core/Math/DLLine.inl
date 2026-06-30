#pragma once
#include "DLLinear.h"
#include "DLDistance.h"

namespace DLMT
{
    inline void DL_LINE::SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection)
    {
        m_Origin = vOrigin;
        m_Dir = vDirection;
    }

    inline DL_VECTOR4AL DL_LINE::ComputePoint(dl_float32 t) const
    {
        return m_Origin + (m_Dir * t);
    }

    inline DL_LINE& DL_LINE::operator *= (const DL_MATRIX44& mtx)
    {
        m_Origin = m_Origin * mtx;
        m_Dir = m_Dir * mtx;
        return *this;
    }

    inline DL_LINE DL_LINE::operator * (const DL_MATRIX44& mtx) const
    {
        return DL_LINE(m_Origin * mtx, m_Dir * mtx);
    }

    inline dl_float32 DL_LINE::GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT) const
    {
        return DLIDist::GetDistanceSq(pt, *this, pT);
    }

    inline dl_float32 DL_LINE::GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT) const
    {
        return DLIDist::GetDistance(pt, *this, pT);
    }
}