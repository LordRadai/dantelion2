#pragma once
#include "Core/Platform/Platform.h"
#include "DLVector.h"

namespace DLMT
{
	struct DL_FRECT
	{
		DL_VECTOR2 Min;
		DL_VECTOR2 Max;

		DL_FRECT() = default;
		DL_FRECT(const DL_VECTOR2& min, const DL_VECTOR2& max) : Min(min), Max(max) {}
		DL_FRECT(dl_float32 minX, dl_float32 minY, dl_float32 maxX, dl_float32 maxY) : Min(minX, minY), Max(maxX, maxY) {}

		DL_VECTOR2 GetSize() const { return Max - Min; }
	};
}