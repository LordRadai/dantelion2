#include "Common.h"

namespace dantelion2
{
	typedef DLKR::DLAllocator*(_fastcall* oGetDefaultAllocator)();

	DLKR::DLAllocator* GetDefaultAllocator()
	{
		return CALL(oGetDefaultAllocator, 0xaf14e0);
	}
}