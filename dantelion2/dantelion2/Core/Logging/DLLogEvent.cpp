#include "DLLogEvent.h"
#include "Call.h"

namespace DLLG
{
	DLLogEvent::DLLogEvent(DLLogLevel level, DLCategory* pCategory, const dl_wchar* cName, const dl_wchar* fmt, va_list args) : m_level(level)
	{
		CALL(oConstructor, 0x882890, this, level, pCategory, cName, fmt, args);
	}
}
