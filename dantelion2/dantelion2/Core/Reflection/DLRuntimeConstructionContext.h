#pragma once
#include "Core/Kernel/DLAllocator.h"

#include "DLAbstractInvokeContext.h"
#include "DLReflection.h"

namespace DLRF
{
	class DLRuntimeConstructionContext : public DLAbstractInvokeContext
	{
        DLKR::DLAllocator* m_pAllocator;
        dl_bool m_isExplicit;

    public:
        typedef DLRawDynamicPtr ReturnType;

		DLRuntimeConstructionContext(DLKR::DLAllocator* pAllocator = DLRF::GetAllocator(), dl_bool isExplicit = false) : 
			m_pAllocator(pAllocator), 
			m_isExplicit(isExplicit) 
		{
		}

		DLKR::DLAllocator* GetAllocator(void) const { return m_pAllocator; }
		dl_bool IsExplicit(void) const const { return m_isExplicit; }

		void SetAllocator(DLKR::DLAllocator* pA) { m_pAllocator = pA; }
		void SetExplicit(dl_bool b) { m_isExplicit = b; }
	};
}