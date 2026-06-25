#include "DLReadWriteLock.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainReadWriteLock*);
	typedef dl_bool(_fastcall* Initialize_t)(DLPlainReadWriteLock*);
	typedef void(_fastcall* Finalize_t)(DLPlainReadWriteLock*);
	typedef dl_int32(_fastcall* ReadLock_t)(DLPlainReadWriteLock*, dl_int);
	typedef dl_int32(_fastcall* ReadUnlock_t)(DLPlainReadWriteLock*);
	typedef dl_int32(_fastcall* WriteLock_t)(DLPlainReadWriteLock*, dl_int);
	typedef dl_int32(_fastcall* TryWriteLock_t)(DLPlainReadWriteLock*);
	typedef dl_int32(_fastcall* WriteUnlock_t)(DLPlainReadWriteLock*);

	DLPlainReadWriteLock::DLPlainReadWriteLock()
	{
		CALL(Constructor_t, 0x88b4b0, this);
	}

	DLPlainReadWriteLock::~DLPlainReadWriteLock()
	{
		CALL(Destructor_t, 0x88bac0, this);
	}

	dl_bool DLPlainReadWriteLock::Initialize()
	{
		return CALL(Initialize_t, 0x88b550, this);
	}

	void DLPlainReadWriteLock::Finalize()
	{
		CALL(Finalize_t, 0x88b4e0, this);
	}

	dl_bool DLPlainReadWriteLock::IsValid(void) const
	{
		return m_id != NULL;
	}

	dl_int32 DLPlainReadWriteLock::Lock(DLTimeout timeout)
	{
		return CALL(oLock, 0x88b670, this, timeout);
	}

	dl_int32 DLPlainReadWriteLock::TryLock(void)
	{
		return CALL(oTryLock, 0x88b680, this);
	}

	dl_int32 DLPlainReadWriteLock::Unlock(void)
	{
		return CALL(oUnlock, 0x88b6f0, this);
	}

	dl_int32 DLPlainReadWriteLock::ReadLock(DLTimeout timeout)
	{
		return CALL(ReadLock_t, 0x88b740, this, timeout);
	}

	dl_int32 DLPlainReadWriteLock::ReadUnlock()
	{
		return CALL(ReadUnlock_t, 0x88b880, this);
	}

	dl_int32 DLPlainReadWriteLock::WriteLock(DLTimeout timeout)
	{
		return CALL(WriteLock_t, 0x88b8d0, this, timeout);
	}

	dl_int32 DLPlainReadWriteLock::TryWriteLock()
	{
		return CALL(TryWriteLock_t, 0x88b810, this);
	}

	dl_int32 DLPlainReadWriteLock::WriteUnlock()
	{
		return CALL(WriteUnlock_t, 0x88ba60, this);
	}
}