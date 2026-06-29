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
	DLKR::DLAllocator* GetDefaultAllocator();
}

// This **must** be used when declaring inline classes with a destructor that calls game code, otherwise the destructor will be called twice, and we risk crashing.
#define ALIGNED_STORAGE(Type, Name, Align) \
    __declspec(align(Align)) unsigned char Name[sizeof(Type)]

#define GET_ALIGNED_STORAGE_PTR(Type, Name) \
	reinterpret_cast<Type*>(Name)