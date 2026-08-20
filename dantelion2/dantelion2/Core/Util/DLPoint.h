#pragma once
#include "Core/Math/DLVector.h"

namespace DLUT
{
	class DL_POINT : public DLMT::DL_VECTOR2
	{
	public:
		DL_POINT() : DLMT::DL_VECTOR2() {}
		DL_POINT(dl_float32 x, dl_float32 y) : DLMT::DL_VECTOR2(x, y) {}
		DL_POINT(dl_uint x, dl_uint y) : DLMT::DL_VECTOR2(static_cast<dl_float32>(x), static_cast<dl_float32>(y)) {}
	};
}