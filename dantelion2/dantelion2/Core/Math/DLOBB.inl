#pragma once
#include "DLLinear.h"

#include <limits>

namespace DLMT
{
// --- Initialization ---
inline void DL_OBB::SetEmpty()
{
    SetXform(DL_IDENTITY_MATRIX44);
    // Use the explicit DL_VECTOR4 constructor instead of internal floating point access
    SetExtents(DL_VECTOR4(-FLT_MAX, -FLT_MAX, -FLT_MAX, 0.0f));
}

// --- Setters ---

inline void DL_OBB::SetValue(DL_AABB_PARAMTYPE aabb, DL_MATRIX44_PARAMTYPE mtx)
{
    DL_VECTOR4AL vCenter, vExtents;
    aabb.GetCenterExtents(vCenter, vExtents);

    // Using the vector component-wise select or constructor logic
    vCenter = DL_VECTOR4(vCenter.x, vCenter.y, vCenter.z, 1.0f);

    SetExtents(vExtents);
    SetXform(mtx);
    SetCenter(vCenter * mtx);
}

inline void DL_OBB::SetValue(DL_VECTOR4AL_PARAMTYPE vExtents, DL_MATRIX44_PARAMTYPE Xform)
{
    SetExtents(vExtents);
    SetXform(Xform);
}

inline void DL_OBB::SetValue(DL_VECTOR4AL_PARAMTYPE vExtents, DL_VECTOR4AL_PARAMTYPE vCenter, DL_MATRIX33_PARAMTYPE mRot)
{
    SetExtents(vExtents);
    SetXform(DL_MATRIX44(mRot));
    SetCenter(vCenter);
}

// --- Transformations ---

inline void DL_OBB::Transform(DL_OBB& obb, DL_MATRIX44_PARAMTYPE mtx) const
{
    obb.SetExtents(GetExtents());
    obb.SetXform(GetXform() * mtx);
}

// --- Direct Accessors ---

inline void DL_OBB::SetCenter(DL_VECTOR4AL_PARAMTYPE vCenter)
{
    // Accessing the row directly via the updated matrix structure
    m_Xform.R[3] = vCenter;
}

inline void DL_OBB::SetExtents(DL_VECTOR4AL_PARAMTYPE vExtents)
{
    m_Extents = vExtents;
}

inline void DL_OBB::SetXform(DL_MATRIX44_PARAMTYPE mXform)
{
    m_Xform = mXform;
}

inline void DL_OBB::SetRotation(DL_MATRIX34_PARAMTYPE mRot)
{
    // Using the new structure, we map the rotation components cleanly
    // Assuming m_Xform is a DL_MATRIX44, we update the rotation part (3x3 or 3x4)
    for (int i = 0; i < 3; ++i) {
        m_Xform.R[i] = DL_VECTOR4(mRot.R[i].x, mRot.R[i].y, mRot.R[i].z, m_Xform.R[i].w);
    }
}

// --- Getters ---

inline const DL_VECTOR4AL& DL_OBB::GetCenter() const
{
    return m_Xform.R[3];
}

inline const DL_VECTOR4AL& DL_OBB::GetExtents() const
{
    return m_Extents;
}

inline const DL_MATRIX44& DL_OBB::GetXform() const
{
    return m_Xform;
}

inline const DL_VECTOR4AL& DL_OBB::GetAxis(DL_AABB::AxisCompornent axis) const
{
    return m_Xform.R[axis];
}

// --- Operators ---

inline DL_OBB& DL_OBB::operator*=(DL_MATRIX44_PARAMTYPE mtx)
{
    SetXform(GetXform() * mtx);
    return *this;
}

inline DL_OBB DL_OBB::operator*(DL_MATRIX44_PARAMTYPE mtx) const
{
    DL_OBB obb;
    obb.SetXform(GetXform() * mtx);
    obb.SetExtents(GetExtents());
    return obb;
}
} // namespace DLMT