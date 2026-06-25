#include "DLLightMutex.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainLightMutex*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainLightMutex*);
	typedef void(_fastcall* Finalize_t)(DLPlainLightMutex*);

	DLPlainLightMutex::DLPlainLightMutex()
	{
		CALL(Constructor_t, 0x84b400, this);
	}

	DLPlainLightMutex::~DLPlainLightMutex()
	{
		CALL(Destructor_t, 0x84b430, this);
	}

	dl_bool DLPlainLightMutex::Initialize()
	{
		return CALL(Initialize_t, 0x84b480, this);
	}

	void DLPlainLightMutex::Finalize()
	{
		CALL(Finalize_t, 0x84b4b0, this);
	}

	dl_bool DLPlainLightMutex::IsValid(void) const
	{
		return m_bIsValid;
	}

	dl_int32 DLPlainLightMutex::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0x84b4f0, this, timeout);
	}

	dl_int32 DLPlainLightMutex::TryLock(void)
	{
		return CALL(oTryLock, 0x84b530, this);
	}

	dl_int32 DLPlainLightMutex::Unlock(void)
	{
		return CALL(oUnlock, 0x84b560, this);
	}
}