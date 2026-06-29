#pragma once
#include "DLVector.h"
#include "DLMatrix.h"
#include "DLRectangle.h"

namespace DLMT
{
    class DL_RSS : public DL_RECTANGLE
    {
    public:
        inline DL_RSS() = default;
        inline DL_RSS(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0,
            const DL_VECTOR4AL& vEdge1, dl_float32 fRadius);
        inline DL_RSS(const DL_RSS& rss);

        // Constructors from point clouds (Placeholder for logic)
        inline DL_RSS(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        inline DL_RSS(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);

        inline void SetValue(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0,
            const DL_VECTOR4AL& vEdge1, dl_float32 fRadius);

        inline void SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        inline void SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);

        dl_float32 GetRadius() const { return m_Radius; }
        dl_float32 GetRadiusSq() const { return m_Radius * m_Radius; }
        void SetRadius(dl_float32 radius) { m_Radius = radius; }

    private:
        dl_float32 m_Radius;
    };
}

#include "DLRSS.inl"