#include "DLLinear.h"

namespace DLMT
{
    // Constructor from array of 3 points
    inline DL_TRIANGLE::DL_TRIANGLE(const DL_VECTOR4AL pt[3])
    {
        SetPoints(pt);
    }

    // Constructor from Origin and Edges
    inline DL_TRIANGLE::DL_TRIANGLE(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1)
    {
        m_Origin = vOrig;
        m_Edge[0] = vEdge0;
        m_Edge[1] = vEdge1;
    }

    // Sets points and derives edges (E0 = P1 - P0, E1 = P2 - P0)
    inline void DL_TRIANGLE::SetPoints(const DL_VECTOR4AL pt[3])
    {
        m_Origin = pt[0];
        m_Edge[0] = pt[1] - pt[0];
        m_Edge[1] = pt[2] - pt[0];
    }

    // Returns a DL_PLANE object representing the triangle's surface
    inline DL_PLANE DL_TRIANGLE::GetPlane() const
    {
        DL_VECTOR4AL normal = GetNormal();

        return DL_PLANE(normal);
    }

    // Matrix transformation
    // Origins are positions (W=1), Edges are directions (W=0)
    inline DL_TRIANGLE DL_TRIANGLE::operator * (const DL_MATRIX44& mtx)
    {
        DL_TRIANGLE result;
        result.m_Origin = m_Origin.TransformCoord(mtx);
        result.m_Edge[0] = m_Edge[0].TransformNormal(mtx);
        result.m_Edge[1] = m_Edge[1].TransformNormal(mtx);
        return result;
    }

    inline DL_VECTOR4AL DL_TRIANGLE::ComputePoint(dl_float32 fS, dl_float32 fT) const
    {
        // P = Origin + s*E0 + t*E1
        return m_Origin + (m_Edge[0] * fS) + (m_Edge[1] * fT);
    }

    inline DL_VECTOR4AL DL_TRIANGLE::GetNormal() const
    {
        // Cross product of edges, normalized
        return (m_Edge[0].Cross(m_Edge[1])).Normalize();
    }

    inline DL_VECTOR4AL DL_TRIANGLE::GetCenter() const
    {
        // Barycentric: 1/3 * (P0 + P1 + P2) = Origin + 1/3 * (E0 + E1)
        return m_Origin + (m_Edge[0] + m_Edge[1]) * (1.0f / 3.0f);
    }

    inline DL_TRIANGLE& DL_TRIANGLE::operator *= (const DL_MATRIX44& mtx)
    {
        m_Origin = m_Origin.TransformCoord(mtx);
        m_Edge[0] = m_Edge[0].TransformNormal(mtx);
        m_Edge[1] = m_Edge[1].TransformNormal(mtx);
        return *this;
    }

    // Constructor from array of 3 points
    inline DL_TRIANGLE3::DL_TRIANGLE3(const DL_VECTOR3AL pt[3])
    {
        SetPoints(pt);
    }

    // Constructor from Origin and Edges
    inline DL_TRIANGLE3::DL_TRIANGLE3(const DL_VECTOR3AL& vOrig, const DL_VECTOR3AL& vEdge0, const DL_VECTOR3AL& vEdge1)
    {
        m_Origin = vOrig;
        m_Edge[0] = vEdge0;
        m_Edge[1] = vEdge1;
    }

    // Sets points and derives edges (E0 = P1 - P0, E1 = P2 - P0)
    inline void DL_TRIANGLE3::SetPoints(const DL_VECTOR3AL pt[3])
    {
        m_Origin = pt[0];
        m_Edge[0] = pt[1] - pt[0];
        m_Edge[1] = pt[2] - pt[0];
    }

    // Returns a DL_PLANE object representing the triangle's surface
    inline DL_PLANE DL_TRIANGLE3::GetPlane() const
    {
        DL_VECTOR3AL normal = GetNormal();

        return DL_PLANE(DL_VECTOR4(normal));
    }

    // Matrix transformation
    // Origins are positions (W=1), Edges are directions (W=0)
    inline DL_TRIANGLE3 DL_TRIANGLE3::operator * (const DL_MATRIX44& mtx)
    {
        DL_TRIANGLE3 result;
        result.m_Origin = m_Origin.TransformCoord(mtx);
        result.m_Edge[0] = m_Edge[0].TransformNormal(mtx);
        result.m_Edge[1] = m_Edge[1].TransformNormal(mtx);
        return result;
    }

    inline DL_VECTOR3AL DL_TRIANGLE3::ComputePoint(dl_float32 fS, dl_float32 fT) const
    {
        // P = Origin + s*E0 + t*E1
        return m_Origin + (m_Edge[0] * fS) + (m_Edge[1] * fT);
    }

    inline DL_VECTOR3AL DL_TRIANGLE3::GetNormal() const
    {
        // Cross product of edges, normalized
        return (m_Edge[0].Cross(m_Edge[1])).Normalize();
    }

    inline DL_VECTOR3AL DL_TRIANGLE3::GetCenter() const
    {
        // Barycentric: 1/3 * (P0 + P1 + P2) = Origin + 1/3 * (E0 + E1)
        return m_Origin + (m_Edge[0] + m_Edge[1]) * (1.0f / 3.0f);
    }

    inline DL_TRIANGLE3& DL_TRIANGLE3::operator *= (const DL_MATRIX44& mtx)
    {
        m_Origin = m_Origin.TransformCoord(mtx);
        m_Edge[0] = m_Edge[0].TransformNormal(mtx);
        m_Edge[1] = m_Edge[1].TransformNormal(mtx);
        return *this;
    }
}