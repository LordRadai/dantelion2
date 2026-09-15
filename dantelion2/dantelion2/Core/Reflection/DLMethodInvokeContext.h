#pragma once
#include "DLAbstractInvokeContext.h"

namespace DLRF
{
	class DLMethod;

	class DLMethodInvokeContext : public DLAbstractInvokeContext
	{
	public:
		typedef dl_bool ReturnType;

		DLRawDynamicPtr GetObject() const { return m_pObj; }

		template<typename T>
		void SetReturnValue(T value)
		{
			m_return.SetValue<T>(value);
		}

	protected:
		dl_char m_unk[240];
		DLRFD::MightyType m_return;
		const DLMethod* m_pM;
		DLRawDynamicPtr m_pObj;
	};
}
