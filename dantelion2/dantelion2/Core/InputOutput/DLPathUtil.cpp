#include "DLPathUtil.h"
#include "Core/Text/DLString.inl"
#include "Core/System/DLRuntime.h"
#include "Call.h"
#include "DLFile.h"

// All helpers accept dantelion device paths ("title:/export/x.xml"), drive paths ("C:\\x\\y.xml"),
// UNC paths ("\\\\server\\share\\x") and relative paths, with '/' and '\\' mixed freely.

namespace DLIO
{
	namespace DLPathUtil
	{
		namespace
		{
			// Last '/' or '\\', whichever comes later. NULL if there is none.
			const dl_wchar* FindLastSeparator(const dl_wchar* path)
			{
				const dl_wchar* pLast = NULL;

				for (const dl_wchar* p = path; *p; ++p)
				{
					if (*p == L'/' || *p == L'\\')
						pLast = p;
				}

				return pLast;
			}

			// Length of the root prefix, including its separator:
			//   "title:/a/b" -> 7 ("title:/"), "C:\\a" -> 3, "\\\\srv\\share\\a" -> 12, "a/b" -> 0.
			size_t GetRootLength(const dl_wchar* path)
			{
				if (path[0] == L'\\' && path[1] == L'\\')
				{
					const dl_wchar* pServerEnd = wcspbrk(path + 2, L"\\/");

					if (!pServerEnd)
						return wcslen(path);

					const dl_wchar* pShareEnd = wcspbrk(pServerEnd + 1, L"\\/");

					return pShareEnd ? static_cast<size_t>(pShareEnd - path) + 1 : wcslen(path);
				}

				// A device ("title:") or drive ("C:") is a name followed by ':' before any separator.
				const dl_wchar* pColon = wcschr(path, L':');
				const dl_wchar* pSeparator = wcspbrk(path, L"\\/");

				if (!pColon || pColon == path || (pSeparator && pSeparator < pColon))
					return 0;

				size_t length = static_cast<size_t>(pColon - path) + 1;

				if (path[length] == L'/' || path[length] == L'\\')
					length++;

				return length;
			}

			// The extension dot of the file name. Dots in directory names are ignored.
			const dl_wchar* FindExtensionDot(const dl_wchar* path)
			{
				const dl_wchar* pSeparator = FindLastSeparator(path);

				return wcsrchr(pSeparator ? pSeparator + 1 : path, L'.');
			}
		}

		const std::wstring GetFileName(const dl_wchar* filePath)
		{
			const dl_wchar* pSeparator = FindLastSeparator(filePath);

			return pSeparator ? pSeparator + 1 : filePath;
		}

		// Directory part without the trailing separator. The root keeps its separator:
		// "title:/a/b.xml" -> "title:/a", "title:/b.xml" -> "title:/".
		const std::wstring GetDirectory(const dl_wchar* filePath)
		{
			const dl_wchar* pSeparator = FindLastSeparator(filePath);

			if (!pSeparator)
				return L"";

			size_t length = static_cast<size_t>(pSeparator - filePath);
			const size_t rootLength = GetRootLength(filePath);

			if (length < rootLength)
				length = rootLength;

			return std::wstring(filePath, length);
		}

		const std::wstring GetPathWithoutExtension(const dl_wchar* filePath)
		{
			const dl_wchar* pDot = FindExtensionDot(filePath);

			return pDot ? std::wstring(filePath, pDot) : std::wstring(filePath);
		}

		// Directory part with the trailing separator: "title:/a/b.xml" -> "title:/a/".
		const std::wstring GetPathWithSeparator(const dl_wchar* filePath)
		{
			const dl_wchar* pSeparator = FindLastSeparator(filePath);

			return pSeparator ? std::wstring(filePath, pSeparator + 1) : std::wstring();
		}

		// Parent of a file or directory. A trailing separator is ignored, the root is never left:
		// "title:/a/b/" -> "title:/a", "title:/a/b.xml" -> "title:/a", "title:/a" -> "title:/".
		const std::wstring GetParentDirectory(const dl_wchar* filePath)
		{
			std::wstring path(filePath);
			const size_t rootLength = GetRootLength(filePath);

			while (path.size() > rootLength && (path[path.size() - 1] == L'/' || path[path.size() - 1] == L'\\'))
				path.erase(path.size() - 1);

			if (path.size() <= rootLength)
				return path;

			return GetDirectory(path.c_str());
		}

		// Name of the directory that contains the file: "title:/export/filter/x.xml" -> "filter".
		// Empty when the file sits directly in the root.
		const std::wstring GetLeafDirectoryName(const dl_wchar* filePath)
		{
			const std::wstring directory = GetDirectory(filePath);

			if (directory.size() <= GetRootLength(directory.c_str()))
				return L"";

			return GetFileName(directory.c_str());
		}

		const std::wstring ChangeExtension(const dl_wchar* filePath, const dl_wchar* newExtension)
		{
			return GetPathWithoutExtension(filePath) + newExtension;
		}

		// Device paths ("title:/...") count as absolute, like drive and UNC paths.
		dl_bool IsAbsolutePath(const dl_wchar* path)
		{
			if (!path)
				return false;

			return GetRootLength(path) > 0;
		}

		// "title:/", "title:", "C:\\", "\\\\server\\share".
		dl_bool IsRoot(const dl_wchar* path)
		{
			if (!path)
				return false;

			const size_t rootLength = GetRootLength(path);

			return rootLength > 0 && path[rootLength] == L'\0';
		}

		dl_bool DoesDirectoryExist(const dl_wchar* path)
		{
			DLFile file(path, 0, DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost(), false, false);

			// DLFile::IsDirectory checks DoesExists itself.
			return file.IsDirectory();
		}

		const std::wstring GetFileExtension(const dl_wchar* filePath)
		{
			const dl_wchar* pDot = FindExtensionDot(filePath);

			return pDot ? pDot + 1 : L"";
		}

		const std::wstring GetFileNameWithoutExtension(const dl_wchar* filePath)
		{
			const dl_wchar* pSeparator = FindLastSeparator(filePath);
			const dl_wchar* pFileName = pSeparator ? pSeparator + 1 : filePath;
			const dl_wchar* pDot = wcsrchr(pFileName, L'.');

			return pDot ? std::wstring(pFileName, pDot) : std::wstring(pFileName);
		}

		// Creates every directory up to the last separator, one level at a time, the way the game
		// does it (GhostPlayer::DbgOutputReplayData). Pass a file path, or a directory ending in '/'.
		void CreateParentDirectory(const dl_wchar* path)
		{
			DLKR::DLAllocator* pAllocator = DLSY::DLRuntimeImpl::GetRuntimeImpl()->GetDefaultAllocator();

			// The root ("title:/", "C:\\") always exists.
			const size_t rootLength = GetRootLength(path);
			std::wstring current(path, rootLength);

			for (const dl_wchar* p = path + rootLength; *p; ++p)
			{
				current += *p;

				if (*p == L'/' || *p == L'\\')
				{
					DLFile directory(current.c_str(), 0, pAllocator, false, false);
					directory.CreateDirectory();
				}
			}
		}
	}
}
