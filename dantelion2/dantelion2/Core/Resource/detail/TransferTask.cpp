#include "TransferTask.h"
#include "Call.h"

typedef const dl_wchar* (_fastcall* oGetTransferState)(const DLRSD::TransferTask* pThis);

const dl_wchar* DLRSD::TransferTask::GetTransferState() const
{
	return CALL(oGetTransferState, 0x8f8650, this);
}