#include "DLPropertyConfigurator.h"
#include "Call.h"

namespace DLLG
{
	typedef dl_bool(_fastcall* oConfigure)(const DLUT::DLProperties&, DLKR::DLAllocator*);

	dl_bool DLPropertyConfigurator::Configure(const DLUT::DLProperties& properties, DLKR::DLAllocator* pAllocator)
	{
		return CALL(oConfigure, 0x8c5d00, properties, pAllocator);
	}
}