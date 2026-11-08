#pragma once
#include "DLString.inl"

namespace DLTX
{
	template<class _Elem>
	class DLFormat
	{
	};

	template<>
	class DLFormat<dl_char>
	{
	public:
		static dl_size FormatV(dl_char* buf, dl_size size, const dl_char* fmt, va_list args);
		static dl_size FormatV(dl_char* buf, const dl_char* fmt, va_list args);
		static dl_size FormatV(DLAsciiString& str, const dl_char* fmt, va_list args);
		static dl_size Format(dl_char* buf, dl_size size, const dl_char* fmt, ...);
		static dl_size Format(dl_char* buf, const dl_char* fmt, ...);
		static dl_size Format(DLAsciiString& str, const dl_char* fmt, ...);
	};

	template<>
	class DLFormat<dl_wchar>
	{
	public:
		static dl_size FormatV(dl_wchar* buf, dl_size size, const dl_wchar* fmt, va_list args);
		static dl_size FormatV(dl_wchar* buf, const dl_wchar* fmt, va_list args);
		static dl_size FormatV(DLString& str, const dl_wchar* fmt, va_list args);
		static dl_size Format(dl_wchar* buf, dl_size size, const dl_wchar* fmt, ...);
		static dl_size Format(dl_wchar* buf, const dl_wchar* fmt, ...);
		static dl_size Format(DLString& str, const dl_wchar* fmt, ...);
	};
}