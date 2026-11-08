#include "DLPathString.h"
#include "Core/System/DLRuntime.h"

namespace DLTX
{
	DLPathString::DLPathString() : m_String(DLSY::DLRuntimeImpl::GetRuntimeImpl()->GetDefaultAllocator()), m_CharacterSet(DLTX::CS_PLATFORM) {}
}