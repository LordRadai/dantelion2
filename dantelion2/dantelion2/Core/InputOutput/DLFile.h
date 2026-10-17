#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Text/DLString.inl"

namespace DLIO
{
    enum DLSeekDirection
    {
        SD_HEAD,
        SD_CURRENT,
        SD_TAIL,
    };

    enum IO_ERROR_CODE 
    {
        IO_ERROR_NONE = 0,
        IO_ERROR_UNKNOWN,
        IO_ERROR_UNSUPPORTED,
        IO_ERROR_PERMISSION_DENIED,
        IO_ERROR_FILE_NOT_EXIST,
        IO_ERROR_NOT_OPEN,
        IO_ERROR_IS_READ_ONLY,
        IO_ERROR_NOT_FILE,
        IO_ERROR_NOT_DIRECTORY,
        IO_ERROR_MULTIPLE_ASYNC,
        IO_ERROR_MULTIPLE_FIND,
        IO_ERROR_NOT_FINDING,
    };

	class DLFile
	{
	public:
		DLFile(const dl_wchar* filePath, dl_size offset, DLKR::DLAllocator* pAllocator, dl_bool param_4 = false, dl_bool bUseCache = false);
		dl_bool DoesExists() const;
		dl_bool IsDirectory() const;
		dl_size GetSize() const;
		DLTX::DLString GetPath() const;

	protected:
		DLKR::DLAllocator* m_pAllocator;
		dl_pointer m_pCacheFileOperator;
		dl_pointer m_pDiskOperator;
		dl_uint m_Flags;
	};
}