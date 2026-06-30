#pragma once
#include "Core/Math/DLSegment.h"

namespace DLLinearEx
{
	class DL_CYLINDER
	{
		typedef const DLMT::DL_SEGMENT& DL_SEGMENT_PARAMTYPE;
		typedef const DLMT::DL_VECTOR4AL& DL_VECTOR4AL_PARAMTYPE;
	public:
		DL_CYLINDER() = default;
		DL_CYLINDER(DL_SEGMENT_PARAMTYPE segment, dl_float32 radius) : m_Segment(segment), m_fRadius(radius) {}
		DL_CYLINDER(DL_VECTOR4AL_PARAMTYPE origin, DL_VECTOR4AL_PARAMTYPE direction, dl_float32 radius) : m_Segment(origin, direction), m_fRadius(radius) {}

		DLMT::DL_VECTOR4AL GetOrigin() const { return m_Segment.GetOrigin(); }
		DLMT::DL_VECTOR4AL GetDirection() const { return m_Segment.GetDirection(); }
		DLMT::DL_VECTOR4AL GetEndPoint() const { return m_Segment.GetEndPoint(); }
		dl_float32 GetLength() const { return m_Segment.GetLength(); }
		dl_float32 GetRadius() const { return m_fRadius; }

		DLMT::DL_VECTOR4AL GetCenter() const { return m_Segment.GetCenter(); }
	private:
		DLMT::DL_SEGMENT m_Segment;
		dl_float32   m_fRadius;
	};
}