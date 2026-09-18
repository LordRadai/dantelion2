#include "DLCharacterSetUtil.h"
#include "DLCharacterSet.h"

#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <iconv.h>
#endif

namespace DLTX
{
	DLTX::DLString DLCharacterSetUtil::AsciiToUnicode(const DLTX::DLAsciiString& ascii)
	{
		std::wstring unicode(ascii.begin(), ascii.end());
		return DLTX::DLString(unicode.c_str());
	}

	DLTX::DLAsciiString DLCharacterSetUtil::UnicodeToAscii(const DLTX::DLString& unicode)
	{
		std::string ascii(unicode.begin(), unicode.end());
		return DLTX::DLAsciiString(ascii.c_str());
	}

	DLTX::DLAsciiString DLCharacterSetUtil::UnicodeToUtf8(const DLTX::DLString& unicode)
	{
		DLTX::DLAsciiString utf8;
		utf8.reserve(unicode.length() * 3);

		for (size_t i = 0; i < unicode.length(); ++i)
		{
			dl_wchar wc = unicode[i];
			if (wc <= 0x7F)
			{
				utf8.push_back(static_cast<char>(wc));
			}
			else if (wc <= 0x7FF)
			{
				utf8.push_back(static_cast<char>(0xC0 | ((wc >> 6) & 0x1F)));
				utf8.push_back(static_cast<char>(0x80 | (wc & 0x3F)));
			}
			else
			{
				utf8.push_back(static_cast<char>(0xE0 | ((wc >> 12) & 0x0F)));
				utf8.push_back(static_cast<char>(0x80 | ((wc >> 6) & 0x3F)));
				utf8.push_back(static_cast<char>(0x80 | (wc & 0x3F)));
			}
		}

		return utf8;
	}

	DLTX::DLString DLCharacterSetUtil::Utf8ToUnicode(const DLTX::DLAsciiString& utf8)
	{
		DLTX::DLString unicode;
		unicode.reserve(utf8.length());
		size_t i = 0;
		while (i < utf8.length())
		{
			unsigned char c = static_cast<unsigned char>(utf8[i]);
			if (c <= 0x7F)
			{
				unicode.push_back(static_cast<dl_wchar>(c));
				i++;
			}
			else if ((c & 0xE0) == 0xC0)
			{
				if (i + 1 >= utf8.length()) break;
				unsigned char c2 = static_cast<unsigned char>(utf8[i + 1]);
				unicode.push_back(static_cast<dl_wchar>(((c & 0x1F) << 6) | (c2 & 0x3F)));
				i += 2;
			}
			else if ((c & 0xF0) == 0xE0)
			{
				if (i + 2 >= utf8.length()) break;
				unsigned char c2 = static_cast<unsigned char>(utf8[i + 1]);
				unsigned char c3 = static_cast<unsigned char>(utf8[i + 2]);
				unicode.push_back(static_cast<dl_wchar>(((c & 0x0F) << 12) | ((c2 & 0x3F) << 6) | (c3 & 0x3F)));
				i += 3;
			}
			else
			{
				i++;
			}
		}

		return unicode;
	}

	DLTX::DLString DLCharacterSetUtil::ShiftJisToUnicode(const DLTX::DLAsciiString& shiftJis)
	{
		DLTX::DLString unicode;
		const char* src = shiftJis.c_str();
		int srcLen = static_cast<int>(shiftJis.length());
		if (srcLen > 0)
		{
			int required = MultiByteToWideChar(932 /* CP_SHIFT_JIS */, 0, src, srcLen, nullptr, 0);
			if (required > 0)
			{
				std::vector<wchar_t> buffer(required);
				MultiByteToWideChar(932, 0, src, srcLen, buffer.data(), required);
				unicode.assign(buffer.begin(), buffer.end());
			}
		}

		return unicode.c_str();
	}

	DLTX::DLAsciiString DLCharacterSetUtil::UnicodeToShiftJis(const DLTX::DLString& unicode)
	{
		DLTX::DLAsciiString shiftJis;
		shiftJis.reserve(unicode.length() * 2);

		const wchar_t* src = unicode.c_str();
		int srcLen = static_cast<int>(unicode.length());
		if (srcLen > 0)
		{
			int required = WideCharToMultiByte(932, 0, src, srcLen, nullptr, 0, nullptr, nullptr);
			if (required > 0)
			{
				std::vector<char> buffer(required);
				WideCharToMultiByte(932, 0, src, srcLen, buffer.data(), required, nullptr, nullptr);
				shiftJis.assign(buffer.begin(), buffer.end());
			}
		}

		return shiftJis.c_str();
	}

	DLTX::DLAsciiString DLCharacterSetUtil::ShiftJisToUtf8(const DLTX::DLAsciiString& shiftJis)
	{
		DLTX::DLString unicode = ShiftJisToUnicode(shiftJis);
		return UnicodeToUtf8(unicode);
	}

	DLTX::DLAsciiString DLCharacterSetUtil::Utf8ToShiftJis(const DLTX::DLAsciiString& utf8)
	{
		DLTX::DLString unicode = Utf8ToUnicode(utf8);
		return UnicodeToShiftJis(unicode);
	}
}