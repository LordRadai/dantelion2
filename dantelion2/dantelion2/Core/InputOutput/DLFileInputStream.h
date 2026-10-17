#pragma once
#include "DLSeekableInputStream.h"

namespace DLIO
{
    class DLFileInputStream : public DLSeekableInputStream
    {
        DLFile* m_pFile;
        IO_ERROR_CODE m_lastError;

    public:
        DLFileInputStream(DLFile& file, bool isAsync = false);
        DLFileInputStream();
        virtual ~DLFileInputStream();

        dl_bool Open(DLFile& file, bool isAsync = false);

        virtual void SetLastError(IO_ERROR_CODE error);
        virtual IO_ERROR_CODE GetLastError() const;
        virtual dl_int32 Read(void* buf, dl_size size);
        virtual dl_bool IsAvailable(void);
        virtual dl_size GetReadSize(void);
        virtual dl_size Skip(dl_size length);
        virtual void Close(void);
        virtual dl_bool IsOpen(void) const;
        virtual dl_size GetAsyncBlockSize(void) const;
        virtual dl_size GetAsyncBufferAlignmentSize(void) const;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total = 0);
        virtual dl_bool StartAsyncRead(dl_int8* buffer, dl_size len);
        virtual dl_bool SeekPosition(dl_pointer_int pos, DLSeekDirection direction = SD_CURRENT);
        virtual dl_pointer_int GetPosition(void);
        virtual dl_bool IsEOS(void);
    };
}