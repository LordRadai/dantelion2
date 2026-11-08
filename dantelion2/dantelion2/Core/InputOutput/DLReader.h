#pragma once
#include "Core/Platform/Platform.h"

namespace DLIO
{
    class DLReader 
    {
    public:
        virtual ~DLReader() {}

        virtual dl_int32 Read(void* buf, dl_size size) = 0;
        virtual dl_int32 Read(dl_wchar* buf, dl_size count, const dl_wchar* pDelim, dl_bool terminate) = 0;
        virtual dl_int32 Read(dl_wchar* buf, dl_size count, dl_wchar delim, dl_bool terminate) = 0;
        virtual dl_int32 Read(dl_char* buf, dl_size count, const dl_char* pDelim, dl_bool terminate) = 0;
        virtual dl_int32 Read(dl_char* buf, dl_size count, dl_char delim, dl_bool terminate) = 0;
        virtual dl_int8 ReadSInt8(void) = 0;
        virtual dl_int16 ReadSInt16(void) = 0;
        virtual dl_int32 ReadSInt32(void) = 0;
        virtual dl_int64 ReadSInt64(void) = 0;
        virtual dl_uint8 ReadUInt8(void) = 0;
        virtual dl_uint16 ReadUInt16(void) = 0;
        virtual dl_uint32 ReadUInt32(void) = 0;
        virtual dl_uint64 ReadUInt64(void) = 0;
        virtual dl_float32 ReadFloat32(void) = 0;
        virtual dl_float64 ReadFloat64(void) = 0;
        virtual dl_char ReadChar(void) = 0;
        virtual dl_wchar ReadWChar(void) = 0;
        virtual dl_bool IsAvailable(void) = 0;
        virtual dl_size GetReadSize(void) = 0;
        virtual dl_size Skip(dl_size length) = 0;
        virtual void Close(void) = 0;
        virtual dl_bool IsOpen(void) const = 0;

        typedef dl_int32(_fastcall* ReadBuffer_t)(DLReader*, void*, dl_size);
        typedef dl_int32(_fastcall* ReadWStringDelimList_t)(DLReader*, dl_wchar*, dl_size, const dl_wchar*, dl_bool);
        typedef dl_int32(_fastcall* ReadWStringDelim_t)(DLReader*, dl_wchar*, dl_size, dl_wchar, dl_bool);
        typedef dl_int32(_fastcall* ReadStringDelimList_t)(DLReader*, dl_char*, dl_size, const dl_char*, dl_bool);
        typedef dl_int32(_fastcall* ReadStringDelim_t)(DLReader*, dl_char*, dl_size, dl_char, dl_bool);
        typedef dl_int8(_fastcall* ReadSInt8_t)(DLReader*);
        typedef dl_int16(_fastcall* ReadSInt16_t)(DLReader*);
        typedef dl_int32(_fastcall* ReadSInt32_t)(DLReader*);
        typedef dl_int64(_fastcall* ReadSInt64_t)(DLReader*);
        typedef dl_uint8(_fastcall* ReadUInt8_t)(DLReader*);
        typedef dl_uint16(_fastcall* ReadUInt16_t)(DLReader*);
        typedef dl_uint32(_fastcall* ReadUInt32_t)(DLReader*);
        typedef dl_uint64(_fastcall* ReadUInt64_t)(DLReader*);
        typedef dl_float32(_fastcall* ReadFloat32_t)(DLReader*);
        typedef dl_float64(_fastcall* ReadFloat64_t)(DLReader*);
        typedef dl_char(_fastcall* ReadChar_t)(DLReader*);
        typedef dl_wchar(_fastcall* ReadWChar_t)(DLReader*);
        typedef dl_bool(_fastcall* IsAvailable_t)(DLReader*);
        typedef dl_size(_fastcall* GetReadSize_t)(DLReader*);
        typedef dl_size(_fastcall* Skip_t)(DLReader*, dl_size);
        typedef void(_fastcall* Close_t)(DLReader*);
        typedef dl_bool(_fastcall* IsOpen_t)(const DLReader*);
    };
 }