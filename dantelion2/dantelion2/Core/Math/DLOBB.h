#pragma once
#include "DLVector.h"
#include "DLMatrix.h"
#include "DLAABB.h"

namespace DLMT
{
    class DL_OBB 
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE;
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE;
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE;
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE;
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE;
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE;
		typedef const DL_MATRIX34& DL_MATRIX34_PARAMTYPE;
        typedef const DL_MATRIX44& DL_MATRIX44_PARAMTYPE;
        typedef const DL_AABB& DL_AABB_PARAMTYPE;
        typedef const DL_OBB& DL_OBB_PARAMTYPE;
    public:
        // --- Initialization & State ---
        inline void SetEmpty(void);

        // --- Setters ---
        inline void SetValue(DL_AABB_PARAMTYPE aabb, DL_MATRIX44_PARAMTYPE mtx);
        inline void SetValue(DL_VECTOR4AL_PARAMTYPE vExtents, DL_MATRIX44_PARAMTYPE Xform);
        inline void SetValue(DL_VECTOR4AL_PARAMTYPE vExtents, DL_VECTOR4AL_PARAMTYPE vCenter, DL_MATRIX33_PARAMTYPE mRot);

        inline void SetCenter(DL_VECTOR4AL_PARAMTYPE vCenter);
        inline void SetExtents(DL_VECTOR4AL_PARAMTYPE vExtents);
        inline void SetXform(DL_MATRIX44_PARAMTYPE mXform);
        inline void SetRotation(DL_MATRIX34_PARAMTYPE mRot);

        // --- Getters ---
        inline const DL_VECTOR4AL& GetCenter(void) const;
        inline const DL_VECTOR4AL& GetExtents(void) const;
        inline const DL_MATRIX44& GetXform(void) const;
        inline const DL_VECTOR4AL& GetAxis(DL_AABB::AxisCompornent axis) const;

        // --- Operations ---
        inline void Transform(DL_OBB& obb, DL_MATRIX44_PARAMTYPE mtx) const;

        // --- Operators ---
        inline DL_OBB& operator *= (DL_MATRIX44_PARAMTYPE mtx);
        inline DL_OBB operator * (DL_MATRIX44_PARAMTYPE mtx) const;

    private:
        DL_MATRIX44 m_Xform;
        DL_VECTOR4AL m_Extents;
    };
}