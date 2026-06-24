#include "DLHeapManager.h"
#include "Call.h"

namespace DLKR
{
	typedef DLKR::DLAllocator*(_fastcall* FindHeap_t)(dl_pointer);

	DLKR::DLAllocator* DLHeapManager::FindHeap(dl_pointer p)
	{
		return CALL(FindHeap_t, 0x8389e0, p);
	}
}