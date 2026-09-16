#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static std::wstring AsciiToUnicode(const dl_char* ascii);
		static std::string UnicodeToAscii(const dl_wchar* unicode);
		static std::string UnicodeToUtf8(const dl_wchar* unicode);
		static std::wstring Utf8ToUnicode(const dl_char* utf8);
		static std::string ShiftJisToUtf8(const dl_char* shiftJis);
		static std::string Utf8ToShiftJis(const dl_char* utf8);
		static std::wstring ShiftJisToUnicode(const dl_char* shiftJis);
		static std::string UnicodeToShiftJis(const dl_wchar* unicode);
	};
}