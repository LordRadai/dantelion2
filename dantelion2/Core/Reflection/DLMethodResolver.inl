#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLVector.h"
#include "dantelion2/Core/Kernel/DLMutex.h"
#include "DLMethodInvoker.inl"
#include "DLParameterInfo.h"

namespace DLRF
{
	class DLRuntimeClass;

	template<typename _DedicatedContextType>
	class DLMethodResolver
	{
		typedef DLMethodInvoker<_DedicatedContextType> InvokerType;
	public:
		typedef DLUT::DLVector<const InvokerType*> InvokerVector;
		typedef DLUT::DLVector<DLParameterInfo> ParamInfoVector;
		typedef _DedicatedContextType DedicatedContextType;

		const DLRuntimeClass& m_rc;
		const dl_char* m_pMethodName;
		const dl_wchar* m_pWMethodName;
		InvokerVector m_invokerList;
		mutable ParamInfoVector m_strictPIList;
		mutable DLParameterInfo* m_pLoosePITop;
		mutable DLKR::DLPlainMutex m_mutex;
	};
}