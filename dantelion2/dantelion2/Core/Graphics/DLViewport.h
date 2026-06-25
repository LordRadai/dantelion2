#pragma once
#include "Core/Platform/Platform.h"

namespace DLGR
{
	struct DL_VIEWPORT
	{
		dl_uint iVar0;
		dl_uint iVar4;
		dl_uint Width;
		dl_uint Height;
		dl_uint iVar10;
		dl_uint iVar14;

		DL_VIEWPORT() {}
		DL_VIEWPORT(dl_uint width, dl_uint height)
			: iVar0(0), iVar4(0), Width(width), Height(height), iVar10(0), iVar14(0) {}
	};
}