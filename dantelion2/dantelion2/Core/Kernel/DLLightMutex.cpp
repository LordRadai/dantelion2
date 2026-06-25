#include "DLLightMutex.h"
#include "Call.h"

namespace DLKR
{
	typedef void(_fastcall* Constructor_t)(DLPlainLightMutex*);
	typedef void(_fastcall* Destructor_t)(DLPlainLightMutex*);

	typedef dl_bool(_fastcall* Initialize_t)(DLPlainLightMutex*);
	typedef void(_fastcall* Finalize_t)(DLPlainLightMutex*);

	DLPlainLightMutex::DLPlainLightMutex()
	{
		CALL(Constructor_t, 0x84b400, this);
	}

	DLPlainLightMutex::~DLPlainLightMutex()
	{
		CALL(Destructor_t, 0x84b430, this);
	}

	dl_bool DLPlainLightMutex::Initialize()
	{
		return CALL(Initialize_t, 0x84b480, this);
	}

	void DLPlainLightMutex::Finalize()
	{
		CALL(Finalize_t, 0x84b4b0, this);
	}
}