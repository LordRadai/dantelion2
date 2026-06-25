#pragma once
#include <string>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Platform/Platform.h"
#include "Core/Util/DLTypeManipulation.h"
#include "Core/Kernel/DLStdAllocator.inl"
#include "DLCharacterSet.h"

namespace DLTX
{
#if defined(_MSC_VER) && (_MSC_VER <= 1800)
    template<class _Elem, typename _Traits = ::std::char_traits<_Elem>, class AllocHost = DLKR::DLAllocator>
    class DLBasicString : public ::std::basic_string<_Elem, _Traits, DLKR::DLStdAllocator<_Elem, AllocHost>>
    {
    public:
        typedef typename DLUT::DLSelect<DLUT::DLTypeEqual<dl_wchar, _Elem>::Result, dl_char, dl_wchar>::Result
            TranslatingType;

        template <typename OtherElemType>
        struct Rebind {
            typedef DLBasicString<OtherElemType, ::std::char_traits<OtherElemType>, AllocHost> other;
        };

        typedef DLBasicString<_Elem, _Traits, AllocHost> ThisClass;
        typedef DLKR::DLStdAllocator<_Elem, AllocHost> Allocator;
        typedef ::std::basic_string<_Elem, ::std::char_traits<_Elem>, Allocator> SuperClass;
        typedef ::std::char_traits<_Elem> CharTraits;

        typedef DLBasicString<dl_wchar, ::std::char_traits<dl_wchar>, AllocHost >
            WideStringType;
        typedef DLBasicString<dl_char, ::std::char_traits<dl_char>, AllocHost >
            AsciiStringType;

        typedef typename DLUT::DLSelect<DLUT::DLTypeEqual<dl_wchar, _Elem>::Result, AsciiStringType, WideStringType>::Result
            OtherStringType;

        typedef _Elem ElementType;

        typedef typename SuperClass::size_type size_type;
        typedef typename SuperClass::const_pointer const_pointer;
        typedef typename SuperClass::value_type value_type;
        typedef typename SuperClass::difference_type difference_type;
        typedef typename SuperClass::pointer pointer;
        typedef typename SuperClass::iterator iterator;
        typedef typename SuperClass::const_iterator const_iterator;

        enum {
            CharacterSet =
            DLUT::DLSelectValue<DLUT::DLTypeEqual<dl_wchar, _Elem>::Result, CS_UNICODE, CS_PLATFORM>::Result,
            TranslatingCharSet = OtherStringType::CharacterSet,
        };

    private:
        dl_uint8 m_charset = CS_PLATFORM;

    public:
        DLBasicString(AllocHost* pAllocator = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) : SuperClass(Allocator(pAllocator))
        {}

        DLBasicString(const DLBasicString& other) : SuperClass(other)
        {
            this->m_charset = other.m_charset;
        }

        DLBasicString(const _Elem* str, AllocHost* pAllocator = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost(), dl_int32 charset = CS_PLATFORM) : SuperClass(str, Allocator(pAllocator))
        {
            this->m_charset = charset;
        }

        void format_append(const _Elem* format, ...)
        {
            va_list args;

            size_type buffer_size = 64;

            while (true)
            {
                buffer_size *= 2;
                _Elem* buffer = new _Elem[buffer_size];

                va_start(args, format);
                int result = vsnprintf(buffer, buffer_size, format, args);
                va_end(args);

                if (result < 0 || static_cast<size_type>(result) >= buffer_size)
                {
                    delete[] buffer;
                    continue;
                }

                this->append(buffer, result);
                delete[] buffer;
                break;
            }
        }

        DLBasicString& operator=(const DLBasicString& other)
        {
            if (this != &other)
            {
                SuperClass::assign(other);
                m_charset = other.m_charset;
            }
            return *this;
        }
    };
#else
    template<class _Elem, typename _Traits = ::std::char_traits<_Elem>>
    class DLBasicString : public ::std::basic_string<_Elem, _Traits>
    {
    public:
        typedef typename DLUT::DLSelect<DLUT::DLTypeEqual<dl_wchar, _Elem>::Result, dl_char, dl_wchar>::Result
            TranslatingType;

        template <typename OtherElemType>
        struct Rebind {
            typedef DLBasicString<OtherElemType, ::std::char_traits<OtherElemType>> other;
        };

        typedef DLBasicString<_Elem, _Traits> ThisClass;
        typedef DLKR::DLStdAllocator<_Elem, DLKR::DLAllocator> Allocator;
        typedef ::std::basic_string<_Elem, _Traits> SuperClass;
        typedef ::std::char_traits<_Elem> CharTraits;

        typedef DLBasicString<dl_wchar, ::std::char_traits<dl_wchar>> WideStringType;
        typedef DLBasicString<dl_char, ::std::char_traits<dl_char>> AsciiStringType;

        typedef typename DLUT::DLSelect<DLUT::DLTypeEqual<dl_wchar, _Elem>::Result, AsciiStringType, WideStringType>::Result
            OtherStringType;

        typedef _Elem ElementType;

        typedef typename SuperClass::size_type size_type;
        typedef typename SuperClass::const_pointer const_pointer;
        typedef typename SuperClass::value_type value_type;
        typedef typename SuperClass::difference_type difference_type;
        typedef typename SuperClass::pointer pointer;
        typedef typename SuperClass::iterator iterator;
        typedef typename SuperClass::const_iterator const_iterator;

        enum {
            CharacterSet =
            DLUT::DLSelectValue<DLUT::DLTypeEqual<dl_wchar, _Elem>::Result, CS_UNICODE, CS_PLATFORM>::Result,
            TranslatingCharSet = OtherStringType::CharacterSet,
        };

    private:
        DLKR::DLAllocator* m_Allocator;
        dl_uint8 m_charset;

    public:
        DLBasicString(DLKR::DLAllocator* pAllocator = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost())
            : SuperClass(), m_Allocator(pAllocator), m_charset(CS_PLATFORM)
        {}

        DLBasicString(const DLBasicString& other)
            : SuperClass(other), m_Allocator(other.m_Allocator), m_charset(other.m_charset)
        {}

        DLBasicString(const _Elem* str, DLKR::DLAllocator* pAllocator = DLKRD::DLAllocationHelper<DLKR::DLAllocator>::GetDefaultHost(), dl_int32 charset = CS_PLATFORM)
            : SuperClass(str), m_Allocator(pAllocator), m_charset(charset)
        {}

        void format_append(const _Elem* format, ...)
        {
            va_list args;

            size_type buffer_size = 64;

            while (true)
            {
                buffer_size *= 2;
                _Elem* buffer = new _Elem[buffer_size];

                va_start(args, format);
                int result = vsnprintf(buffer, buffer_size, format, args);
                va_end(args);

                if (result < 0 || static_cast<size_type>(result) >= buffer_size)
                {
                    delete[] buffer;
                    continue;
                }

                this->append(buffer, result);
                delete[] buffer;
                break;
            }
        }

        DLBasicString& operator=(const DLBasicString& other)
        {
            if (this != &other)
            {
                SuperClass::assign(other);
                m_Allocator = other.m_Allocator;
                m_charset = other.m_charset;
            }
            return *this;
        }
    };
#endif

    typedef DLBasicString<dl_wchar> DLString;
    typedef DLBasicString<dl_char> DLAsciiString;
}