#include "DLAllocationHelper.h"
#include "Core/System/DLRuntime.h"

namespace DLKRD
{
	typedef DLKR::DLAllocator* (_fastcall* oGetTemporaryAllocator)();

	DLKR::DLAllocator* GetTemporaryAllocator()
	{
		return CALL(oGetTemporaryAllocator, 0x833dc0);
	}

	DLKR::DLAllocator* GetDefaultAllocator()
	{
		return DLSY::DLRuntime::GetRuntime()->GetDefaultAllocator();
	}
}