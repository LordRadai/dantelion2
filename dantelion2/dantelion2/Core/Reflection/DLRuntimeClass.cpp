#include "DLRuntimeClass.h"

namespace DLRF
{
	typedef void(_fastcall* oConstructor)(DLRuntimeClass* pThis);
	typedef void(_fastcall* oAddMethod)(DLRuntimeClass* pThis, DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName);
	typedef DLMethod*(_fastcall* oGetMethod)(DLRuntimeClass* pThis, const dl_char* methodName);

	DLRuntimeClass::DLRuntimeClass()
	{
		CALL(oConstructor, 0x83efd0, this);
	}

	void DLRuntimeClass::AddMethod(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName)
	{
		CALL(oAddMethod, 0x83f7c0, this, pMethodInvoker, methodName, wMethodName);
	}

	DLMethod* DLRuntimeClass::GetMethod(const dl_char* methodName)
	{
		return CALL(oGetMethod, 0x840470, this, methodName);
	}
}
