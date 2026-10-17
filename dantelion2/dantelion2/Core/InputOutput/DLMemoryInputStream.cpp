#include "DLMemoryInputStream.h"
#include "Core/Assert/DLAssert.h"
#include <cstring>

namespace DLIO
{
    DLMemoryInputStream::DLMemoryInputStream() :
        m_szBuf(0),
        m_buf(nullptr),
        m_caret(0),
        m_asyncTotal(0),
        m_isOpen(false),
        m_lastError(IO_ERROR_NONE)
    {}

    DLMemoryInputStream::DLMemoryInputStream(const void* buf, dl_size szBuffer) :
        m_szBuf(szBuffer),
        m_buf(static_cast<const dl_uint8*>(buf)),
        m_caret(0),
        m_asyncTotal(0),
        m_isOpen(true),
        m_lastError(IO_ERROR_NONE)
    {}

    DLMemoryInputStream::~DLMemoryInputStream()
    {}

    dl_bool DLMemoryInputStream::Open(const void* buf, dl_size szBuffer)
    {
        if (m_isOpen)
            return false;

        m_szBuf = szBuffer;
        m_isOpen = true;
        m_buf = static_cast<const dl_uint8*>(buf);
        m_caret = 0;
        return true;
    }

    void DLMemoryInputStream::SetLastError(IO_ERROR_CODE code)
    {
        m_lastError = code;
    }

    IO_ERROR_CODE DLMemoryInputStream::GetLastError(void) const
    {
        return m_lastError;
    }

    dl_int32 DLMemoryInputStream::Read(void* buf, dl_size size)
    {
        if (!m_isOpen)
            return -1;

        if (size == 0)
            return 0;

        if (m_szBuf <= m_caret)
            return -1;

        dl_size remaining = m_szBuf - m_caret;
        dl_size readSize = (size < remaining) ? size : remaining;

        std::memcpy(buf, m_buf + m_caret, readSize);
        m_caret += readSize;
        return static_cast<dl_int32>(readSize);
    }

    dl_bool DLMemoryInputStream::IsAvailable(void)
    {
        return m_isOpen && m_szBuf != m_caret;
    }

    dl_size DLMemoryInputStream::GetReadSize(void)
    {
        return m_isOpen ? m_szBuf - m_caret : 0;
    }

    dl_size DLMemoryInputStream::Skip(dl_uint64 length)
    {
        if (!m_isOpen)
            return 0;

        DL_ASSERT(length <= 0x7FFFFFFF, "length is too large");

        dl_size remaining = m_szBuf - m_caret;
        dl_size skipSize = (static_cast<dl_size>(length) < remaining) ? static_cast<dl_size>(length) : remaining;

        m_caret += skipSize;
        return skipSize;
    }

    void DLMemoryInputStream::Close(void)
    {
        m_asyncTotal = 0;
        m_isOpen = false;
    }

    dl_bool DLMemoryInputStream::IsOpen(void) const
    {
        return m_isOpen;
    }

    dl_size DLMemoryInputStream::GetAsyncBlockSize(void) const
    {
        return 1;
    }

    dl_size DLMemoryInputStream::GetAsyncBufferAlignmentSize(void) const
    {
        return 1;
    }

    dl_bool DLMemoryInputStream::QueryAsyncStatus(dl_size* remain, dl_size* total)
    {
        DL_ASSERT(remain != nullptr, "remain is null");

        if (m_asyncTotal <= 0)
            return false;

        *remain = 0;
        if (total)
            *total = static_cast<dl_size>(m_asyncTotal);

        return true;
    }

    dl_bool DLMemoryInputStream::StartAsyncRead(dl_int8* buffer, dl_size len)
    {
        DL_ASSERT(buffer != nullptr, "buffer is null");

        m_asyncTotal = Read(buffer, len);
        if (m_asyncTotal < 0)
            m_asyncTotal = 0;

        return m_asyncTotal == static_cast<dl_int32>(len);
    }

    dl_bool DLMemoryInputStream::SeekPosition(dl_int64 pos, DLSeekDirection direction)
    {
        switch (direction)
        {
        case SD_CURRENT:
            pos += m_caret;
            // fall through
        case SD_HEAD:
            if (pos < 0)
                pos = 0;
            m_caret = static_cast<dl_size>((pos > static_cast<dl_int64>(m_szBuf)) ? m_szBuf : pos);
            return true;

        case SD_TAIL:
        {
            if (pos > 0)
                pos = 0;
            dl_int64 newPos = static_cast<dl_int64>(m_szBuf) + pos;
            m_caret = static_cast<dl_size>((newPos < 0) ? 0 : newPos);
            return true;
        }

        default:
            return false;
        }
    }

    dl_int64 DLMemoryInputStream::GetPosition(void)
    {
        return m_caret;
    }

    dl_bool DLMemoryInputStream::IsEOS(void) const
    {
        return !m_isOpen || m_caret < m_szBuf;
    }
}