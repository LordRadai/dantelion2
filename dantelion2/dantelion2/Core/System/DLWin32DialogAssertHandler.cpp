#include "DLWin32DialogAssertHandler.h"
#include "Call.h"

namespace DLSY
{
	void DLWin32DialogAssertHandler::HandleAssertEvent(const DLPF::DLAssertEvent& event)
	{
		CALL(HandleAssertEvent_t, 0x8c3790, this, event);
	}
}