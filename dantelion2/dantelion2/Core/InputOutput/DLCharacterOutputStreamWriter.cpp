#include "DLCharacterOutputStreamWriter.h"
#include "Call.h"

namespace
{
    // The 2014 DLCharacterSet is a class type: the game takes it through a pointer (R8), not by value.
    typedef void* (_fastcall* DLCharacterOutputStreamWriterCtor_t)(DLIO::DLCharacterOutputStreamWriter*, DLIO::DLOutputStream&, const DLTX::DLCharacterSet*);
    typedef void* (_fastcall* DLCharacterOutputStreamWriterCopyCtor_t)(DLIO::DLCharacterOutputStreamWriter*, const DLIO::DLOutputStreamWriter&, const DLTX::DLCharacterSet*);
    typedef void(_fastcall* DLCharacterOutputStreamWriterDtor_t)(DLIO::DLCharacterOutputStreamWriter*);
}

namespace DLIO
{
    DLCharacterOutputStreamWriter::DLCharacterOutputStreamWriter(DLOutputStream& os, DLTX::DLCharacterSet charset) : DLOutputStreamWriter(os)
    {
        CALL(DLCharacterOutputStreamWriterCtor_t, 0xEFD9C0, this, os, &charset);
    }

    DLCharacterOutputStreamWriter::DLCharacterOutputStreamWriter(const DLOutputStreamWriter& w, DLTX::DLCharacterSet charset) : DLOutputStreamWriter(w)
    {
        CALL(DLCharacterOutputStreamWriterCopyCtor_t, 0xEFDA00, this, w, &charset);
    }

    DLCharacterOutputStreamWriter::~DLCharacterOutputStreamWriter()
    {
        CALL(DLCharacterOutputStreamWriterDtor_t, 0xEFDA40, this);
    }

    dl_size DLCharacterOutputStreamWriter::Write(const void* buf, dl_size size)
    {
        return CALL(WriteBuffer_t, 0xEFDA60, this, buf, size);
    }
}