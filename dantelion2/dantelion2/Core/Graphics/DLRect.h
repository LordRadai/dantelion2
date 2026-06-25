#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Math/DLVector.h"

namespace DLGR
{
	struct DL_FRECT
	{
		DLMT::DL_VECTOR2 Min;
		DLMT::DL_VECTOR2 Max;

		DL_FRECT() = default;
		DL_FRECT(const DLMT::DL_VECTOR2& min, const DLMT::DL_VECTOR2& max) : Min(min), Max(max) {}
		DL_FRECT(dl_float32 minX, dl_float32 minY, dl_float32 maxX, dl_float32 maxY) : Min(minX, minY), Max(maxX, maxY) {}
		DL_FRECT(dl_float32 x, dl_float32 y) : Min(x, y), Max(0, 0) {}

		DLMT::DL_VECTOR2 GetSize() const { return Max - Min; }
	};
}