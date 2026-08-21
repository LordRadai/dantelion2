#pragma once
#include "Core/Platform/Platform.h"

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
        return DLRFD::TypeIDResolver<const T>::Evaluate(t);
    }

    template < typename T >
    inline DLTypeID DLConstDynamicTypeIDOf(const T& t) {
        return DLGetRuntimeClassOf(t).GetConstTypeID();
    }

    template < typename T >
    inline DLTypeID DLTypeIDOf(T& t) {
        return DLRFD::TypeIDResolver<T>::Evaluate(t);
    }

    template < typename T >
    inline DLTypeID DLTypeIDOf(const T& t) {
        return DLConstTypeIDOf(t);
    }

    template < typename T >
    inline DLTypeID DLDynamicTypeIDOf(const T& t) {
        return DLGetRuntimeClassOf(t).GetTypeID();
    }

    template < typename T >
    inline DLTypeID DLStaticGetTypeID(void) {
        return DLRFD::StaticTypeIDResolver<T>::Evaluate();
    }

    template < typename T >
    inline DLTypeID DLStaticGetConstTypeID(void) {
        typedef DLTypeTraits<T> Traits;
        typedef typename Traits::OriginalType OriginalType;
        typedef typename DLSelect<DLTypeTraits<OriginalType>::isVoid, DLNullType, OriginalType>::Result TargetType;
        if (Traits::isPointer)
            return detail::StaticTypeIDResolver<const TargetType*>::Evaluate();
        if (Traits::isReference)
            return detail::StaticTypeIDResolver<const TargetType&>::Evaluate();

        return detail::StaticTypeIDResolver<const TargetType>::Evaluate();
    }
}
