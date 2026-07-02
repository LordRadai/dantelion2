#pragma once
#include "Core/Platform/Platform.h"

namespace DLPF
{
	struct DL_ASSERT_INFO
	{
		dl_uint State;
		const dl_wchar* Msg;
		const dl_wchar* File;
		dl_uint Line;

		DL_ASSERT_INFO(const dl_wchar* msg, const dl_wchar* file, dl_uint line)
			: State(0),Msg(msg), File(file), Line(line) {}
	};

	struct DL_ASSERT_RESULT
	{
		dl_bool bVar0;
		dl_bool bVar1;
	};

	typedef DL_ASSERT_INFO DLAssertEvent;
	typedef DL_ASSERT_RESULT DLAssertResult;

	static class DLAssert
	{
	public:
		static void ReportAssertionFailure(const DLAssertEvent& info);
		static dl_bool IsAssertEnabled() { return s_bAssertEnabled; }
		static void SetAssertEnabled(dl_bool enabled) { s_bAssertEnabled = enabled; }
	private:
		static void _ReportAssertionFailure(const dl_wchar* file, dl_uint line, const dl_wchar* msg, const DLAssertEvent& info);

		static dl_bool s_bAssertEnabled;
	};

#define DL_ASSERT(expr, msg) \
	do { \
		if (!(expr) && DLPF::DLAssert::IsAssertEnabled()) \
		{ \
			DLPF::DLAssert::ReportAssertionFailure(DLPF::DL_ASSERT_INFO(L#msg, __FILEW__, __LINE__)); \
		} \
	} while (0)
}