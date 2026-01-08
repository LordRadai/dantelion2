#pragma once
#include <iostream>
#include "detail/DLStdStreamAdapter.inl"
#include "Core/Kernel/DLMutex.h"
#include "Core/Util/DLLifeCycleAdapter.h"

namespace DLSY
{
	class DLStdOutputStream
	{
		void** _vfptr;
	};

	class DLStdOutputStreamImpl : public DLStdOutputStream
	{
		DLSYD::DLOStreamAdapter<std::basic_ofstream<char, std::char_traits<char>>> m_charAdapter;
		DLSYD::DLOStreamAdapter<std::basic_ofstream<wchar_t, std::char_traits<wchar_t>>> m_wcharAdapter;
		DLUT::DLLifecycleAdapter<DLKR::DLPlainMutex> m_mutex;
	};
}
