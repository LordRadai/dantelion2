#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLLifeCycleAdapter.h"
#include "Core/Kernel/DLLightMutex.h"
#include "Core/Util/DLReferenceCountObject.h"

namespace DLRS
{
	class DLResourceLoadEvent
	{
		void** _vfptr;
	public:
		const dl_wchar* m_pFilePath;
		dl_pointer m_pVar10;
		dl_pointer m_pVar18;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex>* m_pMutex;
		dl_uint m_flags;
		DLUT::DLReferenceCountObject* m_pFileReadOperationCB;

		DLUT::DLReferenceCountObject* GetFileReadOperationCB() const { return m_pFileReadOperationCB; }
		dl_uint GetFlags() const { return m_flags; }
	};
}
