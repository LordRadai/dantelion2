#include "DLRuntimeClass.h"

namespace DLRF
{
	typedef void(_fastcall* oConstructor)(DLRuntimeClass* pThis);
	typedef void(_fastcall* oAddMethod)(DLRuntimeClass* pThis, DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName);
	typedef DLMethod*(_fastcall* oGetMethod)(DLRuntimeClass* pThis, const dl_char* methodName);

	DLRuntimeClass::DLRuntimeClass() : m_methods(nullptr)
	{
		CALL(oConstructor, 0x83efd0, this);
	}

	void DLRuntimeClass::AddInvoker(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* name, const dl_wchar* wName)
	{
		CALL(AddInvoker_t, 0x83f7c0, this, pMethodInvoker, name, wName);
	}

	void DLRuntimeClass::AddInvoker(DLMethodInvoker<DLRuntimeConstructionContext>* pMethodInvoker, const dl_char* name, const dl_wchar* wName)
	{
		CALL(AddInvokerRt_t, 0x83f870, this, pMethodInvoker, name, wName);
	}

	void DLRuntimeClass::AddMethod(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName)
	{
		CALL(oAddMethod, 0x83f7c0, this, pMethodInvoker, methodName, wMethodName);
	}

	DLMethod* DLRuntimeClass::FindMethod(const dl_char* methodName)
	{
		return CALL(oGetMethod, 0x83f640, this, methodName);
	}
}
