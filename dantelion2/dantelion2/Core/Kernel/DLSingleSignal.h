#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainSingleSignal : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_semaphore_t m_id;
        dl_bool m_initialStatus;
    public:
		DLPlainSingleSignal();

		virtual ~DLPlainSingleSignal() override;
		virtual dl_bool IsValid(void) const override;
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
		virtual dl_int32 TryLock(void) override;
		virtual dl_int32 Unlock(void) override;

		dl_bool Initialize();
		void Finalize();

		void Signal();
    };
}