#pragma once
#include "DLInputStream.h"

namespace DLIO
{
    class DLPseudoAsyncInputStream : public DLInputStream
    {
    protected:
        dl_int32 m_asyncTotal;
    public:
        DLPseudoAsyncInputStream() : m_asyncTotal(0) {}
        virtual dl_size GetAsyncBlockSize(void) const;
        virtual dl_size GetAsyncBufferAlignmentSize(void) const;
        virtual dl_bool QueryAsyncStatus(dl_size* remain, dl_size* total = 0);
        virtual dl_bool StartAsyncRead(dl_int8* buffer, dl_size len);
    };
}