#include "DLLinear.h"

namespace DLMT
{
    inline dl_float32 DL_PLANE::DotCoord(const DL_VECTOR4AL& pt) const
    {
        return m_Plane.Dot(pt);
    }

    inline void DL_PLANE::Transform(const DL_MATRIX44& mtx)
    {
        m_Plane = m_Plane.TransformCoord(mtx);
    }
}