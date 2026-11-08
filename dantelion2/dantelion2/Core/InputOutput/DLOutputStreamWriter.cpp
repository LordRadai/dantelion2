#include "DLOutputStreamWriter.h"
#include "Call.h"

namespace
{
    typedef void* (_fastcall* DLOutputStreamWriterCtor_t)(DLIO::DLOutputStreamWriter*, DLIO::DLOutputStream&);
    typedef void* (_fastcall* DLOutputStreamWriterCopyCtor_t)(DLIO::DLOutputStreamWriter*, const DLIO::DLOutputStreamWriter&);
    typedef void(_fastcall* DLOutputStreamWriterDtor_t)(DLIO::DLOutputStreamWriter*);
}

namespace DLIO
{
    DLOutputStreamWriter::DLOutputStreamWriter(DLOutputStream& os) : m_os(os)
    {
        CALL(DLOutputStreamWriterCtor_t, 0x888920, this, os);
    }

    DLOutputStreamWriter::DLOutputStreamWriter(const DLOutputStreamWriter& w) : m_os(w.m_os)
    {
        CALL(DLOutputStreamWriterCopyCtor_t, 0x888940, this, w);
    }

    DLOutputStreamWriter::~DLOutputStreamWriter()
    {
        CALL(DLOutputStreamWriterDtor_t, 0x888960, this);
    }

    dl_size DLOutputStreamWriter::Write(const void* buf, dl_size size) { return CALL(WriteBuffer_t, 0x888980, this, buf, size); }
    dl_size DLOutputStreamWriter::Skip(dl_size size) { return CALL(Skip_t, 0x8889A0, this, size); }
    void DLOutputStreamWriter::Flush(void) { CALL(Flush_t, 0x888A20, this); }
    void DLOutputStreamWriter::Close(void) { CALL(Close_t, 0x888A60, this); }
    dl_bool DLOutputStreamWriter::IsOpen(void) const { return CALL(IsOpen_t, 0x888A40, this); }
}