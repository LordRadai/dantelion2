#pragma once
#include "DLSphere.h"

#include <cmath>

namespace DLMT
{
    inline DL_SPHERE::DL_SPHERE(DL_VECTOR4AL_PARAMTYPE vCenter,
        dl_float32 fRadius)
    {
		m_Sphere = DL_VECTOR4AL(vCenter.x, vCenter.y, vCenter.z, fRadius);
    }

    inline DL_SPHERE::DL_SPHERE(const DL_SPHERE& sphere)
    {
        m_Sphere = sphere.m_Sphere;
    }

    inline DL_SPHERE::DL_SPHERE(const DL_VECTOR3* pVerts,
        dl_uint32 uiNum)
    {
        SetEmpty();
        ExtendBy(pVerts, uiNum);
    }

    inline void DL_SPHERE::SetValue(DL_VECTOR4AL_PARAMTYPE vCenter,
        dl_float32 fRadius)
    {
		m_Sphere = DL_VECTOR4AL(vCenter.x, vCenter.y, vCenter.z, fRadius);
    }

    inline void DL_SPHERE::SetValue(const DL_VECTOR3* pVerts,
        dl_uint32 uiNum)
    {
        SetEmpty();
        ExtendBy(pVerts, uiNum);
    }

    inline void DL_SPHERE::SetValue(const DL_VECTOR4AL* pVerts,
        dl_uint32 uiNum)
    {
        SetEmpty();
        ExtendBy(pVerts, uiNum);
    }

    inline void DL_SPHERE::ExtendBy(DL_VECTOR4AL_PARAMTYPE pt)
    {
        // Get current sphere data
        DL_VECTOR4AL center = GetCenter(); // Assuming this returns a DL_VECTOR4AL
        dl_float32 radius = m_Sphere.w;

        // Calculate vector from center to point
        DL_VECTOR4AL D = pt - center;
        dl_float32 lenSq = D.LengthSq();

        // Check if the point is outside the current sphere
        if (lenSq > (radius * radius))
        {
            dl_float32 len = std::sqrtf(lenSq);

            // Calculate new radius: average of old radius and distance
            dl_float32 newRadius = (radius + len) * 0.5f;

            // Calculate new center
            // C = Center + (D / len) * (len - newRadius)
            DL_VECTOR4AL direction = D / len;
            DL_VECTOR4AL newCenter = center + direction * (len - newRadius);

            // Update sphere (assuming m_Sphere is a DL_VECTOR4AL)
            m_Sphere = DL_VECTOR4AL(newCenter.x, newCenter.y, newCenter.z, newRadius);
        }
    }

    inline void DL_SPHERE::ExtendBy(DL_SPHERE_PARAMTYPE sphere)
    {
        DL_VECTOR4AL vDiff = sphere.GetCenter() - GetCenter();
        dl_float32 len = vDiff.Length();
        dl_float32 radius0 = GetRadius();
        dl_float32 radius1 = sphere.GetRadius();

        if (radius1 + len < radius0)
        {
            return;
        }
        if (radius0 + len < radius1)
        {
            (*this) = sphere;
            return;
        }

        dl_float32 rad = radius0;
        radius0 = (len + radius0 + radius1) * 0.5f;

        vDiff /= len;

        SetCenter(GetCenter() + (radius0 - rad) * vDiff);
        SetRadius(radius0);
    }

    inline void DL_SPHERE::ExtendBy(const DLMT::DL_VECTOR3* pVerts, dl_uint32 uiNum)
    {
        if (uiNum == 0) return;

        dl_uint32 iVert0 = 0, iVert1 = 0;
        dl_float32 fMinSqrLen = 0.0f;

        // Find the two furthest points to initialize the sphere
        for (dl_uint32 i = 0; i < uiNum; i++)
        {
            for (dl_uint32 j = i + 1; j < uiNum; j++)
            {
                dl_float32 fSqrLen = (pVerts[i] - pVerts[j]).LengthSquared();
                if (fMinSqrLen < fSqrLen)
                {
                    fMinSqrLen = fSqrLen;
                    iVert0 = i;
                    iVert1 = j;
                }
            }
        }

        // Initialize sphere with the two furthest points
        // Note: Assuming SetEmpty() sets radius to a negative value or 0
        DL_SPHERE sp;
        sp.SetEmpty();

        // Convert DL_VECTOR3 to DL_VECTOR4AL
        sp.ExtendBy(DL_VECTOR4AL(pVerts[iVert0], 0.0f));
        sp.ExtendBy(DL_VECTOR4AL(pVerts[iVert1], 0.0f));

        // Expand to include all other vertices
        for (dl_uint32 i = 0; i < uiNum; i++)
        {
            if (i != iVert0 && i != iVert1)
            {
                sp.ExtendBy(DL_VECTOR4AL(pVerts[i], 0.0f));
            }
        }

        // Merge the result back into this sphere
        ExtendBy(sp);
    }

