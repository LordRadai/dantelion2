#pragma once
#include "DLOutputStream.h"

namespace DLIO
{
    class DLSeekableOutputStream : public DLOutputStream
    {
    public:
        virtual ~DLSeekableOutputStream() {}
        virtual dl_bool SeekPosition(dl_pointer_int pos, DLSeekDirection direction = SD_CURRENT) = 0;
        virtual dl_pointer_int GetPosition(void) = 0;
        virtual void SetEOFOnClose(dl_bool setEOFOnClose) = 0;
        virtual void WriteAlignedPadding(dl_size alignment, dl_uint8 fill);

        typedef dl_bool(_fastcall* SeekPosition_t)(DLSeekableOutputStream*, dl_pointer_int, DLSeekDirection);
        typedef dl_pointer_int(_fastcall* GetPosition_t)(DLSeekableOutputStream*);
        typedef void(_fastcall* SetEOFOnClose_t)(DLSeekableOutputStream*, dl_bool);
        typedef void(_fastcall* WriteAlignedPadding_t)(DLSeekableOutputStream*, dl_size, dl_uint8);
    };
}