#include "DLAABB.h"
#include <algorithm>

namespace DLMT
{
    inline DL_AABB::DL_AABB(DL_VECTOR4AL_PARAMTYPE _min,
        DL_VECTOR4AL_PARAMTYPE _max)
    {
        SetMin(_min);
        SetMax(_max);
    }

    inline DL_AABB::DL_AABB(const DL_AABB& aabb)
    {
        SetMin(aabb.GetMin());
        SetMax(aabb.GetMax());
    }

    inline dl_bool DL_AABB::Contains(DL_VECTOR4AL_PARAMTYPE pt) const
    {
        return (pt.x >= GetMin().x && pt.x <= GetMax().x) &&
            (pt.y >= GetMin().y && pt.y <= GetMax().y) &&
            (pt.z >= GetMin().z && pt.z <= GetMax().z);
    }

    inline dl_bool DL_AABB::Contains(DL_AABB_PARAMTYPE aabb) const
    {
		return Contains(aabb.GetMin()) && Contains(aabb.GetMax());
    }

    inline void DL_AABB::SetMin(DL_VECTOR4AL_PARAMTYPE vMin)
    {
        m_Min = vMin;
    }

    inline void DL_AABB::SetMax(DL_VECTOR4AL_PARAMTYPE vMax)
    {
        m_Max = vMax;
    }

    inline void DL_AABB::SetMinMax(DL_VECTOR4AL_PARAMTYPE vMin,
        DL_VECTOR4AL_PARAMTYPE vMax)
    {
        SetMin(vMin);
        SetMax(vMax);
    }

    inline void DL_AABB::SetCenterExtents(
        DL_VECTOR4AL_PARAMTYPE vCenter,
        DL_VECTOR4AL_PARAMTYPE vExtents)
    {
        SetMin(DL_VECTOR4AL(vCenter - vExtents));
        SetMax(vCenter + vExtents);
    }

    inline void DL_AABB::SetEmpty(void)
    {
        SetMin(DL_VECTOR4AL(0.f, 0.f, 0.f, 0.0f));
        SetMax(DL_VECTOR4AL(0.f, 0.f, 0.f, 0.0f));
    }

    inline void DL_AABB::SetVector(DL_VECTOR4AL_PARAMTYPE pt)
    {
        SetMin(pt);
        SetMax(pt);
    }

    inline void DL_AABB::GetMinMax(DL_VECTOR4AL& vMin,
        DL_VECTOR4AL& vMax) const
    {
        vMin = GetMin();
        vMax = GetMax();
    }

    inline void DL_AABB::GetCenterExtents(
        DL_VECTOR4AL& vCenter,
        DL_VECTOR4AL& vExtents) const
    {
        vCenter = (GetMin() + GetMax()) * 0.5f;
        vExtents = GetMax() - vCenter;
    }

    inline DL_VECTOR4AL& DL_AABB::GetMin(DL_VECTOR4AL& vMin) const
    {
        vMin = GetMin();
        return vMin;
    }

    inline DL_VECTOR4AL& DL_AABB::GetMax(DL_VECTOR4AL& vMax) const
    {
        vMax = GetMax();
        return vMax;
    }

    inline DL_VECTOR4AL DL_AABB::GetMin(void)
    {
        return m_Min;
    }

    inline DL_VECTOR4AL DL_AABB::GetMax(void)
    {
        return m_Max;
    }

    inline const DL_VECTOR4AL& DL_AABB::GetMin(void) const
    {
        return m_Min;
    }

    inline const DL_VECTOR4AL& DL_AABB::GetMax(void) const
    {
        return m_Max;
    }

    inline dl_float32 DL_AABB::GetMin(DL_AABB::AxisCompornent axis) const
    {
        return m_Min[axis];
    }

    inline dl_float32 DL_AABB::GetMax(DL_AABB::AxisCompornent axis) const
    {
        return m_Max[axis];
    }

    inline DL_VECTOR4AL& DL_AABB::GetCenter(DL_VECTOR4AL& vCenter) const
    {
        vCenter = GetCenter();
        return vCenter;
    }

    inline DL_VECTOR4AL& DL_AABB::GetExtents(DL_VECTOR4AL& vExtents) const
    {
        vExtents = GetExtents();
        return vExtents;
    }

    inline DL_VECTOR4AL DL_AABB::GetCenter(void) const
    {
        return (GetMin() + GetMax()) * 0.5f;
    }

    inline DL_VECTOR4AL DL_AABB::GetExtents(void) const
    {
        return (GetMax() - GetMin()) * 0.5f;
    }

    inline dl_float32 DL_AABB::GetCenter(DL_AABB::AxisCompornent axis) const
    {
        DL_VECTOR4AL v;
        return GetCenter(v)[axis];
    }

    inline dl_float32 DL_AABB::GetExtents(DL_AABB::AxisCompornent axis) const
    {
        DL_VECTOR4AL v;
        return GetExtents(v)[axis];
    }

    inline DL_VECTOR4AL DL_AABB::GetDiagonal() const
    {
        return GetMax() - GetMin();
    }

    inline dl_float32 DL_AABB::GetWidth(void) const
    {
        return (GetMax().x - GetMin().x);
    }

    inline dl_float32 DL_AABB::GetHeight(void) const
    {
        return (GetMax().y - GetMin().y);
    }

    inline dl_float32 DL_AABB::GetDepth(void) const
    {
        return (GetMax().z - GetMin().z);
    }

    inline dl_float32 DL_AABB::GetVolume(void) const
    {
        return GetWidth() * GetHeight() * GetDepth();
    }

