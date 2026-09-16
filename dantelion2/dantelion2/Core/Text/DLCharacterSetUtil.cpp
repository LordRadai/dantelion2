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
	const dl_wchar* DLCharacterSetUtil::AsciiToUnicode(const dl_char* ascii)
	{
		std::wstring utf(ascii, ascii + strlen(ascii));
		return utf.c_str();
	}

	const dl_char* DLCharacterSetUtil::UnicodeToAscii(const dl_wchar* unicode)
	{
		std::string ascii(unicode, unicode + wcslen(unicode));
		return ascii.c_str();
	}

	const dl_char* DLCharacterSetUtil::UnicodeToUtf8(const dl_wchar* unicode)
	{
		std::string utf8;
		utf8.reserve(wcslen(unicode) * 3);

		for (size_t i = 0; i < wcslen(unicode); ++i)
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

		return utf8.c_str();
	}

	const dl_wchar* DLCharacterSetUtil::Utf8ToUnicode(const dl_char* utf8)
	{
		std::wstring unicode;
		unicode.reserve(strlen(utf8));
		size_t i = 0;
		while (i < strlen(utf8))
		{
			unsigned char c = static_cast<unsigned char>(utf8[i]);
			if (c <= 0x7F)
			{
				unicode.push_back(static_cast<dl_wchar>(c));
				i++;
			}
			else if ((c & 0xE0) == 0xC0)
			{
				if (i + 1 >= strlen(utf8)) break;
				unsigned char c2 = static_cast<unsigned char>(utf8[i + 1]);
				unicode.push_back(static_cast<dl_wchar>(((c & 0x1F) << 6) | (c2 & 0x3F)));
				i += 2;
			}
			else if ((c & 0xF0) == 0xE0)
			{
				if (i + 2 >= strlen(utf8)) break;
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

		return unicode.c_str();
	}

	const dl_wchar* DLCharacterSetUtil::ShiftJisToUnicode(const dl_char* shiftJis)
	{
		std::wstring unicode;
		const char* src = shiftJis;
		int srcLen = static_cast<int>(strlen(shiftJis));
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

	const dl_char* DLCharacterSetUtil::UnicodeToShiftJis(const dl_wchar* unicode)
	{
		std::string shiftJis;
		shiftJis.reserve(wcslen(unicode) * 2);

		const wchar_t* src = unicode;
		int srcLen = static_cast<int>(wcslen(unicode));
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

	const dl_char* DLCharacterSetUtil::ShiftJisToUtf8(const dl_char* shiftJis)
	{
		const dl_wchar* unicode = ShiftJisToUnicode(shiftJis);
		return UnicodeToUtf8(unicode);
	}

	const dl_char* DLCharacterSetUtil::Utf8ToShiftJis(const dl_char* utf8)
	{
		const dl_wchar* unicode = Utf8ToUnicode(utf8);
		return UnicodeToShiftJis(unicode);
	}
}