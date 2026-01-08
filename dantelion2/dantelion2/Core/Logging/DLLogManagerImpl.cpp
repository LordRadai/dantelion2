#include "DLLogManagerImpl.h"
#include "FRPG2Call.h"

namespace DLLG
{
	typedef dl_bool(_fastcall* oSetRootAllocator)(DLLogManagerImpl*, DLKR::DLAllocator*);
	typedef DLKR::DLAllocator* (_fastcall* oGetRootAllocator)(DLLogManagerImpl*);
	typedef DLKR::DLAllocator* (_fastcall* oGetAllocator)(DLLogManagerImpl*);
	typedef DLKR::DLAllocator* (_fastcall* oGetMessageAllocator)(DLLogManagerImpl*);
	typedef void(_fastcall* oProcessAllLogEvents)(DLLogManagerImpl*);
	typedef void(_fastcall* oResetConfiguration)(DLLogManagerImpl*);
	typedef dl_bool(_fastcall* oApplyConfiguration)(DLLogManagerImpl*, DLLoggingConfiguration&);
	typedef void(_fastcall* oGetConfiguration)(DLLogManagerImpl*, DLLoggingConfiguration&);
	typedef dl_uint(_fastcall* oGetTotalBufferSize)(DLLogManagerImpl*);
	typedef void(_fastcall* oSetTotalBufferSize)(DLLogManagerImpl*, dl_uint);
	typedef dl_uint(_fastcall* oGetMessageBufferSize)(DLLogManagerImpl*);
	typedef void(_fastcall* oSetMessageBufferSize)(DLLogManagerImpl*, dl_uint);
	typedef DLCategoryRepository* (_fastcall* oGetCategoryRepository)(DLLogManagerImpl*);
	typedef DLLoggingStrategy* (_fastcall* oGetLoggingStrategy)(DLLogManagerImpl*);
	typedef void(_fastcall* oLog)(DLLogManagerImpl*, DLLogEvent&);
	typedef DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>& (_fastcall* oGetMutex)(DLLogManagerImpl*);
	typedef void(_fastcall* oDestructor)(DLLogManagerImpl*);

	typedef DLLogManagerImpl* (__fastcall* oGetInstance)();

	dl_bool DLLogManagerImpl::SetRootAllocator(DLKR::DLAllocator* pAllocator)
	{
		return FRPG2_CALL(oSetRootAllocator, 0x8841d0, this, pAllocator);
	}

	DLKR::DLAllocator* DLLogManagerImpl::GetRootAllocator()
	{
		return FRPG2_CALL(oGetRootAllocator, 0x884190, this);
	}

	DLKR::DLAllocator* DLLogManagerImpl::GetAllocator()
	{
		return FRPG2_CALL(oGetAllocator, 0x884350, this);
	}

	DLKR::DLAllocator* DLLogManagerImpl::GetMessageAllocator()
	{
		return FRPG2_CALL(oGetMessageAllocator, 0x884400, this);
	}

	void DLLogManagerImpl::ProcessAllLogEvents()
	{
		FRPG2_CALL(oProcessAllLogEvents, 0x8845f0, this);
	}

	void DLLogManagerImpl::ResetConfiguration()
	{
		FRPG2_CALL(oResetConfiguration, 0x884660, this);
	}

	dl_bool DLLogManagerImpl::ApplyConfiguration(DLLoggingConfiguration& config)
	{
		return FRPG2_CALL(oApplyConfiguration, 0x884680, this, config);
	}

	void DLLogManagerImpl::GetConfiguration(DLLoggingConfiguration& config)
	{
		FRPG2_CALL(oGetConfiguration, 0x884760, this, config);
	}

	dl_uint DLLogManagerImpl::GetTotalBufferSize()
	{
		return FRPG2_CALL(oGetTotalBufferSize, 0x8841b0, this);
	}

	void DLLogManagerImpl::SetTotalBufferSize(dl_uint size)
	{
		FRPG2_CALL(oSetTotalBufferSize, 0x884250, this, size);
	}

	dl_uint DLLogManagerImpl::GetMessageBufferSize()
	{
		return FRPG2_CALL(oGetMessageBufferSize, 0x8841c0, this);
	}

	void DLLogManagerImpl::SetMessageBufferSize(dl_uint size)
	{
		FRPG2_CALL(oSetMessageBufferSize, 0x8842d0, this, size);
	}

	DLCategoryRepository* DLLogManagerImpl::GetCategoryRepository()
	{
		return FRPG2_CALL(oGetCategoryRepository, 0x884490, this);
	}

	DLLoggingStrategy* DLLogManagerImpl::GetLoggingStrategy()
	{
		return FRPG2_CALL(oGetLoggingStrategy, 0x884540, this);
	}

	void DLLogManagerImpl::Log(DLLogEvent& pLE)
	{
		FRPG2_CALL(oLog, 0x884870, this, pLE);
	}

	DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>& DLLogManagerImpl::GetMutex()
	{
		return FRPG2_CALL(oGetMutex, 0x884890, this);
	}

	DLLogManagerImpl::~DLLogManagerImpl()
	{
		FRPG2_CALL(oDestructor, 0x885450, this);
	}

	DLLogManagerImpl* DLLogManagerImpl::GetInstance()
	{
		return FRPG2_CALL(oGetInstance, 0x883770);
	}
}