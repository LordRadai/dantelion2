#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainReadWriteLock : public DLSyncObject {

        enum {
            INVALID_RWLOCK_ID = 0
        };

        sys_rwlock_t m_id;
        sys_rwlock_t m_10;
        sys_rwlock_t m_18;
        dl_int m_20;
    public:
		DLPlainReadWriteLock();

		virtual ~DLPlainReadWriteLock() override;
		virtual dl_bool IsValid(void) const override;
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
		virtual dl_int32 TryLock(void) override;
		virtual dl_int32 Unlock(void) override;

		dl_bool Initialize();
		void Finalize();

        dl_int32 ReadLock(DLTimeout timeout = DL_TIMEOUT_INFINITE);
		dl_int32 ReadUnlock();
		dl_int32 WriteLock(DLTimeout timeout = DL_TIMEOUT_INFINITE);
		dl_int32 TryWriteLock();
		dl_int32 WriteUnlock();
    };
}