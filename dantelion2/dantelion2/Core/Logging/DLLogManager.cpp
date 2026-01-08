#include "DLLogManager.h"
#include "Call.h"

namespace DLLG
{
	typedef void(_fastcall* oDestructor)(DLLogManager*);

	DLLogManager::~DLLogManager()
	{
		CALL(oDestructor, 0x885420, this);
	}
}