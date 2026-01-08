#include "DLResourceFileLoadEventQueue.h"
#include "FRPG2Call.h"

namespace DLRS
{
	typedef bool(_fastcall* oGetFileLoadEvent)(DLResourceFileLoadEventQueue* pThis, DLResourceFileLoadEvent* pOutEvent);

	bool DLResourceFileLoadEventQueue::GetFileLoadEvent(DLResourceFileLoadEvent* pOutEvent)
	{
		return FRPG2_CALL(oGetFileLoadEvent, 0x8d76f0, this, pOutEvent);
	}
}
