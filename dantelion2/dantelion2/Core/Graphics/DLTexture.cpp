#include "DLTexture.h"
#include "Call.h"

typedef DLGR::DLTextureFormat(_fastcall* GetDLTextureFormat_t)(DXGI_FORMAT);

namespace DLGR
{
	DLTextureFormat DLTextureBase::GetDLTextureFormat() const
	{
		DLCG2::CGTexture2D* pTexture = static_cast<DLCG2::CGTexture2D*>(this->m_pCGTexture);

		if (pTexture == nullptr)
			return DLTEXFMT_NUM;

		return GetDLTextureFormat(pTexture->GetFormat());
	}

	DLTextureFormat DLTextureBase::GetDLTextureFormat(DXGI_FORMAT format)
	{
		return CALL(GetDLTextureFormat_t, 0xf28b90, format);
	}
}