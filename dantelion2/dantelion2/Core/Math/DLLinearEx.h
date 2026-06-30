#pragma once
#include "DLLinear.h"

namespace DLLinearEx
{
	struct DL_ARROW : public DLMT::DL_SEGMENT
	{
		DL_ARROW() = default;
		DL_ARROW(const DLMT::DL_SEGMENT& segment, dl_float32 shaftRadius, dl_float32 headRadius, dl_float32 shaftRatio)
			: DLMT::DL_SEGMENT(segment), m_fShaftRadius(shaftRadius), m_fHeadRadius(headRadius), m_fShaftRatio(shaftRatio) {}
		DL_ARROW(const DLMT::DL_VECTOR4AL& origin, const DLMT::DL_VECTOR4AL& direction, dl_float32 shaftRadius, dl_float32 headRadius, dl_float32 shaftRatio)
			: DLMT::DL_SEGMENT(origin, direction), m_fShaftRadius(shaftRadius), m_fHeadRadius(headRadius), m_fShaftRatio(shaftRatio) {}

		dl_float32 GetShaftRadius() const { return m_fShaftRadius; }
		dl_float32 GetHeadRadius() const { return m_fHeadRadius; }
		dl_float32 GetShaftLengthRatio() const { return m_fShaftRatio; }

		dl_float32 m_fShaftRadius;
		dl_float32 m_fHeadRadius;
		dl_float32 m_fShaftRatio;
	};

	struct DL_CONE : public DLMT::DL_SEGMENT
	{
		DL_CONE() = default;
		DL_CONE(DLMT::DL_SEGMENT_PARAMTYPE segment, dl_float32 radius) : DLMT::DL_SEGMENT(segment), m_fRadius(radius) {}
		DL_CONE(DLMT::DL_VECTOR4AL_PARAMTYPE origin, DLMT::DL_VECTOR4AL_PARAMTYPE direction, dl_float32 radius) : DLMT::DL_SEGMENT(origin, direction), m_fRadius(radius) {}

		dl_float32 GetRadius() const { return m_fRadius; }

		dl_float32 m_fRadius;
	};

	struct DL_CYLINDER : public DLMT::DL_SEGMENT
	{
		DL_CYLINDER() = default;
		DL_CYLINDER(DLMT::DL_SEGMENT_PARAMTYPE segment, dl_float32 radius) : DLMT::DL_SEGMENT(segment), m_fRadius(radius) {}
		DL_CYLINDER(DLMT::DL_VECTOR4AL_PARAMTYPE origin, DLMT::DL_VECTOR4AL_PARAMTYPE direction, dl_float32 radius) : DLMT::DL_SEGMENT(origin, direction), m_fRadius(radius) {}

		dl_float32 GetRadius() const { return m_fRadius; }

		dl_float32 m_fRadius;
	};
}