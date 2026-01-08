#pragma once
#include "DLAppender.h"
#include "dantelion2/Core/Util/DLSet.h"
#include "DLLogLevel.inl"
#include "dantelion2/Core/Reflection/DLRuntimeClassImpl.inl"

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

		typedef DLRF::DLRuntimeClassImpl<DLCategory>*(_fastcall* oGetRuntimeClass)(DLCategory*);
		typedef void(_fastcall* oDestructor)(DLCategory*);
	};
}
