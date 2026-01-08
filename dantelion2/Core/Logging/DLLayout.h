#pragma once
#include "dantelion2/Core/Text/DLString.inl"
#include "dantelion2/Core/Reflection/DLRuntimeClassImpl.inl"

namespace DLLG
{
	class DLLayout
	{
		DLTX::DLString m_name;
		DLTX::DLCharacterSet m_cs;
	public:
		DLLayout();

		virtual DLRF::DLRuntimeClassImpl<DLLayout>* GetRuntimeClass() const;
		virtual void Format(/*const DLLogEvent& e, DLIO::DLWriter &w*/);
		virtual DLTX::DLString& GetName();
		virtual void SetName(const dl_wchar* name);
		virtual ~DLLayout();
	};
}
