#include "DLTypeID.h"
#include "DLRuntimeClass.h"
#include "DLDynamicPtr.h"

namespace DLRFD
{
    template < typename T >
    inline DLRF::DLTypeID StaticTypeIDResolver<T>::Evaluate(void) {
        static dl_char _idh;

        return reinterpret_cast<DLTypeID> (&_idh);
    }

    template < typename T >
    inline DLRF::DLTypeID TypeIDResolver<T>::Evaluate(T&) {
        return StaticTypeIDResolver<T>::Evaluate();
    }

    template<>
    struct TypeIDResolver<const DLRF::DLRuntimeClass&> {
        static inline DLRF::DLTypeID Evaluate(const DLRF::DLRuntimeClass& rc) {
            return rc.GetTypeID();
        }
    };
}