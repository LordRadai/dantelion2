#include "DLTemporaryMemoryTraits.h"
#include "Call.h"

typedef DLKR::DLAllocator* (_fastcall* GetDefaultHost_t)();

namespace DLUT
{
	DLKR::DLAllocator* DLTemporaryMemoryTraits::GetDefaultHost()
	{
		return CALL(GetDefaultHost_t, 0x833dc0);
	}
}