#include "DLInputStreamReader.h"
#include "Call.h"

namespace
{
    typedef void* (_fastcall* DLInputStreamReaderCtor_t)(DLIO::DLInputStreamReader*, DLIO::DLInputStream&);
    typedef void* (_fastcall* DLInputStreamReaderCopyCtor_t)(DLIO::DLInputStreamReader*, const DLIO::DLInputStreamReader&);
    typedef void(_fastcall* DLInputStreamReaderDtor_t)(DLIO::DLInputStreamReader*);
}

namespace DLIO
{
    DLInputStreamReader::DLInputStreamReader(DLInputStream& in) : m_in(in)
    {
        CALL(DLInputStreamReaderCtor_t, 0x874950, this, in);
    }

    DLInputStreamReader::DLInputStreamReader(const DLInputStreamReader& in) : m_in(in.m_in)
    {
        CALL(DLInputStreamReaderCopyCtor_t, 0x874970, this, in);
    }

    DLInputStreamReader::~DLInputStreamReader()
    {
        CALL(DLInputStreamReaderDtor_t, 0x874990, this);
    }

    dl_int32 DLInputStreamReader::Read(void* buf, dl_size size) { return CALL(ReadBuffer_t, 0x8749B0, this, buf, size); }
    dl_int32 DLInputStreamReader::Read(dl_wchar* buf, dl_size count, dl_wchar delim, dl_bool terminate) { return CALL(ReadWStringDelim_t, 0x8749D0, this, buf, count, delim, terminate); }
    dl_int32 DLInputStreamReader::Read(dl_wchar* buf, dl_size count, const dl_wchar* pDelim, dl_bool terminate) { return CALL(ReadWStringDelimList_t, 0x874A00, this, buf, count, pDelim, terminate); }
    dl_int32 DLInputStreamReader::Read(dl_char* buf, dl_size count, dl_char delim, dl_bool terminate) { return CALL(ReadStringDelim_t, 0x874A60, this, buf, count, delim, terminate); }
    dl_int32 DLInputStreamReader::Read(dl_char* buf, dl_size count, const dl_char* pDelim, dl_bool terminate) { return CALL(ReadStringDelimList_t, 0x874B00, this, buf, count, pDelim, terminate); }
    dl_int8 DLInputStreamReader::ReadSInt8(void) { return CALL(ReadSInt8_t, 0x874B60, this); }
    dl_int16 DLInputStreamReader::ReadSInt16(void) { return CALL(ReadSInt16_t, 0x874BA0, this); }
    dl_int32 DLInputStreamReader::ReadSInt32(void) { return CALL(ReadSInt32_t, 0x874BE0, this); }
    dl_int64 DLInputStreamReader::ReadSInt64(void) { return CALL(ReadSInt64_t, 0x874C20, this); }
    dl_uint8 DLInputStreamReader::ReadUInt8(void) { return CALL(ReadUInt8_t, 0x874C60, this); }
    dl_uint16 DLInputStreamReader::ReadUInt16(void) { return CALL(ReadUInt16_t, 0x874CA0, this); }
    dl_uint32 DLInputStreamReader::ReadUInt32(void) { return CALL(ReadUInt32_t, 0x874CE0, this); }
    dl_uint64 DLInputStreamReader::ReadUInt64(void) { return CALL(ReadUInt64_t, 0x874D20, this); }
    dl_float32 DLInputStreamReader::ReadFloat32(void) { return CALL(ReadFloat32_t, 0x874DE0, this); }
    dl_float64 DLInputStreamReader::ReadFloat64(void) { return CALL(ReadFloat64_t, 0x874E20, this); }
    dl_char DLInputStreamReader::ReadChar(void) { return CALL(ReadChar_t, 0x874D60, this); }
    dl_wchar DLInputStreamReader::ReadWChar(void) { return CALL(ReadWChar_t, 0x874DA0, this); }
    dl_bool DLInputStreamReader::IsAvailable(void) { return CALL(IsAvailable_t, 0x874E60, this); }
    dl_size DLInputStreamReader::GetReadSize(void) { return CALL(GetReadSize_t, 0x874E90, this); }
    dl_size DLInputStreamReader::Skip(dl_size length) { return CALL(Skip_t, 0x874EB0, this, length); }
    void DLInputStreamReader::Close(void) { CALL(Close_t, 0x874EF0, this); }
    dl_bool DLInputStreamReader::IsOpen(void) const { return CALL(IsOpen_t, 0x874ED0, this); }
}