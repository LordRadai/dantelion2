#pragma once
#include "DLTypeID.h"
#include "DLDynamicPtr.h"

namespace DLRFD
{
    template < typename T >
    inline DLRF::DLTypeID StaticTypeIDResolver<T>::Evaluate(void) {
        static dl_char _idh;

        return reinterpret_cast<DLRF::DLTypeID> (&_idh);
    }

    template < typename T >
    inline DLRF::DLTypeID TypeIDResolver<T>::Evaluate(T&) {
        return StaticTypeIDResolver<T>::Evaluate();
    }
}