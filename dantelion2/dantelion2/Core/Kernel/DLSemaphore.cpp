#include "DLSemaphore.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainSemaphore*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainSemaphore*);
	typedef void(_fastcall* Finalize_t)(DLPlainSemaphore*);

	DLPlainSemaphore::DLPlainSemaphore()
	{
		CALL(Constructor_t, 0x91f7c0, this);
	}

	DLPlainSemaphore::~DLPlainSemaphore()
	{
		CALL(Destructor_t, 0x91fb50, this);
	}

	dl_bool DLPlainSemaphore::IsValid(void) const
	{
		return m_semaphore != NULL;
	}

	dl_int32 DLPlainSemaphore::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0x91f970, this, timeout);
	}

	dl_int32 DLPlainSemaphore::TryLock(void)
	{
		return CALL(oTryLock, 0x91fa20, this);
	}

	dl_int32 DLPlainSemaphore::Unlock(void)
	{
		return CALL(oUnlock, 0x91fa90, this);
	}
}