#include "DLHierarchy.h"
#include "Call.h"

namespace DLLG
{
	DLRF::DLRuntimeClass* DLHierarchy::GetRuntimeClass()
	{
		return VIRTUAL_CALL(this, 0, oGetRuntimeClass, this);
	}

	void DLHierarchy::SetAllocator(DLKR::DLAllocator* pA)
	{
		VIRTUAL_CALL(this, 1, oSetAllocator, this, pA);
	}

	DLKR::DLAllocator* DLHierarchy::GetAllocator()
	{
		return VIRTUAL_CALL(this, 2, oGetAllocator, this);
	}

	dl_bool DLHierarchy::DoesExist(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 3, oDoesExist, this, cName);
	}

	dl_bool DLHierarchy::HasLayout(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 4, oHasLayout, this, cName);
	}

	dl_bool DLHierarchy::HasAppender(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 5, oHasAppender, this, cName);
	}

	DLCategory& DLHierarchy::GetCategory(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 6, oGetCategory, this, cName);
	}

	DLCategory& DLHierarchy::GetCategory2(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 7, oGetCategory2, this, cName);
	}

	DLAppender* DLHierarchy::GetAppender(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 8, oGetAppender, this, cName);
	}

	DLAppender* DLHierarchy::AddDefaultAppender(const dl_wchar* name)
	{
		return VIRTUAL_CALL(this, 9, oAddDefaultAppender, this, name);
	}

	dl_bool DLHierarchy::AddAppender(DLAppender* pAppender)
	{
		return VIRTUAL_CALL(this, 10, oAddAppender, this, pAppender);
	}

	DLAppender* DLHierarchy::AddAppender(const dl_char* className, const dl_wchar* name)
	{
		return VIRTUAL_CALL(this, 11, oAddAppenderByName, this, className, name);
	}

	DLLayout* DLHierarchy::AddDefaultLayout(const dl_wchar* name)
	{
		return VIRTUAL_CALL(this, 12, oAddDefaultLayout, this, name);
	}

	dl_bool DLHierarchy::AddLayout(DLLayout* pLayout)
	{
		return VIRTUAL_CALL(this, 13, oAddLayout, this, pLayout);
	}

	DLLayout* DLHierarchy::AddLayout(const dl_char* className, const dl_wchar* name)
	{
		return VIRTUAL_CALL(this, 14, oAddLayoutByClassName, this, className, name);
	}

	void DLHierarchy::RemoveCategory(const dl_wchar* cName)
	{
		VIRTUAL_CALL(this, 15, oRemoveCategory, this, cName);
	}

	DLCategory* DLHierarchy::AddCategory(const dl_wchar* cName)
	{
		return VIRTUAL_CALL(this, 16, oAddCategory, this, cName);
	}

	DLCategory* DLHierarchy::GetRootCategory()
	{
		return VIRTUAL_CALL(this, 17, oGetRootCategory, this);
	}

	void DLHierarchy::ProcessEvent(const DLLogEvent& e)
	{
		VIRTUAL_CALL(this, 18, oProcessEvent, this, e);
	}

	dl_uint DLHierarchy::GetDefaultAppenderSize()
	{
		return VIRTUAL_CALL(this, 19, oGetDefaultAppenderSize, this);
	}

	void DLHierarchy::SetDefaultAppenderSize(dl_uint newSize)
	{
		VIRTUAL_CALL(this, 20, oSetDefaultAppenderSize, this, newSize);
	}

	void DLHierarchy::ClearAppenders()
	{
		VIRTUAL_CALL(this, 21, oClearAppenders, this);
	}

	void DLHierarchy::InitializeAppenders()
	{
		VIRTUAL_CALL(this, 22, oInitializeAppenders, this);
	}

	DLHierarchy::~DLHierarchy()
	{
		VIRTUAL_CALL(this, 23, oDestructor, this);
	}
}