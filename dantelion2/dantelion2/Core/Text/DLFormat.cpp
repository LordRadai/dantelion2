#include "DLFormat.h"
#include "Call.h"

namespace DLTX
{
	typedef dl_size(_fastcall* c_FormatV_t)(dl_char*, const dl_char*, va_list);
	typedef dl_size(_fastcall* c_FormatV_size_t)(dl_char*, dl_size, const dl_char*, va_list);
	typedef dl_size(_fastcall* c_FormatV_str_t)(DLAsciiString&, const dl_char*, va_list);

	typedef dl_size(_fastcall* wc_FormatV_t)(dl_wchar*, const dl_wchar*, va_list);
	typedef dl_size(_fastcall* wc_FormatV_size_t)(dl_wchar*, dl_size, const dl_wchar*, va_list);
	typedef dl_size(_fastcall* wc_FormatV_str_t)(DLString&, const dl_wchar*, va_list);

	dl_size DLFormat<dl_char>::Format(DLAsciiString& buf, const dl_char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_size v = FormatV(buf, fmt, args);

		va_end(args);

		return v;
	}

	dl_size DLFormat<dl_char>::Format(dl_char* buf, dl_size size, const dl_char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_size v = FormatV(buf, size, fmt, args);

		va_end(args);

		return v;
	}

	dl_size DLFormat<dl_char>::Format(dl_char* buf, const dl_char* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_size v = FormatV(buf, fmt, args);

		va_end(args);

		return v;
	}

	dl_size DLFormat<dl_char>::FormatV(dl_char* buf, const dl_char* fmt, va_list args)
	{
		return CALL(c_FormatV_t, 0x834c90, buf, fmt, args);
	}

	dl_size DLFormat<dl_char>::FormatV(dl_char* buf, dl_size size, const dl_char* fmt, va_list args)
	{
		return CALL(c_FormatV_size_t, 0x834c60, buf, size, fmt, args);
	}

	dl_size DLFormat<dl_char>::FormatV(DLAsciiString& buf, const dl_char* fmt, va_list args)
	{
		return CALL(c_FormatV_str_t, 0x834cb0, buf, fmt, args);
	}

	dl_size DLFormat<dl_wchar>::Format(DLString& buf, const dl_wchar* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_size v = FormatV(buf, fmt, args);

		va_end(args);

		return v;
	}

	dl_size DLFormat<dl_wchar>::Format(dl_wchar* buf, dl_size size, const dl_wchar* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_size v = FormatV(buf, size, fmt, args);

		va_end(args);

		return v;
	}

	dl_size DLFormat<dl_wchar>::Format(dl_wchar* buf, const dl_wchar* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		dl_size v = FormatV(buf, fmt, args);

		va_end(args);

		return v;
	}

	dl_size DLFormat<dl_wchar>::FormatV(dl_wchar* buf, const dl_wchar* fmt, va_list args)
	{
		return CALL(wc_FormatV_t, 0x834f40, buf, fmt, args);
	}

	dl_size DLFormat<dl_wchar>::FormatV(dl_wchar* buf, dl_size size, const dl_wchar* fmt, va_list args)
	{
		return CALL(wc_FormatV_size_t, 0x834f10, buf, size, fmt, args);
	}

	dl_size DLFormat<dl_wchar>::FormatV(DLString& buf, const dl_wchar* fmt, va_list args)
	{
		return CALL(wc_FormatV_str_t, 0x834f60, buf, fmt, args);
	}
}