#pragma once
#include "DLVector.h"
#include "DLMatrix.h"
#include "DLPlane.h"

namespace DLMT
{
    class DL_TRIANGLE
    {
    public:
        DL_TRIANGLE() = default;
        DL_TRIANGLE(const DL_VECTOR4AL pt[3]);
        DL_TRIANGLE(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1);

        void SetPoints(const DL_VECTOR4AL pt[3]);
        DL_VECTOR4AL ComputePoint(dl_float32 fS, dl_float32 fT) const;
        DL_VECTOR4AL GetNormal() const;
        DL_VECTOR4AL GetCenter() const;
        DL_PLANE GetPlane() const;

        DL_TRIANGLE& operator *= (const DL_MATRIX44& mtx);
        DL_TRIANGLE operator * (const DL_MATRIX44& mtx);

		DL_VECTOR4AL GetEdge(dl_uint32 index) const { return m_Edge[index]; }
		DL_VECTOR4AL GetOrigin() const { return m_Origin; }
    protected:
        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Edge[2];
    };

    class DL_TRIANGLE3 : public DL_TRIANGLE { /* ... specific storage overrides ... */ };
}

#include "DLTriangle.inl"