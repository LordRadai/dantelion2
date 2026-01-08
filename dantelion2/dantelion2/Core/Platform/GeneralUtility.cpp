#include "GeneralUtility.h"
#include "dantelion2/FRPG2Call.h"
#include "dantelion2/Core/System/DLRuntime.h"
#include <cstdarg>
#include <cstdio>

void PrintDebugString(const char* str, ...)
{
	char buf[4096];
	va_list args;
	va_start(args, str);
	vsnprintf(buf, sizeof(buf), str, args);
	va_end(args);

	OutputDebugStringA(buf);
}

void DLPanic::ReportPanic(const dl_char* file, dl_uint32 line, const dl_char* reason)
{
	switch (DL_PANIC_MODE)
	{
	case DLPanicMode::DLPANICMODE_INVOKEDEBUGGER:
		PrintDebugString("---------------------------------\n[Dantelion2 Panic] \n%s(%d)\n%s\n", file, line, reason);
		DLSY::DLRuntime::InvokeDebugger();
		PrintDebugString("\n---------------------------------\n");
		break;
	case DLPanicMode::DLPANICMODE_THROWEXCEPTION:
	{
		char buf[4096];
		snprintf(buf, sizeof(buf), "\n%s(%d):\n%s\n", file, line, reason);

		throw DLPanicException(buf);
		break;
	}
	case DLPanicMode::DLPANICMODE_COREDUMP:
		break;
	default:
		break;
	}

	PrintDebugString("DL_PANIC is firing core dump...\n");
	std::abort();
}