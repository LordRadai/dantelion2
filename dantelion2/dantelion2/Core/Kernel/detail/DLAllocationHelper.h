#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Kernel/DLBackAllocator.h"
#include "dantelion2/FRPG2Call.h"

namespace DLKRD
{
    namespace
    {
		typedef DLKR::DLBackAllocator*(_fastcall* oGetTemporaryAllocator)();

        DLKR::DLBackAllocator* GetTemporaryAllocator()
        {
			return FRPG2_CALL(oGetTemporaryAllocator, 0x833dc0);
        }
    }

    template<class AllocHost>
    struct DLAllocationHelper {
        inline static AllocHost* GetDefaultHost(void) 
        {
            return nullptr;
        }
    };

    template<>
    struct DLAllocationHelper<DLKR::DLAllocator> {
        inline static DLKR::DLAllocator* GetDefaultHost(void) 
        {
            return GetTemporaryAllocator();
        }
    };
}