#pragma once
#include "DLResourceLoadEventQueue.h"
#include "DLResourceFileLoadEvent.h"

namespace DLRS
{
	class DLResourceFileLoadEventQueue : public DLResourceLoadEventQueue
	{
		class UnkTransferData
		{
		public:
			dl_pointer m_pVar0;
			dl_pointer m_pVar8;
			dl_pointer m_pVar10;
			DLKR::DLAllocator* m_pAllocator;
			dl_int m_iVar20;
			dl_bool m_bVar24;
			dl_bool m_bVar25;
			dl_bool m_bVar26;
			dl_bool bVar27;
			DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_mutex;
		};
	public:
		dl_uint m_iVar28;
		UnkTransferData m_transferData[2];

		bool GetFileLoadEvent(DLRS::DLResourceFileLoadEvent* pOutEvent);
	};
}
