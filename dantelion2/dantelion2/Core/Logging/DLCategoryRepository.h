#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Reflection/DLRuntimeClassImpl.inl"
#include "DLLogEvent.h"

namespace DLLG
{
	class DLCategoryRepository
	{
	public:
		virtual DLRF::DLRuntimeClass* GetRuntimeClass();
		virtual void SetAllocator(DLKR::DLAllocator* pA) = 0;
		virtual DLKR::DLAllocator* GetAllocator() = 0;
		virtual dl_bool DoesExist(const dl_wchar* cName) = 0;
		virtual dl_bool HasLayout(const dl_wchar* cName) = 0;
		virtual dl_bool HasAppender(const dl_wchar* cName) = 0;
		virtual DLCategory& GetCategory(const dl_wchar* cName) = 0;
		virtual DLCategory& GetCategory2(const dl_wchar* cName) = 0;
		virtual DLAppender* GetAppender(const dl_wchar* cName) = 0;
		virtual DLAppender* AddDefaultAppender(const dl_wchar* name = 0) = 0;
		virtual dl_bool AddAppender(DLAppender* pAppender) = 0;
		virtual DLAppender* AddAppender(const dl_char* className, const dl_wchar* name = 0) = 0;
		virtual DLLayout* AddDefaultLayout(const dl_wchar* name = 0) = 0;
		virtual dl_bool AddLayout(DLLayout* pLayout) = 0;
		virtual DLLayout* AddLayout(const dl_char* className, const dl_wchar* name = 0) = 0;
		virtual void RemoveCategory(const dl_wchar* cName) = 0;
		virtual DLCategory* AddCategory(const dl_wchar* cName) = 0;
		virtual DLCategory* GetRootCategory() = 0;
		virtual void ProcessEvent(const DLLogEvent& e) = 0;
		virtual dl_uint GetDefaultAppenderSize() = 0;
		virtual void SetDefaultAppenderSize(dl_uint newSize) = 0;
		virtual void ClearAppenders() = 0;
		virtual void InitializeAppenders() = 0;
		virtual ~DLCategoryRepository();

		typedef DLRF::DLRuntimeClass* (_fastcall* oGetRuntimeClass)(DLCategoryRepository*);
		typedef void(_fastcall* oSetAllocator)(DLCategoryRepository*, DLKR::DLAllocator*);
		typedef DLKR::DLAllocator* (_fastcall* oGetAllocator)(DLCategoryRepository*);
		typedef dl_bool(_fastcall* oDoesExist)(DLCategoryRepository*, const dl_wchar*);
		typedef dl_bool(_fastcall* oHasLayout)(DLCategoryRepository*, const dl_wchar*);
		typedef dl_bool(_fastcall* oHasAppender)(DLCategoryRepository*, const dl_wchar*);
		typedef DLCategory& (_fastcall* oGetCategory)(DLCategoryRepository*, const dl_wchar*);
		typedef DLCategory& (_fastcall* oGetCategory2)(DLCategoryRepository*, const dl_wchar*);
		typedef DLAppender* (_fastcall* oGetAppender)(DLCategoryRepository*, const dl_wchar*);
		typedef DLAppender* (_fastcall* oAddDefaultAppender)(DLCategoryRepository*, const dl_wchar*);
		typedef dl_bool(_fastcall* oAddAppender)(DLCategoryRepository*, DLAppender*);
		typedef DLAppender* (_fastcall* oAddAppenderByName)(DLCategoryRepository*, const dl_char*, const dl_wchar*);
		typedef DLLayout* (_fastcall* oAddDefaultLayout)(DLCategoryRepository*, const dl_wchar*);
		typedef dl_bool(_fastcall* oAddLayout)(DLCategoryRepository*, DLLayout*);
		typedef DLLayout* (_fastcall* oAddLayoutByClassName)(DLCategoryRepository*, const dl_char*, const dl_wchar*);
		typedef void(_fastcall* oRemoveCategory)(DLCategoryRepository*, const dl_wchar*);
		typedef DLCategory* (_fastcall* oAddCategory)(DLCategoryRepository*, const dl_wchar*);
		typedef DLCategory* (_fastcall* oGetRootCategory)(DLCategoryRepository*);
		typedef void(_fastcall* oProcessEvent)(DLCategoryRepository*, const DLLogEvent&);
		typedef dl_uint(_fastcall* oGetDefaultAppenderSize)(DLCategoryRepository*);
		typedef void(_fastcall* oSetDefaultAppenderSize)(DLCategoryRepository*, dl_uint);
		typedef void(_fastcall* oClearAppenders)(DLCategoryRepository*);
		typedef void(_fastcall* oInitializeAppenders)(DLCategoryRepository*);
		typedef void(_fastcall* oDestructor)(DLCategoryRepository*);
	};
}
