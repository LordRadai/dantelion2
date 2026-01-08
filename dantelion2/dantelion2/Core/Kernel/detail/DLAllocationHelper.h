#pragma once
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLBackAllocator.h"
#include "Call.h"

namespace DLKRD
{
    namespace
    {
		typedef DLKR::DLBackAllocator*(_fastcall* oGetTemporaryAllocator)();

        DLKR::DLBackAllocator* GetTemporaryAllocator()
        {
			return CALL(oGetTemporaryAllocator, 0x833dc0);
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