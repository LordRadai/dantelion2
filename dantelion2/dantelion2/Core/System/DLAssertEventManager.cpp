#include "DLAssertEventManager.h"
#include "Call.h"

namespace DLSY
{
	typedef void(_fastcall* Ctor_t)(DLAssertEventManagerImpl*, DLKR::DLAllocator*);

	DLAssertEventManager::~DLAssertEventManager()
	{
		CALL(Dtor_t, 0x88f780, this);
	}

	DLAssertEventManagerImpl::DLAssertEventManagerImpl(DLKR::DLAllocator* pAllocator)
	{
		CALL(Ctor_t, 0x88e6d0, this, pAllocator);
	}

	void DLAssertEventManagerImpl::AddAssertEventListener(const DLAssertEventListener& listener)
	{
		CALL(AddAssertEventListener_t, 0x88e890, this, listener);
	}

	void DLAssertEventManagerImpl::RemoveAssertEventListener(const DLAssertEventListener& listener)
	{
		CALL(RemoveAssertEventListener_t, 0x88e910, this, listener);
	}

	void DLAssertEventManagerImpl::AddInputEventSocket(const DLAssertEventSocket& socket)
	{
		CALL(AddInputEventSocket_t, 0x88e970, this, socket);
	}

	void DLAssertEventManagerImpl::RemoveAssertEventListener(const DLAssertEventListener& listener)
	{
		CALL(RemoveAssertEventListener_t, 0x88e9f0, this, listener);
	}

	void DLAssertEventManagerImpl::FireAssertEvent(const DLAssertEvent& event)
	{
		CALL(FireAssertEvent_t, 0x88ea50, this, event);
	}

	DLAssertEventManagerImpl::~DLAssertEventManagerImpl()
	{
		CALL(Dtor_t, 0x88f7b0, this);
	}
}