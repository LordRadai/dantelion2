#include "DLTextProcessManager.h"
#include "Call.h"

namespace DLGR
{
	typedef void(_fastcall* Constructor_t)(DLTextProcessManager*, DLKR::DLAllocator*);

	DLTextProcessManager::DLTextProcessManager(DLKR::DLAllocator* pAllocator)
	{
		CALL(Constructor_t, 0xf400d0, this, pAllocator);
	}

	DLTextProcessManager::~DLTextProcessManager()
	{
		CALL(Destructor_t, 0xf40170, this);
	}
}