#pragma once
#include "Core/Kernel/DLAllocator.h"

namespace DLCG2
{
	class CGResource
	{
	public:
		virtual ~CGResource();

		typedef void(_fastcall* Destructor_t)(CGResource*);
	protected:
		DLKR::DLAllocator* m_pAllocator;
		dl_int m_nRefCount;
	};
}