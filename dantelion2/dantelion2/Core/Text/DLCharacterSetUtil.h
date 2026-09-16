#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static const dl_wchar* AsciiToUnicode(const DLAsciiString& ascii);
		static const dl_char* UnicodeToAscii(const DLString& unicode);
		static const dl_char* UnicodeToUtf8(const DLString& unicode);
		static const dl_wchar* Utf8ToUnicode(const DLAsciiString& utf8);
		static const dl_char* ShiftJisToUtf8(const DLAsciiString& shiftJis);
		static const dl_char* Utf8ToShiftJis(const DLAsciiString& utf8);
		static const dl_wchar* ShiftJisToUnicode(const DLAsciiString& shiftJis);
		static const dl_char* UnicodeToShiftJis(const DLString& unicode);
	};
}