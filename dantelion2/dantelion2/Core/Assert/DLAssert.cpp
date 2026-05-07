#include "DLAssert.h"
#include "Core/System/DLRuntime.h"

namespace DLPF
{
	void DLAssert::ReportAssertionFailure(const DL_ASSERT_INFO& info)
	{
		_ReportAssertionFailure(info.File, info.Line, info.Msg, info);
	}

	void DLAssert::_ReportAssertionFailure(const dl_wchar* file, dl_uint line, const dl_wchar* msg, const DL_ASSERT_INFO& info)
	{
		DLSY::DLRuntime* pRuntime = DLSY::DLRuntime::GetRuntime();
		DLSY::DLAssertEventManager* pAssertEventManager = pRuntime->GetAssertEventManager();

		pAssertEventManager->FireAssertEvent(info);
	}
}