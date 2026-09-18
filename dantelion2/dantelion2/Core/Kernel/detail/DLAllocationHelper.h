#pragma once
#include "Core/Kernel/DLAllocator.h"
#include "Core/Kernel/DLBackAllocator.h"
#include "Call.h"

namespace DLKRD
{
	DLKR::DLAllocator* GetDefaultAllocator();
    DLKR::DLAllocator* GetTemporaryAllocator();

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
            return GetDefaultAllocator();
        }
    };
}