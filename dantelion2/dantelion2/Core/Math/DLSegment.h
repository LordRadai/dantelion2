#pragma once
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    class DL_SEGMENT
    {
		typedef const DL_VECTOR4AL& DL_VECTOR4AL_PARAMTYPE;
		typedef const DL_MATRIX44& DL_MATRIX44_PARAMTYPE;
    public:
		DL_SEGMENT() = default;
		DL_SEGMENT(DL_VECTOR4AL_PARAMTYPE vOrigin, DL_VECTOR4AL_PARAMTYPE vDirection) : m_Origin(vOrigin), m_Dir(vDirection) {}

        // Accessors
        inline const DL_VECTOR4AL& GetOrigin() const;
        inline const DL_VECTOR4AL& GetDirection() const;
        inline void GetDirection(DL_VECTOR4AL& _dir) const;

        inline DL_VECTOR4AL GetEndPoint() const;
        inline DL_VECTOR4AL GetCenter() const;
        inline dl_float32 GetLength() const;
        inline dl_float32 GetLengthSq() const;

        // Mutators
        inline void SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection);
        inline void SetPoints(const DL_VECTOR4AL& vPt0, const DL_VECTOR4AL& vPt1);
        inline void SetOrigin(const DL_VECTOR4AL& vOrigin);
        inline void SetDirection(const DL_VECTOR4AL& vDirection);
        inline void SetEndPoint(const DL_VECTOR4AL& vEndPoint);

        // Geometry Operations
        inline DL_VECTOR4AL ComputePoint(dl_float32 t) const;
        inline dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;
        inline dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;

        // Operators
        inline DL_SEGMENT& operator*=(const DL_MATRIX44& mtx);
        inline DL_SEGMENT operator*(const DL_MATRIX44& mtx) const;

    private:
        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Dir;
    };
}

#include "DLSegment.inl"