#include "DLTrigonometry.h"
#include <cmath>

namespace DLMT
{
	dl_float32 DLCosf(dl_float32 radians)
	{
		return std::cos(radians);
	}

	dl_float32 DLSinf(dl_float32 radians)
	{
		return std::sin(radians);
	}

	dl_float32 DLTanf(dl_float32 radians)
	{
		return std::tan(radians);
	}

	dl_float32 DLACosf(dl_float32 value)
	{
		return std::acos(value);
	}

	dl_float32 DLASinf(dl_float32 value)
	{
		return std::asin(value);
	}

	dl_float32 DLATanf(dl_float32 value)
	{
		return std::atan(value);
	}

	dl_float32 DLATan2f(dl_float32 y, dl_float32 x)
	{
		return std::atan2(y, x);
	}
}