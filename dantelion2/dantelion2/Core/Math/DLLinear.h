#pragma once
#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    struct DL_SEGMENT;
    struct DL_LINE;
    struct DL_RAY;
    struct DL_RECTANGLE;
    struct DL_PLANE;
    struct DL_SPHERE;
    struct DL_AABB;
    struct DL_OBB;
    struct DL_LSS;
    struct DL_RSS;
    struct DL_TRIANGLE;
    struct DL_TRIANGLE3;
    struct DL_FRUSTUM;

    typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
    typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE;
    typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE;
    typedef const DL_VECTOR2AL& DL_VECTOR2AL_PARAMTYPE;
    typedef const DL_VECTOR3AL& DL_VECTOR3AL_PARAMTYPE;
    typedef const DL_VECTOR4AL& DL_VECTOR4AL_PARAMTYPE;
    typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE;
    typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE;
	typedef const DL_MATRIX34& DL_MATRIX34_PARAMTYPE;
    typedef const DL_MATRIX44& DL_MATRIX44_PARAMTYPE;
    typedef const DL_SPHERE& DL_SPHERE_PARAMTYPE;
    typedef const DL_AABB& DL_AABB_PARAMTYPE;
    typedef const DL_OBB& DL_OBB_PARAMTYPE;
    typedef const DL_LSS& DL_LSS_PARAMTYPE;
	typedef const DL_RSS& DL_RSS_PARAMTYPE;
	typedef const DL_TRIANGLE& DL_TRIANGLE_PARAMTYPE;
	typedef const DL_TRIANGLE3& DL_TRIANGLE3_PARAMTYPE;
	typedef const DL_PLANE& DL_PLANE_PARAMTYPE;
	typedef const DL_FRUSTUM& DL_FRUSTUM_PARAMTYPE;
	typedef const DL_RECTANGLE& DL_RECTANGLE_PARAMTYPE;
	typedef const DL_SEGMENT& DL_SEGMENT_PARAMTYPE;
	typedef const DL_LINE& DL_LINE_PARAMTYPE;
	typedef const DL_RAY& DL_RAY_PARAMTYPE;

    struct DL_SEGMENT
    {
        DL_SEGMENT() = default;
        DL_SEGMENT(DL_VECTOR4AL_PARAMTYPE vOrigin, DL_VECTOR4AL_PARAMTYPE vDirection) : m_Origin(vOrigin), m_Dir(vDirection) {}

        // Accessors
        const DL_VECTOR4AL& GetOrigin() const;
        const DL_VECTOR4AL& GetDirection() const;
        void GetDirection(DL_VECTOR4AL& _dir) const;

        DL_VECTOR4AL GetEndPoint() const;
        DL_VECTOR4AL GetCenter() const;
        dl_float32 GetLength() const;
        dl_float32 GetLengthSq() const;

        // Mutators
        void SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection);
        void SetPoints(const DL_VECTOR4AL& vPt0, const DL_VECTOR4AL& vPt1);
        void SetOrigin(const DL_VECTOR4AL& vOrigin);
        void SetDirection(const DL_VECTOR4AL& vDirection);
        void SetEndPoint(const DL_VECTOR4AL& vEndPoint);

        // Geometry Operations
        DL_VECTOR4AL ComputePoint(dl_float32 t) const;
        dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;
        dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;

        // Operators
        DL_SEGMENT& operator*=(const DL_MATRIX44& mtx);
        DL_SEGMENT operator*(const DL_MATRIX44& mtx) const;

        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Dir;
    };

    struct DL_RAY
    {
        DL_RAY() = default;
        DL_RAY(const DL_VECTOR4AL& origin, const DL_VECTOR4AL& direction)
            : m_Origin(origin), m_Dir(direction) {}

        const DL_VECTOR4AL& GetOrigin() const { return m_Origin; }
        const DL_VECTOR4AL& GetDirection() const { return m_Dir; }

        void SetOrigin(const DL_VECTOR4AL& vOrigin) { m_Origin = vOrigin; }
        void SetDirection(const DL_VECTOR4AL& vDirection) { m_Dir = vDirection; }
        void SetOriginDirection(const DL_VECTOR4AL& vOrigin, const DL_VECTOR4AL& vDirection);

        dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;
        dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pT = nullptr) const;

        // Compute point: P = Origin + t * Dir (clamped t >= 0)
        DL_VECTOR4AL ComputePoint(dl_float32 t) const;

        DL_RAY& operator *= (const DL_MATRIX44& mtx);
        DL_RAY operator * (const DL_MATRIX44& mtx) const;

        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Dir;
    };

    struct DL_LINE
    {
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

        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Dir;
    };

    struct DL_RECTANGLE
    {
        DL_RECTANGLE() = default;
        DL_RECTANGLE(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1);
        DL_RECTANGLE(const DL_RECTANGLE& rect);

        void SetValue(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0, const DL_VECTOR4AL& vEdge1);

        void SetOrigin(const DL_VECTOR4AL& vOrig) { m_Origin = vOrig; }
        void SetEdge0(const DL_VECTOR4AL& vEdge0) { m_Edge[0] = vEdge0; }
        void SetEdge1(const DL_VECTOR4AL& vEdge1) { m_Edge[1] = vEdge1; }

        DL_VECTOR4AL GetOrigin() const { return m_Origin; }
        DL_VECTOR4AL GetEdge0() const { return m_Edge[0]; }
        DL_VECTOR4AL GetEdge1() const { return m_Edge[1]; }
        DL_VECTOR4AL GetCenter() const;
        DL_VECTOR4AL GetNormal() const;

        DL_VECTOR4AL ComputePoint(dl_float32 fS, dl_float32 fT) const;

        dl_float32 GetDistanceSq(const DL_VECTOR4AL& pt, dl_float32* pfU = nullptr, dl_float32* pfV = nullptr) const;
        dl_float32 GetDistance(const DL_VECTOR4AL& pt, dl_float32* pfU = nullptr, dl_float32* pfV = nullptr) const;

        DL_RECTANGLE& operator *= (const DL_MATRIX44& mtx);
        DL_RECTANGLE operator * (const DL_MATRIX44& mtx) const;

        DL_VECTOR4AL m_Edge[2];
        DL_VECTOR4AL m_Origin;
    };

    struct DL_PLANE
    {
        DL_PLANE() : m_Plane(0.0f, 1.0f, 0.0f, 0.0f) {}
        DL_PLANE(const DL_VECTOR4AL& plane)
            : m_Plane(plane) {}

        const DL_VECTOR4AL& GetPlane() const { return m_Plane; }

        void SetPlane(const DL_VECTOR4AL& plane) { m_Plane = plane; }

        dl_float32 DotCoord(const DL_VECTOR4AL& pt) const;

        void Transform(const DL_MATRIX44& mtx);

        DL_VECTOR4AL m_Plane;
    };

    struct DL_SPHERE
    {
        // --- Constructors ---
        DL_SPHERE() = default;

        DL_SPHERE(DL_VECTOR4AL_PARAMTYPE vCenter, dl_float32 fRadius);
        DL_SPHERE(const DL_SPHERE& sphere);
        DL_SPHERE(const DL_VECTOR3* pVerts, dl_uint32 uiNum);

        // --- Setters ---
        void SetValue(DL_VECTOR4AL_PARAMTYPE vCenter, dl_float32 fRadius);
        void SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        void SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);
        void SetEmpty(void);

        // --- Geometry Extension ---
        // Expands the sphere to include additional geometry
        void ExtendBy(DL_VECTOR4AL_PARAMTYPE pt);
        void ExtendBy(DL_SPHERE_PARAMTYPE sphere);
        void ExtendBy(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        void ExtendBy(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);
        void ExtendBy(DL_AABB_PARAMTYPE aabb);
        void ExtendBy(DL_OBB_PARAMTYPE obb);

        // --- Queries ---
        dl_bool Contains(DL_VECTOR4AL_PARAMTYPE pt) const;
        dl_bool Contains(DL_SPHERE_PARAMTYPE sphere) const;

        // --- Getters/Setters ---
        DL_VECTOR4AL GetCenter(void) const;
        void SetCenter(DL_VECTOR4AL_PARAMTYPE vCenter);

        dl_float32 GetRadius(void) const;
        dl_float32 GetRadiusSq(void) const;
        void SetRadius(dl_float32 Radius);

        // --- Operators ---
        DL_SPHERE& operator *= (DL_MATRIX44_PARAMTYPE mtx);
        DL_SPHERE operator * (DL_MATRIX44_PARAMTYPE mtx) const;

        DL_VECTOR4AL m_Sphere;
    };

    struct DL_AABB
    {
        enum AxisCompornent
        {
            AXIS_X = 0,
            AXIS_Y = 1,
            AXIS_Z = 2,
        };

        // Constructors
        DL_AABB(void) {}
        DL_AABB(DL_VECTOR4AL_PARAMTYPE _min, DL_VECTOR4AL_PARAMTYPE _max);
        DL_AABB(const DL_AABB& aabb);
        ~DL_AABB(void) {}

        // Containment and Validity
        dl_bool Contains(DL_VECTOR4AL_PARAMTYPE pt) const;
        dl_bool Contains(DL_AABB_PARAMTYPE aabb) const;
        dl_bool IsValid(void) const;

        // Setters
        void SetMin(DL_VECTOR4AL_PARAMTYPE vMin);
        void SetMax(DL_VECTOR4AL_PARAMTYPE vMax);
        void SetMinMax(DL_VECTOR4AL_PARAMTYPE vMin, DL_VECTOR4AL_PARAMTYPE vMax);
        void SetCenterExtents(DL_VECTOR4AL_PARAMTYPE vCenter, DL_VECTOR4AL_PARAMTYPE vExtents);
        void SetEmpty(void);
        void SetVector(DL_VECTOR4AL_PARAMTYPE pt);

        // Getters
        void GetMinMax(DL_VECTOR4AL& vMin, DL_VECTOR4AL& vMax) const;
        void GetCenterExtents(DL_VECTOR4AL& vCenter, DL_VECTOR4AL& vExtents) const;

        DL_VECTOR4AL& GetMin(DL_VECTOR4AL& vMin) const;
        DL_VECTOR4AL& GetMax(DL_VECTOR4AL& vMax) const;

        DL_VECTOR4AL GetMin(void);
        DL_VECTOR4AL GetMax(void);
        const DL_VECTOR4AL& GetMin(void) const;
        const DL_VECTOR4AL& GetMax(void) const;

        dl_float32 GetMin(AxisCompornent axis) const;
        dl_float32 GetMax(AxisCompornent axis) const;

        // Center & Extents
        DL_VECTOR4AL& GetCenter(DL_VECTOR4AL& vCenter) const;
        DL_VECTOR4AL& GetExtents(DL_VECTOR4AL& vExtents) const;
        DL_VECTOR4AL GetCenter(void) const;
        DL_VECTOR4AL GetExtents(void) const;
        dl_float32 GetCenter(AxisCompornent axis) const;
        dl_float32 GetExtents(AxisCompornent axis) const;

        // Geometry
        DL_VECTOR4AL GetDiagonal() const;
        dl_float32 GetWidth(void) const;
        dl_float32 GetHeight(void) const;
        dl_float32 GetDepth(void) const;
        dl_float32 GetVolume(void) const;

        // Modification
        void ExtendBy(DL_VECTOR4AL_PARAMTYPE pt);
        void ExtendBy(DL_AABB_PARAMTYPE aabb);
        DL_AABB Transform(DL_MATRIX44_PARAMTYPE mtx) const;

        // Operators
        DL_AABB& operator *= (dl_float32 s);
        DL_AABB& operator *= (DL_MATRIX44_PARAMTYPE mtx);
        DL_AABB& operator /= (dl_float32 s);
        DL_AABB& operator += (DL_VECTOR4AL_PARAMTYPE vTrans);
        DL_AABB operator * (dl_float32 s);
        DL_AABB operator * (DL_MATRIX44_PARAMTYPE mtx);

        DL_VECTOR4AL m_Min;
        DL_VECTOR4AL m_Max;
    };

    struct DL_OBB
    {
        DL_OBB(void) {}
        DL_OBB(DL_AABB_PARAMTYPE aabb, DL_MATRIX44_PARAMTYPE mtx) { SetValue(aabb, mtx); }
        DL_OBB(DL_VECTOR4AL_PARAMTYPE vExtents, DL_MATRIX44_PARAMTYPE Xform) { SetValue(vExtents, Xform); }
        DL_OBB(DL_VECTOR4AL_PARAMTYPE vExtents, DL_VECTOR4AL_PARAMTYPE vCenter, DL_MATRIX33_PARAMTYPE mRot) { SetValue(vExtents, vCenter, mRot); }

        // --- Initialization & State ---
        void SetEmpty(void);

        // --- Setters ---
        void SetValue(DL_AABB_PARAMTYPE aabb, DL_MATRIX44_PARAMTYPE mtx);
        void SetValue(DL_VECTOR4AL_PARAMTYPE vExtents, DL_MATRIX44_PARAMTYPE Xform);
        void SetValue(DL_VECTOR4AL_PARAMTYPE vExtents, DL_VECTOR4AL_PARAMTYPE vCenter, DL_MATRIX33_PARAMTYPE mRot);

        void SetCenter(DL_VECTOR4AL_PARAMTYPE vCenter);
        void SetExtents(DL_VECTOR4AL_PARAMTYPE vExtents);
        void SetXform(DL_MATRIX44_PARAMTYPE mXform);
        void SetRotation(DL_MATRIX34_PARAMTYPE mRot);

        // --- Getters ---
        const DL_VECTOR4AL& GetCenter(void) const;
        const DL_VECTOR4AL& GetExtents(void) const;
        const DL_MATRIX44& GetXform(void) const;
        const DL_VECTOR4AL& GetAxis(DL_AABB::AxisCompornent axis) const;

        // --- Operations ---
        void Transform(DL_OBB& obb, DL_MATRIX44_PARAMTYPE mtx) const;

        // --- Operators ---
        DL_OBB& operator *= (DL_MATRIX44_PARAMTYPE mtx);
        DL_OBB operator * (DL_MATRIX44_PARAMTYPE mtx) const;

        DL_MATRIX44 m_Xform;
        DL_VECTOR4AL m_Extents;
    };

	struct DL_LSS : public DL_SEGMENT
    {
        DL_LSS() = default;
        DL_LSS(DL_SEGMENT_PARAMTYPE seg, dl_float32 fRadius);
        DL_LSS(DL_LSS_PARAMTYPE lss);
        DL_LSS(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        DL_LSS(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);

        // Mutators
        void SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        void SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);
        void SetValue(DL_SEGMENT_PARAMTYPE seg, dl_float32 fRadius);
        void SetRadius(dl_float32 Radius);

        // Accessors
        dl_float32 GetRadius() const;
        dl_float32 GetRadiusSq() const;

        // Inclusion checks
        dl_bool Contains(DL_VECTOR4AL_PARAMTYPE pt) const;
        dl_bool Contains(DL_SPHERE_PARAMTYPE sphere) const;
        dl_bool Contains(DL_LSS_PARAMTYPE lss) const;

        // Geometric Distance interface
        dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE pt) const;

        dl_float32 m_Radius;
    };

    struct DL_RSS : public DL_RECTANGLE
    {
        DL_RSS() = default;
        DL_RSS(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0,
            const DL_VECTOR4AL& vEdge1, dl_float32 fRadius);
        DL_RSS(const DL_RSS& rss);

        // Constructors from point clouds (Placeholder for logic)
        DL_RSS(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        DL_RSS(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);

        void SetValue(const DL_VECTOR4AL& vOrig, const DL_VECTOR4AL& vEdge0,
            const DL_VECTOR4AL& vEdge1, dl_float32 fRadius);

        void SetValue(const DL_VECTOR3* pVerts, dl_uint32 uiNum);
        void SetValue(const DL_VECTOR4AL* pVerts, dl_uint32 uiNum);

        dl_float32 GetRadius() const { return m_Radius; }
        dl_float32 GetRadiusSq() const { return m_Radius * m_Radius; }
        void SetRadius(dl_float32 radius) { m_Radius = radius; }

        dl_float32 m_Radius;
    };

    struct DL_TRIANGLE
    {
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

        DL_VECTOR4AL m_Origin;
        DL_VECTOR4AL m_Edge[2];
    };

    struct DL_TRIANGLE3
    {
        DL_TRIANGLE3() = default;
        DL_TRIANGLE3(const DL_VECTOR3AL pt[3]);
        DL_TRIANGLE3(const DL_VECTOR3AL& vOrig, const DL_VECTOR3AL& vEdge0, const DL_VECTOR3AL& vEdge1);

        void SetPoints(const DL_VECTOR3AL pt[3]);
        DL_VECTOR3AL ComputePoint(dl_float32 fS, dl_float32 fT) const;
        DL_VECTOR3AL GetNormal() const;
        DL_VECTOR3AL GetCenter() const;
        DL_PLANE GetPlane() const;

        DL_TRIANGLE3& operator *= (const DL_MATRIX44& mtx);
        DL_TRIANGLE3 operator * (const DL_MATRIX44& mtx);

        DL_VECTOR3AL GetEdge(dl_uint32 index) const { return m_Edge[index]; }
        DL_VECTOR3AL GetOrigin() const { return m_Origin; }

        DL_VECTOR3AL m_Origin;
        DL_VECTOR3AL m_Edge[2];
    };

    struct DL_FRUSTUM
    {
        enum DLFrustumPlaneIndex
        {
            FRUSTUM_PLANE_LEFT,
            FRUSTUM_PLANE_RIGHT,
            FRUSTUM_PLANE_BOTTOM,
            FRUSTUM_PLANE_TOP,
            FRUSTUM_PLANE_NEAR,
            FRUSTUM_PLANE_FAR,

            FRUSTUM_PLANE_NUM,
            FRUSTUM_PLANE_FORCE_DWORD = 0x7FFFFFFF,
        };

        enum DLFrustumType
        {
            FRUSTUM_TYPE_PERSPECTIVE,
            FRUSTUM_TYPE_ORTHOGRAPHIC,
        };

        enum DLFrustumCoordinate
        {
            FRUSTUM_COORDINATE_RIGHTHAND,
            FRUSTUM_COORDINATE_LEFTHAND,
        };

        enum DLFrustumVertexIndices
        {
            FRUSTUM_INDEX_LEFT_TOP_NEAR = 0,
            FRUSTUM_INDEX_RIGHT_TOP_NEAR,
            FRUSTUM_INDEX_LEFT_BOTTOM_NEAR,
            FRUSTUM_INDEX_RIGHT_BOTTOM_NEAR,
            FRUSTUM_INDEX_LEFT_TOP_FAR,
            FRUSTUM_INDEX_RIGHT_TOP_FAR,
            FRUSTUM_INDEX_LEFT_BOTTOM_FAR,
            FRUSTUM_INDEX_RIGHT_BOTTOM_FAR,
            FRUSTUM_INDEX_NUM,
        };

    public:

        DL_FRUSTUM() {}

        DL_FRUSTUM(DLFrustumType Type,
            DLFrustumCoordinate Coord,
            dl_float32 Left,
            dl_float32 Right,
            dl_float32 Bottom,
            dl_float32 Top,
            dl_float32 Near,
            dl_float32 Far);

        DL_FRUSTUM(DLFrustumCoordinate Coord,
            dl_float32 FovAngleY,
            dl_float32 AspectHByW,
            dl_float32 Near,
            dl_float32 Far);

        DL_FRUSTUM(DL_MATRIX44_PARAMTYPE ProjMtx);

        DL_FRUSTUM(DL_FRUSTUM_PARAMTYPE Frustum);

        const DL_PLANE& GetPlane(DLFrustumPlaneIndex Index) const;

        /*
        DL_FRUSTUM operator * (DL_MATRIX44_PARAMTYPE Mtx) const;
        DL_FRUSTUM& operator *= (DL_MATRIX44_PARAMTYPE Mtx);
        DL_FRUSTUM& operator = (DL_FRUSTUM_PARAMTYPE Rhs);

        DL_FRUSTUM Multiply(DL_MATRIX44_PARAMTYPE Mtx) const;

        DL_FRUSTUM& SetValue(DL_MATRIX44_PARAMTYPE ProjMtx);

        DL_FRUSTUM& SetValue(DLFrustumType Type,
            DLFrustumCoordinate Coord,
            dl_float32 Left,
            dl_float32 Right,
            dl_float32 Bottom,
            dl_float32 Top,
            dl_float32 Near,
            dl_float32 Far);

        DL_FRUSTUM& SetValue(DLFrustumCoordinate Coord,
            dl_float32 FovAngleY,
            dl_float32 AspectHByW,
            dl_float32 Near,
            dl_float32 Far);


        DL_MATRIX44 ComputeProjectionMatrix(void) const;

        dl_bool ComputeVertices(DL_VECTOR4AL verts[8]) const;
        dl_bool GetTriangleListIndices(dl_uint32 Indices[12][3]) const;

        const dl_uint32* GetEdges(void) const;

        dl_bool ComputeTriangles(DL_TRIANGLE Triangles[12]) const;
        */
    public:
        DL_PLANE m_Planes[6];
    };
}