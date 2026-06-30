#pragma once
#include "Core/Math/DLSegment.h"

namespace DLLinearEx
{
	class DL_ARROW
	{
	public:
		DL_ARROW() = default;
		DL_ARROW(const DLMT::DL_SEGMENT& segment, dl_float32 shaftLength, dl_float32 headRadius, dl_float32 shaftRadius)
			: m_Segment(segment), m_fShaftLength(shaftLength), m_fHeadRadius(headRadius), m_fShaftRadius(shaftRadius) {}
		DL_ARROW(const DLMT::DL_VECTOR4AL& origin, const DLMT::DL_VECTOR4AL& direction, dl_float32 shaftLength, dl_float32 headRadius, dl_float32 shaftRadius)
			: m_Segment(origin, direction), m_fShaftLength(shaftLength), m_fHeadRadius(headRadius), m_fShaftRadius(shaftRadius) {}
		
		DLMT::DL_VECTOR4AL GetOrigin() const { return m_Segment.GetOrigin(); }
		DLMT::DL_VECTOR4AL GetDirection() const { return m_Segment.GetDirection(); }
		DLMT::DL_VECTOR4AL GetEndPoint() const { return m_Segment.GetEndPoint(); }
		DLMT::DL_VECTOR4AL GetCenter() const { return m_Segment.GetCenter(); }
		dl_float32 GetLength() const { return m_Segment.GetLength(); }
		dl_float32 GetLengthSq() const { return m_Segment.GetLengthSq(); }
		dl_float32 GetShaftLength() const { return m_fShaftLength; }
		dl_float32 GetHeadRadius() const { return m_fHeadRadius; }
		dl_float32 GetShaftRadius() const { return m_fShaftRadius; }
	private:
		DLMT::DL_SEGMENT m_Segment;
		dl_float32 m_fShaftLength;
		dl_float32 m_fHeadRadius;
		dl_float32 m_fShaftRadius;
	};
}