#include "DLCharacterSetUtil.h"

namespace DLTX
{
	DLString DLCharacterSetUtil::AsciiToUnicode(const DLAsciiString& ascii)
	{
		std::wstring utf(ascii.begin(), ascii.end());

		return DLTX::DLString(utf.c_str());
	}

	DLAsciiString DLCharacterSetUtil::UnicodeToAscii(const DLString& unicode)
	{
		std::string ascii(unicode.begin(), unicode.end());
		return DLTX::DLAsciiString(ascii.c_str());
	}
}