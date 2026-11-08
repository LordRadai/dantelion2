#include "DLSeekableOutputStream.h"
#include "Call.h"

namespace DLIO
{
    void DLSeekableOutputStream::WriteAlignedPadding(dl_size alignment, dl_uint8 fill)
    {
        CALL(WriteAlignedPadding_t, 0x896820, this, alignment, fill);
    }
}