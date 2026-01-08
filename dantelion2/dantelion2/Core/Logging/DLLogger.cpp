#include "DLLogger.h"
#include "dantelion2/FRPG2Call.h"

namespace DLLG
{
	typedef void(_fastcall* oLog)(DLLogger*, DLLogLevel, const dl_wchar*, ...);
	typedef void(_fastcall* oLogSpecific)(DLLogger*, const dl_wchar*, ...);

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
		FRPG2_CALL(oLog, 0x8819b0, this, level, message);
	}

	void DLLogger::LogDebug(const dl_wchar* message, ...)
	{
		FRPG2_CALL(oLogSpecific, 0x881a00, this, message);
	}

	void DLLogger::LogInfo(const dl_wchar* message, ...)
	{
		FRPG2_CALL(oLogSpecific, 0x881a50, this, message);
	}

	void DLLogger::LogNotice(const dl_wchar* message, ...)
	{
		FRPG2_CALL(oLogSpecific, 0x881aa0, this, message);
	}

	void DLLogger::LogWarn(const dl_wchar* message, ...)
	{
		FRPG2_CALL(oLogSpecific, 0x881af0, this, message);
	}

	void DLLogger::LogError(const dl_wchar* message, ...)
	{
		FRPG2_CALL(oLogSpecific, 0x881b40, this, message);
	}

	void DLLogger::LogFatal(const dl_wchar* message, ...)
	{
		FRPG2_CALL(oLogSpecific, 0x881b90, this, message);
	}
}
