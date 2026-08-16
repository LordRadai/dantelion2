#include "DLCharacterSetUtil.h"

namespace DLTX
{
	DLString DLCharacterSetUtil::AsciiToUnicode(DLAsciiString& ascii)
	{
		std::wstring utf(ascii.begin(), ascii.end());

		return DLTX::DLString(utf.c_str());
	}
}