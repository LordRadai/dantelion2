#include "DLCategory.h"
#include "Call.h"

namespace DLLG
{
	typedef void(_fastcall* oAddAppender)(DLCategory*, const dl_wchar*);

	DLRF::DLRuntimeClassImpl<DLCategory>* DLCategory::GetRuntimeClass()
	{
		return CALL(oGetRuntimeClass, 0x886680, this);
	}
	
	DLCategory::~DLCategory()
	{
		CALL(oDestructor, 0x8873a0, this);
	}

	void DLCategory::AddAppender(const dl_wchar* name)
	{
		CALL(oAddAppender, 0x886860, this, name);
	}
}
