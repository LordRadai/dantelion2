#pragma once
#include "Core/Platform/Platform.h"

namespace DLIO
{
    class DLWriter
    {
    public:
        virtual ~DLWriter() {}

        // Declaration order matters: MSVC lays the Write overloads out in reverse (slot 18 = buffer ... slot 1 = bool).
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
        virtual dl_size Write(dl_bool value); // 2014 addition, slot 1 (type inferred: 1 byte in DL)
        virtual void Flush(void) = 0;
        virtual void Close(void) = 0;
        virtual dl_bool IsOpen(void) const = 0;

        typedef dl_size(_fastcall* WriteBuffer_t)(DLWriter*, const void*, dl_size);
        typedef dl_size(_fastcall* WriteWString_t)(DLWriter*, const dl_wchar*);
        typedef dl_size(_fastcall* WriteString_t)(DLWriter*, const dl_char*);
        typedef dl_size(_fastcall* WriteWStringCount_t)(DLWriter*, const dl_wchar*, dl_size);
        typedef dl_size(_fastcall* WriteStringCount_t)(DLWriter*, const dl_char*, dl_size);
        typedef dl_size(_fastcall* WriteUInt8_t)(DLWriter*, dl_uint8);
        typedef dl_size(_fastcall* WriteUInt16_t)(DLWriter*, dl_uint16);
        typedef dl_size(_fastcall* WriteUInt32_t)(DLWriter*, dl_uint32);
        typedef dl_size(_fastcall* WriteUInt64_t)(DLWriter*, dl_uint64);
        typedef dl_size(_fastcall* WriteSInt8_t)(DLWriter*, dl_int8);
        typedef dl_size(_fastcall* WriteSInt16_t)(DLWriter*, dl_int16);
        typedef dl_size(_fastcall* WriteSInt32_t)(DLWriter*, dl_int32);
        typedef dl_size(_fastcall* WriteSInt64_t)(DLWriter*, dl_int64);
        typedef dl_size(_fastcall* WriteFloat32_t)(DLWriter*, dl_float32);
        typedef dl_size(_fastcall* WriteFloat64_t)(DLWriter*, dl_float64);
        typedef dl_size(_fastcall* Skip_t)(DLWriter*, dl_size);
        typedef dl_size(_fastcall* WriteChar_t)(DLWriter*, dl_char);
        typedef dl_size(_fastcall* WriteWChar_t)(DLWriter*, dl_wchar);
        typedef dl_size(_fastcall* WriteBool_t)(DLWriter*, dl_bool);
        typedef void(_fastcall* Flush_t)(DLWriter*);
        typedef void(_fastcall* Close_t)(DLWriter*);
        typedef dl_bool(_fastcall* IsOpen_t)(const DLWriter*);
    };
}