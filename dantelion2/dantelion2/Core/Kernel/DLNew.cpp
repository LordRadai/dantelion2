#include "DLNew.h"
#include "Call.h"

typedef dl_pointer(_fastcall* AllocateAligned_t)(size_t, size_t, DLKR::DLAllocator*);
typedef void(_fastcall* Deallocate_t)(void*, DLKR::DLAllocator*);

namespace DLKR
{
	dl_pointer AllocationSupporter::Allocate(size_t blockSize, dl_size align, DLAllocator* pAllocator)
	{
		return CALL(AllocateAligned_t, 0x833320, blockSize, align, pAllocator);
	}

	void AllocationSupporter::Deallocate(void* p, DLAllocator* pAllocator)
	{
		return CALL(Deallocate_t, 0x8332d0, p, pAllocator);
	}
}