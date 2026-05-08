#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Text/DLString.inl"
#include "DLMap.h"
#include "DLSet.h"

namespace DLUT
{
	typedef DLMap<DLTX::DLString, DLTX::DLString> DLProperty;

	class DLProperties : public DLUT::DLSet<DLProperty>
	{
	public:	
		DLProperties(DLKR::DLAllocator* pAllocator = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost());

		dl_int GetInteger(DLTX::DLString name, dl_int defaultValue);
		dl_bool GetBoolean(DLTX::DLString name, dl_bool defaultValue);
		dl_float32 GetFloat32(DLTX::DLString name, dl_float32 defaultValue);
		void GetString(DLTX::DLString* pBuf, DLTX::DLString name, DLTX::DLString defaultValue);
		void SetProperty(DLTX::DLString name, DLTX::DLString value);
	};
}
