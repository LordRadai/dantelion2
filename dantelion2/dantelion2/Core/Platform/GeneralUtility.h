#pragma once
#include "Platform.h"
#include <exception>

template < typename T > struct DLMaxSize;
template < typename T > struct DLMinSize;
template <> struct DLMaxSize<dl_int8> { const static dl_int8 Value = 0x7F; };
template <> struct DLMaxSize<dl_int16> { const static dl_int16 Value = 0x7FFF; };
template <> struct DLMaxSize<dl_int32> { const static dl_int32 Value = 0x7FFFFFFF; };
template <> struct DLMaxSize<dl_int64> { const static dl_int64 Value = 0x7FFFFFFFFFFFFFFFULL; };
template <> struct DLMaxSize<dl_uint8> { const static dl_uint8 Value = 0xFF; };
template <> struct DLMaxSize<dl_uint16> { const static dl_uint16 Value = 0xFFFF; };
template <> struct DLMaxSize<dl_uint32> { const static dl_uint32 Value = 0xFFFFFFFF; };
template <> struct DLMaxSize<dl_uint64> { const static dl_uint64 Value = 0xFFFFFFFFFFFFFFFFULL; };
template <> struct DLMaxSize<dl_char> { const static dl_char Value = 0x7F; };

template <> struct DLMinSize<dl_int8> { const static dl_int8 Value = -128; };
template <> struct DLMinSize<dl_int16> { const static dl_int16 Value = 0x800; };
template <> struct DLMinSize<dl_int32> { const static dl_int32 Value = 0x80000000; };
template <> struct DLMinSize<dl_int64> { const static dl_int64 Value = 0x8000000000000000LL; };
template <> struct DLMinSize<dl_uint8> { const static dl_uint8 Value = 0; };
template <> struct DLMinSize<dl_uint16> { const static dl_uint16 Value = 0; };
template <> struct DLMinSize<dl_uint32> { const static dl_uint32 Value = 0; };
template <> struct DLMinSize<dl_uint64> { const static dl_uint64 Value = 0; };
template <> struct DLMinSize<dl_char> { const static dl_char Value = -128; };

template <> struct DLMinSize<dl_bool> { const static dl_bool Value = false; };
template <> struct DLMaxSize<dl_bool> { const static dl_bool Value = true; };

template <> struct DLMinSize<dl_wchar> { const static dl_wchar Value = 0; };
template <> struct DLMaxSize<dl_wchar> { const static dl_wchar Value = 0xFFFF; };

enum DLPanicMode
{
    DLPANICMODE_COREDUMP,
    DLPANICMODE_INVOKEDEBUGGER,
    DLPANICMODE_THROWEXCEPTION,
    DLPANICMODE_NUM
};

class DLPanicException : public std::exception 
{
    const dl_char* m_pMsg;
	dl_bool m_bThreadSafe;
public:
    DLPanicException(const dl_char* msg) : m_pMsg(msg), m_bThreadSafe(false) {}
    DLPanicException(const std::exception& e) : m_pMsg(e.what()), m_bThreadSafe(false) {}
    DLPanicException(const DLPanicException& e) : m_pMsg(e.what()), m_bThreadSafe(false) {}
    const char* what() const { return m_pMsg; }
};

class DLPanic 
{
public:
    static void ReportPanic(const dl_char* file, dl_uint32 line, const dl_char* reason);

    typedef void(_fastcall* oReportPanic)(const dl_char* file, dl_uint32 line, const dl_char* reason);
};

#define DL_PANIC(error) DLPanic::ReportPanic(__FILE__, __LINE__, error)
#define DL_PANIC_MODE *(DLPanicMode*)(MODULE_ADDR + 0x157d524)