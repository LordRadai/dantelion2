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

        template <typename _Elem, typename _DelimTypeFn, typename _ReadFn>
        dl_int32 _Read(_Elem* buf, dl_size size, dl_bool terminate, _DelimTypeFn df, _ReadFn rf)
        {
            if (m_isEos)
                return -1;

            dl_int32 copiedSize = 0;

            for (; copiedSize <= (dl_int32)size; copiedSize++, buf++)
            {
                _Elem c = (this->*rf)();
                if (!IsAvailable()) break;
                if (df(c)) break;
                *buf = c;
            }

            if (terminate) *buf = 0;
            return copiedSize;
        }

    public:
        DLInputStreamReader(DLInputStream& in);
        DLInputStreamReader(const DLInputStreamReader& in);

        virtual ~DLInputStreamReader();

        virtual dl_int32 Read(void* buf, dl_size size);
        virtual dl_int32 Read(dl_wchar* buf, dl_size size, dl_wchar delim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_wchar* buf, dl_size size, const dl_wchar* pDelim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_char* buf, dl_size size, dl_char delim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_char* buf, dl_size size, const dl_char* pDelim, dl_bool terminate = true);

        virtual dl_int8 ReadSInt8(void);
        virtual dl_int16 ReadSInt16(void);
        virtual dl_int32 ReadSInt32(void);
        virtual dl_int64 ReadSInt64(void);
        virtual dl_uint8 ReadUInt8(void);
        virtual dl_uint16 ReadUInt16(void);
        virtual dl_uint32 ReadUInt32(void);
        virtual dl_uint64 ReadUInt64(void);
        virtual dl_char ReadChar(void);
        virtual dl_wchar ReadWChar(void);
        virtual dl_float32 ReadFloat32(void);
        virtual dl_float64 ReadFloat64(void);
        virtual dl_bool IsAvailable(void);
        virtual dl_size GetReadSize(void);
        virtual dl_size Skip(dl_size length);
        virtual dl_bool IsOpen(void) const;
        virtual void Close(void);

        dl_bool IsEOS(void) const;
    };
}