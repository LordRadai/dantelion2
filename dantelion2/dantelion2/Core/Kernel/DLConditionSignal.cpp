#include "DLConditionSignal.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainConditionSignal*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainConditionSignal*);
	typedef void(_fastcall* Finalize_t)(DLPlainConditionSignal*);
	typedef void(_fastcall* SetState_t)(DLPlainConditionSignal*, dl_bool);

	DLPlainConditionSignal::DLPlainConditionSignal()
	{
		CALL(Constructor_t, 0x8897d0, this);
	}

	DLPlainConditionSignal::~DLPlainConditionSignal()
	{
		CALL(Destructor_t, 0x889ab0, this);
	}

	dl_bool DLPlainConditionSignal::Initialize()
	{
		return CALL(Initialize_t, 0x889850, this);
	}

	void DLPlainConditionSignal::Finalize()
	{
		CALL(Finalize_t, 0x8898a0, this);
	}

	void DLPlainConditionSignal::SetState(dl_bool bState)
	{
		CALL(SetState_t, 0x8898f0, this, bState);
	}

	dl_bool DLPlainConditionSignal::IsValid(void) const
	{
		return m_mutex_id != NULL;
	}

	dl_int DLPlainConditionSignal::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0x889960, this, timeout);
	}

	dl_int32 DLPlainConditionSignal::TryLock()
	{
		return CALL(oTryLock, 0x889a10, this);
	}

	dl_int32 DLPlainConditionSignal::Unlock()
	{
		return CALL(oUnlock, 0x889a80, this);
	}
}
