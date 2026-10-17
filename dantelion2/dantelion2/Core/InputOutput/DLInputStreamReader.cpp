#include "DLInputStreamReader.h"
#include "Core/Text/DLStringUtil.h"

namespace DLIO 
{
    inline DLInputStreamReader::DLInputStreamReader(DLInputStream& in)
        : m_in(in), m_isEos(false) {}

    inline DLInputStreamReader::DLInputStreamReader(const DLInputStreamReader& in)
        : m_in(in.m_in), m_isEos(false) {}

    inline DLInputStreamReader::~DLInputStreamReader() {}

    inline dl_int32 DLInputStreamReader::Read(void* buf, dl_size size) {
        return m_in.Read(buf, size);
    }

    namespace detail 
    {
        template < typename _Elem >
        struct EvalByDelimList 
        {
            const _Elem* m_pDelim;
            EvalByDelimList(const _Elem* pDelim) : m_pDelim(pDelim) {}
            dl_bool operator() (_Elem c) {
                return DLTX::DLStringUtil<_Elem>::FindFirstOf(m_pDelim, c) != 0;
            }
        };

        template < typename _Elem >
        struct EvalByDelim 
        {
            const _Elem m_delim;
            EvalByDelim(_Elem c) : m_delim(c) {}
            dl_bool operator() (_Elem c) {
                return m_delim == c;
            }
        };
    };

    inline dl_int32 DLInputStreamReader::Read(dl_wchar* buf, dl_size count, const dl_wchar* pDelim, dl_bool terminate) {
        if (DLTX::DLStringUtil<dl_wchar>::GetLength(pDelim) == 1)
            return Read(buf, count, *pDelim, terminate);
        return _Read(buf, count, terminate, detail::EvalByDelimList<dl_wchar>(pDelim), &DLInputStreamReader::ReadWChar);
    }

    inline dl_int32 DLInputStreamReader::Read(dl_wchar* buf, dl_size count, dl_wchar delim, dl_bool terminate) {
        return _Read(buf, count, terminate, detail::EvalByDelim<dl_wchar>(delim), &DLInputStreamReader::ReadWChar);
    }

    inline dl_int32 DLInputStreamReader::Read(dl_char* buf, dl_size count, const dl_char* pDelim, dl_bool terminate) {
        if (DLTX::DLStringUtil<dl_char>::GetLength(pDelim) == 1)
            return Read(buf, count, *pDelim, terminate);
        return _Read(buf, count, terminate, detail::EvalByDelimList<dl_char>(pDelim), &DLInputStreamReader::ReadChar);
    }

    inline dl_int32 DLInputStreamReader::Read(dl_char* buf, dl_size count, dl_char delim, dl_bool terminate) {
        return _Read(buf, count, terminate, detail::EvalByDelim<dl_char>(delim), &DLInputStreamReader::ReadChar);
    }

    inline dl_int8 DLInputStreamReader::ReadSInt8(void) {
        dl_int8 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_int16 DLInputStreamReader::ReadSInt16(void) {
        dl_int16 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_int32 DLInputStreamReader::ReadSInt32(void) {
        dl_int32 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_int64 DLInputStreamReader::ReadSInt64(void) {
        dl_int64 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_uint8 DLInputStreamReader::ReadUInt8(void) {
        dl_uint8 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_uint16 DLInputStreamReader::ReadUInt16(void) {
        dl_uint16 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_uint32 DLInputStreamReader::ReadUInt32(void) {
        dl_uint32 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_uint64 DLInputStreamReader::ReadUInt64(void) {
        dl_uint64 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_float32 DLInputStreamReader::ReadFloat32(void) {
        dl_float32 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_float64 DLInputStreamReader::ReadFloat64(void) {
        dl_float64 value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_char DLInputStreamReader::ReadChar(void) {
        dl_char value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_wchar DLInputStreamReader::ReadWChar(void) {
        dl_wchar value = 0;
        m_isEos = Read(&value, sizeof(value)) < 0;
        return value;
    }

    inline dl_bool DLInputStreamReader::IsAvailable(void) {
        return !IsEOS() && m_in.IsAvailable();
    }

    inline dl_size DLInputStreamReader::GetReadSize(void) {
        return m_in.GetReadSize();
    }

    inline dl_size DLInputStreamReader::Skip(dl_size length) {
        return m_in.Skip(length);
    }

    inline dl_bool DLInputStreamReader::IsOpen(void) const {
        return m_in.IsOpen();
    }

    inline dl_bool DLInputStreamReader::IsEOS(void) const {
        return m_isEos;
    }

    inline void DLInputStreamReader::Close(void) {
        m_in.Close();
    }
}