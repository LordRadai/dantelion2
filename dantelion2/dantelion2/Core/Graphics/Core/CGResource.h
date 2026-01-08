#pragma once
#include "Core/Kernel/DLAllocator.h"

namespace DLCG2
{
	class CGResource
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		dl_int m_nRefCount;
	};
}