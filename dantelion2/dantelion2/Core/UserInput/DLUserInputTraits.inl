#pragma once
#include "Core/Util/DLVector.h"
#include "Core/Kernel/DLAllocator.h"
#include "Core/Platform/Platform.h"
#include "details/UserInputExtension.h"

namespace DLUI
{
	template<class ThreadingPolicy>
	class DLUserInputTraits
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		ThreadingPolicy m_sync;
		DLUT::DLVector<DLUID::UserInputExtension*> m_extensions;
	};
}