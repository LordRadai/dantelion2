#pragma once
#include <string>
#include "Core/Kernel/DLAllocator.h"
#include "Core/Platform/Platform.h"
#include "Core/Util/DLTypeManipulation.h"
#include "Core/Kernel/DLStdAllocator.inl"
#include "DLCharSet.h"

namespace DLTX
{
    template<class _Elem, typename _Traits = ::std::char_traits<_Elem>, class AllocHost = DLKR::DLAllocator>
    class DLBasicString : public ::std::basic_string<_Elem, _Traits> 
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
        typedef ::std::basic_string<_Elem, ::std::char_traits<_Elem>> SuperClass;
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
		DLKR::DLAllocator* m_pAllocator;
        dl_uint8 m_charset = CS_PLATFORM;

    public:
        DLBasicString() : SuperClass(), m_pAllocator(DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost()) {}

		DLBasicString(const DLBasicString& other) : SuperClass(other), m_pAllocator(other.m_pAllocator)
		{
			this->m_charset = other.m_charset;
		}

		DLBasicString(const _Elem* str, AllocHost* pAllocator = DLKRD::DLAllocationHelper<AllocHost>::GetDefaultHost(), dl_int32 charset = CS_PLATFORM) : SuperClass(str), m_pAllocator(pAllocator)
        {
			this->m_charset = charset;
        }

		DLBasicString& operator=(const DLBasicString& other)
		{
			if (this != &other)
			{
				std::basic_string<_Elem, _Traits>::operator=(other);
				m_charset = other.m_charset;
			}
			return *this;
		}
    };

    typedef DLBasicString<dl_wchar> DLString;
    typedef DLBasicString<dl_char> DLAsciiString;
}