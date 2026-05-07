#pragma once
#include "Core/Platform/Platform.h"

namespace DLSY
{
	class DLExitEventListener
	{
	public:
		virtual void Execute() = 0;
		virtual ~DLExitEventListener() {}
	};

	typedef dl_uint DLExitEventPriority;
	typedef void(*DLExitEventProc)();
}