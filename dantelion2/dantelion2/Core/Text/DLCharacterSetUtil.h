#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static DLTX::DLString AsciiToUnicode(const DLTX::DLAsciiString& ascii);
		static DLTX::DLAsciiString UnicodeToAscii(const DLTX::DLString& unicode);
		static DLTX::DLAsciiString UnicodeToUtf8(const DLTX::DLString& unicode);
		static DLTX::DLString Utf8ToUnicode(const DLTX::DLAsciiString& utf8);
		static DLTX::DLAsciiString ShiftJisToUtf8(const DLTX::DLAsciiString& shiftJis);
		static DLTX::DLAsciiString Utf8ToShiftJis(const DLTX::DLAsciiString& utf8);
		static DLTX::DLString ShiftJisToUnicode(const DLTX::DLAsciiString& shiftJis);
		static DLTX::DLAsciiString UnicodeToShiftJis(const DLTX::DLString& unicode);
	};
}