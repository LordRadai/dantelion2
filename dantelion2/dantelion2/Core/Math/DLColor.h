#pragma once
#include "DLVector.h"
#include "Core/Platform/Platform.h"

namespace DLMT
{
	typedef dl_uint DL_COLOR_32;
}

namespace DLMT2
{
	struct DL_COLOR_U8
	{
		dl_uchar A;
		dl_uchar B;
		dl_uchar G;
		dl_uchar R;
	};
}