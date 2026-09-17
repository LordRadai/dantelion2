#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Text/DLString.inl"

namespace DLIO
{
	class DLFile
	{
	public:
		DLFile(const dl_wchar* filePath, dl_size offset, DLKR::DLAllocator* pAllocator, dl_bool param_4 = false, dl_bool param_5 = false);
		dl_bool DoesExists() const;
		dl_bool IsDirectory() const;
		dl_size GetSize() const;
		DLTX::DLString GetPath() const;

	protected:
		DLKR::DLAllocator* m_pAllocator;
		dl_pointer m_pVar8;
		dl_pointer m_pVar10;
		dl_uint m_iVar18;
	};
}