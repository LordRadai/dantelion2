#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLRSD
{
	class TransferTask
	{
		void** _vfptr;
		dl_char m_data[352];

	public:
		const dl_wchar* GetTransferState() const;
	};
}
