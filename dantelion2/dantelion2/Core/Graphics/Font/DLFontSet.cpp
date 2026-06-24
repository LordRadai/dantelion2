#include "DLFontSet.h"

namespace DLGR
{
	typedef dl_bool(_fastcall* RegisterFont_t)(DLFontSet*, dl_uint, DLFontData*);

	dl_bool DLGR::DLFontSet::RegisterFont(dl_uint id, DLFontData* pFontData)
	{
		return CALL(RegisterFont_t, 0xf3ed30, this, id, pFontData);
	}
}