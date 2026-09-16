#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static DLTX::DLString AsciiToUnicode(const DLAsciiString& ascii);
		static DLTX::DLAsciiString UnicodeToAscii(const DLString& unicode);
		static DLTX::DLAsciiString UnicodeToUtf8(const DLString& unicode);
		static DLTX::DLString Utf8ToUnicode(const DLAsciiString& utf8);
		static DLTX::DLAsciiString ShiftJisToUtf8(const DLAsciiString& shiftJis);
		static DLTX::DLAsciiString Utf8ToShiftJis(const DLAsciiString& utf8);
		static DLTX::DLString ShiftJisToUnicode(const DLAsciiString& shiftJis);
		static DLTX::DLAsciiString UnicodeToShiftJis(const DLString& unicode);
	};
}