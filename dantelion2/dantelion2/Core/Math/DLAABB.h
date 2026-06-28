#pragma once
#include "Core/Platform/Platform.h"
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
	class DL_AABB
	{
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE;
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE;
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE;
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE;
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE;
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE;
        typedef const DL_MATRIX44& DL_MATRIX44_PARAMTYPE;
        typedef const DL_AABB& DL_AABB_PARAMTYPE;
    public:
        enum AxisCompornent
        {
            AxisX = 0,
            AxisY = 1,
            AxisZ = 2,
            AxisW = 3
        };

        // Constructors
        DL_AABB(void) {}
        inline DL_AABB(DL_VECTOR4AL_PARAMTYPE _min, DL_VECTOR4AL_PARAMTYPE _max);
        inline DL_AABB(const DL_AABB& aabb);
        ~DL_AABB(void) {}

        // Containment and Validity
        inline dl_bool Contains(DL_VECTOR4AL_PARAMTYPE pt) const;
        inline dl_bool Contains(DL_AABB_PARAMTYPE aabb) const;
        inline dl_bool IsValid(void) const;

        // Setters
        inline void SetMin(DL_VECTOR4AL_PARAMTYPE vMin);
        inline void SetMax(DL_VECTOR4AL_PARAMTYPE vMax);
        inline void SetMinMax(DL_VECTOR4AL_PARAMTYPE vMin, DL_VECTOR4AL_PARAMTYPE vMax);
        inline void SetCenterExtents(DL_VECTOR4AL_PARAMTYPE vCenter, DL_VECTOR4AL_PARAMTYPE vExtents);
        inline void SetEmpty(void);
        inline void SetVector(DL_VECTOR4AL_PARAMTYPE pt);

        // Getters
        inline void GetMinMax(DL_VECTOR4AL& vMin, DL_VECTOR4AL& vMax) const;
        inline void GetCenterExtents(DL_VECTOR4AL& vCenter, DL_VECTOR4AL& vExtents) const;

        inline DL_VECTOR4AL& GetMin(DL_VECTOR4AL& vMin) const;
        inline DL_VECTOR4AL& GetMax(DL_VECTOR4AL& vMax) const;

        inline DL_VECTOR4AL GetMin(void);
        inline DL_VECTOR4AL GetMax(void);
        inline const DL_VECTOR4AL& GetMin(void) const;
        inline const DL_VECTOR4AL& GetMax(void) const;

        inline dl_float32 GetMin(AxisCompornent axis) const;
        inline dl_float32 GetMax(AxisCompornent axis) const;

        // Center & Extents
        inline DL_VECTOR4AL& GetCenter(DL_VECTOR4AL& vCenter) const;
        inline DL_VECTOR4AL& GetExtents(DL_VECTOR4AL& vExtents) const;
        inline DL_VECTOR4AL GetCenter(void) const;
        inline DL_VECTOR4AL GetExtents(void) const;
        inline dl_float32 GetCenter(AxisCompornent axis) const;
        inline dl_float32 GetExtents(AxisCompornent axis) const;

        // Geometry
        inline DL_VECTOR4AL GetDiagonal() const;
        inline dl_float32 GetWidth(void) const;
        inline dl_float32 GetHeight(void) const;
        inline dl_float32 GetDepth(void) const;
        inline dl_float32 GetVolume(void) const;

        // Modification
        inline void ExtendBy(DL_VECTOR4AL_PARAMTYPE pt);
        inline void ExtendBy(DL_AABB_PARAMTYPE aabb);
        inline DL_AABB Transform(DL_MATRIX44_PARAMTYPE mtx) const;

        // Operators
        inline DL_AABB& operator *= (dl_float32 s);
        inline DL_AABB& operator *= (DL_MATRIX44_PARAMTYPE mtx);
        inline DL_AABB& operator /= (dl_float32 s);
        inline DL_AABB& operator += (DL_VECTOR4AL_PARAMTYPE vTrans);
        inline DL_AABB operator * (dl_float32 s);
        inline DL_AABB operator * (DL_MATRIX44_PARAMTYPE mtx);

    private:
        DL_VECTOR4AL m_Min;
        DL_VECTOR4AL m_Max;
	};
}

#include "DLAABB.inl"