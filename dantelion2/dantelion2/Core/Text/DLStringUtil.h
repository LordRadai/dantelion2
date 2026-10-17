#pragma once
#include "DLString.inl"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <string>

namespace DLTX
{
    namespace detail
    {
        template <typename T>
        const T* IntToString(dl_int32 value, T* buf, dl_int32 radix)
        {
            if (radix != 10 && radix != 16 && radix != 8 && radix != 2)
                return nullptr;

            const char digits[] = "0123456789abcdef";
            T tmp[33];
            dl_int len = 0;

            dl_bool negative = (radix == 10 && value < 0);
            dl_uint32 v = negative ? 0u - static_cast<dl_uint32>(value) : static_cast<dl_uint32>(value);

            do
            {
                tmp[len++] = static_cast<T>(digits[v % radix]);
                v /= radix;
            } while (v != 0);

            T* out = buf;
            if (negative)
                *out++ = static_cast<T>('-');

            while (len > 0)
                *out++ = tmp[--len];

            *out = 0;
            return buf;
        }
    }

    template <typename T>
    class DLStringUtil {};

    template <>
    class DLStringUtil<dl_char> 
    {
    public:
        static void Copy(dl_char* dst, const dl_char* src) { std::strcpy(dst, src); }
        static void Copy(dl_char* dst, const dl_char* src, dl_size size) { std::strncpy(dst, src, size); }
        static void Concatinate(dl_char* dst, const dl_char* src) { std::strcat(dst, src); }
        static void Concatinate(dl_char* dst, const dl_char* src, dl_size size) { std::strncat(dst, src, size); }
        static dl_int Compare(const dl_char* s1, const dl_char* s2) { return std::strcmp(s1, s2); }
        static dl_int Compare(const dl_char* s1, const dl_char* s2, dl_size size) { return std::strncmp(s1, s2, size); }
        static const dl_char* FindFirstOf(const dl_char* src, dl_char key) { return std::strchr(src, key); }
        static const dl_char* FindFirstOf(const dl_char* src, const dl_char* keys) { return std::strpbrk(src, keys); }
        static const dl_char* FindLastOf(const dl_char* src, dl_char key) { return std::strrchr(src, key); }
        static const dl_char* FindSubstring(const dl_char* src, const dl_char* substr) { return std::strstr(src, substr); }

        static dl_size GetLength(const dl_char* string) { return std::strlen(string); }
        static dl_size GetLengthOfConstructedBy(const dl_char* string, const dl_char* charset) { return std::strspn(string, charset); }
        static dl_size GetLengthOfNotConstructedBy(const dl_char* string, const dl_char* charset) { return std::strcspn(string, charset); }

        static dl_int32 ToInt32(const dl_char* string) { return std::atoi(string); }
        static dl_int64 ToInt64(const dl_char* string) { return _atoi64(string); }
        static dl_float32 ToFloat32(const dl_char* string) { return static_cast<dl_float32>(std::atof(string)); }
        static dl_float64 ToFloat64(const dl_char* string) { return std::atof(string); }

        static const dl_char* ToString(dl_int32 value, dl_char* buf, dl_int32 radix = 10)
        {
            return detail::IntToString(value, buf, radix);
        }

        static const dl_char* ToString(dl_float32 value, dl_char* buf, dl_int32 digits)
        {
            return ToString(static_cast<dl_float64>(value), buf, digits);
        }

        static const dl_char* ToString(dl_float64 value, dl_char* buf, dl_int32 digits)
        {
            std::sprintf(buf, "%.*f", digits, value);
            return buf;
        }
    };

    template <>
    class DLStringUtil<dl_wchar> 
    {
    public:
        static void Copy(dl_wchar* dst, const dl_wchar* src) { std::wcscpy(dst, src); }
        static void Copy(dl_wchar* dst, const dl_wchar* src, dl_size size) { std::wcsncpy(dst, src, size); }
        static void Concatinate(dl_wchar* dst, const dl_wchar* src) { std::wcscat(dst, src); }
        static void Concatinate(dl_wchar* dst, const dl_wchar* src, dl_size size) { std::wcsncat(dst, src, size); }
        static dl_int Compare(const dl_wchar* s1, const dl_wchar* s2) { return std::wcscmp(s1, s2); }
        static dl_int Compare(const dl_wchar* s1, const dl_wchar* s2, dl_size size) { return std::wcsncmp(s1, s2, size); }
        static const dl_wchar* FindFirstOf(const dl_wchar* src, dl_wchar key) { return std::wcschr(src, key); }
        static const dl_wchar* FindFirstOf(const dl_wchar* src, const dl_wchar* keys) { return std::wcspbrk(src, keys); }
        static const dl_wchar* FindLastOf(const dl_wchar* src, dl_wchar key) { return std::wcsrchr(src, key); }
        static const dl_wchar* FindSubstring(const dl_wchar* src, const dl_wchar* substr) { return std::wcsstr(src, substr); }

        static dl_size GetLength(const dl_wchar* string) { return std::wcslen(string); }
        static dl_size GetLengthOfConstructedBy(const dl_wchar* string, const dl_wchar* charset) { return std::wcsspn(string, charset); }
        static dl_size GetLengthOfNotConstructedBy(const dl_wchar* string, const dl_wchar* charset) { return std::wcscspn(string, charset); }

        static dl_int32 ToInt32(const dl_wchar* string) { return static_cast<dl_int32>(std::wcstol(string, nullptr, 10)); }
        static dl_int64 ToInt64(const dl_wchar* string) { return _wcstoi64(string, nullptr, 10); }
        static dl_float32 ToFloat32(const dl_wchar* string) { return static_cast<dl_float32>(std::wcstod(string, nullptr)); }
        static dl_float64 ToFloat64(const dl_wchar* string) { return std::wcstod(string, nullptr); }

        static const dl_wchar* ToString(dl_int32 value, dl_wchar* buf, dl_int32 radix = 10)
        {
            return detail::IntToString(value, buf, radix);
        }

        static const dl_wchar* ToString(dl_float32 value, dl_wchar* buf, dl_int32 digits)
        {
            return ToString(static_cast<dl_float64>(value), buf, digits);
        }

        static const dl_wchar* ToString(dl_float64 value, dl_wchar* buf, dl_int32 digits)
        {
            dl_wchar tmp[512];
            std::swprintf(tmp, sizeof(tmp) / sizeof(tmp[0]), L"%.*f", digits, value);
            std::wcscpy(buf, tmp);
            return buf;
        }
    };
}