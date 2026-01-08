#include "DLHierarchy.h"
#include "dantelion2/FRPG2Call.h"

namespace DLLG
{
	DLRF::DLRuntimeClass* DLHierarchy::GetRuntimeClass()
	{
		return FRPG2_VCALL(this, 0, oGetRuntimeClass, this);
	}

	void DLHierarchy::SetAllocator(DLKR::DLAllocator* pA)
	{
		FRPG2_VCALL(this, 1, oSetAllocator, this, pA);
	}

	DLKR::DLAllocator* DLHierarchy::GetAllocator()
	{
		return FRPG2_VCALL(this, 2, oGetAllocator, this);
	}

	dl_bool DLHierarchy::DoesExist(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 3, oDoesExist, this, cName);
	}

	dl_bool DLHierarchy::HasLayout(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 4, oHasLayout, this, cName);
	}

	dl_bool DLHierarchy::HasAppender(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 5, oHasAppender, this, cName);
	}

	DLCategory& DLHierarchy::GetCategory(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 6, oGetCategory, this, cName);
	}

	DLCategory& DLHierarchy::GetCategory2(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 7, oGetCategory2, this, cName);
	}

	DLAppender* DLHierarchy::GetAppender(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 8, oGetAppender, this, cName);
	}

	DLAppender* DLHierarchy::AddDefaultAppender(const dl_wchar* name)
	{
		return FRPG2_VCALL(this, 9, oAddDefaultAppender, this, name);
	}

	dl_bool DLHierarchy::AddAppender(DLAppender* pAppender)
	{
		return FRPG2_VCALL(this, 10, oAddAppender, this, pAppender);
	}

	DLAppender* DLHierarchy::AddAppender(const dl_char* className, const dl_wchar* name)
	{
		return FRPG2_VCALL(this, 11, oAddAppenderByName, this, className, name);
	}

	DLLayout* DLHierarchy::AddDefaultLayout(const dl_wchar* name)
	{
		return FRPG2_VCALL(this, 12, oAddDefaultLayout, this, name);
	}

	dl_bool DLHierarchy::AddLayout(DLLayout* pLayout)
	{
		return FRPG2_VCALL(this, 13, oAddLayout, this, pLayout);
	}

	DLLayout* DLHierarchy::AddLayout(const dl_char* className, const dl_wchar* name)
	{
		return FRPG2_VCALL(this, 14, oAddLayoutByClassName, this, className, name);
	}

	void DLHierarchy::RemoveCategory(const dl_wchar* cName)
	{
		FRPG2_VCALL(this, 15, oRemoveCategory, this, cName);
	}

	DLCategory* DLHierarchy::AddCategory(const dl_wchar* cName)
	{
		return FRPG2_VCALL(this, 16, oAddCategory, this, cName);
	}

	DLCategory* DLHierarchy::GetRootCategory()
	{
		return FRPG2_VCALL(this, 17, oGetRootCategory, this);
	}

	void DLHierarchy::ProcessEvent(const DLLogEvent& e)
	{
		FRPG2_VCALL(this, 18, oProcessEvent, this, e);
	}

	dl_uint DLHierarchy::GetDefaultAppenderSize()
	{
		return FRPG2_VCALL(this, 19, oGetDefaultAppenderSize, this);
	}

	void DLHierarchy::SetDefaultAppenderSize(dl_uint newSize)
	{
		FRPG2_VCALL(this, 20, oSetDefaultAppenderSize, this, newSize);
	}

	void DLHierarchy::ClearAppenders()
	{
		FRPG2_VCALL(this, 21, oClearAppenders, this);
	}

	void DLHierarchy::InitializeAppenders()
	{
		FRPG2_VCALL(this, 22, oInitializeAppenders, this);
	}

	DLHierarchy::~DLHierarchy()
	{
		FRPG2_VCALL(this, 23, oDestructor, this);
	}
}