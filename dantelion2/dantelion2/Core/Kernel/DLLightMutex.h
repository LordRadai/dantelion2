#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainLightMutex : public DLSyncObject 
    {
        sys_lwmutex_t m_id;
        dl_bool m_bIsValid;
    public:
		DLPlainLightMutex();

		virtual ~DLPlainLightMutex() override;
		virtual dl_bool IsValid(void) const override;
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
		virtual dl_int32 TryLock(void) override;
		virtual dl_int32 Unlock(void) override;

        dl_bool Initialize();
        void Finalize();
    };
}