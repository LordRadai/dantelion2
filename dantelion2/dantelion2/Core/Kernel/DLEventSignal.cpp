#include "DLEventSignal.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainEventSignal*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainEventSignal*);
	typedef void(_fastcall* Finalize_t)(DLPlainEventSignal*);
	typedef dl_int32(_fastcall* Wait_t)(DLPlainEventSignal*);

	DLPlainEventSignal::DLPlainEventSignal()
	{
		CALL(Constructor_t, 0xefef30, this);
	}

	DLPlainEventSignal::~DLPlainEventSignal()
	{
		CALL(Destructor_t, 0xeff1c0, this);
	}

	dl_bool DLPlainEventSignal::Initialize()
	{
		return CALL(Initialize_t, 0xefefb0, this);
	}

	void DLPlainEventSignal::Finalize()
	{
		CALL(Finalize_t, 0xeff000, this);
	}

	dl_int32 DLPlainEventSignal::Wait()
	{
		return CALL(Wait_t, 0xeff050, this);
	}

	dl_bool DLPlainEventSignal::IsValid(void) const
	{
		return m_mutex_id != NULL;
	}

	dl_int32 DLPlainEventSignal::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0xeff090, this, timeout);
	}

	dl_int32 DLPlainEventSignal::TryLock(void)
	{
		return CALL(oTryLock, 0xeff140, this);
	}

	dl_int32 DLPlainEventSignal::Unlock(void)
	{
		return CALL(oUnlock, 0xeff180, this);
	}
}