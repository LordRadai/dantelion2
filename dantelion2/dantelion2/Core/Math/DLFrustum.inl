#include "DLLinear.h"

namespace DLMT
{
    inline DL_FRUSTUM::DL_FRUSTUM(DLFrustumType Type,
        DLFrustumCoordinate Coord,
        dl_float32 Left,
        dl_float32 Right,
        dl_float32 Bottom,
        dl_float32 Top,
        dl_float32 Near,
        dl_float32 Far)
    {
        SetValue(Type, Coord, Left, Right, Bottom, Top, Near, Far);
    }

    inline DL_FRUSTUM::DL_FRUSTUM(DLFrustumCoordinate Coord,
        dl_float32 FovAngleY,
        dl_float32 AspectHByW,
        dl_float32 Near,
        dl_float32 Far)
    {
        SetValue(Coord, FovAngleY, AspectHByW, Near, Far);
    }

    inline DL_FRUSTUM::DL_FRUSTUM(DL_MATRIX44_PARAMTYPE ProjMtx)
    {
        SetValue(ProjMtx);
    }

    inline DL_FRUSTUM::DL_FRUSTUM(DL_FRUSTUM_PARAMTYPE Frustum)
    {
        m_Planes[FRUSTUM_PLANE_LEFT] = Frustum.m_Planes[FRUSTUM_PLANE_LEFT];
        m_Planes[FRUSTUM_PLANE_RIGHT] = Frustum.m_Planes[FRUSTUM_PLANE_RIGHT];
        m_Planes[FRUSTUM_PLANE_BOTTOM] = Frustum.m_Planes[FRUSTUM_PLANE_BOTTOM];
        m_Planes[FRUSTUM_PLANE_TOP] = Frustum.m_Planes[FRUSTUM_PLANE_TOP];
        m_Planes[FRUSTUM_PLANE_NEAR] = Frustum.m_Planes[FRUSTUM_PLANE_NEAR];
        m_Planes[FRUSTUM_PLANE_FAR] = Frustum.m_Planes[FRUSTUM_PLANE_FAR];
    }

    inline const DL_PLANE& DL_FRUSTUM::GetPlane(DLFrustumPlaneIndex Index) const
    {
        return m_Planes[Index];
    }

