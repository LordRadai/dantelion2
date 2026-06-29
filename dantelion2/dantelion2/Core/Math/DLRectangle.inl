#include "DLRectangle.h"

namespace DLMT
{
    inline DL_RECTANGLE::DL_RECTANGLE(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1)
    {
        SetValue(vOrig, vEdge0, vEdge1);
    }

    inline DL_RECTANGLE::DL_RECTANGLE(const DL_RECTANGLE& rect)
    {
        SetValue(rect.m_Origin, rect.m_Edge[0], rect.m_Edge[1]);
    }

    inline void DL_RECTANGLE::SetValue(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1)
    {
        m_Origin = vOrig;
        m_Edge[0] = vEdge0;
        m_Edge[1] = vEdge1;
    }

    inline DL_VECTOR4AL DL_RECTANGLE::ComputePoint(dl_float32 fS, dl_float32 fT) const
    {
        // P = Origin + (Edge0 * fS) + (Edge1 * fT)
        return m_Origin + (m_Edge[0] * fS) + (m_Edge[1] * fT);
    }

    inline DL_VECTOR4AL DL_RECTANGLE::GetNormal() const
    {
        // Assuming Cross3 is the 3D cross product of the X, Y, Z components
        return { m_Edge[0].y * m_Edge[1].z - m_Edge[0].z * m_Edge[1].y,
                 m_Edge[0].z * m_Edge[1].x - m_Edge[0].x * m_Edge[1].z,
                 m_Edge[0].x * m_Edge[1].y - m_Edge[0].y * m_Edge[1].x, 0.0f };
    }

    inline DL_VECTOR4AL DL_RECTANGLE::GetCenter() const
    {
        return m_Origin + (m_Edge[0] * 0.5f) + (m_Edge[1] * 0.5f);
    }

    inline DL_RECTANGLE& DL_RECTANGLE::operator *= (const DL_MATRIX44& mtx)
    {
        m_Origin = m_Origin * mtx; // Assuming operator* handles W=1 transformation
        m_Edge[0] = m_Edge[0] * mtx; // Need to ensure W=0 for vector transform
        m_Edge[1] = m_Edge[1] * mtx;
        return *this;
    }
}