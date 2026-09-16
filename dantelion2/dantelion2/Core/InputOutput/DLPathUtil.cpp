#include "DLPathUtil.h"
#include "Core/Text/DLString.inl"
#include "Call.h"
#include "DLFile.h"

namespace DLIO
{
	namespace DLPathUtil
	{
		typedef const dl_wchar*(_fastcall* GetFileExtension_t)(const dl_wchar*);
		typedef const dl_wchar* (_fastcall* GetFileNameWithoutExtension_t)(const dl_wchar*);

		const std::wstring GetFileName(const dl_wchar* filePath)
		{
			const dl_wchar* lastSlash = wcsrchr(filePath, L'\\');

			if (!lastSlash)
				lastSlash = wcsrchr(filePath, L'/');

			return lastSlash ? lastSlash + 1 : filePath;
		}

		const std::wstring GetDirectory(const dl_wchar* filePath)
		{
			const dl_wchar* lastSlash = wcsrchr(filePath, L'\\');

			if (!lastSlash)
				lastSlash = wcsrchr(filePath, L'/');

			if (lastSlash)
			{
				static DLTX::DLString directory;
				directory.assign(filePath, lastSlash - filePath);
				return directory.c_str();
			}

			return L"";
		}

		const std::wstring GetPathWithoutExtension(const dl_wchar* filePath)
		{
			const dl_wchar* lastDot = wcsrchr(filePath, L'.');

			if (lastDot)
			{
				static DLTX::DLString pathWithoutExt;
				pathWithoutExt.assign(filePath, lastDot - filePath);
				return pathWithoutExt.c_str();
			}

			return filePath;
		}

		const std::wstring GetPathWithSeparator(const dl_wchar* filePath)
		{
			const dl_wchar* lastSlash = wcsrchr(filePath, L'\\');

			if (!lastSlash)
				lastSlash = wcsrchr(filePath, L'/');

			if (lastSlash)
			{
				static DLTX::DLString pathWithSep;
				pathWithSep.assign(filePath, lastSlash - filePath + 1);
				return pathWithSep.c_str();
			}

			return L"";
		}

		const std::wstring GetParentDirectory(const dl_wchar* filePath)
		{
			const dl_wchar* lastSlash = wcsrchr(filePath, L'\\');

			if (!lastSlash)
				lastSlash = wcsrchr(filePath, L'/');

			if (lastSlash)
			{
				static DLTX::DLString parentDir;
				parentDir.assign(filePath, lastSlash - filePath);
				return parentDir.c_str();
			}

			return L"";
		}

		const std::wstring GetLeafDirectoryName(const dl_wchar* filePath)
		{
			std::wstring path(filePath);

			// No separator anywhere -> no directory component at all.
			size_t end = path.find_last_of(L"\\/");
			if (end == std::wstring::npos)
				return L"";

			// Find the separator before that one, if any.
			size_t start = (end == 0) ? std::wstring::npos : path.find_last_of(L"\\/", end - 1);

			size_t leafBegin = (start == std::wstring::npos) ? 0 : start + 1;
			std::wstring leaf = path.substr(leafBegin, end - leafBegin);

			return leaf.c_str();
		}

		const std::wstring ChangeExtension(const dl_wchar* filePath, const dl_wchar* newExtension)
		{
			const dl_wchar* lastDot = wcsrchr(filePath, L'.');
			if (lastDot)
			{
				static DLTX::DLString newFilePath;
				newFilePath.assign(filePath, lastDot - filePath);
				newFilePath += newExtension;
				return newFilePath.c_str();
			}
			else
			{
				static DLTX::DLString newFilePath;
				newFilePath.assign(filePath);
				newFilePath += newExtension;
				return newFilePath.c_str();
			}
		}

		dl_bool IsAbsolutePath(const dl_wchar* path)
		{
			if (!path || wcslen(path) < 3)
				return false;

			if (iswalpha(path[0]) && path[1] == L':' && (path[2] == L'\\' || path[2] == L'/'))
				return true;

			if (path[0] == L'\\' && path[1] == L'\\')
				return true;

			return false;
		}

		dl_bool IsRoot(const dl_wchar* path)
		{
			if (!path || wcslen(path) < 3)
				return false;

			if (iswalpha(path[0]) && path[1] == L':' && (path[2] == L'\\' || path[2] == L'/') && wcslen(path) == 3)
				return true;

			if (path[0] == L'\\' && path[1] == L'\\')
			{
				const dl_wchar* firstSlash = wcschr(path + 2, L'\\');

				if (!firstSlash)
					return false;

				const dl_wchar* secondSlash = wcschr(firstSlash + 1, L'\\');

				if (!secondSlash)
					return true;

				return false;
			}

			return false;
		}

		dl_bool DoesDirectoryExist(const dl_wchar* path)
		{
			DLFile file(path, 0, DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost(), false, false);

			if (!file.DoesExists())
				return false;

			return file.IsDirectory();
		}

		const std::wstring GetFileExtension(const dl_wchar* filePath)
		{
			return CALL(GetFileExtension_t, 0x83a7b0, filePath);
		}

		const std::wstring GetFileNameWithoutExtension(const dl_wchar* filePath)
		{
			return CALL(GetFileNameWithoutExtension_t, 0x83ab80, filePath);
		}

		void CreateParentDirectory(const dl_wchar* path)
		{
			std::wstring current;
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