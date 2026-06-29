#pragma once
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    class DL_LINE
    {
    public:
        DL_LINE() = default;
        DL_LINE(const DL_VECTOR4AL& origin, const DL_VECTOR4AL& direction)
            : m_Origin(origin), m_Dir(direction) {}

        const DL_VECTOR4AL& GetOrigin() const { return m_Origin; }
        const DL_VECTOR4AL& GetDirection() const { return m_Dir; }

        void SetOrigin(const DL_VECTOR4AL& vOrigin) { m_Origin = vOrigin; }
        void SetDirection(const DL_VECTOR4AL& vDirection) { m_Dir = vDirection; }
        void SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection);

        // Distance calculations (Delegated to external utility if needed)
        dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;
        dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;

        // Point computation: P = Origin + t * Dir
        DL_VECTOR4AL ComputePoint(dl_float32 t) const;

        // Transformation operators
        DL_LINE& operator *= (const DL_MATRIX44& mtx);
        DL_LINE operator * (const DL_MATRIX44& mtx) const;

    private:
        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Dir;
    };
}