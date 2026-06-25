#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainMutex : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_mutex_t m_id;

    public:
		DLPlainMutex();
        virtual ~DLPlainMutex() override;
        virtual dl_bool IsValid(void) const override;
        virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
        virtual dl_int32 TryLock(void) override;
        virtual dl_int32 Unlock(void) override;

	    dl_bool Initialize();
	    void Finalize();
    };
}
