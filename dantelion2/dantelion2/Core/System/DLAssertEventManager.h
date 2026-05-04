#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"
#include "Core/Util/DLMap.h"

namespace DLSY
{
	class DLAssertEventListener;
	class DLAssertEventSocket;
	
	class DLAssertEvent
	{
		dl_bool m_bVar0;
		dl_bool m_bVar1;
	};

	class DLAssertEventManager
	{
	public:
		DLAssertEventManager() {}

		virtual void AddAssertEventListener(const DLAssertEventListener& listener) = 0;
		virtual void RemoveAssertEventListener(const DLAssertEventListener& listener) = 0;
		virtual void AddInputEventSocket(const DLAssertEventSocket& socket) = 0;
		virtual void RemoveInputEventSocket(const DLAssertEventSocket& socket) = 0;
		virtual void FireAssertEvent(const DLAssertEvent& event) = 0;
		virtual ~DLAssertEventManager();

		typedef void(_fastcall* AddAssertEventListener_t)(DLAssertEventManager*, const DLAssertEventListener&);
		typedef void(_fastcall* RemoveAssertEventListener_t)(DLAssertEventManager*, const DLAssertEventListener&);
		typedef void(_fastcall* AddInputEventSocket_t)(DLAssertEventManager*, const DLAssertEventSocket&);
		typedef void(_fastcall* RemoveInputEventSocket_t)(DLAssertEventManager*, const DLAssertEventSocket&);
		typedef void(_fastcall* FireAssertEvent_t)(DLAssertEventManager*, const DLAssertEvent&);
		typedef void(_fastcall* Dtor_t)(DLAssertEventManager*);
	};

	class DLAssertEventManagerImpl : public DLAssertEventManager
	{
	public:
		DLAssertEventManagerImpl(DLKR::DLAllocator* pAllocator);

		virtual void AddAssertEventListener(const DLAssertEventListener& listener) override;
		virtual void RemoveAssertEventListener(const DLAssertEventListener& listener) override;
		virtual void AddInputEventSocket(const DLAssertEventSocket& socket) override;
		virtual void RemoveInputEventSocket(const DLAssertEventSocket& socket);
		virtual void FireAssertEvent(const DLAssertEvent& event) override;
		virtual ~DLAssertEventManagerImpl();

		DLUT::DLMap<dl_pointer, dl_uint> m_listeners;
		DLUT::DLMap<dl_pointer, dl_uint> m_sockets;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
	};
}
