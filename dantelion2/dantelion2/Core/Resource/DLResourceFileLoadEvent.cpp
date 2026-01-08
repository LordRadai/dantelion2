#include "DLResourceFileLoadEvent.h"
#include "dantelion2/FRPG2Call.h"

namespace DLRS
{
	typedef void(_fastcall* oConstructor)(DLResourceFileLoadEvent*);

	DLResourceFileLoadEvent::DLResourceFileLoadEvent()
	{
		FRPG2_CALL(oConstructor, 0x8f7310, this);
	}
}
