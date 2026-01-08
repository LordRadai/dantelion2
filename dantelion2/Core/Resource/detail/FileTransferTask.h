#pragma once
#include "TransferTask.h"

namespace DLRSD
{
	class FileTransferTask : public TransferTask
	{
		dl_char m_data[464];
	};
}
