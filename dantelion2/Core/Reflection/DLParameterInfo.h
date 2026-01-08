#pragma once
#include "DLTypeID.h"

namespace DLRF
{
	struct DLParameterInfo
	{
		const static dl_uint32 MAX_PARAM_SIZE = 15;

		DLTypeID id[MAX_PARAM_SIZE];
		const void* pData;
	};
}
