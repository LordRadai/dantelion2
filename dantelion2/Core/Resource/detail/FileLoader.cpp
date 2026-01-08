#include "FileLoader.h"

namespace DLRSD
{
	const dl_wchar* FileLoader::FileTransferData::GetTransferStateName() const
	{
		switch (*this->m_pTransferState)
		{
		case TRANSFER_START: return L"TRANSFER_START";
		case TRANSFER_DCX: return L"TRANSFER_DCX";
		case TRANSFER_IN_PROGRESS: return L"TRANSFER_IN_PROGRESS";
		case TRANSFER_COMPLETED: return L"TRANSFER_COMPLETED";
		default: return L"UNKNOWN";
		}
	}
}
