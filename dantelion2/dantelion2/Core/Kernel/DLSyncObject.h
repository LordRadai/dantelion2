#pragma once
#include "Core/Util/DLNonCopyable.h"
#include "Core/Platform/Platform.h"
#include "Types.h"
#include "SyncTraits.h"

namespace DLKR
{
	class DLSyncObject : public DLUT::DLNonCopyable
	{
    public:
        enum ERROR_CODE 
        {
            ERR_NONE,
            ERR_RESOURCE,
            ERR_BUSY,
            ERR_TIMEOUT,
            ERR_UNKNOWN,
        };

        virtual dl_bool IsValid(void) const = 0;
        virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) = 0;
        virtual dl_int32 TryLock(void) = 0;
        virtual dl_int32 Unlock(void) = 0;

        typedef void(_fastcall* oDestructor)(DLSyncObject* pThis);
        typedef dl_bool(_fastcall* oIsValid)(const DLSyncObject* pThis);
        typedef dl_int32(_fastcall* oLock)(DLSyncObject* pThis, DLTimeout);
        typedef dl_int32(_fastcall* oTryLock)(DLSyncObject* pThis);
        typedef dl_int32(_fastcall* oUnlock)(DLSyncObject* pThis);
	};
}