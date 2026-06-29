#pragma once
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    class DL_RECTANGLE
    {
    public:
        DL_RECTANGLE() = default;
        inline DL_RECTANGLE(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1);
        inline DL_RECTANGLE(const DL_RECTANGLE& rect);

        inline void SetValue(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1);

        void SetOrigin(const DL_VECTOR4AL& vOrig) { m_Origin = vOrig; }
        void SetEdge0(const DL_VECTOR4AL& vEdge0) { m_Edge[0] = vEdge0; }
        void SetEdge1(const DL_VECTOR4AL& vEdge1) { m_Edge[1] = vEdge1; }

        DL_VECTOR4AL GetOrigin() const { return m_Origin; }
        DL_VECTOR4AL GetEdge0() const { return m_Edge[0]; }
        DL_VECTOR4AL GetEdge1() const { return m_Edge[1]; }
        inline DL_VECTOR4AL GetCenter() const;
        inline DL_VECTOR4AL GetNormal() const;

        inline DL_VECTOR4AL ComputePoint(dl_float32 fS, dl_float32 fT) const;

        inline dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pfU = nullptr, dl_float32* pfV = nullptr) const;
        inline dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pfU = nullptr, dl_float32* pfV = nullptr) const;

        inline DL_RECTANGLE& operator *= (const DL_MATRIX44& mtx);
        inline DL_RECTANGLE operator * (const DL_MATRIX44& mtx) const;

    private:
        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Edge[2];
    };
}

#include "DLRectangle.inl"