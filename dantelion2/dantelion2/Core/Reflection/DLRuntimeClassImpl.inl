#pragma once
#include "DLRuntimeClass.h"
#include "dantelion2/FRPG2Call.h"

namespace DLRF
{
	template<typename T>
	class DLRuntimeClassImpl : public DLRuntimeClass
	{
		const dl_char* m_pName;
		const dl_wchar* m_pWName;

	public:
		DLRuntimeClassImpl(const char* name, const wchar_t* wName) : DLRuntimeClass(), m_pName(name), m_pWName(wName)
		{
		}

		const dl_char* GetName() const { return m_pName; }
		const dl_wchar* GetWName() const { return m_pWName; }

		bool IsOfType(const char* typeName) const
		{
			if (strcmp(this->GetName(), typeName) == 0)
				return true;

			return false;
		}

		bool IsOfType(const wchar_t* typeName) const
		{
			if (wcscmp(this->GetWName(), typeName) == 0)
				return true;

			return false;
		}
	};
}
