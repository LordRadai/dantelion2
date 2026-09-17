#include "DLFile.h"
#include "Core/Assert/DLAssert.h"
#include "Core/System/DLRuntime.h"
#include "Call.h"

namespace DLIO
{
	typedef void(_fastcall* Constructor_t)(DLFile*, const dl_wchar*, dl_size, DLKR::DLAllocator*, dl_bool, dl_bool);
	typedef dl_bool(_fastcall* Exists_t)(const DLFile*);
	typedef dl_bool(_fastcall* IsDirectory_t)(const DLFile*);
	typedef dl_size(_fastcall* GetSize_t)(const DLFile*);
	typedef void(_fastcall* GetPath_t)(const DLFile*, DLTX::DLString*);

	DLFile::DLFile(const dl_wchar* filePath, dl_size offset, DLKR::DLAllocator* pAllocator, dl_bool param_4, dl_bool param_5)
	{
		CALL(Constructor_t, 0xb14fe0, this, filePath, offset, pAllocator, param_4, param_5);
	}

	dl_bool DLFile::DoesExists() const
	{
		return CALL(Exists_t, 0x855440, this);
	}

	dl_bool DLFile::IsDirectory() const
	{
		DWORD attributes = GetFileAttributesW(reinterpret_cast<const dl_wchar*>(GetPath().c_str()));
		return (attributes != INVALID_FILE_ATTRIBUTES) && (attributes & FILE_ATTRIBUTE_DIRECTORY);
	}

	dl_size DLFile::GetSize() const
	{
		return CALL(GetSize_t, 0x855dc0, this);
	}

	DLTX::DLString DLFile::GetPath() const
	{
		DLTX::DLString path(DLSY::DLRuntimeImpl::GetRuntimeImpl()->GetDefaultAllocator());
		CALL(GetPath_t, 0x855950, this, &path);
		return path;
	}
}