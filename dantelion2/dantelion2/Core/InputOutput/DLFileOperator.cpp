#include "DLFileOperator.h"
#include "Call.h"

namespace DLIO
{
	DLFileOperator::DLFileOperator(const DLTX::DLPathString& path, const DLFileDevice* pDevice, const DLFile* pFile, DLKR::DLAllocator* pAllocator)
	{
		CALL(DLFileOperatorCtor_t, 0x896A50, this, path, pDevice, pFile, pAllocator);
	}

	DLFileOperator::~DLFileOperator()
	{
		CALL(DLFileOperatorDtor_t, 0x896DD0, this, 0); // 0 = destroy only, no free
	}

	dl_bool DLFileOperator::Initialize(dl_bool flag1, dl_bool flag2)
	{
		return CALL(InitializeFlags_t, 0x896B40, this, flag1, flag2);
	}

	dl_bool DLFileOperator::Initialize(const DLTX::DLString& path, dl_bool flag1, dl_bool flag2)
	{
		return CALL(InitializeString_t, 0x896B70, this, path, flag1, flag2);
	}

	dl_bool DLFileOperator::Initialize(const DLTX::DLTempString& path, dl_bool flag1, dl_bool flag2)
	{
		return CALL(InitializeTempString_t, 0x896BE0, this, path, flag1, flag2);
	}

	dl_bool DLFileOperator::Initialize(const DLTX::DLPathString& path, dl_bool flag1, dl_bool flag2)
	{
		return CALL(InitializePathString_t, 0x896C50, this, path, flag1, flag2);
	}

	dl_bool DLFileOperator::Initialize(const DLFileOperator& other)
	{
		return CALL(InitializeCopy_t, 0x896D00, this, other);
	}

	dl_bool DLFileOperator::Finalize()
	{
		return CALL(Finalize_t, 0x896D50, this);
	}

	dl_bool DLFileOperator::Flush()
	{
		return CALL(Flush_t, 0x896D90, this);
	}
}