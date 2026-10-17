#include "DLWriter.h"
#include "Core/Text/DLStringUtil.h"
#include "Core/Math/DLMathCommon.h"

namespace DLIO
{
    inline dl_size DLWriter::Write(const dl_wchar* string) {
        dl_size count = DLTX::DLStringUtil<dl_wchar>::GetLength(string);
        return Write(string, count);
    }

    inline dl_size DLWriter::Write(const dl_char* string) {
        dl_size count = DLTX::DLStringUtil<dl_char>::GetLength(string);
        return Write(string, count);
    }

    inline dl_size DLWriter::Write(const dl_wchar* string, dl_size count) {
        return Write(static_cast<const void*>(string), count * sizeof(dl_wchar));
    }

    inline dl_size DLWriter::Write(const dl_char* string, dl_size count) {
        return Write(static_cast<const void*>(string), count * sizeof(dl_char));
    }

    inline dl_size DLWriter::Write(dl_uint8 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_uint16 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_uint32 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_uint64 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_int8 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_int16 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_int32 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_int64 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_float32 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_float64 value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_char value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Write(dl_wchar value) {
        return Write((const void*)&value, sizeof(value));
    }

    inline dl_size DLWriter::Skip(dl_size size) {
        dl_int i = (dl_int)size;
        const dl_int kBUFSIZE = 1024;
        char buf[kBUFSIZE];
        while (i > 0) {
            Write(buf, DLMT::DLMin(i, kBUFSIZE));
            i -= kBUFSIZE;
        }
        return size;
    }
}