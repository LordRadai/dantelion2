#pragma once
#include "DLNullType.h"

namespace DLUT
{
    namespace TypeList {

        template < class T, class U = DLNullType >
        struct DLTypeList {
            typedef T Head;
            typedef U Tail;
        };

        template < class TList >
        struct Length {

            template < typename T, bool _dummy >
            struct NCUp {
                enum { Value = 1 };
            };

            template <bool _dummy>
            struct NCUp<DLNullType, _dummy> {
                enum { Value = 0 };
            };

            enum { Size = NCUp<typename TList::Head, true>::Value + Length<typename TList::Tail>::Size };
        };

        template <>
        struct Length<DLNullType> {
            enum { Size = 0 };
        };

        template <class TList, unsigned int index>
        struct TypeAt {

            typedef typename TList::Head Head;
            typedef typename TList::Tail Tail;

        private:

            template<unsigned int i, bool _dummy>
            struct In {
                typedef typename TypeAt<Tail, i - 1>::Result Result;
            };

            template<bool _dummy>
            struct In<0, _dummy> {
                typedef Head Result;
            };

        public:
            typedef typename In<index, true>::Result Result;
        };

        template <class TList, unsigned int index, typename DefaultType = DLNullType>
        struct TypeAtNonStrict {

            typedef typename TList::Head Head;
            typedef typename TList::Tail Tail;

        private:
            template<class TList1, unsigned int i, bool _dummy_in>
            struct In {
                template < class TList_Tail, bool _dummy_obcheck >
                struct OBCheck {
                    typedef typename TypeAtNonStrict< typename TList1::Tail, i - 1, DefaultType>::Result Result;
                };

                template <bool _dummy_obcheck>
                struct OBCheck<DLUT::DLNullType, _dummy_obcheck> {
                    typedef DefaultType Result;
                };

                typedef typename OBCheck<typename TList1::Tail, true>::Result Result;
            };

            template<bool _dummy_in>
            struct In<DLTypeList<Head, Tail>, 0, _dummy_in> {
                typedef Head Result;
            };

        public:
            typedef typename In<TList, index, true>::Result Result;
        };

        template <class TList, class T> struct IndexOf;

        template <class T>
        struct IndexOf<DLNullType, T>
        {
            enum { value = -1 };
        };

        template <class T, class Tail>
        struct IndexOf<DLTypeList<T, Tail>, T>
        {
            enum { value = 0 };
        };

        template <class Head, class Tail, class T>
        struct IndexOf<DLTypeList<Head, Tail>, T>
        {
        private:
            enum { temp = IndexOf<Tail, T>::value };
        public:
            enum { value = (temp == -1 ? -1 : 1 + temp) };
        };

        template <class TList, class T> struct Append;

        template <> struct Append<DLNullType, DLNullType>
        {
            typedef DLNullType Result;
        };

        template <class T> struct Append<DLNullType, T>
        {
            typedef DLTypeList<T, DLNullType> Result;
        };

        template <class Head, class Tail>
        struct Append<DLNullType, DLTypeList<Head, Tail> >
        {
            typedef DLTypeList<Head, Tail> Result;
        };

        template <class Head, class Tail, class T>
        struct Append<DLTypeList<Head, Tail>, T>
        {
            typedef DLTypeList<Head,
                typename Append<Tail, T>::Result>
                Result;
        };

        template <class TList, class T> struct Erase;

        template <class T>
        struct Erase<DLNullType, T>
        {
            typedef DLNullType Result;
        };

        template <class T, class Tail>
        struct Erase<DLTypeList<T, Tail>, T>
        {
            typedef Tail Result;
        };

        template <class Head, class Tail, class T>
        struct Erase<DLTypeList<Head, Tail>, T>
        {
            typedef DLTypeList<Head,
                typename Erase<Tail, T>::Result>
                Result;
        };

        template <class TList, class T> struct EraseAll;
        template <class T>
        struct EraseAll<DLNullType, T>
        {
            typedef DLNullType Result;
        };
        template <class T, class Tail>
        struct EraseAll<DLTypeList<T, Tail>, T>
        {

            typedef typename EraseAll<Tail, T>::Result Result;
        };
        template <class Head, class Tail, class T>
        struct EraseAll<DLTypeList<Head, Tail>, T>
        {

            typedef DLTypeList<Head,
                typename EraseAll<Tail, T>::Result>
                Result;
        };
    }
}