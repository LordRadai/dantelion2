#include "DLLogManager.h"
#include "FRPG2Call.h"

namespace DLLG
{
	typedef void(_fastcall* oDestructor)(DLLogManager*);

	DLLogManager::~DLLogManager()
	{
		FRPG2_CALL(oDestructor, 0x885420, this);
	}
}