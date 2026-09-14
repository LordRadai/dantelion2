#pragma once
#include "Core/Platform/Platform.h"
#include "Core/Util/DLTypeManipulation.h"
#include "Core/Util/DLNullType.h"

namespace DLRF
{
    typedef dl_pointer_int DLTypeID;
}

namespace DLRFD {
    template < typename T >
    struct TypeIDResolver {
        static DLRF::DLTypeID Evaluate(T&);
    };

    template < typename T >
    struct StaticTypeIDResolver {
        static DLRF::DLTypeID Evaluate(void);
    };
}

namespace DLRF
{
    const static DLTypeID DL_INVALID_TYPEID = 0;

    template < typename T >
    inline DLTypeID DLConstTypeIDOf(const T& t) {
        return ::DLRFD::TypeIDResolver<const T>::Evaluate(t);
    }

    template < typename T >
    inline DLTypeID DLTypeIDOf(T& t) {
        return ::DLRFD::TypeIDResolver<T>::Evaluate(t);
    }

    template < typename T >
    inline DLTypeID DLTypeIDOf(const T& t) {
        return DLConstTypeIDOf(t);
    }

    template < typename T >
    inline DLTypeID DLStaticGetTypeID(void) {
        return ::DLRFD::StaticTypeIDResolver<T>::Evaluate();
    }
}

#include "DLTypeID.inl"