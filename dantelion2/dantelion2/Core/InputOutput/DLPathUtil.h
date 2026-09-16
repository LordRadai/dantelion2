#pragma once
#include "Core/Platform/Platform.h"
#include <string>

namespace DLIO
{
	namespace DLPathUtil
	{
		dl_bool IsAbsolutePath(const dl_wchar* path);
		dl_bool IsRoot(const dl_wchar* path);
		dl_bool DoesDirectoryExist(const dl_wchar* path);

		const std::wstring ChangeExtension(const dl_wchar* filePath, const dl_wchar* newExtension);
		const std::wstring GetDirectory(const dl_wchar* filePath);
		const std::wstring GetFileExtension(const dl_wchar* filePath);
		const std::wstring GetFileName(const dl_wchar* filePath);
		const std::wstring GetFileNameWithoutExtension(const dl_wchar* filePath);
		const std::wstring GetParentDirectory(const dl_wchar* filePath);
		const std::wstring GetLeafDirectoryName(const dl_wchar* filePath);
		const std::wstring GetPathWithoutExtension(const dl_wchar* filePath);
		const std::wstring GetPathWithSeparator(const dl_wchar* filePath);

		void CreateParentDirectory(const dl_wchar* path);
	};
}