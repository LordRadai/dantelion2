#include "DLSingleSignal.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainSingleSignal*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainSingleSignal*);
	typedef void(_fastcall* Finalize_t)(DLPlainSingleSignal*);
	typedef void(_fastcall* Signal_t)(DLPlainSingleSignal*);

	DLPlainSingleSignal::DLPlainSingleSignal()
	{
		CALL(Constructor_t, 0x8f2ea0, this);
	}

	DLPlainSingleSignal::~DLPlainSingleSignal()
	{
		CALL(Destructor_t, 0x8f3160, this);
	}

	dl_bool DLPlainSingleSignal::Initialize()
	{
		return CALL(Initialize_t, 0x8f2f20, this);
	}

	void DLPlainSingleSignal::Finalize()
	{
		CALL(Finalize_t, 0x8f2f70, this);
	}

	dl_bool DLPlainSingleSignal::IsValid(void) const
	{
		return m_id != NULL;
	}

	dl_int32 DLPlainSingleSignal::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0x8f3000, this, timeout);
	}

	dl_int32 DLPlainSingleSignal::TryLock(void)
	{
		return CALL(oTryLock, 0x8f30b0, this);
	}

	dl_int32 DLPlainSingleSignal::Unlock(void)
	{
		return CALL(oUnlock, 0x8f3120, this);
	}

	void DLPlainSingleSignal::Signal()
	{
		CALL(Signal_t, 0x8f2fc0, this);
	}
}