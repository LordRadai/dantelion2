#pragma once
#include "Core/Platform/Platform.h"

namespace DLPF
{
	struct DL_ASSERT_INFO
	{
		const dl_wchar* Msg;
		const dl_wchar* File;
		dl_uint Line;

		DL_ASSERT_INFO(const dl_wchar* msg, const dl_wchar* file, dl_uint line)
			: Msg(msg), File(file), Line(line) {}
	};

	typedef DL_ASSERT_INFO DLAssertEvent;

	static class DLAssert
	{
	public:
		static void ReportAssertionFailure(const DL_ASSERT_INFO& info);
		static dl_bool IsAssertEnabled() { return s_bAssertEnabled; }
		static void SetAssertEnabled(dl_bool enabled) { s_bAssertEnabled = enabled; }
	private:
		static void _ReportAssertionFailure(const dl_wchar* file, dl_uint line, const dl_wchar* msg, const DL_ASSERT_INFO& info);

		static dl_bool s_bAssertEnabled;
	};

#define DL_ASSERT(expr) \
	do { \
		if (!(expr) && DLPF::DLAssert::IsAssertEnabled()) \
		{ \
			DLPF::DLAssert::ReportAssertionFailure(DLPF::DL_ASSERT_INFO(L#expr, __FILEW__, __LINE__)); \
		} \
	} while (0)
}