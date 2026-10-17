#pragma once
#include "Core/Platform/Platform.h"

namespace DLMT
{
	template <typename T>
	inline T DLMin(T a, T b) { return (a < b) ? a : b; }

	template <typename T>
	inline T DLMax(T a, T b) { return (a > b) ? a : b; }
}