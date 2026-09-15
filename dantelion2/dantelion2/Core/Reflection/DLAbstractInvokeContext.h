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
	protected:
		const static dl_size MAX_PARAM_SIZE = DLParameterInfo::MAX_PARAM_SIZE;

		__declspec(align(16)) DLParameterInfo m_strictParamInfo;
		__declspec(align(16)) DLParameterInfo m_looseParamInfo;
		DLRFD::MightyType m_primitives[MAX_PARAM_SIZE];
		DLRawDynamicPtr m_args[MAX_PARAM_SIZE];
		dl_uint8 m_nParams;
		dl_uint16 m_rtCheckFlag;
	};
}
