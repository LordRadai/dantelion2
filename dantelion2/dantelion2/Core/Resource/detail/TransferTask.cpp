#include "TransferTask.h"
#include "FRPG2Call.h"

typedef const dl_wchar* (_fastcall* oGetTransferState)(const DLRSD::TransferTask* pThis);

const dl_wchar* DLRSD::TransferTask::GetTransferState() const
{
	return FRPG2_CALL(oGetTransferState, 0x8f8650, this);
}