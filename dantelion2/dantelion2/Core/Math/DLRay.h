#pragma once
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    class DL_RAY
    {
    public:
        DL_RAY() = default;
        DL_RAY(const DL_VECTOR4AL& origin, const DL_VECTOR4AL& direction)
            : m_Origin(origin), m_Dir(direction) {}

        const DL_VECTOR4AL& GetOrigin() const { return m_Origin; }
        const DL_VECTOR4AL& GetDirection() const { return m_Dir; }

        void SetOrigin(const DL_VECTOR4AL& vOrigin) { m_Origin = vOrigin; }
        void SetDirection(const DL_VECTOR4AL& vDirection) { m_Dir = vDirection; }
        void SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection);

        inline dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;
        inline dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;

        // Compute point: P = Origin + t * Dir (clamped t >= 0)
        inline DL_VECTOR4AL ComputePoint(dl_float32 t) const;

        inline DL_RAY& operator *= (const DL_MATRIX44& mtx);
        inline DL_RAY operator * (const DL_MATRIX44& mtx) const;

    private:
        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Dir;
    };
}

#include "DLRay.inl"