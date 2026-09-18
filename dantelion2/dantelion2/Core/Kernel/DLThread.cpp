#include "DLThread.h"
#include "DLThreadTraits.h"
#include "Call.h"

namespace DLKR
{
	namespace
	{
		typedef void(_fastcall* Constructor_t)(DLThread*, DLRunnable*, dl_size, dl_size, dl_uint, dl_char*, dl_size);
	}

	DLThread::DLThread(DLRunnable* pRunnable, dl_size param_2, dl_size param_3, dl_uint param_4, dl_char* name, dl_size heapSize)
	{
		CALL(Constructor_t, 0x84b830, this, pRunnable, param_2, param_3, param_4, name, heapSize);
	}

	void DLThread::_Terminate(dl_bool bForce)
	{
		CALL(_Terminate_t, 0x84b7b0, this, bForce);
	}

	DLThread::~DLThread()
	{
		CALL(Destructor_t, 0x84c440, this);
	}

	void DLThread::Yield()
	{
		DLThreadTraits::Yield();
	}

	void DLThread::Sleep(DWORD milliseconds)
	{
		DLThreadTraits::Sleep(milliseconds);
	}

	DWORD DLThread::GetCurrentThreadID()
	{
		return DLThreadTraits::GetCurrentThreadID();
	}

	sys_thread_t DLThread::GetCurrentThread()
	{
		return DLThreadTraits::GetCurrentThread();
	}
}
