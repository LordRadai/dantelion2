#include "DLCategory.h"
#include "dantelion2/FRPG2Call.h"

namespace DLLG
{
	typedef void(_fastcall* oAddAppender)(DLCategory*, const dl_wchar*);

	DLRF::DLRuntimeClassImpl<DLCategory>* DLCategory::GetRuntimeClass()
	{
		return FRPG2_CALL(oGetRuntimeClass, 0x886680, this);
	}
	
	DLCategory::~DLCategory()
	{
		FRPG2_CALL(oDestructor, 0x8873a0, this);
	}

	void DLCategory::AddAppender(const dl_wchar* name)
	{
		FRPG2_CALL(oAddAppender, 0x886860, this, name);
	}
}
