#include "DLThreadTraits.h"

namespace DLKR
{
	void DLThreadTraits::Yield()
	{
		Sleep(0);
	}

	void DLThreadTraits::Sleep(DWORD milliseconds)
	{
		::Sleep(milliseconds);
	}

	DWORD DLThreadTraits::GetCurrentThreadID()
	{
		return ::GetCurrentThreadId();
	}

	sys_thread_t DLThreadTraits::GetCurrentThread()
	{
		return ::GetCurrentThread();
	}
}