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

	    dl_bool Initialize();
	    void Finalize();
    };
}
