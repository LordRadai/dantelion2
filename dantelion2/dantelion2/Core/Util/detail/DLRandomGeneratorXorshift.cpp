#include "DLRandomGeneratoXorshift.h"
#include "Call.h"

namespace DLUTD
{
	typedef void(_fastcall* Constructor_t)(DLRandomGeneratorXorshift*);
	typedef void(_fastcall* Initialize_t)(DLRandomGeneratorXorshift*, dl_uint);

	DLRandomGeneratorXorshift::DLRandomGeneratorXorshift(dl_uint seed)
	{
		CALL(Constructor_t, 0x84a5f0, this);
	}

	void DLRandomGeneratorXorshift::Initialize(dl_uint seed)
	{
		CALL(Initialize_t, 0x84a660, this, seed);
	}
}