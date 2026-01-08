#include "DLCategoryRepository.h"
#include "Call.h"

namespace DLLG
{
	DLRF::DLRuntimeClass* DLCategoryRepository::GetRuntimeClass()
	{
		return CALL(oGetRuntimeClass, 0x8865c0, this);
	}
	
	DLCategoryRepository::~DLCategoryRepository()
	{
		CALL(oDestructor, 0x8872e0, this);
	}
}
