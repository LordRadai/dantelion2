#pragma once
#include <iostream>
#include "detail/DLStdStreamAdapter.inl"
#include "dantelion2/Core/Kernel/DLMutex.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"

namespace DLSY
{
	class DLStdInputStream
	{
		void** _vfptr;
	};

	class DLStdInputStreamImpl : public DLStdInputStream
	{
		DLSYD::DLIStreamAdapter<std::basic_ifstream<char, std::char_traits<char>>> m_charAdapter;
		DLSYD::DLIStreamAdapter<std::basic_ifstream<wchar_t, std::char_traits<wchar_t>>> m_wcharAdapter;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainMutex> m_mutex;
	};
}
