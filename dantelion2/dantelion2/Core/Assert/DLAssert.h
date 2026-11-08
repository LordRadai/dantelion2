#pragma once
#include "Core/Platform/Platform.h"

namespace DLPF
{
	namespace DLPFD
	{
		inline const wchar_t* PickMsg(const wchar_t* /*text*/, const wchar_t* value) { return value; }
		inline const wchar_t* PickMsg(const wchar_t* /*text*/, wchar_t* value) { return value; }
		template <typename T>
		inline const wchar_t* PickMsg(const wchar_t* text, const T&) { return text; }
	}

	struct DL_ASSERT_INFO
	{
		dl_uint State;
		const dl_wchar* Msg;
		const dl_wchar* File;
		dl_uint Line;
		dl_bool bIgnore;

		DL_ASSERT_INFO(const dl_wchar* msg, const dl_wchar* file, dl_uint line)
			: State(0), Msg(msg), File(file), Line(line), bIgnore(false) {}
	};

	struct DL_ASSERT_RESULT
	{
		dl_bool bIgnore;
		dl_bool bAbort;
	};

	typedef DL_ASSERT_INFO DLAssertEvent;
	typedef DL_ASSERT_RESULT DLAssertResult;

	static class DLAssert
	{
	public:
		static void ReportAssertionFailure(DLAssertEvent& info);
		static dl_bool IsAssertEnabled() { return s_bAssertEnabled; }
		static void SetAssertEnabled(dl_bool enabled) { s_bAssertEnabled = enabled; }
	private:
		static void _ReportAssertionFailure(const dl_wchar* file, dl_uint line, const dl_wchar* msg, DLAssertEvent& info);

		static dl_bool s_bAssertEnabled;
	};
}

#define DL_ASSERT(expr, msg)														\
    do {																			\
        if (!(expr) && DLPF::DLAssert::IsAssertEnabled())							\
        {																			\
            DLPF::DLAssert::ReportAssertionFailure(DLPF::DL_ASSERT_INFO(			\
                DLPF::DLPFD::PickMsg(L#msg, (msg)), __FILEW__, __LINE__));			\
        }																			\
    } while (0)