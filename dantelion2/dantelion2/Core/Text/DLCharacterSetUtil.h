#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLCharacterSetUtil
	{
	public:
		static DLTX::DLString AsciiToUnicode(DLAsciiString& ascii);
	};
}