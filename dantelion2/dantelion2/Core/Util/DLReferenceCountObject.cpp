#include "DLReferenceCountObject.h"

namespace DLUT
{
	void DLReferenceCountObject::AddRef()
	{
		this->m_nRefCount += 1;
	}

	void DLReferenceCountObject::UnRef()
	{
		this->m_nRefCount -= 1;
	}
}