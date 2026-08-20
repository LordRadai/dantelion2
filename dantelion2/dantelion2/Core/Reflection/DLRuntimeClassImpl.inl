#pragma once
#include "DLRuntimeClass.h"
#include "Call.h"

namespace DLRF
{
	template<typename T>
	class DLRuntimeClassImpl : public DLRuntimeClass
	{
		const dl_char* m_Name;
		const dl_wchar* m_UnicodeName;

	public:
		DLRuntimeClassImpl(const char* name, const wchar_t* wName) : DLRuntimeClass(), m_Name(name), m_UnicodeName(wName)
		{
		}
	};
}
