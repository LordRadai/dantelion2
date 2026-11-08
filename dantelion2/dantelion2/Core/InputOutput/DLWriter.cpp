#include "DLWriter.h"
#include "Call.h"

namespace DLIO
{
    dl_size DLWriter::Write(const dl_wchar* string) { return CALL(WriteWString_t, 0x8C2740, this, string); }
    dl_size DLWriter::Write(const dl_char* string) { return CALL(WriteString_t, 0x8C2760, this, string); }
    dl_size DLWriter::Write(const dl_wchar* string, dl_size count) { return CALL(WriteWStringCount_t, 0x8C2780, this, string, count); }
    dl_size DLWriter::Write(const dl_char* string, dl_size count) { return CALL(WriteStringCount_t, 0x8C27A0, this, string, count); }
    dl_size DLWriter::Write(dl_uint8 value) { return CALL(WriteUInt8_t, 0x8C27B0, this, value); }
    dl_size DLWriter::Write(dl_uint16 value) { return CALL(WriteUInt16_t, 0x8C27E0, this, value); }
    dl_size DLWriter::Write(dl_uint32 value) { return CALL(WriteUInt32_t, 0x8C2810, this, value); }
    dl_size DLWriter::Write(dl_uint64 value) { return CALL(WriteUInt64_t, 0x8C2840, this, value); }
    dl_size DLWriter::Write(dl_int8 value) { return CALL(WriteSInt8_t, 0x8C2870, this, value); }
    dl_size DLWriter::Write(dl_int16 value) { return CALL(WriteSInt16_t, 0x8C28A0, this, value); }
    dl_size DLWriter::Write(dl_int32 value) { return CALL(WriteSInt32_t, 0x8C28D0, this, value); }
    dl_size DLWriter::Write(dl_int64 value) { return CALL(WriteSInt64_t, 0x8C2900, this, value); }
    dl_size DLWriter::Write(dl_float32 value) { return CALL(WriteFloat32_t, 0x8C2930, this, value); }
    dl_size DLWriter::Write(dl_float64 value) { return CALL(WriteFloat64_t, 0x8C2960, this, value); }
    dl_size DLWriter::Skip(dl_size size) { return CALL(Skip_t, 0x8C2990, this, size); }
    dl_size DLWriter::Write(dl_char value) { return CALL(WriteChar_t, 0x8C2A10, this, value); }
    dl_size DLWriter::Write(dl_wchar value) { return CALL(WriteWChar_t, 0x8C2A40, this, value); }
    dl_size DLWriter::Write(dl_bool value) { return CALL(WriteBool_t, 0x8C2A70, this, value); }
}