    inline void DL_AABB::ExtendBy(DL_VECTOR4AL_PARAMTYPE pt)
    {
        DL_VECTOR4AL vMin = GetMin();
        DL_VECTOR4AL vMax = GetMax();

        // The parentheses around (std::min) and (std::max) stop macro expansion
        SetMin(DL_VECTOR4AL(
            (std::min)(vMin.x, pt.x),
            (std::min)(vMin.y, pt.y),
            (std::min)(vMin.z, pt.z),
            vMin.w
        ));

        SetMax(DL_VECTOR4AL(
            (std::max)(vMax.x, pt.x),
            (std::max)(vMax.y, pt.y),
            (std::max)(vMax.z, pt.z),
            vMax.w
        ));
    }

    inline void DL_AABB::ExtendBy(DL_AABB_PARAMTYPE aabb)
    {
        // Expand this box to encompass the other 'aabb'
        DL_VECTOR4AL ourMin = GetMin();
        DL_VECTOR4AL ourMax = GetMax();
        const DL_VECTOR4AL& otherMin = aabb.GetMin();
        const DL_VECTOR4AL& otherMax = aabb.GetMax();

        SetMin(DL_VECTOR4AL(
            (std::min)(ourMin.x, otherMin.x),
            (std::min)(ourMin.y, otherMin.y),
            (std::min)(ourMin.z, otherMin.z),
            ourMin.w
        ));

        SetMax(DL_VECTOR4AL(
            (std::max)(ourMax.x, otherMax.x),
            (std::max)(ourMax.y, otherMax.y),
            (std::max)(ourMax.z, otherMax.z),
            ourMax.w
        ));
    }

    inline DL_AABB DL_AABB::Transform(DL_MATRIX44_PARAMTYPE mtx) const
    {
        DL_AABB result;

        // 1. Start the new AABB by transforming the original Min point.
        // In your original code, DL_SELECT_1110 was used to ensure W=1 for the translation.
        DL_VECTOR4AL originalMin = GetMin();
        DL_VECTOR4 vMin4(originalMin.x, originalMin.y, originalMin.z, 1.0f);

        // Transform the point by the matrix (Translation + Rotation/Scale)
        DL_VECTOR4AL vMin = DL_VECTOR4AL(vMin4 * mtx);

        // Initialize result with the transformed min point
        result.SetMin(vMin);
        result.SetMax(vMin);

        // 2. Calculate the "Delta" (Diagonal) of the box
        DL_VECTOR4AL minPt = GetMin();
        DL_VECTOR4AL maxPt = GetMax();
        float dx = maxPt.x - minPt.x;
        float dy = maxPt.y - minPt.y;
        float dz = maxPt.z - minPt.z;

        // 3. Get the basis vectors from the matrix (rows 0, 1, 2)
        DL_VECTOR4AL vX, vY, vZ;
        mtx.GetRow(vX, 0);
        mtx.GetRow(vY, 1);
        mtx.GetRow(vZ, 2);

        // 4. Scale basis vectors by the box dimensions
        // These represent the three edges of the box meeting at 'min'
        vX = DL_VECTOR4AL(vX * dx);
        vY = DL_VECTOR4AL(vY * dy);
        vZ = DL_VECTOR4AL(vZ * dz);

        // 5. Accumulate the bounds. 
        // For each axis, we check if the transformed edge is positive or negative.
        auto AccumulateAxis = [&](const DL_VECTOR4AL& edge) {
            DL_VECTOR4AL currentMin = result.GetMin();
            DL_VECTOR4AL currentMax = result.GetMax();

            // X Component of edge
            if (edge.x < 0.0f) currentMin.x += edge.x; else currentMax.x += edge.x;
            // Y Component of edge
            if (edge.y < 0.0f) currentMin.y += edge.y; else currentMax.y += edge.y;
            // Z Component of edge
            if (edge.z < 0.0f) currentMin.z += edge.z; else currentMax.z += edge.z;

            result.SetMin(currentMin);
            result.SetMax(currentMax);
            };

        AccumulateAxis(vX);
        AccumulateAxis(vY);
        AccumulateAxis(vZ);

        return result;
    }

    inline dl_bool DL_AABB::IsValid(void) const
    {
        const DL_VECTOR4AL& vMin = GetMin();
        const DL_VECTOR4AL& vMax = GetMax();

        if (vMax.x < vMin.x) return false;
        if (vMax.y < vMin.y) return false;
        if (vMax.z < vMin.z) return false;

        return true;
    }

    inline DL_AABB& DL_AABB::operator *= (dl_float32 s)
    {
        DL_VECTOR4AL vCenter, vExtents;
        GetCenterExtents(vCenter, vExtents);
        SetCenterExtents(vCenter, vExtents * s);
        return *this;
    }

    inline DL_AABB& DL_AABB::operator *= (DL_MATRIX44_PARAMTYPE mtx)
    {
        *this = Transform(mtx);
        return *this;
    }

    inline DL_AABB& DL_AABB::operator /= (dl_float32 s)
    {
        DL_VECTOR4AL vCenter, vExtents;
        GetCenterExtents(vCenter, vExtents);
        SetCenterExtents(vCenter, vExtents / s);
        return *this;
    }

    inline DL_AABB& DL_AABB::operator += (DL_VECTOR4AL_PARAMTYPE vTrans)
    {
        SetMin(GetMin() + vTrans);
        SetMax(GetMax() + vTrans);
        return *this;
    }

    inline DL_AABB DL_AABB::operator * (dl_float32 s)
    {
        DL_AABB aabb;
        DL_VECTOR4AL vCenter, vExtents;
        GetCenterExtents(vCenter, vExtents);
        aabb.SetCenterExtents(vCenter, vExtents * s);
        return aabb;
    }

    inline DL_AABB DL_AABB::operator * (DL_MATRIX44_PARAMTYPE mtx)
    {
        return Transform(mtx);
    }
}