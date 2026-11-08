#pragma once
#include "Core/Platform/Platform.h"
#include "DLFile.h"

namespace DLIO
{
    class DLOutputStream
    {
    public:
        virtual void SetLastError(IO_ERROR_CODE code) = 0;
        virtual ~DLOutputStream() {}
        virtual IO_ERROR_CODE GetLastError(void) const = 0;
        virtual dl_size Write(const void* buf, dl_size size) = 0;
        virtual dl_size GetWriteSize(void) = 0;
        virtual void Close(void) = 0;
        virtual void Flush(void) = 0;
        virtual dl_bool IsOpen(void) const = 0;
        virtual dl_size GetAsyncBlockSize(void) const = 0;
        virtual dl_size GetAsyncBufferAlignmentSize(void) const = 0;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total = 0) = 0;
        virtual dl_bool StartAsyncWrite(dl_int8* buffer, dl_size len) = 0;

        typedef void(_fastcall* SetLastError_t)(DLOutputStream*, IO_ERROR_CODE);
        typedef IO_ERROR_CODE(_fastcall* GetLastError_t)(const DLOutputStream*);
        typedef dl_size(_fastcall* Write_t)(DLOutputStream*, const void*, dl_size);
        typedef dl_size(_fastcall* GetWriteSize_t)(DLOutputStream*);
        typedef void(_fastcall* Close_t)(DLOutputStream*);
        typedef void(_fastcall* Flush_t)(DLOutputStream*);
        typedef dl_bool(_fastcall* IsOpen_t)(const DLOutputStream*);
        typedef dl_size(_fastcall* GetAsyncBlockSize_t)(const DLOutputStream*);
        typedef dl_size(_fastcall* GetAsyncBufferAlignmentSize_t)(const DLOutputStream*);
        typedef dl_bool(_fastcall* QueryAsyncStatus_t)(DLOutputStream*, dl_size*, dl_size*);
        typedef dl_bool(_fastcall* StartAsyncWrite_t)(DLOutputStream*, dl_int8*, dl_size);
    };
}