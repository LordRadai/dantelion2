#include "DLFile.h"
#include "Call.h"

namespace DLIO
{
	typedef void(_fastcall* Constructor_t)(DLFile*, const dl_wchar*, dl_size, DLKR::DLAllocator*, dl_bool, dl_bool);
	typedef dl_bool(_fastcall* Exists_t)(const DLFile*);
	typedef dl_size(_fastcall* GetSize_t)(const DLFile*);

	DLFile::DLFile(const dl_wchar* filePath, dl_size offset, DLKR::DLAllocator* pAllocator, dl_bool param_4, dl_bool param_5)
	{
		CALL(Constructor_t, 0x855120, this, filePath, offset, pAllocator, param_4, param_5);
	}

	dl_bool DLFile::Exists() const
	{
		return CALL(Exists_t, 0x855440, this);
	}

	dl_size DLFile::GetSize() const
	{
		return CALL(GetSize_t, 0x855dc0, this);
	}
}