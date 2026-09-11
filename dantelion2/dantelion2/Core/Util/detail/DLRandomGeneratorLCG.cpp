#include "DLRandomGeneratorLCG.h"
#include "Call.h"

namespace DLUTD
{
	typedef void(_fastcall* Initialize_t)(DLRandomGeneratorLCG*, dl_uint32);

	void DLRandomGeneratorLCG::Initialize(dl_size seed)
	{
		CALL(Initialize_t, 0x874010, this, static_cast<dl_uint32>(seed));
	}
}