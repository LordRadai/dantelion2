#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainSemaphore : public DLSyncObject {

        enum {
            INVALID_SEMA_ID = 0
        };

        sys_semaphore_t m_semaphore;
        dl_int32 m_initial;
        dl_int32 m_max;
    public:
		DLPlainSemaphore();
        
        virtual ~DLPlainSemaphore() override;
		virtual dl_bool IsValid(void) const override;
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
		virtual dl_int32 TryLock(void) override;
		virtual dl_int32 Unlock(void) override;
    };
}