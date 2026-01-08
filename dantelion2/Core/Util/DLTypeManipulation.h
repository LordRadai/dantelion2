#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLUT
{
    template <typename T, typename U>
    struct DLTypeEqual 
    {
        enum { Result = false };
    };

    template <typename T>
    struct DLTypeEqual<T, T> 
    {
        enum { Result = true };
    };

    template <dl_bool expression, typename _OnTrueType, typename _OnFalseType>
    class DLSelect 
    {
        typedef _OnTrueType OnTrueType;
        typedef _OnFalseType OnFalseType;

        template < dl_bool _expression, dl_bool _dummy >
        struct Selecter {
            typedef OnTrueType Result;
        };

        template < dl_bool _dummy >
        struct Selecter<false, _dummy> {
            typedef OnFalseType Result;
        };

    public:
        typedef typename Selecter<expression, true>::Result Result;
    };

    template <dl_bool expression, dl_int OnTrueValue, dl_int OnFalseValue>
    class DLSelectValue {

        template <dl_bool _expression, dl_bool _dummy>
        struct Selecter {
            enum { Result = OnTrueValue };
        };

        template <dl_bool _dummy>
        struct Selecter<false, _dummy> {
            enum { Result = OnFalseValue };
        };

    public:
        enum { Result = Selecter<expression, true>::Result };
    };
}
