#pragma once
#include "Core/Kernel/DLAllocator.h"
#include "Core/Util/DLReferenceCountObject.h"

namespace DLGR
{
	class DLGfxReferenceCountObject : public DLUT::DLReferenceCountObject
	{
	public:
		virtual void Destroy() override;
		virtual ~DLGfxReferenceCountObject();

		typedef void(_fastcall* Destructor_t)(DLGfxReferenceCountObject*);

	protected:
		DLKR::DLAllocator* m_pAllocator;
	};
}