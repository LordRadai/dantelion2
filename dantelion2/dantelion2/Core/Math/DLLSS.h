#pragma once

#include "DLVector.h"
#include "DLMatrix.h"
#include "DLSegment.h"
#include "DLSphere.h"

namespace DLMT {

    class DL_LSS {
        // Typedefs for interface consistency
        typedef const DL_VECTOR4AL& DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_SEGMENT& DL_SEGMENT_PARAMTYPE;
        typedef const DL_SPHERE& DL_SPHERE_PARAMTYPE;
        typedef const DL_LSS& DL_LSS_PARAMTYPE;

    public:
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

        // Setters required by implementation logic
		void SetOrigin(const DL_VECTOR4AL& vOrigin) { m_Segment.SetOrigin(vOrigin); }
		void SetDirection(const DL_VECTOR4AL& vDir) { m_Segment.SetDirection(vDir); }

        // Accessors
        dl_float32 GetRadius() const;
        dl_float32 GetRadiusSq() const;

		DL_VECTOR4AL GetOrigin() const { return m_Segment.GetOrigin(); }
		DL_VECTOR4AL GetDirection() const { return m_Segment.GetDirection(); }
		DL_VECTOR4AL GetEndPoint() const { return m_Segment.GetEndPoint(); }

        // Inclusion checks
        dl_bool Contains(DL_VECTOR4AL_PARAMTYPE pt) const;
        dl_bool Contains(DL_SPHERE_PARAMTYPE sphere) const;
        dl_bool Contains(DL_LSS_PARAMTYPE lss) const;

        // Geometric Distance interface
        dl_float32 GetDistanceSq(DL_VECTOR4AL_PARAMTYPE pt) const;
    private:
		DL_SEGMENT   m_Segment;
        dl_float32   m_Radius;
    };
}

#include "DLLSS.inl"