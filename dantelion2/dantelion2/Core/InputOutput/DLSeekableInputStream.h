#pragma once
#include "DLInputStream.h"

namespace DLIO
{
    class DLSeekableInputStream : public DLInputStream
    {
    public:
        virtual ~DLSeekableInputStream() {}
        virtual dl_bool SeekPosition(dl_int64 pos, DLSeekDirection direction = SD_CURRENT) = 0;
        virtual dl_int64 GetPosition(void) = 0;
        virtual dl_bool IsEOS(void) const = 0;

        typedef dl_bool(_fastcall* SeekPosition_t)(DLSeekableInputStream*, dl_pointer_int, DLSeekDirection);
        typedef dl_pointer_int(_fastcall* GetPosition_t)(DLSeekableInputStream*);
        typedef dl_bool(_fastcall* IsEOS_t)(DLSeekableInputStream*);
    };
}