    inline void DL_SPHERE::ExtendBy(const DLMT::DL_VECTOR4AL* pVerts, dl_uint32 uiNum)
    {
        using namespace DLMT;

        if (uiNum == 0) return;

        dl_uint32 iVert0 = 0, iVert1 = 0;
        dl_float32 fMinSqrLen = 0.0f;

        // 1. Find the two furthest points
        // Note: We use LengthSquared() if LengthSq3() is not exposed in your struct, 
        // or keep LengthSq3() if it is a specific requirement.
        for (dl_uint32 i = 0; i < uiNum; i++)
        {
            for (dl_uint32 j = i + 1; j < uiNum; j++)
            {
                dl_float32 fSqrLen = (pVerts[i] - pVerts[j]).LengthSq();
                if (fMinSqrLen < fSqrLen)
                {
                    fMinSqrLen = fSqrLen;
                    iVert0 = i;
                    iVert1 = j;
                }
            }
        }

        // 2. Initialize temporary sphere with the two furthest points
        DL_SPHERE sp;
        sp.SetEmpty();
        sp.ExtendBy(pVerts[iVert0]);
        sp.ExtendBy(pVerts[iVert1]);

        // 3. Expand to include all other vertices
        for (dl_uint32 i = 0; i < uiNum; i++)
        {
            if (i != iVert0 && i != iVert1)
            {
                sp.ExtendBy(pVerts[i]);
            }
        }

        // 4. Merge the temporary sphere result into this sphere
        ExtendBy(sp);
    }

    inline void DL_SPHERE::ExtendBy(DL_AABB_PARAMTYPE aabb)
    {
        DL_SPHERE sp;

        sp.SetRadius(aabb.GetExtents().Length());
        sp.SetCenter(aabb.GetCenter());

        ExtendBy(sp);
    }

    inline void DL_SPHERE::ExtendBy(DL_OBB_PARAMTYPE obb)
    {
        DL_SPHERE sp;

        sp.SetRadius(obb.GetExtents().Length());
        sp.SetCenter(obb.GetCenter());

        ExtendBy(sp);
    }

    inline void DL_SPHERE::SetEmpty(void)
    {
        m_Sphere = DL_VECTOR4_ZERO;
    }

    inline dl_bool DL_SPHERE::Contains(DL_VECTOR4AL_PARAMTYPE pt) const
    {
        // Calculate vector from sphere center to point
        DL_VECTOR4AL D = pt - GetCenter();

        // Calculate squared distance using x, y, z components
        // We manually compute the 3D squared length to ensure we ignore the 'w' component
        dl_float32 fLenSq = (D.x * D.x) + (D.y * D.y) + (D.z * D.z);

        // Compare against the cached radius squared
        return fLenSq < GetRadiusSq();
    }

    inline dl_bool DL_SPHERE::Contains(DL_SPHERE_PARAMTYPE sphere) const
    {
        using namespace DLMT;

        dl_float32 r0 = GetRadius();
        dl_float32 r1 = sphere.GetRadius();

        // The contained sphere cannot be larger than the host sphere
        if (r0 < r1)
            return false;

        // Vector between centers
        DL_VECTOR4AL D = sphere.GetCenter() - GetCenter();

        // Distance squared (3D, ignoring W/radius component)
        dl_float32 fLenSq = (D.x * D.x) + (D.y * D.y) + (D.z * D.z);

        // Difference in radii
        dl_float32 fRadDiff = r0 - r1;

        // The spheres are contained if the distance between centers 
        // is less than the difference in radii
        return fLenSq < (fRadDiff * fRadDiff);
    }

    inline DL_VECTOR4AL DL_SPHERE::GetCenter(void) const
    {
        return DL_VECTOR4AL(m_Sphere.x, m_Sphere.y, m_Sphere.z, 0.0f);
    }

    inline void DL_SPHERE::SetCenter(DL_VECTOR4AL_PARAMTYPE vCenter)
    {
		m_Sphere = DL_VECTOR4AL(vCenter.x, vCenter.y, vCenter.z, m_Sphere.w);
    }

    inline dl_float32 DL_SPHERE::GetRadius(void) const
    {
        return m_Sphere.w;
    }

    inline dl_float32 DL_SPHERE::GetRadiusSq(void) const
    {
        dl_float32 radius = GetRadius();
        return radius * radius;
    }

    inline void DL_SPHERE::SetRadius(dl_float32 Radius)
    {
		m_Sphere.w = Radius;
    }

    inline DL_SPHERE& DL_SPHERE::operator *= (DL_MATRIX44_PARAMTYPE mtx)
    {
        DL_VECTOR4AL newCenter = GetCenter() * mtx;
        SetCenter(newCenter);

        dl_float32 scale = mtx.GetScale();
        m_Sphere.w *= scale;

        return *this;
    }

    inline DL_SPHERE DL_SPHERE::operator * (DL_MATRIX44_PARAMTYPE mtx) const
    {
        DL_SPHERE sp;

        DL_VECTOR4AL newCenter = GetCenter() * mtx;
        sp.SetCenter(newCenter);

        dl_float32 scale = mtx.GetScale();
        sp.SetRadius(sp.GetRadius() * scale);

        return sp;
    }
}