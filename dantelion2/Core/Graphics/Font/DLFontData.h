#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "DLFontRenderer.h"
#include "dantelion2/Core/Reflection/DLRuntimeClassImpl.inl"
#include "dantelion2/Core/Graphics/DLDrawDevice.h"
#include "dantelion2/Core/Util/DLReferenceCountObject.h"

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
