#include "DLResourceFileLoadEvent.h"
#include "Call.h"

namespace DLRS
{
	typedef void(_fastcall* oConstructor)(DLResourceFileLoadEvent*);

	DLResourceFileLoadEvent::DLResourceFileLoadEvent()
	{
		CALL(oConstructor, 0x8f7310, this);
	}
}
