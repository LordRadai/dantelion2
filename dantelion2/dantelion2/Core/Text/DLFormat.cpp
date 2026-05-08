#include "DLFormat.h"
#include "Call.h"

namespace DLTX
{
	typedef dl_int(_fastcall* oFormatV)(DLString&, const dl_wchar*, va_list);

	dl_int DLFormat<dl_wchar>::Format(DLString& buf, const dl_wchar* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_int v = FormatV(buf, fmt, args);

		va_end(args);
		return v;
	}

	dl_int DLFormat<dl_wchar>::FormatV(DLString& buf, const dl_wchar* fmt, va_list args)
	{
		return CALL(oFormatV, 0x296c0, buf, fmt, args);
	}
}