#pragma once
#include "Core/Platform/Platform.h"

namespace DLSY
{
	void DLRawTrace(dl_bool bPrint, dl_char* fmt, ...);
	void DLTrace(dl_char* fmt, ...);
	void DLTraceCategory(dl_char* category, dl_char* fmt, ...);
	void DLEnableTrace(dl_bool bEnable);
}