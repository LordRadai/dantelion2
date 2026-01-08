#pragma once
#include "Core/Util/DLDateTime.h"
#include "Core/Text/DLString.inl"
#include "DLCategory.h"
#include "DLLogLevel.inl"

namespace DLLG
{
	class DLLogEvent
	{
		DLLogLevel m_level;
		dl_size m_time;
		DLTX::DLString m_cName;
		const dl_wchar* m_pVar40;
		dl_uint m_iVar48;
		DLTX::DLString m_message;
		DLCategory* m_pCategory;
		DLUT::DLDateTime m_date;
		sys_thread_t m_threadID;
		DLTX::DLString m_ndc;

	public:
		DLLogEvent(DLLogLevel level, DLCategory* pCategory, const dl_wchar* cName, const dl_wchar* fmt, va_list args);

		typedef void(_fastcall* oConstructor)(DLLogEvent*, DLLogLevel, DLCategory*, const dl_wchar*, const dl_wchar*, va_list);
	};
}
