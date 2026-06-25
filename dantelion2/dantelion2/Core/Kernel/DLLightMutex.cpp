#include "DLLightMutex.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainLightMutex*);

	DLPlainLightMutex::DLPlainLightMutex()
	{
		CALL(Constructor_t, 0x84b400, this);
	}
}