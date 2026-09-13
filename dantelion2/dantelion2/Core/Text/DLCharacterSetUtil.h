#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static DLTX::DLString AsciiToUnicode(const DLAsciiString& ascii);
		static DLTX::DLAsciiString UnicodeToAscii(const DLString& unicode);
	};
}