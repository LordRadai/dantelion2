#include "DLTextProcessor.h"
#include <Call.h>

namespace DLGR
{
	typedef void(_fastcall* MeasureRect_t)(DLTextProcessor*, DLGR::DL_FRECT&, const dl_wchar*, dl_bool);

	void DLTextProcessor::MeasureRect(DLGR::DL_FRECT& outRect, const dl_wchar* text, dl_bool param_2)
	{
		CALL(MeasureRect_t, 0xf35890, this, outRect, text, param_2);
	}
}