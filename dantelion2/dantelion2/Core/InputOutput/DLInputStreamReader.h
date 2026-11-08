#pragma once
#include "DLReader.h"
#include "DLInputStream.h"

namespace DLIO
{
    class DLInputStreamReader : public DLReader
    {
    protected:
        DLInputStream& m_in;
        dl_bool m_isEos;

    public:
        DLInputStreamReader(DLInputStream& in);
        DLInputStreamReader(const DLInputStreamReader& in);
        virtual ~DLInputStreamReader();

        virtual dl_int32 Read(void* buf, dl_size size);
        virtual dl_int32 Read(dl_wchar* buf, dl_size count, const dl_wchar* pDelim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_wchar* buf, dl_size count, dl_wchar delim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_char* buf, dl_size count, const dl_char* pDelim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_char* buf, dl_size count, dl_char delim, dl_bool terminate = true);
        virtual dl_int8 ReadSInt8(void);
        virtual dl_int16 ReadSInt16(void);
        virtual dl_int32 ReadSInt32(void);
        virtual dl_int64 ReadSInt64(void);
        virtual dl_uint8 ReadUInt8(void);
        virtual dl_uint16 ReadUInt16(void);
        virtual dl_uint32 ReadUInt32(void);
        virtual dl_uint64 ReadUInt64(void);
        virtual dl_float32 ReadFloat32(void);
        virtual dl_float64 ReadFloat64(void);
        virtual dl_char ReadChar(void);
        virtual dl_wchar ReadWChar(void);
        virtual dl_bool IsAvailable(void);
        virtual dl_size GetReadSize(void);
        virtual dl_size Skip(dl_size length);
        virtual void Close(void);
        virtual dl_bool IsOpen(void) const;

        dl_bool IsEOS(void) const { return m_isEos; }
    };
}