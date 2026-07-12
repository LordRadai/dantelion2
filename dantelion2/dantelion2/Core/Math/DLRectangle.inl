#include "DLLinear.h"
#include "DLClamp.inl"

#include <math.h>

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

	inline dl_float32 DL_RECTANGLE::GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pfU, dl_float32* pfV) const
	{
		// Compute the vector from the rectangle origin to the point
		DL_VECTOR4AL diff = pt - m_Origin;
		// Project the difference onto the edges to find the parameters u and v
		dl_float32 u = diff.Dot(m_Edge[0]) / m_Edge[0].LengthSq();
		dl_float32 v = diff.Dot(m_Edge[1]) / m_Edge[1].LengthSq();
		// Clamp u and v to [0, 1] to stay within the rectangle
		if (pfU) *pfU = u;
		if (pfV) *pfV = v;
		u = DLClamp(u, 0.0f, 1.0f);
		v = DLClamp(v, 0.0f, 1.0f);
		// Compute the closest point on the rectangle
		DL_VECTOR4AL closestPoint = ComputePoint(u, v);
		// Return the squared distance from the point to the closest point on the rectangle
		return (pt - closestPoint).LengthSq();
	}

	inline dl_float32 DL_RECTANGLE::GetDistance(const DL_VECTOR4AL& pt, dl_float32* pfU, dl_float32* pfV) const
	{
		return sqrtf(GetDistanceSq(pt, pfU, pfV));
	}

    inline DL_VECTOR4AL DL_RECTANGLE::GetNormal() const
    {
        // Assuming Cross3 is the 3D cross product of the X, Y, Z components
        return DL_VECTOR4AL(m_Edge[0].y * m_Edge[1].z - m_Edge[0].z * m_Edge[1].y,
                 m_Edge[0].z * m_Edge[1].x - m_Edge[0].x * m_Edge[1].z,
                 m_Edge[0].x * m_Edge[1].y - m_Edge[0].y * m_Edge[1].x, 0.0f);
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

	inline DL_RECTANGLE DL_RECTANGLE::operator * (const DL_MATRIX44& mtx) const
	{
		DL_RECTANGLE result = *this;
		result *= mtx;
		return result;
	}
}