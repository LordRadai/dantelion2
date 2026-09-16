#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static const dl_wchar* AsciiToUnicode(const dl_char* ascii);
		static const dl_char* UnicodeToAscii(const dl_wchar* unicode);
		static const dl_char* UnicodeToUtf8(const dl_wchar* unicode);
		static const dl_wchar* Utf8ToUnicode(const dl_char* utf8);
		static const dl_char* ShiftJisToUtf8(const dl_char* shiftJis);
		static const dl_char* Utf8ToShiftJis(const dl_char* utf8);
		static const dl_wchar* ShiftJisToUnicode(const dl_char* shiftJis);
		static const dl_char* UnicodeToShiftJis(const dl_wchar* unicode);
	};
}