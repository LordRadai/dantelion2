#pragma once
#include "Core/Platform/Platform.h"
#include "DLVector.h"

namespace DLUT
{
	class PODVectorBase
	{
	public:

	private:
		DLUT::DLVector<dl_pointer> m_vector;
		dl_uint16 m_iVar20;
		dl_uint16 m_iVar22;
		dl_bool m_bVar26;
		dl_bool m_bInitialized;
	};
}