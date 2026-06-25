#include "DLMutex.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainMutex*);

	DLPlainMutex::DLPlainMutex()
	{
		CALL(Constructor_t, 0x88df30, this);
	}
}