#pragma once
#include "DLRuntime.h"
#include "DLWin32DialogAssertHandler.h"

namespace DLSY
{
	dl_bool SetLoggingConfigFromProperties(DLUT::DLProperties* pProperties, DLKR::DLAllocator* pAllocator);
}