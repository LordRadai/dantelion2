#include "DLProperties.h"
#include "Call.h"

namespace DLUT
{
	typedef void(_fastcall* oConstructor)(DLProperties*, DLKR::DLAllocator*);
	typedef void(_fastcall* oCopyConstructor)(DLProperties*, DLProperties&, DLKR::DLAllocator*);

	typedef dl_int(_fastcall* oGetPropertyInt)(DLProperties* pThis, const DLTX::DLString& name, dl_int defaultValue);
	typedef dl_bool(_fastcall* oGetPropertyBool)(DLProperties* pThis, const DLTX::DLString& name, dl_bool defaultValue);
	typedef dl_float32(_fastcall* oGetPropertyFloat)(DLProperties* pThis, const DLTX::DLString& name, dl_float32 defaultValue);
	typedef void(_fastcall* oGetPropertyString)(DLProperties* pThis, DLTX::DLString&, const DLTX::DLString& name, const DLTX::DLString& defaultValue);
	typedef void(_fastcall* oSetPropertyValue)(DLProperties* pThis, const DLTX::DLString& name, const DLTX::DLString& value);

	DLProperties::DLProperties(DLKR::DLAllocator* pAllocator)
	{
		CALL(oConstructor, 0x87b970, this, pAllocator);
	}

	DLProperties::DLProperties(DLProperties& other, DLKR::DLAllocator* pAllocator)
	{
		CALL(oCopyConstructor, 0x87b9e0, this, other, pAllocator);
	}

	dl_int DLProperties::GetInteger(const DLTX::DLString& name, dl_int defaultValue)
	{
		return CALL(oGetPropertyInt, 0x87cd40, this, name, defaultValue);
	}

	dl_bool DLProperties::GetBoolean(const DLTX::DLString& name, dl_bool defaultValue)
	{
		return CALL(oGetPropertyBool, 0x87d010, this, name, defaultValue);
	}

	dl_float32 DLProperties::GetFloat32(const DLTX::DLString& name, dl_float32 defaultValue)
	{
		return CALL(oGetPropertyFloat, 0x87d440, this, name, defaultValue);
	}

	void DLProperties::GetString(DLTX::DLString& out, const DLTX::DLString& name, const DLTX::DLString& defaultValue)
	{
		CALL(oGetPropertyString, 0x87d320, this, out, name, defaultValue);
	}

	void DLProperties::SetProperty(const DLTX::DLString& name, const DLTX::DLString& value)
	{
		CALL(oSetPropertyValue, 0x87d720, this, name, value);
	}
}