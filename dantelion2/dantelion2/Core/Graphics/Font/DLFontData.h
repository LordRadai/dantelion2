#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "DLFontRenderer.h"
#include "Core/Reflection/DLRuntimeClassImpl.inl"
#include "Core/Graphics/DLDrawDevice.h"
#include "Core/Util/DLReferenceCountObject.h"
#include "Core/Graphics/DLTexture.h"

namespace DLGR
{
	struct DL_FONT_LETTER_INFO;

	class DLFontData : public DLUT::DLReferenceCountObject
	{
	public:
		virtual void Destroy() override {}
		virtual ~DLFontData() {}  
		virtual DLRF::DLRuntimeClass* GetRuntimeClassOfThis() const;
		virtual dl_int16 GetFontSize() const = 0;
		virtual dl_int GetCodeSet() const = 0;
		virtual dl_bool GetLetterInfo(dl_uint code, dl_uint prevCode, DL_FONT_LETTER_INFO& info) = 0;
		virtual DLFontRenderer* CreateRenderer(DLDrawDevice* pDrawDevice, DLKR::DLAllocator* pAllocator1, DLKR::DLAllocator* pAllocator2) const = 0;

		typedef DLRF::DLRuntimeClass* (_fastcall* GetRuntimeClassOfThis_t)(const DLFontData*);
		typedef dl_int16(_fastcall* GetFontSize_t)(const DLFontData*);
		typedef dl_int(_fastcall* GetCodeSet_t)(const DLFontData*);
		typedef dl_bool(_fastcall* GetLetterInfo_t)(DLFontData*, dl_uint, dl_uint, DL_FONT_LETTER_INFO&);
		typedef DLFontRenderer* (_fastcall* CreateRenderer_t)(const DLFontData*, DLDrawDevice*, DLKR::DLAllocator*, DLKR::DLAllocator*);
	private:
		DLFontRenderer* m_pDLFontRenderer;
		DLKR::DLAllocator* m_pAllocator;
	};

	class DLRasterFontData : public DLFontData
	{
	public:
		virtual ~DLRasterFontData() override {}
		virtual dl_uint16 GetTextureCount() const = 0;
		virtual dl_int GetSamplerNum() const = 0;
		virtual dl_bool SetTexture(dl_int idx, DLTexture2D* pTexture, dl_int sampler) = 0;
		virtual dl_bool GetTexture(dl_int idx, DLTexture2D*& out, dl_int sampler) const = 0;

		typedef dl_uint16(_fastcall* GetTextureCount_t)(const DLRasterFontData*);
		typedef dl_int(_fastcall* GetSamplerNum_t)(const DLRasterFontData*);
		typedef dl_bool(_fastcall* SetTexture_t)(DLRasterFontData*, dl_int, DLTexture2D*, dl_int);
		typedef dl_bool(_fastcall* GetTexture_t)(const DLRasterFontData*, dl_int, DLTexture2D*&, dl_int);
	};
}
