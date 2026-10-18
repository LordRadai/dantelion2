#include "DLFontData.h"
#include "Call.h"

namespace DLGR
{
	typedef DLRF::DLRuntimeClass*(_fastcall* oGetRuntimeClass)(const DLFontData*);
	typedef DLFontRenderer*(_fastcall* oCreateDLFontRenderer)(DLFontData*, DLGR::DLDrawDevice*, DLKR::DLAllocator*, DLKR::DLAllocator*);

	typedef DLKR::DLAllocator**(_fastcall* oGetFontAllocator)();

	DLRF::DLRuntimeClass* DLFontData::GetRuntimeClassOfThis() const
	{
		return CALL(oGetRuntimeClass, 0xf40930, this);
	}
}
