#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Kernel/DLAllocator.h"
#include "DLFontRenderer.h"
#include "Core/Reflection/DLRuntimeClassImpl.inl"
#include "Core/Graphics/DLDrawDevice.h"
#include "Core/Util/DLReferenceCountObject.h"

namespace DLGR
{
	class DLFontData : public DLUT::DLReferenceCountObject
	{
	public:
		DLFontRenderer* m_pDLFontRenderer;
		DLKR::DLAllocator* m_pAllocator;

		DLRF::DLRuntimeClassImpl<DLFontData>* GetRuntimeClass();
		DLFontRenderer* CreateDLFontRenderer(DLGR::DLDrawDevice* pDrawDevice, DLKR::DLAllocator* pAllocator1, DLKR::DLAllocator* pAllocator2);

		void SetDLFontRenderer(DLFontRenderer* pRenderer);
		static DLKR::DLAllocator* GetFontAllocator();

		typedef void(_fastcall* oSetDLFontRenderer)(DLFontData*, DLFontRenderer*);
	};
}
