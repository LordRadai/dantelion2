#pragma once
#include "DLSegment.h"
#include "DLDistance.h"

namespace DLMT
{
    inline const DL_VECTOR4AL& DL_SEGMENT::GetOrigin() const { return m_Origin; }

    inline const DL_VECTOR4AL& DL_SEGMENT::GetDirection() const { return m_Dir; }

    inline void DL_SEGMENT::GetDirection(DL_VECTOR4AL& _dir) const { _dir = m_Dir; }

    inline DL_VECTOR4AL DL_SEGMENT::GetEndPoint() const { return m_Origin + m_Dir; }

    inline DL_VECTOR4AL DL_SEGMENT::GetCenter() const { return (m_Origin + (m_Origin + m_Dir)) * 0.5f; }

    inline dl_float32 DL_SEGMENT::GetLength() const { return m_Dir.Length(); }

    inline dl_float32 DL_SEGMENT::GetLengthSq() const { return m_Dir.LengthSq(); }

    inline void DL_SEGMENT::SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection) {
        m_Origin = vOrigin;
        m_Dir = vDirection;
    }

    inline void DL_SEGMENT::SetPoints(const DL_VECTOR4AL& vPt0, const DL_VECTOR4AL& vPt1) {
        m_Origin = vPt0;
        m_Dir = vPt1 - vPt0;
    }

    inline void DL_SEGMENT::SetOrigin(const DL_VECTOR4AL& vOrigin) { m_Origin = vOrigin; }

    inline void DL_SEGMENT::SetDirection(const DL_VECTOR4AL& vDirection) { m_Dir = vDirection; }

    inline void DL_SEGMENT::SetEndPoint(const DL_VECTOR4AL& vEndPoint) { m_Dir = vEndPoint - m_Origin; }

    inline DL_VECTOR4AL DL_SEGMENT::ComputePoint(dl_float32 t) const {
        // Clamp t and calculate point: Origin + (Direction * t)
        t = (t < 0.0f) ? 0.0f : (t > 1.0f ? 1.0f : t);
        return m_Origin + (m_Dir * t);
    }

    inline dl_float32 DL_SEGMENT::GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT) const {
        // Delegate to distance calculation utility
        return DLIDist::GetDistanceSq(pt, *this, pT);
    }

    inline dl_float32 DL_SEGMENT::GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT) const {
        return DLIDist::GetDistance(pt, *this, pT);
    }

    inline DL_SEGMENT& DL_SEGMENT::operator*=(const DL_MATRIX44& mtx) {
        // Transform origin as point, direction as normal
        m_Origin = m_Origin * mtx; // Assuming matrix supports vector multiplication
        m_Dir = m_Dir * mtx;       // Directional transform
        return *this;
    }

    inline DL_SEGMENT DL_SEGMENT::operator*(const DL_MATRIX44& mtx) const {
        DL_SEGMENT result = *this;
        result *= mtx;
        return result;
    }
}