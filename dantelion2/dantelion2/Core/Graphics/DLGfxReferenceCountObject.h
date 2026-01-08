#pragma once
#include "Core/Kernel/DLAllocator.h"
#include "Core/Util/DLReferenceCountObject.h"

namespace DLGR
{
	class DLGfxReferenceCountObject : public DLUT::DLReferenceCountObject
	{
	protected:
		DLKR::DLAllocator* m_pAllocator;
	};
}