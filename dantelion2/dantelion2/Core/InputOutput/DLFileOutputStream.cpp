#include "DLFileOutputStream.h"
#include "Call.h"

namespace
{
    typedef void* (_fastcall* DLFileOutputStreamCtor_t)(DLIO::DLFileOutputStream*, DLIO::DLFile&, dl_bool, dl_bool, dl_bool, dl_bool);
    typedef void* (_fastcall* DLFileOutputStreamDefaultCtor_t)(DLIO::DLFileOutputStream*);
    typedef void(_fastcall* DLFileOutputStreamDtor_t)(DLIO::DLFileOutputStream*);
    typedef dl_bool(_fastcall* Open_t)(DLIO::DLFileOutputStream*, DLIO::DLFile&, dl_bool, dl_bool, dl_bool, dl_bool);
}

namespace DLIO
{
    DLFileOutputStream::DLFileOutputStream(DLFile& file, dl_bool isAppend, dl_bool isAsync, dl_bool unkFlag40, dl_bool unkFlag80)
    {
        CALL(DLFileOutputStreamCtor_t, 0x875EB0, this, file, isAppend, isAsync, unkFlag40, unkFlag80);
    }

    DLFileOutputStream::DLFileOutputStream()
    {
        CALL(DLFileOutputStreamDefaultCtor_t, 0x875F10, this);
    }

    DLFileOutputStream::~DLFileOutputStream()
    {
        CALL(DLFileOutputStreamDtor_t, 0x875F40, this);
    }

    dl_bool DLFileOutputStream::Open(DLFile& file, dl_bool isAppend, dl_bool isAsync, dl_bool unkFlag40, dl_bool unkFlag80)
    {
        return CALL(Open_t, 0x875F80, this, file, isAppend, isAsync, unkFlag40, unkFlag80);
    }

    void DLFileOutputStream::SetLastError(IO_ERROR_CODE error)
    {
        CALL(SetLastError_t, 0x875EA0, this, error);
    }

    IO_ERROR_CODE DLFileOutputStream::GetLastError(void) const
    {
        return CALL(GetLastError_t, 0x876560, this);
    }

    dl_size DLFileOutputStream::Write(const void* buf, dl_size size)
    {
        return CALL(Write_t, 0x876050, this, buf, size);
    }

    dl_size DLFileOutputStream::GetWriteSize(void)
    {
        return CALL(GetWriteSize_t, 0x8760F0, this);
    }

    void DLFileOutputStream::Close(void)
    {
        CALL(Close_t, 0x876140, this);
    }

    void DLFileOutputStream::Flush(void)
    {
        CALL(Flush_t, 0x8761C0, this);
    }

    dl_bool DLFileOutputStream::IsOpen(void) const
    {
        return CALL(IsOpen_t, 0x876220, this);
    }

    dl_size DLFileOutputStream::GetAsyncBlockSize(void) const
    {
        return CALL(GetAsyncBlockSize_t, 0x876380, this);
    }

    dl_size DLFileOutputStream::GetAsyncBufferAlignmentSize(void) const
    {
        return CALL(GetAsyncBufferAlignmentSize_t, 0x8763D0, this);
    }

    dl_bool DLFileOutputStream::QueryAsyncStatus(dl_size* remain, dl_size* total)
    {
        return CALL(QueryAsyncStatus_t, 0x876420, this, remain, total);
    }

    dl_bool DLFileOutputStream::StartAsyncWrite(dl_int8* buffer, dl_size len)
    {
        return CALL(StartAsyncWrite_t, 0x8764C0, this, buffer, len);
    }

    dl_bool DLFileOutputStream::SeekPosition(dl_pointer_int pos, DLSeekDirection direction)
    {
        return CALL(SeekPosition_t, 0x876270, this, pos, direction);
    }

    dl_pointer_int DLFileOutputStream::GetPosition(void)
    {
        return CALL(GetPosition_t, 0x876300, this);
    }

    void DLFileOutputStream::SetEOFOnClose(dl_bool setEOFOnClose)
    {
        CALL(SetEOFOnClose_t, 0x876350, this, setEOFOnClose);
    }
}