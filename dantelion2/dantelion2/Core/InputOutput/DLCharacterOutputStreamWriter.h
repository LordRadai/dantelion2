#pragma once
#include "DLOutputStreamWriter.h"
#include "Core/Text/DLCharacterSet.h"

namespace DLIO
{
    class DLCharacterOutputStreamWriter : public DLOutputStreamWriter
    {
        DLTX::DLCharacterSet m_cs;

    public:
        using DLWriter::Write;

        DLCharacterOutputStreamWriter(DLOutputStream& os, DLTX::DLCharacterSet charset);
        DLCharacterOutputStreamWriter(const DLOutputStreamWriter& w, DLTX::DLCharacterSet charset);
        virtual ~DLCharacterOutputStreamWriter();

        virtual dl_size Write(const void* buf, dl_size size);

        void SetCharacterSet(DLTX::DLCharacterSet cs) { m_cs = cs; }
        DLTX::DLCharacterSet GetCharacterSet(void) const { return m_cs; }
    };
}