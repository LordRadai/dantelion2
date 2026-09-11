#pragma once
#include "Core/Platform/Platform.h"

namespace DLMT
{
	dl_float32 DLCosf(dl_float32 radians);
	dl_float32 DLSinf(dl_float32 radians);
	dl_float32 DLTanf(dl_float32 radians);
	dl_float32 DLACosf(dl_float32 value);
	dl_float32 DLASinf(dl_float32 value);
	dl_float32 DLATanf(dl_float32 value);
	dl_float32 DLATan2f(dl_float32 y, dl_float32 x);
}