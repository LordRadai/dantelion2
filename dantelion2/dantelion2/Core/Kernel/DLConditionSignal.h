#pragma once
#include "DLAtomicInt.h"
#include "DLSyncObject.h"
#include "Core/Platform/GeneralUtility.h"
#include "Types.h"
#include <Windows.h>

namespace DLKR
{
    class DLPlainConditionSignal : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_mutex_t m_mutex_id;

    public:
		DLPlainConditionSignal();

        dl_bool Initialize();
		void Finalize();

		void SetState(dl_bool bState);

		virtual ~DLPlainConditionSignal() override;
		virtual dl_bool IsValid(void) const override;
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override;
		virtual dl_int32 TryLock(void) override;
		virtual dl_int32 Unlock(void) override;
    };
}