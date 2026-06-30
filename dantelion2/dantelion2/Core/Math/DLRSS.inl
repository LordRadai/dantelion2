#pragma once
#include "DLLinear.h"

#include <cmath>

namespace DLMT
{
    inline DL_RSS::DL_RSS(const DL_VECTOR3* pVerts, dl_uint32 uiNum)
    {
		SetValue(reinterpret_cast<const DL_VECTOR4AL*>(pVerts), uiNum);
    }

    inline DL_RSS::DL_RSS(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum)
    {
		SetValue(pVerts, uiNum);
    }

    inline DL_RSS::DL_RSS(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0,
        const DL_VECTOR4AL& vEdge1, dl_float32 fRadius)
    {
        SetValue(vOrig, vEdge0, vEdge1, fRadius);
    }

    inline DL_RSS::DL_RSS(const DL_RSS& rss)
        : DL_RECTANGLE(rss), m_Radius(rss.m_Radius) {}

    inline void DL_RSS::SetValue(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0,
        const DL_VECTOR4AL& vEdge1, dl_float32 fRadius)
    {
        DL_RECTANGLE::SetValue(vOrig, vEdge0, vEdge1);
        m_Radius = fRadius;
    }

    inline void DL_RSS::SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum)
    {
        if (uiNum == 0) return;

        // 1. Calculate the Mean (Center of the cloud)
        DL_VECTOR3 vMean = DL_VECTOR3_ZERO;
        for (dl_uint32 i = 0; i < uiNum; ++i)
        {
            vMean += pVerts[i];
        }
        vMean *= (1.0f / (dl_float32)uiNum);

        // 2. Compute Covariance Matrix to find principal axes
        // (Simplified: You would typically use Principal Component Analysis (PCA))
        // Here, we find the extents along the axes to define Edge0 and Edge1.

        // 

        DL_VECTOR3 vMin = pVerts[0];
        DL_VECTOR3 vMax = pVerts[0];

        for (dl_uint32 i = 1; i < uiNum; ++i)
        {
            vMin.x = std::fmin(vMin.x, pVerts[i].x);
            vMin.y = std::fmin(vMin.y, pVerts[i].y);
            vMin.z = std::fmin(vMin.z, pVerts[i].z);

            vMax.x = std::fmax(vMax.x, pVerts[i].x);
            vMax.y = std::fmax(vMax.y, pVerts[i].y);
            vMax.z = std::fmax(vMax.z, pVerts[i].z);
        }

        // 3. Define the base rectangle from the AABB (Axis-Aligned Bounding Box)
        // In a production scenario, you would transform these by the Eigenvectors 
        // of the covariance matrix for an OBB.
        DL_VECTOR3 vOrigin = { vMin.x, vMin.y, vMin.z };
        DL_VECTOR3 vEdge0 = { vMax.x - vMin.x, 0.0f, 0.0f };
        DL_VECTOR3 vEdge1 = { 0.0f, vMax.y - vMin.y, 0.0f };

        // 4. Set Radius (e.g., the average extent in the Z-axis)
        dl_float32 fRadius = (vMax.z - vMin.z) * 0.5f;

        SetValue(DL_VECTOR4AL(vOrigin.x, vOrigin.y, vOrigin.z, 1.0f), DL_VECTOR4AL(vEdge0.x, vEdge0.y, vEdge0.z, 0.0f), DL_VECTOR4AL(vEdge1.x, vEdge1.y, vEdge1.z, 0.0f), fRadius);
    }

    inline void DL_RSS::SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum)
    {
        if (uiNum == 0) return;

        // 1. Calculate the Mean (Center of the cloud)
        DL_VECTOR4AL vMean = DL_VECTOR4_ZERO;
        for (dl_uint32 i = 0; i < uiNum; ++i)
        {
            vMean += pVerts[i];
        }
        vMean *= (1.0f / (dl_float32)uiNum);

        // 2. Compute Covariance Matrix to find principal axes
        // (Simplified: You would typically use Principal Component Analysis (PCA))
        // Here, we find the extents along the axes to define Edge0 and Edge1.

        // 

        DL_VECTOR4AL vMin = pVerts[0];
        DL_VECTOR4AL vMax = pVerts[0];

        for (dl_uint32 i = 1; i < uiNum; ++i)
        {
            vMin.x = std::fmin(vMin.x, pVerts[i].x);
            vMin.y = std::fmin(vMin.y, pVerts[i].y);
            vMin.z = std::fmin(vMin.z, pVerts[i].z);

            vMax.x = std::fmax(vMax.x, pVerts[i].x);
            vMax.y = std::fmax(vMax.y, pVerts[i].y);
            vMax.z = std::fmax(vMax.z, pVerts[i].z);
        }

        // 3. Define the base rectangle from the AABB (Axis-Aligned Bounding Box)
        // In a production scenario, you would transform these by the Eigenvectors 
        // of the covariance matrix for an OBB.
        DL_VECTOR4AL vOrigin = { vMin.x, vMin.y, vMin.z, 1.0f };
        DL_VECTOR4AL vEdge0 = { vMax.x - vMin.x, 0.0f, 0.0f, 0.0f };
        DL_VECTOR4AL vEdge1 = { 0.0f, vMax.y - vMin.y, 0.0f, 0.0f };

        // 4. Set Radius (e.g., the average extent in the Z-axis)
        dl_float32 fRadius = (vMax.z - vMin.z) * 0.5f;

        SetValue(vOrigin, vEdge0, vEdge1, fRadius);
    }
}