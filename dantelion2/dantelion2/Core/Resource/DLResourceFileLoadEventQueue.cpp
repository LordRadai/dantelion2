#include "DLResourceFileLoadEventQueue.h"
#include "Call.h"

namespace DLRS
{
	typedef bool(_fastcall* oGetFileLoadEvent)(DLResourceFileLoadEventQueue* pThis, DLResourceFileLoadEvent* pOutEvent);

	bool DLResourceFileLoadEventQueue::GetFileLoadEvent(DLResourceFileLoadEvent* pOutEvent)
	{
		return CALL(oGetFileLoadEvent, 0x8d76f0, this, pOutEvent);
	}
}
