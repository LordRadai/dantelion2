#include "DLLogger.h"
#include "Call.h"

namespace DLLG
{
	typedef void(_fastcall* oLog)(DLLogger*, DLLogLevel, const dl_wchar*, ...);
	typedef void(_fastcall* oLogSpecificW)(DLLogger*, const dl_wchar*, ...);
	typedef void(_fastcall* oLogSpecificA)(DLLogger*, const dl_char*, ...);

	DLLogger::DLLogger(const dl_wchar* name)
		: m_cName(name), m_level(DLLogLevel::LL_INTEGER_DEBUG), m_iVar14(0)
	{
		m_pCategory = nullptr;
	}

	DLLogger::~DLLogger()
	{
		delete m_pCategory;
	}

	void DLLogger::Log(DLLogLevel level, const dl_wchar* message, ...)
	{
		CALL(oLog, 0x8819b0, this, level, message);
	}

	void DLLogger::LogDebug(const dl_wchar* message, ...)
	{
		CALL(oLogSpecificW, 0x881a00, this, message);
	}

	void DLLogger::LogDebug(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881c40, this, message);
	}

	void DLLogger::LogInfo(const dl_wchar* message, ...)
	{
		CALL(oLogSpecificW, 0x881a50, this, message);
	}

	void DLLogger::LogInfo(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881ca0, this, message);
	}

	void DLLogger::LogNotice(const dl_wchar* message, ...)
	{
		CALL(oLogSpecificW, 0x881aa0, this, message);
	}

	void DLLogger::LogNotice(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881d00, this, message);
	}

	void DLLogger::LogWarn(const dl_wchar* message, ...)
	{
		CALL(oLogSpecificW, 0x881af0, this, message);
	}

	void DLLogger::LogWarn(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881d60, this, message);
	}

	void DLLogger::LogError(const dl_wchar* message, ...)
	{
		CALL(oLogSpecificW, 0x881b40, this, message);
	}

	void DLLogger::LogError(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881dc0, this, message);
	}

	void DLLogger::LogFatal(const dl_wchar* message, ...)
	{
		CALL(oLogSpecificW, 0x881b90, this, message);
	}

	void DLLogger::LogFatal(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881e20, this, message);
	}
}
