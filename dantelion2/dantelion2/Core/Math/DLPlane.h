#pragma once
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    class DL_PLANE
    {
    public:
        DL_PLANE() : m_Normal(0.0f, 1.0f, 0.0f, 0.0f), m_Dist(0.0f) {}
        DL_PLANE(const DL_VECTOR4AL& normal, dl_float32 dist)
            : m_Normal(normal), m_Dist(dist) {}

        const DL_VECTOR4AL& GetNormal() const { return m_Normal; }
        dl_float32 GetDist() const { return m_Dist; }

        void SetNormal(const DL_VECTOR4AL& normal) { m_Normal = normal; }
        void SetDist(dl_float32 dist) { m_Dist = dist; }

        // Distance from point to plane
        inline dl_float32 DotCoord(const DL_VECTOR4AL& pt) const;

        // Transform plane by matrix: Normal * M^-T, Dist update
        inline void Transform(const DL_MATRIX44& mtx);
    private:
        DL_VECTOR4AL m_Normal; // Plane normal (usually normalized)
        dl_float32   m_Dist;   // Plane constant
    };
}

#include "DLPlane.inl"