#pragma once
#include "DLLayout.h"
#include "Core/Reflection/DLRuntimeClassImpl.inl"

namespace DLLG
{
	class DLLogEvent;

	class DLAppender
	{
		DLLayout* m_pLayout;
		DLTX::DLString m_name;
	public:
		DLAppender();

		virtual DLRF::DLRuntimeClassImpl<DLAppender>* GetRuntimeClass();
		virtual dl_bool vfunction1();
		virtual dl_bool vfunction2();
		virtual void Append(const DLLogEvent& e);
		virtual DLLayout* GetLayout();
		virtual const DLTX::DLString& GetName();
		virtual void SetLayout(const dl_wchar* pLayoutName);
		virtual void SetLayout(DLLayout* pLayout);
		virtual void SetName(const dl_wchar* name);
		virtual ~DLAppender();

		typedef void(_fastcall* DLAppenderConstructor)(DLAppender*);
		typedef DLRF::DLRuntimeClassImpl<DLAppender>* (_fastcall* DLAppenderGetRuntimeClass)(DLAppender*);
		typedef dl_bool(_fastcall* DLAppenderVFunc1)(DLAppender*);
		typedef dl_bool(_fastcall* DLAppenderVFunc2)(DLAppender*);
		typedef void(_fastcall* DLAppenderAppend)(DLAppender*, const DLLogEvent&);
		typedef DLLayout* (_fastcall* DLAppenderGetLayout)(DLAppender*);
		typedef const DLTX::DLString& (_fastcall* DLAppenderGetName)(DLAppender*);
		typedef void(_fastcall* DLAppenderSetLayoutByName)(DLAppender*, const dl_wchar*);
		typedef void(_fastcall* DLAppenderSetLayout)(DLAppender*, DLLayout*);
		typedef void(_fastcall* DLAppenderSetName)(DLAppender*, const dl_wchar*);
		typedef void(_fastcall* DLAppenderDestructor)(DLAppender*);
	};
}
