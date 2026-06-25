#pragma once
#include "DLAppender.h"
#include "Core/Util/DLSet.h"
#include "DLLogLevel.inl"
#include "Core/Reflection/DLRuntimeClassImpl.inl"

namespace DLLG
{
	class DLCategory
	{
		DLUT::DLSet<DLAppender*> m_aList;
		DLLogLevel m_level;
		DLTX::DLString m_name;
		dl_bool m_bIsTerminating;
	public:
		virtual DLRF::DLRuntimeClassImpl<DLCategory>* GetRuntimeClass();
		virtual ~DLCategory();

		void AddAppender(const dl_wchar* name);

		void SetLogLevel(DLLogLevel level) { m_level = level; }
		DLLogLevel GetLogLevel() const { return m_level; }

		typedef DLRF::DLRuntimeClassImpl<DLCategory>*(_fastcall* oGetRuntimeClass)(DLCategory*);
		typedef void(_fastcall* oDestructor)(DLCategory*);
	};
}
