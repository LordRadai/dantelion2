#include "GeneralUtility.h"
#include "Core/System/DLRuntime.h"
#include "Core/System/DLTrace.h"
#include <cstdarg>
#include <cstdio>

DLPanicMode& DLPanic::panic_mode_override = *(DLPanicMode*)(MODULE_ADDR + 0x157d524);

void DLPanic::ReportPanic(const dl_char* file, dl_uint32 line, const dl_char* reason, ...)
{
	dl_char buf[4096];

	va_list args;
	va_start(args, reason);
	vsnprintf(buf, sizeof(buf), reason, args);
	va_end(args);

	switch (panic_mode_override)
	{
	case DLPanicMode::DLPANICMODE_COREDUMP:
		break;
	case DLPanicMode::DLPANICMODE_INVOKEDEBUGGER:
		DLSY::DLRawTrace(true, "---------------------------------\n[Dantelion2 Panic] \n%s(%d)\n", file, line);
		DLSY::DLRawTrace(true, "%s\n", buf);

		DLSY::DLRuntime::InvokeDebugger();

		DLSY::DLRawTrace(true, "\n---------------------------------\n");
		break;
	case DLPanicMode::DLPANICMODE_THROWEXCEPTION:
	{
		throw DLPanicException(buf);
	}
	default:
		break;
	}

	DLSY::DLRawTrace(true, "DL_PANIC is firing core dump...\n");
	DLSY::DLRuntime::Abort();
}