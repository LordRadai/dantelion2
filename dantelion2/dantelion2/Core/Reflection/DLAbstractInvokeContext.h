#pragma once
#include "Core/Util/DLNonCopyable.h"
#include "DLParameterInfo.h"
#include "DLDynamicPtr.h"
#include "detail/MightyType.h"

namespace DLRF
{
	class DLAbstractInvokeContext : public DLUT::DLNonCopyable
	{
	public:
		const static dl_size MAX_PARAM_SIZE = DLParameterInfo::MAX_PARAM_SIZE;

		DLParameterInfo m_params;
		dl_int m_iVar88;
		dl_int* m_unk[MAX_PARAM_SIZE];
		dl_int m_iVar108;
		DLRFD::MightyType m_primitives[MAX_PARAM_SIZE];
		DLRawDynamicPtr m_args[MAX_PARAM_SIZE];
		dl_uint8 m_nParams;
		dl_uint16 m_rtCheckFlag;
		dl_uint16 m_iVar45C;
	};
}
