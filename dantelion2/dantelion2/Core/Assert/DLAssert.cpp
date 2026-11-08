#include "DLAssert.h"
#include "Core/System/DLRuntime.h"

namespace DLPF
{
	bool DLAssert::s_bAssertEnabled = true;

	void DLAssert::ReportAssertionFailure(DLAssertEvent& info)
	{
		if (!info.bIgnore)
			_ReportAssertionFailure(info.File, info.Line, info.Msg, info);
	}

	void DLAssert::_ReportAssertionFailure(const dl_wchar* file, dl_uint line, const dl_wchar* msg, DLAssertEvent& info)
	{
		DLSY::DLRuntime* pRuntime = DLSY::DLRuntime::GetRuntime();
		DLSY::DLAssertEventManager* pAssertEventManager = pRuntime->GetAssertEventManager();

		DLAssertResult result;
		pAssertEventManager->FireAssertEvent(&result, info);

		if (result.bIgnore)
		{
			info.bIgnore = true;
			return;
		}
		else if (result.bAbort)
		{
			DLSY::DLRuntime::InvokeDebugger();
			DL_PANIC("Assertion event insisted on terminating the program.");
		}
		else
		{
			return;
		}
	}
}