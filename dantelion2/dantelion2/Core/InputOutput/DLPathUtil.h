#pragma once
#include "Core/Platform/Platform.h"

namespace DLIO
{
	namespace DLPathUtil
	{
		const dl_wchar* ChangeExtension(const dl_wchar* filePath, const dl_wchar* newExtension);
		dl_bool DoesDirectoryExist(const dl_wchar* path);
		const dl_wchar* GetDirectory(const dl_wchar* filePath);
		const dl_wchar* GetFileExtension(const dl_wchar* filePath);
		const dl_wchar* GetFileName(const dl_wchar* filePath);
		const dl_wchar* GetFileNameWithoutExtension(const dl_wchar* filePath);
		const dl_wchar* GetParentDirectory(const dl_wchar* filePath);
		const dl_wchar* GetLeafDirectoryName(const dl_wchar* filePath);
		const dl_wchar* GetPathWithoutExtension(const dl_wchar* filePath);
		const dl_wchar* GetPathWithSeparator(const dl_wchar* filePath);

		void CreateParentDirectory(const dl_wchar* path);
	};
}