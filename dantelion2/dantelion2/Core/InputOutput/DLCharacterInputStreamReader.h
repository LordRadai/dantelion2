#pragma once
#include "DLInputStreamReader.h"
#include "Core/Text/DLCharacterSet.h"

namespace DLIO
{
    class DLCharacterInputStreamReader : public DLInputStreamReader
    {
    protected:
        dl_uint8 m_pad11[7];
        DLTX::DLCharacterSet m_cs;

    public:
        DLCharacterInputStreamReader(DLInputStream& in, DLTX::DLCharacterSet charset);
        DLCharacterInputStreamReader(const DLInputStreamReader& in, DLTX::DLCharacterSet charset);
        virtual ~DLCharacterInputStreamReader();

        virtual dl_int32 Read(void* buf, dl_size size);
        virtual dl_int32 Read(dl_wchar* buf, dl_size count, const dl_wchar* pDelim, dl_bool terminate = true);
        virtual dl_int32 Read(dl_wchar* buf, dl_size count, dl_wchar delim, dl_bool terminate = true);
        virtual dl_wchar ReadWChar(void);

        void SetCharacterSet(DLTX::DLCharacterSet cs) { m_cs = cs; }
        DLTX::DLCharacterSet GetCharacterSet(void) const { return m_cs; }
    };
}