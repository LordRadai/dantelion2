#pragma once
#include "Core/Graphics/Graphics.h"
#include "Core/Kernel/Kernel.h"
#include "Core/Util/Util.h"
#include "Core/Math/Math.h"
#include "Core/Platform/Platform.h"
#include "Core/Text/Text.h"
#include "Core/UserInput/UserInput.h"
#include "Core/Network/Network.h"
#include "Core/Reflection/Reflection.h"
#include "Core/System/System.h"
#include "Core/Resource/Resource.h"
#include "Core/Logging/Logging.h"

namespace dantelion2
{
	typedef dl_uint(_fastcall* LoadSystemProperties_t)(DLUT::DLProperties&, DLKR::DLAllocator*);
}