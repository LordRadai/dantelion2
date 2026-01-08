#include "DLFontData.h"
#include "FRPG2Call.h"

namespace DLGR
{
	typedef DLRF::DLRuntimeClassImpl<DLFontData>*(_fastcall* oGetRuntimeClass)(DLFontData*);
	typedef DLFontRenderer*(_fastcall* oCreateDLFontRenderer)(DLFontData*, DLGR::DLDrawDevice*, DLKR::DLAllocator*, DLKR::DLAllocator*);

	typedef DLKR::DLAllocator**(_fastcall* oGetFontAllocator)();

	DLRF::DLRuntimeClassImpl<DLFontData>* DLFontData::GetRuntimeClass()
	{
		return FRPG2_VCALL(this, 2, oGetRuntimeClass, this);
	}

	void DLFontData::SetDLFontRenderer(DLFontRenderer* pRenderer)
	{
		FRPG2_CALL(oSetDLFontRenderer, 0xf409c0, this, pRenderer);
	}

	DLFontRenderer* DLFontData::CreateDLFontRenderer(DLGR::DLDrawDevice* pDrawDevice, DLKR::DLAllocator* pAllocator1, DLKR::DLAllocator* pAllocator2)
	{
		return FRPG2_VCALL(this, 6, oCreateDLFontRenderer, this, pDrawDevice, pAllocator1, pAllocator2);
	}

	DLKR::DLAllocator* DLFontData::GetFontAllocator()
	{
		return *FRPG2_CALL(oGetFontAllocator, 0xf3eb50);
	}
}
