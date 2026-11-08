#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Text/DLString.inl"
#include "DLFileOperator.h"

#undef CreateDirectory

namespace DLIO
{
    class DLFileEnumerator;

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
        ~DLFile();

        dl_bool DoesExists() const;
		dl_bool IsDirectory() const;
		dl_size GetSize() const;
		DLTX::DLString GetPath() const;
        void EnumerateContents(DLFileEnumerator& enumerator);
        dl_bool CreateDirectory();

    protected:
        DLFileOperator* _GetOperator() const;

		DLKR::DLAllocator* m_pAllocator;
		DLFileOperator* m_pCacheFileOperator;
        DLFileOperator* m_pDiskOperator;
		dl_uint m_Flags;
	};
}