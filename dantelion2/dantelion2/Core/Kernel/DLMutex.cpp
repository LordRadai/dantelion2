#include "DLMutex.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainMutex*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainMutex*);
	typedef void(_fastcall* Finalize_t)(DLPlainMutex*);

	DLPlainMutex::DLPlainMutex()
	{
		CALL(Constructor_t, 0x88df30, this);
	}

	DLPlainMutex::~DLPlainMutex()
	{
		CALL(Destructor_t, 0x88df50, this);
	}

	dl_bool DLPlainMutex::Initialize()
	{
		return CALL(Initialize_t, 0x88dfb0, this);
	}

	void DLPlainMutex::Finalize()
	{
		CALL(Finalize_t, 0x88dff0, this);
	}

	dl_bool DLPlainMutex::IsValid(void) const
	{
		return m_id != NULL;
	}

	dl_int32 DLPlainMutex::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0x88e040, this, timeout);
	}

	dl_int32 DLPlainMutex::TryLock(void)
	{
		return CALL(oTryLock, 0x88e0d0, this);
	}

	dl_int32 DLPlainMutex::Unlock(void)
	{
		return CALL(oUnlock, 0x88e140, this);
	}
}