#pragma once
#include "DLSyncObject.h"
#include "Types.h"

namespace DLKR
{
    class DLPlainEventSignal : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_mutex_t m_mutex_id;

    public:
		DLPlainEventSignal();

        virtual ~DLPlainEventSignal() override;
		virtual dl_bool IsValid(void) const override;
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
		virtual dl_int32 TryLock(void) override;
		virtual dl_int32 Unlock(void) override;

        dl_bool Initialize();
		void Finalize();

		dl_int32 Wait();
    };
}
