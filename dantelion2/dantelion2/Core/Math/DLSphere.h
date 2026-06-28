#pragma once
#include "Core/Platform/Platform.h"
#include "DLVector.h"

#include "DLAABB.h"
#include "DLOBB.h"

namespace DLMT
{
    class DL_SPHERE 
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
        typedef const DL_SPHERE& DL_SPHERE_PARAMTYPE;
		typedef const DL_AABB& DL_AABB_PARAMTYPE;
		typedef const DL_OBB& DL_OBB_PARAMTYPE;
    public:
        // --- Constructors ---
        DL_SPHERE() = default;

        inline DL_SPHERE(DL_VECTOR4AL_PARAMTYPE vCenter, dl_float32 fRadius);
        inline DL_SPHERE(const DL_SPHERE& sphere);
        inline DL_SPHERE(const DL_VECTOR3* pVerts, dl_uint32 uiNum);

        // --- Setters ---
        inline void SetValue(DL_VECTOR4AL_PARAMTYPE vCenter, dl_float32 fRadius);
        inline void SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        inline void SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);
        inline void SetEmpty(void);

        // --- Geometry Extension ---
        // Expands the sphere to include additional geometry
        inline void ExtendBy(DL_VECTOR4AL_PARAMTYPE pt);
        inline void ExtendBy(DL_SPHERE_PARAMTYPE sphere);
        inline void ExtendBy(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        inline void ExtendBy(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);
        inline void ExtendBy(DL_AABB_PARAMTYPE aabb);
        inline void ExtendBy(DL_OBB_PARAMTYPE obb);

        // --- Queries ---
        inline dl_bool Contains(DL_VECTOR4AL_PARAMTYPE pt) const;
        inline dl_bool Contains(DL_SPHERE_PARAMTYPE sphere) const;

        // --- Getters/Setters ---
        inline DL_VECTOR4AL GetCenter(void) const;
        inline void SetCenter(DL_VECTOR4AL_PARAMTYPE vCenter);

        inline dl_float32 GetRadius(void) const;
        inline dl_float32 GetRadiusSq(void) const;
        inline void SetRadius(dl_float32 Radius);

        // --- Operators ---
        inline DL_SPHERE& operator *= (DL_MATRIX44_PARAMTYPE mtx);
        inline DL_SPHERE operator * (DL_MATRIX44_PARAMTYPE mtx) const;

    private:
        DL_VECTOR4AL m_Sphere;
    };
}