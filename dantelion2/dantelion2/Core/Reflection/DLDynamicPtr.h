#pragma once
#include "Core/Platform/Platform.h"

namespace DLRF
{
    class DLRuntimeClass;

	class DLRawDynamicPtr
	{
        union 
        {
            dl_uint64 m_value;
            struct 
            {
                const DLRuntimeClass* m_pRC;
                void* m_pObject;
            };
        };
	};
}
