#include "DLCharacterInputStreamReader.h"
#include "Call.h"

namespace
{
    typedef void* (_fastcall* DLCharacterInputStreamReaderCtor_t)(DLIO::DLCharacterInputStreamReader*, DLIO::DLInputStream&, const DLTX::DLCharacterSet*);
    typedef void* (_fastcall* DLCharacterInputStreamReaderCopyCtor_t)(DLIO::DLCharacterInputStreamReader*, const DLIO::DLInputStreamReader&, const DLTX::DLCharacterSet*);
    typedef void(_fastcall* DLCharacterInputStreamReaderDtor_t)(DLIO::DLCharacterInputStreamReader*);
}

namespace DLIO
{
    DLCharacterInputStreamReader::DLCharacterInputStreamReader(DLInputStream& in, DLTX::DLCharacterSet charset) : DLInputStreamReader(in)
    {
        CALL(DLCharacterInputStreamReaderCtor_t, 0xEFD4B0, this, in, &charset);
    }

    DLCharacterInputStreamReader::DLCharacterInputStreamReader(const DLInputStreamReader& in, DLTX::DLCharacterSet charset) : DLInputStreamReader(in)
    {
        CALL(DLCharacterInputStreamReaderCopyCtor_t, 0xEFD4F0, this, in, &charset);
    }

    DLCharacterInputStreamReader::~DLCharacterInputStreamReader()
    {
        CALL(DLCharacterInputStreamReaderDtor_t, 0xEFD530, this);
    }

    dl_int32 DLCharacterInputStreamReader::Read(void* buf, dl_size size) { return CALL(ReadBuffer_t, 0xEFD550, this, buf, size); }
    dl_int32 DLCharacterInputStreamReader::Read(dl_wchar* buf, dl_size count, dl_wchar delim, dl_bool terminate) { return CALL(ReadWStringDelim_t, 0xEFD700, this, buf, count, delim, terminate); }
    dl_int32 DLCharacterInputStreamReader::Read(dl_wchar* buf, dl_size count, const dl_wchar* pDelim, dl_bool terminate) { return CALL(ReadWStringDelimList_t, 0xEFD730, this, buf, count, pDelim, terminate); }
    dl_wchar DLCharacterInputStreamReader::ReadWChar(void) { return CALL(ReadWChar_t, 0xEFD790, this); }
}