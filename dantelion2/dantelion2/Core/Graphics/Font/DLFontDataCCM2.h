#pragma once
#include "DLFontData.h"

namespace DLGR
{
	class DLFontDataCCM2 : public DLRasterFontData
	{
	private:
		dl_pointer m_pCCM2FileData;
		dl_pointer m_pTextureList;
		dl_bool m_bVar30;
		dl_uint m_iVar34;
	};
}
