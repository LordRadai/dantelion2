#include "DLTimer.h"

namespace DLSY
{
	dl_int64& DLTimer::m_timerFreq = *reinterpret_cast<dl_int64*>(MODULE_ADDR + 0x16683b8);
}