#include "DLFileEnumerator.h"
#include "Core/System/DLRuntime.h"

namespace
{
	typedef DLIO::DLFileEnumerator* (_fastcall* DLFileEnumeratorCtor_t)(DLIO::DLFileEnumerator*);
	typedef void(_fastcall* DLFileEnumeratorDtor_t)(DLIO::DLFileEnumerator*);
}

namespace DLIO
{
	DLFileEnumerator::DLFileEnumerator() : m_Directory(DLSY::DLRuntimeImpl::GetRuntimeImpl()->GetDefaultAllocator()), m_Handle(nullptr), m_pSPI(nullptr)
	{
		CALL(DLFileEnumeratorCtor_t, 0x8754F0, this);
	}

	DLFileEnumerator::~DLFileEnumerator()
	{
		CALL(DLFileEnumeratorDtor_t, 0x875620, this);
	}

	dl_bool DLFileEnumerator::GetNextFile(DLTX::DLPathString& path)
	{
		return CALL(GetNextFile_t, 0x875690, this, path);
	}
}
