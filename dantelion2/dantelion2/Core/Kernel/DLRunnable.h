#pragma once
#include "Core/Platform/Platform.h"

namespace DLKR
{
	class DLThreadMessageBroker;

	class DLRunnable
	{
	public:
		virtual void Run(DLThreadMessageBroker* pBroker) = 0;
		virtual ~DLRunnable() {}
	};
}
