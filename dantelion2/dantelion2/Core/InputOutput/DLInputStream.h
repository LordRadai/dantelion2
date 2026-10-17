#pragma once
#include "Core/Platform/Platform.h"
#include "DLFile.h"

namespace DLIO
{
    class DLInputStream
    {
    public:
        virtual void SetLastError(IO_ERROR_CODE code) = 0;
        virtual ~DLInputStream() {}
        virtual IO_ERROR_CODE GetLastError(void) const = 0;
        virtual dl_int32 Read(void* buf, dl_size size) = 0;
        virtual dl_bool IsAvailable(void) = 0;
        virtual dl_size GetReadSize(void) = 0;
        virtual dl_size Skip(dl_uint64 length) = 0;
        virtual void Close(void) = 0;
        virtual dl_bool IsOpen(void) const = 0;
        virtual dl_size GetAsyncBlockSize(void) const = 0;
        virtual dl_size GetAsyncBufferAlignmentSize(void) const = 0;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total = 0) = 0;
        virtual dl_bool StartAsyncRead(dl_int8* buffer, dl_size len) = 0;

        typedef void(_fastcall* SetLastError_t)(DLInputStream*, IO_ERROR_CODE);
        typedef IO_ERROR_CODE(_fastcall* GetLastError_t)(const DLInputStream*);
        typedef dl_int32(_fastcall* Read_t)(DLInputStream*, void*, dl_size);
        typedef dl_bool(_fastcall* IsAvailable_t)(DLInputStream*);
        typedef dl_size(_fastcall* GetReadSize_t)(DLInputStream*);
        typedef dl_size(_fastcall* Skip_t)(DLInputStream*, dl_size);
        typedef void(_fastcall* Close_t)(DLInputStream*);
        typedef dl_bool(_fastcall* IsOpen_t)(const DLInputStream*);
        typedef dl_size(_fastcall* GetAsyncBlockSize_t)(const DLInputStream*);
        typedef dl_size(_fastcall* GetAsyncBufferAlignmentSize_t)(const DLInputStream*);
        typedef dl_bool(_fastcall* QueryAsyncStatus_t)(DLInputStream*, dl_size*, dl_size*);
        typedef dl_bool(_fastcall* StartAsyncRead_t)(DLInputStream*, dl_int8*, dl_size);
    };
}