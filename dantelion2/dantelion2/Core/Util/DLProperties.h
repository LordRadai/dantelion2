#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Text/DLString.inl"
#include "DLMap.h"
#include "DLSet.h"

namespace DLUT
{
	typedef DLMap<DLTX::DLString, DLTX::DLString> DLProperty;

	class DLProperties : public DLProperty
	{
	public:	
		DLProperties(DLKR::DLAllocator* pAllocator = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost());

		dl_int GetInteger(const DLTX::DLString& name, dl_int defaultValue);
		dl_bool GetBoolean(const DLTX::DLString& name, dl_bool defaultValue);
		dl_float32 GetFloat32(const DLTX::DLString& name, dl_float32 defaultValue);
		void GetString(DLTX::DLString& out, const DLTX::DLString& name, const DLTX::DLString& defaultValue);
		void SetProperty(const DLTX::DLString& name, const DLTX::DLString& value);
	};
}
