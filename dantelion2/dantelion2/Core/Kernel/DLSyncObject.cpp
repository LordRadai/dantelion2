#include "DLSyncObject.h"
#include "Call.h"

namespace DLKR
{
	typedef void(__fastcall* oDestructor)(DLSyncObject* pThis);
	typedef dl_bool(__fastcall* oIsValid)(DLSyncObject* pThis);
	typedef dl_int32(__fastcall* oLock)(DLSyncObject* pThis, DLTimeout);
	typedef dl_int32(__fastcall* oTryLock)(DLSyncObject* pThis);
	typedef dl_int32(__fastcall* oUnlock)(DLSyncObject* pThis);

	DLSyncObject::~DLSyncObject() {
		VIRTUAL_CALL(this, 0, oDestructor, this);
	}

	dl_bool DLSyncObject::IsValid() const {
		return VIRTUAL_CALL((DLSyncObject*)this, 1, oIsValid, (DLSyncObject*)this);
	}

	dl_int32 DLSyncObject::Lock(DLTimeout timeout) {
		return VIRTUAL_CALL(this, 2, oLock, this, timeout);
	}

	dl_int32 DLSyncObject::TryLock() {
		return VIRTUAL_CALL(this, 3, oTryLock, this);
	}

	dl_int32 DLSyncObject::Unlock() {
		return VIRTUAL_CALL(this, 4, oUnlock, this);
	}
}