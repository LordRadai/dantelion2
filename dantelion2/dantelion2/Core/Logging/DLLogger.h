#pragma once
#include "Core/Platform/Platform.h"
#include "DLCategory.h"

namespace DLLG
{
	class DLLogger
	{
		const dl_wchar* m_cName;
		DLCategory* m_pCategory;
		DLLogLevel m_level;
		dl_int m_iVar14;

	public:
		DLLogger();
		DLLogger(const dl_wchar* name);
		~DLLogger();

		DLLogLevel GetLogLevel() const { return m_level; }
		const dl_wchar* GetName() const { return m_cName; }
		DLCategory* GetCategory() const { return m_pCategory; }

		void SetName(const dl_wchar* name) { m_cName = name; }
		void SetCategory(DLCategory* category) { m_pCategory = category; }
		void SetLogLevel(DLLogLevel level) { m_level = level; }

		void Log(DLLogLevel level, const dl_wchar* message, ...);
		void LogDebug(const dl_wchar* message, ...);
		void LogInfo(const dl_wchar* message, ...);
		void LogNotice(const dl_wchar* message, ...);
		void LogWarn(const dl_wchar* message, ...);
		void LogError(const dl_wchar* message, ...);
		void LogFatal(const dl_wchar* message, ...);

		void* operator new(size_t size, DLKR::DLAllocator* pAllocator)
		{
			return pAllocator->Allocate(size);
		}

		void operator delete(void* p, DLKR::DLAllocator* pAllocator)
		{
			pAllocator->Free(p);
		}
	};
}