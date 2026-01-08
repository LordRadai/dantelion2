#pragma once
#include "DLAbstractInvokeContext.h"

namespace DLRF
{
	class DLMethodInvokeContext : public DLAbstractInvokeContext
	{
		dl_char m_unk[240];
	public:
		DLRFD::MightyType m_return;
		dl_pointer m_pM;
		DLRawDynamicPtr m_pObj;
	};
}
