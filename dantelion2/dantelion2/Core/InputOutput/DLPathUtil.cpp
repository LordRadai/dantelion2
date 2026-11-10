#include "DLPathUtil.h"
#include "Core/Text/DLString.inl"
#include "Core/System/DLRuntime.h"
#include "DLFile.h".

namespace DLIO
{
	namespace DLPathUtil
	{
		namespace
		{
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

				const dl_wchar* pColon = wcschr(path, L':');
				const dl_wchar* pSeparator = wcspbrk(path, L"\\/");

				if (!pColon || pColon == path || (pSeparator && pSeparator < pColon))
					return 0;

				size_t length = static_cast<size_t>(pColon - path) + 1;

				if (path[length] == L'/' || path[length] == L'\\')
					length++;

				return length;
			}

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

		const std::wstring GetPathWithSeparator(const dl_wchar* filePath)
		{
			const dl_wchar* pSeparator = FindLastSeparator(filePath);

			return pSeparator ? std::wstring(filePath, pSeparator + 1) : std::wstring();
		}

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

		dl_bool IsAbsolutePath(const dl_wchar* path)
		{
			if (!path)
				return false;

			return GetRootLength(path) > 0;
		}

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

		void CreateParentDirectory(const dl_wchar* path)
		{
			const size_t rootLength = GetRootLength(path);
			std::wstring current(path, rootLength);

			for (const dl_wchar* p = path + rootLength; *p; ++p)
			{
				current += *p;

				if (*p == L'/' || *p == L'\\')
				{
					DLFile directory(current.c_str(), 0, DLSY::DLRuntimeImpl::GetRuntimeImpl()->GetDefaultAllocator(), false, false);
					directory.CreateDirectory();
				}
			}
		}
	}
}