    /*
    inline DL_FRUSTUM DL_FRUSTUM::operator * (DL_MATRIX44_PARAMTYPE Mtx) const
    {
        DL_FRUSTUM Result;

        DL_MATRIX44 mInvT = Mtx.Inverse();

        Result.m_Planes[FRUSTUM_PLANE_LEFT] =
            DL_PLANE::Transform(m_Planes[FRUSTUM_PLANE_LEFT], mInvT);
        Result.m_Planes[FRUSTUM_PLANE_RIGHT] =
            DL_PLANE::Transform(m_Planes[FRUSTUM_PLANE_RIGHT], mInvT);
        Result.m_Planes[FRUSTUM_PLANE_BOTTOM] =
            DL_PLANE::Transform(m_Planes[FRUSTUM_PLANE_BOTTOM], mInvT);
        Result.m_Planes[FRUSTUM_PLANE_TOP] =
            DL_PLANE::Transform(m_Planes[FRUSTUM_PLANE_TOP], mInvT);
        Result.m_Planes[FRUSTUM_PLANE_FAR] =
            DL_PLANE::Transform(m_Planes[FRUSTUM_PLANE_FAR], mInvT);
        Result.m_Planes[FRUSTUM_PLANE_NEAR] =
            DL_PLANE::Transform(m_Planes[FRUSTUM_PLANE_NEAR], mInvT);

        return Result;
    }

    inline DL_FRUSTUM& DL_FRUSTUM::operator *= (DL_MATRIX44_PARAMTYPE Mtx)
    {
        DL_VECTOR4AL vDet;
        DL_MATRIX44 mT = DLIMat44::Transpose(Mtx);
        DL_MATRIX44 mInvT = DLIMat44::Inverse(&vDet, mT);

        m_Planes[FRUSTUM_PLANE_LEFT] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_LEFT], mInvT);
        m_Planes[FRUSTUM_PLANE_RIGHT] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_RIGHT], mInvT);
        m_Planes[FRUSTUM_PLANE_BOTTOM] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_BOTTOM], mInvT);
        m_Planes[FRUSTUM_PLANE_TOP] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_TOP], mInvT);
        m_Planes[FRUSTUM_PLANE_NEAR] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_NEAR], mInvT);
        m_Planes[FRUSTUM_PLANE_FAR] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_FAR], mInvT);

        return *this;
    }

    inline DL_FRUSTUM& DL_FRUSTUM::operator = (DL_FRUSTUM_PARAMTYPE Rhs)
    {
        m_Planes[FRUSTUM_PLANE_LEFT] = Rhs.m_Planes[FRUSTUM_PLANE_LEFT];
        m_Planes[FRUSTUM_PLANE_RIGHT] = Rhs.m_Planes[FRUSTUM_PLANE_RIGHT];
        m_Planes[FRUSTUM_PLANE_BOTTOM] = Rhs.m_Planes[FRUSTUM_PLANE_BOTTOM];
        m_Planes[FRUSTUM_PLANE_TOP] = Rhs.m_Planes[FRUSTUM_PLANE_TOP];
        m_Planes[FRUSTUM_PLANE_NEAR] = Rhs.m_Planes[FRUSTUM_PLANE_NEAR];
        m_Planes[FRUSTUM_PLANE_FAR] = Rhs.m_Planes[FRUSTUM_PLANE_FAR];
        return *this;
    }

    inline DL_FRUSTUM DL_FRUSTUM::Multiply(DL_MATRIX44_PARAMTYPE Mtx) const
    {
        DL_FRUSTUM Result;


        Result.m_Planes[FRUSTUM_PLANE_LEFT] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_LEFT], Mtx);
        Result.m_Planes[FRUSTUM_PLANE_RIGHT] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_RIGHT], Mtx);
        Result.m_Planes[FRUSTUM_PLANE_BOTTOM] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_BOTTOM], Mtx);
        Result.m_Planes[FRUSTUM_PLANE_TOP] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_TOP], Mtx);
        Result.m_Planes[FRUSTUM_PLANE_FAR] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_FAR], Mtx);
        Result.m_Planes[FRUSTUM_PLANE_NEAR] =
            DLIPlane::Transform(m_Planes[FRUSTUM_PLANE_NEAR], Mtx);

        return Result;
    }

    inline DL_FRUSTUM& DL_FRUSTUM::SetValue(DLFrustumType Type,
        DLFrustumCoordinate Coord,
        dl_float32 Left,
        dl_float32 Right,
        dl_float32 Bottom,
        dl_float32 Top,
        dl_float32 Near,
        dl_float32 Far)
    {
        DL_MATRIX44 ProjMtx;

        if (Type == FRUSTUM_TYPE_PERSPECTIVE)
        {
            if (Coord == FRUSTUM_COORDINATE_LEFTHAND)
            {
                ProjMtx = DLIMat44::PerspectiveOffCenterLH_GL(Left, Right, Bottom, Top, Near, Far);
            }
            else
            {
                ProjMtx = DLIMat44::PerspectiveOffCenterRH_GL(Left, Right, Bottom, Top, Near, Far);
            }
        }
        else
        {
            if (Coord == FRUSTUM_COORDINATE_LEFTHAND)
            {
                ProjMtx = DLIMat44::OrthographicOffCenterLH_GL(Left, Right, Bottom, Top, Near, Far);
            }
            else
            {
                ProjMtx = DLIMat44::OrthographicOffCenterRH_GL(Left, Right, Bottom, Top, Near, Far);
            }
        }

        return SetValue(ProjMtx);
    }

    inline DL_FRUSTUM& DL_FRUSTUM::SetValue(DLFrustumCoordinate Coord,
        dl_float32 FovAngleY,
        dl_float32 AspectHByW,
        dl_float32 Near,
        dl_float32 Far)
    {
        DL_MATRIX44 ProjMtx;

        if (Coord == FRUSTUM_COORDINATE_LEFTHAND)
        {
            ProjMtx = DLIMat44::PerspectiveFovLH_GL(FovAngleY, AspectHByW, Near, Far);
        }
        else
        {
            ProjMtx = DLIMat44::PerspectiveFovRH_GL(FovAngleY, AspectHByW, Near, Far);
        }

        return SetValue(ProjMtx);
    }

    inline DL_FRUSTUM& DL_FRUSTUM::SetValue(DL_MATRIX44_PARAMTYPE ProjMtx)
    {
        DL_MATRIX44 ProjMtxT = DLIMat44::Transpose(ProjMtx);

        m_Planes[FRUSTUM_PLANE_LEFT] = -(ProjMtxT.R[3] + ProjMtxT.R[0]);
        m_Planes[FRUSTUM_PLANE_RIGHT] = -(ProjMtxT.R[3] - ProjMtxT.R[0]);
        m_Planes[FRUSTUM_PLANE_BOTTOM] = -(ProjMtxT.R[3] + ProjMtxT.R[1]);
        m_Planes[FRUSTUM_PLANE_TOP] = -(ProjMtxT.R[3] - ProjMtxT.R[1]);
        m_Planes[FRUSTUM_PLANE_NEAR] = -(ProjMtxT.R[3] + ProjMtxT.R[2]);
        m_Planes[FRUSTUM_PLANE_FAR] = -(ProjMtxT.R[3] - ProjMtxT.R[2]);

        return *this;
    }

    inline DL_MATRIX44 DL_FRUSTUM::ComputeProjectionMatrix(void) const
    {
        DL_MATRIX44 ProjMtx;

        ProjMtx.R[3] = -0.5f * (*reinterpret_cast<const DL_VECTOR4AL*>(&m_Planes[FRUSTUM_PLANE_LEFT]) +
            *reinterpret_cast<const DL_VECTOR4AL*>(&m_Planes[FRUSTUM_PLANE_RIGHT]));
        ProjMtx.R[0] = *reinterpret_cast<const DL_VECTOR4AL*>(&m_Planes[FRUSTUM_PLANE_RIGHT]) + ProjMtx.R[3];
        ProjMtx.R[1] = *reinterpret_cast<const DL_VECTOR4AL*>(&m_Planes[FRUSTUM_PLANE_TOP]) + ProjMtx.R[3];
        ProjMtx.R[2] = *reinterpret_cast<const DL_VECTOR4AL*>(&m_Planes[FRUSTUM_PLANE_FAR]) + ProjMtx.R[3];

        return DLIMat44::Transpose(ProjMtx);
    }

    inline dl_bool DL_FRUSTUM::ComputeVertices(DL_VECTOR4AL verts[8]) const
    {
        if (verts == 0) return false;

        dl_bool bResult;

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_LEFT],
            m_Planes[FRUSTUM_PLANE_TOP],
            m_Planes[FRUSTUM_PLANE_NEAR],
            verts[0]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_RIGHT],
            m_Planes[FRUSTUM_PLANE_TOP],
            m_Planes[FRUSTUM_PLANE_NEAR],
            verts[1]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_LEFT],
            m_Planes[FRUSTUM_PLANE_BOTTOM],
            m_Planes[FRUSTUM_PLANE_NEAR],
            verts[2]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_RIGHT],
            m_Planes[FRUSTUM_PLANE_BOTTOM],
            m_Planes[FRUSTUM_PLANE_NEAR],
            verts[3]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_LEFT],
            m_Planes[FRUSTUM_PLANE_TOP],
            m_Planes[FRUSTUM_PLANE_FAR],
            verts[4]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_RIGHT],
            m_Planes[FRUSTUM_PLANE_TOP],
            m_Planes[FRUSTUM_PLANE_FAR],
            verts[5]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_LEFT],
            m_Planes[FRUSTUM_PLANE_BOTTOM],
            m_Planes[FRUSTUM_PLANE_FAR],
            verts[6]);

        bResult = DLIPlane::IntersectPlanes(m_Planes[FRUSTUM_PLANE_RIGHT],
            m_Planes[FRUSTUM_PLANE_BOTTOM],
            m_Planes[FRUSTUM_PLANE_FAR],
            verts[7]);

        return true;
    }

    inline dl_bool DL_FRUSTUM::GetTriangleListIndices(
        dl_uint32 Indices[12][3]) const
    {
        if (Indices == 0) return false;

        static const dl_uint32 s_Indices[12][3] =
        {
            { 0, 2, 1 }, { 1, 2, 3 },
            { 5, 1, 3 }, { 5, 3, 7 },
            { 5, 7, 6 }, { 5, 6, 4 },
            { 4, 6, 2 }, { 4, 2, 0 },
            { 4, 0, 1 }, { 4, 1, 5 },
            { 2, 6, 7 }, { 2, 7, 3 }
        };

        DLMemory::Copy(Indices, s_Indices, sizeof(s_Indices));

        return true;
    }

    inline const dl_uint32* DL_FRUSTUM::GetEdges(void) const
    {
        static const dl_uint32 EdgeIndices[] =
        {
            0, 1, 1, 3, 3, 2, 2, 0,
            7, 6, 6, 4, 4, 5, 5, 7,
            1, 5, 6, 2,
            3, 7, 4, 0
        };

        return EdgeIndices;
    }

    inline dl_bool DL_FRUSTUM::ComputeTriangles(DL_TRIANGLE Triangles[12]) const
    {
        DL_VECTOR4AL Verts[8];
        dl_uint32 Indices[12][3];

        if (Triangles == 0) return false;
        if (!ComputeVertices(Verts)) return false;
        if (!GetTriangleListIndices(Indices)) return false;

        for (dl_int32 i = 0; i < 12; i++)
        {
            Triangles[i].SetPoints(Verts[Indices[i][0]],
                Verts[Indices[i][1]],
                Verts[Indices[i][2]]);
        }

        return true;
    }
    */
}
