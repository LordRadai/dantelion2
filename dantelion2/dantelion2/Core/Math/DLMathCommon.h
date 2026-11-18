#pragma once
#include "Core/Platform/Platform.h"

namespace DLMT
{
	template <typename T>
	inline T DLMin(T a, T b) { return (a < b) ? a : b; }

	template <typename T>
	inline T DLMax(T a, T b) { return (a > b) ? a : b; }

	dl_float32 DLSqrtf(dl_float32 x) { return sqrtf(x); }
	dl_float32 DLFabsf(dl_float32 x) { return fabsf(x); }
	dl_float32 DLFloorf(dl_float32 x) { return floorf(x); }
	dl_float32 DLCeilf(dl_float32 x) { return ceilf(x); }
}