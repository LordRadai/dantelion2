#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"
#include "dantelion2/Core/Kernel/DLLightMutex.h"
#include "dantelion2/Core/Util/DLReferenceCountObject.h"

class FileReadOperation;

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
		FileReadOperation* m_pFileReadOperation;

		const dl_wchar* GetFilePath() const;
		dl_uint GetFileSize() const;
		dl_uint GetFlags() const { return m_flags; }
	};
}
