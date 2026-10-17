#pragma once
#include "Core/Platform/Platform.h"

namespace DLIO
{
    class DLWriter {
    public:
        virtual ~DLWriter() {}

        virtual dl_size Write(const void* buf, dl_size size) = 0;
        virtual dl_size Write(const dl_wchar* string);
        virtual dl_size Write(const dl_char* string);
        virtual dl_size Write(const dl_wchar* string, dl_size count);
        virtual dl_size Write(const dl_char* string, dl_size count);
        virtual dl_size Write(dl_uint8 value);
        virtual dl_size Write(dl_uint16 value);
        virtual dl_size Write(dl_uint32 value);
        virtual dl_size Write(dl_uint64 value);
        virtual dl_size Write(dl_int8 value);
        virtual dl_size Write(dl_int16 value);
        virtual dl_size Write(dl_int32 value);
        virtual dl_size Write(dl_int64 value);
        virtual dl_size Write(dl_float32 value);
        virtual dl_size Write(dl_float64 value);
        virtual dl_size Skip(dl_size size);
        virtual dl_size Write(dl_char value);
        virtual dl_size Write(dl_wchar value);
        virtual void Flush(void) = 0;
        virtual void Close(void) = 0;
        virtual dl_bool IsOpen(void) const = 0;
    };
}