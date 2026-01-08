#include "DLLogManagerImpl.h"
#include "Call.h"

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
		return CALL(oSetRootAllocator, 0x8841d0, this, pAllocator);
	}

	DLKR::DLAllocator* DLLogManagerImpl::GetRootAllocator()
	{
		return CALL(oGetRootAllocator, 0x884190, this);
	}

	DLKR::DLAllocator* DLLogManagerImpl::GetAllocator()
	{
		return CALL(oGetAllocator, 0x884350, this);
	}

	DLKR::DLAllocator* DLLogManagerImpl::GetMessageAllocator()
	{
		return CALL(oGetMessageAllocator, 0x884400, this);
	}

	void DLLogManagerImpl::ProcessAllLogEvents()
	{
		CALL(oProcessAllLogEvents, 0x8845f0, this);
	}

	void DLLogManagerImpl::ResetConfiguration()
	{
		CALL(oResetConfiguration, 0x884660, this);
	}

	dl_bool DLLogManagerImpl::ApplyConfiguration(DLLoggingConfiguration& config)
	{
		return CALL(oApplyConfiguration, 0x884680, this, config);
	}

	void DLLogManagerImpl::GetConfiguration(DLLoggingConfiguration& config)
	{
		CALL(oGetConfiguration, 0x884760, this, config);
	}

	dl_uint DLLogManagerImpl::GetTotalBufferSize()
	{
		return CALL(oGetTotalBufferSize, 0x8841b0, this);
	}

	void DLLogManagerImpl::SetTotalBufferSize(dl_uint size)
	{
		CALL(oSetTotalBufferSize, 0x884250, this, size);
	}

	dl_uint DLLogManagerImpl::GetMessageBufferSize()
	{
		return CALL(oGetMessageBufferSize, 0x8841c0, this);
	}

	void DLLogManagerImpl::SetMessageBufferSize(dl_uint size)
	{
		CALL(oSetMessageBufferSize, 0x8842d0, this, size);
	}

	DLCategoryRepository* DLLogManagerImpl::GetCategoryRepository()
	{
		return CALL(oGetCategoryRepository, 0x884490, this);
	}

	DLLoggingStrategy* DLLogManagerImpl::GetLoggingStrategy()
	{
		return CALL(oGetLoggingStrategy, 0x884540, this);
	}

	void DLLogManagerImpl::Log(DLLogEvent& pLE)
	{
		CALL(oLog, 0x884870, this, pLE);
	}

	DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>& DLLogManagerImpl::GetMutex()
	{
		return CALL(oGetMutex, 0x884890, this);
	}

	DLLogManagerImpl::~DLLogManagerImpl()
	{
		CALL(oDestructor, 0x885450, this);
	}

	DLLogManagerImpl* DLLogManagerImpl::GetInstance()
	{
		return CALL(oGetInstance, 0x883770);
	}
}