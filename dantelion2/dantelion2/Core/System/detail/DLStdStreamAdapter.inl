#pragma once
#include "Core/Platform/Platform.h"

namespace DLSYD
{
	template<class T>
	class DLOStreamAdapter
	{
		void** _vfptr;
		dl_pointer m_pStream;
		dl_uint m_iVar10;
	};

	template<class T>
	class DLIStreamAdapter
	{
		void** _vfptr;
		dl_pointer m_pStream;
		dl_uint m_iVar10;
	};
}
