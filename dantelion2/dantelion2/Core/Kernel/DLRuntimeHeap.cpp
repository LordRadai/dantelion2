#include "DLRuntimeHeap.h"

#include "Call.h"

namespace DLKR
{
	typedef DLKR::DLAllocator* (_fastcall* GetAllocator_t)();

	DLAllocator* DLRuntimeHeap::GetAllocator()
	{
		return CALL(GetAllocator_t, 0x35040);
	}
}