#pragma once
#include "Core/Platform/Platform.h"

namespace DLIO
{
	namespace DLPathUtil
	{
		const dl_wchar* GetFileExtension(const dl_wchar* filePath);
		const dl_wchar* GetFileNameWithoutExtension(const dl_wchar* filePath);
		void CreateDirectoriesRecursive(const dl_wchar* path);
	};
}