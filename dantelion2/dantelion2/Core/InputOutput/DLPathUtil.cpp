#include "DLPathUtil.h"
#include "Core/Text/DLString.inl"
#include "Call.h"

namespace DLIO
{
	namespace DLPathUtil
	{
		typedef const dl_wchar* (_fastcall* GetFileExtension_t)(const dl_wchar*);
		typedef const dl_wchar* (_fastcall* GetFileNameWithoutExtension_t)(const dl_wchar*);

		const dl_wchar* GetFileExtension(const dl_wchar* filePath)
		{
			return CALL(GetFileExtension_t, 0x83a7b0, filePath);
		}

		const dl_wchar* GetFileNameWithoutExtension(const dl_wchar* filePath)
		{
			return CALL(GetFileNameWithoutExtension_t, 0x83ab80, filePath);
		}

		void CreateDirectoriesRecursive(const dl_wchar* path)
		{
			DLTX::DLString current;
			for (size_t i = 0; i < wcslen(path); ++i)
			{
				wchar_t c = path[i];
				current += c;
				if (c == L'/' || c == L'\\')
					CreateDirectoryW(current.c_str(), nullptr);
			}

			CreateDirectoryW(path, nullptr);
		}
	}
}