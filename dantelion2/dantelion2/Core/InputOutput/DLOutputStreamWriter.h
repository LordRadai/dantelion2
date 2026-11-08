#pragma once
#include "DLWriter.h"
#include "DLOutputStream.h"

namespace DLIO
{
    class DLOutputStreamWriter : public DLWriter
    {
    protected:
        DLOutputStream& m_os;

    public:
        using DLWriter::Write;

        DLOutputStreamWriter(DLOutputStream& os);
        DLOutputStreamWriter(const DLOutputStreamWriter& w);
        virtual ~DLOutputStreamWriter();

        virtual dl_size Write(const void* buf, dl_size size);
        virtual dl_size Skip(dl_size size);
        virtual void Flush(void);
        virtual void Close(void);
        virtual dl_bool IsOpen(void) const;
    };
}