#pragma once
#include "Core/Platform/Platform.h"

namespace DLSY
{
	void DLRawTrace(dl_bool bPrint, const dl_char* fmt, ...);
	void DLRawTraceV(dl_bool bPrint, const dl_char* fmt, va_list args);
	void DLTrace(const dl_char* fmt, ...);
	void DLTraceCategory(const dl_char* category, const dl_char* fmt, ...);
	void DLEnableTrace(dl_bool bEnable);
}