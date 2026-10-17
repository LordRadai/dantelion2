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
    };
 }