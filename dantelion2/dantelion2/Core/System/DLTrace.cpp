#include "DLTrace.h"
#include "Call.h"

namespace
{
}

namespace DLSY
{
	typedef void(_fastcall* DLTrace_t)(const dl_char*, ...);
	typedef void(_fastcall* DLTraceCategory_t)(const dl_char*, const dl_char*, ...);
	typedef void(_fastcall* DLEnableTrace_t)(dl_bool);
	typedef void(_fastcall* DLRawTrace_t)(dl_bool, const dl_char*, ...);

	void DLTrace(const dl_char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		CALL(DLTrace_t, 0x882b70, fmt, args);

		va_end(args);
	}

	void DLTraceCategory(const dl_char* category, const dl_char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		CALL(DLTraceCategory_t, 0x882c30, category, fmt, args);

		va_end(args);
	}

	void DLEnableTrace(dl_bool bEnable)
	{
		CALL(DLEnableTrace_t, 0x882d40, bEnable);
	}

	void DLRawTrace(dl_bool bPrint, const dl_char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		CALL(DLRawTrace_t, 0x882c90, bPrint, fmt, args);

		va_end(args);
	}

	void DLRawTraceV(dl_bool bPrint, const dl_char* fmt, va_list args)
	{
		DLRawTrace(bPrint, fmt, args);
	}
}