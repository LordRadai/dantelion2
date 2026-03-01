#include "System.h"

namespace DLSY
{
	typedef dl_bool(_fastcall* oSetLoggingConfigFromProperties)(DLUT::DLProperties*, DLKR::DLAllocator*);

	dl_bool SetLoggingConfigFromProperties(DLUT::DLProperties* pProperties, DLKR::DLAllocator* pAllocator)
	{
		return CALL(oSetLoggingConfigFromProperties, 0x8c5f80, pProperties, pAllocator);
	}
}