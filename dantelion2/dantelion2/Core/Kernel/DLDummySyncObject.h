#pragma once
#include "DLSyncObject.h"
#include "Core/Platform/Platform.h"
#include "Types.h"
#include "SyncTraits.h"

namespace DLKR
{
	class DLDummySyncObject : public DLSyncObject
	{
	public:
		virtual dl_bool IsValid(void) const override { return true; }
		virtual dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE) override { return 0; }
		virtual dl_int32 TryLock(void) override { return 0; }
		virtual dl_int32 Unlock(void) override { return 0; }
	};
}