#pragma once
#include "DLSeekableOutputStream.h"

namespace DLIO
{
    class DLFileOutputStream : public DLSeekableOutputStream
    {
        DLFile* m_pFile;
        dl_bool m_setEOFOnClose;
        IO_ERROR_CODE m_lastError;

    public:
        DLFileOutputStream(DLFile& file, dl_bool isAppend = false, dl_bool isAsync = false, dl_bool unkFlag40 = true, dl_bool unkFlag80 = true);
        DLFileOutputStream();
        virtual ~DLFileOutputStream();

        dl_bool Open(DLFile& file, dl_bool isAppend = false, dl_bool isAsync = false, dl_bool unkFlag40 = true, dl_bool unkFlag80 = true);

        virtual void SetLastError(IO_ERROR_CODE error);
        virtual IO_ERROR_CODE GetLastError(void) const;
        virtual dl_size Write(const void* buf, dl_size size);
        virtual dl_size GetWriteSize(void);
        virtual void Close(void);
        virtual void Flush(void);
        virtual dl_bool IsOpen(void) const;
        virtual dl_size GetAsyncBlockSize(void) const;
        virtual dl_size GetAsyncBufferAlignmentSize(void) const;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total = 0);
        virtual dl_bool StartAsyncWrite(dl_int8* buffer, dl_size len);
        virtual dl_bool SeekPosition(dl_pointer_int pos, DLSeekDirection direction = SD_CURRENT);
        virtual dl_pointer_int GetPosition(void);
        virtual void SetEOFOnClose(dl_bool setEOFOnClose);
    };
}