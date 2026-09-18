#pragma once
#include "Core/Platform/Platform.h"
#include "DLRunnable.h"
#include "DLLightMutex.h"
#include "DLConditionSignal.h"

#undef Yield

namespace DLKR
{
	class DLThread
	{
	private:
		virtual void _Terminate(dl_bool bForce);

	public:
		DLThread(DLRunnable* pRunnable, dl_size param_2, dl_size param_3, dl_uint param_4, dl_char* name, dl_size heapSize);
		virtual ~DLThread();

		typedef void(_fastcall* _Terminate_t)(DLThread*, dl_bool);
		typedef void(_fastcall* Destructor_t)(DLThread*);

		static DWORD GetCurrentThreadID();
		static void Yield();
		static void Sleep(DWORD milliseconds);
		static sys_thread_t GetCurrentThread();
	private:
		sys_thread_t m_id;
		dl_int m_threadID;
		DLRunnable* m_pRunnable;
		dl_pointer m_pTarget;
		dl_pointer m_pMemory;
		DLPlainLightMutex m_messageLock;
		DLPlainConditionSignal m_messageSignal;
		dl_pointer m_pVar78;
		dl_char m_threadName[40];
		dl_bool m_bFinished;
		dl_pointer m_pVarB0;
		dl_pointer m_pVarB8;
		dl_bool m_bRunning;
	};
}
