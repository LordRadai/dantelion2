#pragma once
#include "Core/Reflection/DLTypeID.h"

namespace DLRF
{
    namespace DLRFD
    {
        class MightyType
        {
            enum
            {
                MT_VOID = 0,
                MT_SCALAR,
                MT_POINTER,
                MT_REFERENCE,
                MT_OBJECT
            };

            union
            {
                dl_uint32 m_obj[4];
                struct 
                {
                    dl_float64 m_f64;
                    dl_uint64 m_ui64;
                };
            };

            union
            {
                dl_int64 m_i64;
                void* m_ptr;
            };

            union
            {
                struct
                {
                    dl_uint32 m_type : 3;
                    dl_uint32 m_pad : 29;
                };

                dl_uint32 m_attributes;
            };

            DLTypeID m_tid;
        };
    }
}