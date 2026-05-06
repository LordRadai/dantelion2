#include "DLGfxReferenceCountObject.h"
#include "Call.h"

namespace DLGR
{
	void DLGfxReferenceCountObject::Destroy()
	{
		CALL(Destroy_t, 0x966870, this);
	}

	DLGfxReferenceCountObject::~DLGfxReferenceCountObject()
	{
		CALL(Destructor_t, 0x9668a0, this);
	}
}