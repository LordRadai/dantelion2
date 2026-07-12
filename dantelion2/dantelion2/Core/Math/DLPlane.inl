#include "DLLinear.h"
#include "DLLinearIntrinsic.h"

#include <limits>

namespace DLMT
{
    inline DL_PLANE::DL_PLANE(dl_float32 nx, dl_float32 ny, dl_float32 nz, dl_float32 d)
    {
        SetValue(nx, ny, nz, d);
    }

    inline DL_PLANE::DL_PLANE(DL_VECTOR4AL_PARAMTYPE pt,
        DL_VECTOR4AL_PARAMTYPE n)
    {
        *this = DLIPlane::FromPointNormal(pt, n);
    }

    inline DL_PLANE::DL_PLANE(DL_VECTOR4AL_PARAMTYPE p0,
        DL_VECTOR4AL_PARAMTYPE p1,
        DL_VECTOR4AL_PARAMTYPE p2)
    {
        *this = DLIPlane::FromPoints(p0, p1, p2);
    }

    inline DL_PLANE::DL_PLANE(DL_VECTOR4AL_PARAMTYPE plane)
    {
        m_Plane = plane;
    }

    inline DL_PLANE::DL_PLANE(const DL_PLANE& plane)
    {
        m_Plane = plane.m_Plane;
    }

    inline void DL_PLANE::SetValue(dl_float32 nx, dl_float32 ny, dl_float32 nz, dl_float32 d)
    {
        m_Plane = DL_VECTOR4(nx, ny, nz, d);
    }

    inline void DL_PLANE::SetValue(DL_VECTOR4AL_PARAMTYPE pt,
        DL_VECTOR4AL_PARAMTYPE n)
    {
        *this = DLIPlane::FromPointNormal(pt, n);
    }

    inline void DL_PLANE::SetValue(DL_VECTOR4AL_PARAMTYPE p0,
        DL_VECTOR4AL_PARAMTYPE p1,
        DL_VECTOR4AL_PARAMTYPE p2)
    {
        *this = DLIPlane::FromPoints(p0, p1, p2);
    }

    inline void DL_PLANE::SetValue(DL_VECTOR4AL_PARAMTYPE plane)
    {
        m_Plane = plane;
    }

    inline dl_float32 DL_PLANE::GetDistance(DL_VECTOR4AL_PARAMTYPE pt) const
    {
        return DLIPlane::DotCoord(*this, pt);
    }

    inline dl_bool DL_PLANE::Belongs(DL_VECTOR4AL_PARAMTYPE pt) const
    {
        return (dl_bool)(fabs(GetDistance(pt)) < FLT_EPSILON);
    }

    inline void DL_PLANE::Normalize(void)
    {
        *this = DLIPlane::Normalize(*this);
    }

    inline DL_PLANE DL_PLANE::Normalize(void) const
    {
        return DLIPlane::Normalize(*this);
    }

    inline DL_PLANE::operator DL_VECTOR3AL& ()
    {
        return *reinterpret_cast<DL_VECTOR3AL*>(&m_Plane);
    }

    inline DL_PLANE::operator const DL_VECTOR3AL& () const
    {
        return *reinterpret_cast<const DL_VECTOR3AL*>(&m_Plane);
    }

    inline DL_PLANE::operator DL_VECTOR4AL& ()
    {
        return m_Plane;
    }

    inline DL_PLANE::operator const DL_VECTOR4AL& () const
    {
        return m_Plane;
    }

    inline DL_VECTOR4AL DL_PLANE::GetNormal(void) const
    {
        return DLMT::DL_VECTOR4AL(m_Plane.x, m_Plane.y, m_Plane.z, 1.0f);
    }

    inline void DL_PLANE::SetNormal(DL_VECTOR4AL_PARAMTYPE Normal)
    {
        DL_VECTOR4AL normalized = DLMT::DL_VECTOR4AL(Normal.x, Normal.y, Normal.z, 1.0f);
        m_Plane = DLMT::DL_VECTOR4AL(normalized.x, normalized.y, normalized.z, m_Plane.w);
    }

    inline dl_float32 DL_PLANE::GetDist(void) const
    {
        return m_Plane.w;
    }

    inline void DL_PLANE::SetDist(dl_float32 Dist)
    {
        DL_VECTOR4AL vDist = DL_VECTOR4AL(m_Plane.x, m_Plane.y, m_Plane.z, Dist);
        m_Plane = vDist;
    }

    inline DL_PLANE& DL_PLANE::operator *= (DL_MATRIX44_PARAMTYPE mtx)
    {
        DL_MATRIX44 mT = mtx.Transpose();
        DL_MATRIX44 mInvT = mT.Inverse();

        *this = DLIPlane::Transform(*this, mInvT);
        return *this;
    }

    inline DL_PLANE DL_PLANE::operator * (DL_MATRIX44_PARAMTYPE mtx) const
    {
        DL_MATRIX44 mT = mtx.Transpose();
        DL_MATRIX44 mInvT = mT.Inverse();

        return DLIPlane::Transform(*this, mInvT);
    }

    inline dl_bool DL_PLANE::operator == (DL_PLANE_PARAMTYPE rhs) const
    {
        return m_Plane == rhs.m_Plane;
    }

    inline dl_bool DL_PLANE::operator != (DL_PLANE_PARAMTYPE rhs) const
    {
        return m_Plane != rhs.m_Plane;
    }
}