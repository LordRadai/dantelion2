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

        virtual dl_bool IsValid(void) const;
        virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE);
        virtual dl_int32 TryLock(void);
        virtual dl_int32 Unlock(void);
	};
}