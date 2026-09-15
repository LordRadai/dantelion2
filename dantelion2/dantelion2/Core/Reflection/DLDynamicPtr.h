#pragma once
#include "Core/Platform/Platform.h"

#undef GetObject

namespace DLRF
{
    class DLRuntimeClass;

	class DLRawDynamicPtr
	{
    public:
		void* Get() const { return m_pObject; }
		const DLRuntimeClass* GetRuntimeClass() const { return m_pRC; }
    protected:
        union 
        {
            dl_uint64 m_value;
            struct 
            {
                const DLRuntimeClass* m_pRC;
                void* m_pObject;
            };
        };
	};;
}
