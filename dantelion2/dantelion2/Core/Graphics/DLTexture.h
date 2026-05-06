#pragma once
#include "Core/Core.h"
#include "DLGPUResource.h"
#include "Core/Graphics/DLDrawContextDefines.h"

namespace DLGR
{
	class DLTextureBase : public DLGPUResource
	{
	public:
		virtual dl_int GetType() = 0;
		virtual dl_bool IsEnabled() = 0;
		virtual DLCG2::CGResource* GetCGResource() { return this->m_pCGTexture; }
		virtual dl_int GetFormat() { return DLTEXTYPE_NONE; }
		virtual void GetUserData() {}

		dl_uint GetWidth() const { return this->m_width; }
		dl_uint GetHeight() const { return this->m_height; }
		dl_uint GetMipMapLevelNum() const { return this->m_mipMapLevelNum; }

		DLTextureFormat GetTextureType() const;
		static DLTextureFormat GetDLTextureFormat(DXGI_FORMAT format);

    protected:
        DLCG2::CGResource* m_pCGTexture;
        DLCG2::CGShaderResourceView* m_pCGShaderResourceView;
        dl_uint m_mipMapLevelNum;
        dl_int m_iVar3C;
        dl_uint m_width;
        dl_uint m_height;
        dl_int m_iVar48;
        dl_bool m_bVar4C;
        dl_pointer m_pVar50;
        dl_pointer m_pVar58;
	};

	class DLTexture2D : public DLTextureBase
	{
		dl_pointer m_pVar60;

	public:
		virtual dl_int GetType() override { return DLTEXTYPE_2D; }

		DLCG2::CGTexture2D* GetTexture() const { return static_cast<DLCG2::CGTexture2D*>(this->m_pCGTexture); }
		DLCG2::CGShaderResourceView* GetShaderResourceView() const { return this->m_pCGShaderResourceView; }
	};
}