#include "DLCategoryRepository.h"
#include "FRPG2Call.h"

namespace DLLG
{
	DLRF::DLRuntimeClass* DLCategoryRepository::GetRuntimeClass()
	{
		return FRPG2_CALL(oGetRuntimeClass, 0x8865c0, this);
	}
	
	DLCategoryRepository::~DLCategoryRepository()
	{
		FRPG2_CALL(oDestructor, 0x8872e0, this);
	}
}
