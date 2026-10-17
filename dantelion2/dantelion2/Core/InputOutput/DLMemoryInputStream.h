#pragma once
#include "DLSeekableInputStream.h"
#include "DLFile.h"

namespace DLIO
{
    class DLMemoryInputStream : public DLSeekableInputStream
    {
        dl_size m_szBuf;
        const dl_uint8* m_buf;
        dl_size m_caret;
        dl_int32 m_asyncTotal;
        dl_bool m_isOpen;
        IO_ERROR_CODE m_lastError;

    public:
        DLMemoryInputStream();
        DLMemoryInputStream(const void* buf, dl_size szBuffer);
        virtual ~DLMemoryInputStream();

        dl_bool Open(const void* buf, dl_size szBuffer);

        virtual void SetLastError(IO_ERROR_CODE code);
        virtual IO_ERROR_CODE GetLastError(void) const;
        virtual dl_int32 Read(void* buf, dl_size size);
        virtual dl_bool IsAvailable(void);
        virtual dl_size GetReadSize(void);
        virtual dl_size Skip(dl_uint64 length);
        virtual void Close(void);
        virtual dl_bool IsOpen(void) const;
        virtual dl_size GetAsyncBlockSize(void) const;
        virtual dl_size GetAsyncBufferAlignmentSize(void) const;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total = 0);
        virtual dl_bool StartAsyncRead(dl_int8* buffer, dl_size len);
        virtual dl_bool SeekPosition(dl_int64 pos, DLSeekDirection direction = SD_CURRENT);
        virtual dl_int64 GetPosition(void);
        virtual dl_bool IsEOS(void) const;
    };
}