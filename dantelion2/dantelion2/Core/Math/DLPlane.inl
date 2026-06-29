#include "DLPlane.h"

namespace DLMT
{
    inline dl_float32 DL_PLANE::DotCoord(const DL_VECTOR4AL& pt) const
    {
        return m_Normal.Dot(pt) + m_Dist;
    }

    inline void DL_PLANE::Transform(const DL_MATRIX44& mtx)
    {
        m_Normal = m_Normal.TransformNormal(mtx).Normalize();
    }
}