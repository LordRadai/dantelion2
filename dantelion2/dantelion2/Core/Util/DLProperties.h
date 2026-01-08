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
		dl_int GetIntProperty(DLTX::DLString name, dl_int defaultValue);
		dl_bool GetBoolProperty(DLTX::DLString name, dl_bool defaultValue);
		dl_float32 GetFloatProperty(DLTX::DLString name, dl_float32 defaultValue);
		void GetStringProperty(DLTX::DLString* pBuf, DLTX::DLString name, DLTX::DLString defaultValue);
		void SetPropertyValue(DLTX::DLString name, DLTX::DLString value);
	};
}
