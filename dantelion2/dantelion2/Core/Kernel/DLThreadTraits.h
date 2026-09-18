#pragma once
#include <thread>
#include "Core/Platform/Platform.h"

#undef Yield

namespace DLKR
{
	static class DLThreadTraits
	{
	public:
		static void Yield();
		static void Sleep(DWORD milliseconds);
		static DWORD GetCurrentThreadID();
		static sys_thread_t GetCurrentThread();
	};
}