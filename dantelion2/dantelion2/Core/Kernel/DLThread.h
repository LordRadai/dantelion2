#pragma once
#include "Core/Platform/Platform.h"
#include "DLRunnable.h"
#include "DLLightMutex.h"
#include "DLConditionSignal.h"

namespace DLKR
{
	class DLThread
	{
		void** _vfptr;
	public:
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
