#include "DLLogger.h"
#include "Call.h"

namespace DLLG
{
	typedef void(_cdecl* oLog)(DLLogger*, DLLogLevel, const dl_wchar*, ...);
	typedef void(_cdecl* oLogSpecificW)(DLLogger*, const dl_wchar*, ...);
	typedef void(_cdecl* oLogSpecificA)(DLLogger*, const dl_char*, ...);

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
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLog, 0x8819b0, this, level, buffer);
	}

	void DLLogger::LogDebug(const dl_wchar* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLogSpecificW, 0x881a00, this, buffer);
	}

	void DLLogger::LogDebug(const dl_char* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		char buffer[1024];
		vsprintf_s(buffer, message, args);

		va_end(args);

		CALL(oLogSpecificA, 0x881c40, this, buffer);
	}

	void DLLogger::LogInfo(const dl_wchar* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLogSpecificW, 0x881a50, this, buffer);
	}

	void DLLogger::LogInfo(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881ca0, this, message);
	}

	void DLLogger::LogNotice(const dl_wchar* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLogSpecificW, 0x881aa0, this, buffer);
	}

	void DLLogger::LogNotice(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881d00, this, message);
	}

	void DLLogger::LogWarn(const dl_wchar* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLogSpecificW, 0x881af0, this, buffer);
	}

	void DLLogger::LogWarn(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881d60, this, message);
	}

	void DLLogger::LogError(const dl_wchar* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLogSpecificW, 0x881b40, this, buffer);
	}

	void DLLogger::LogError(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881dc0, this, message);
	}

	void DLLogger::LogFatal(const dl_wchar* message, ...)
	{
		va_list args;
		va_start(args, message);

		// Format the string into a local buffer
		wchar_t buffer[1024];
		_vsnwprintf_s(buffer, _TRUNCATE, message, args);

		va_end(args);

		CALL(oLogSpecificW, 0x881b90, this, buffer);
	}

	void DLLogger::LogFatal(const dl_char* message, ...)
	{
		CALL(oLogSpecificA, 0x881e20, this, message);
	}
}
