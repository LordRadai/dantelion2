#include "DLRuntimeClass.h"

namespace DLRF
{
	typedef void(_fastcall* oConstructor)(DLRuntimeClass* pThis);
	typedef void(_fastcall* oAddMethod)(DLRuntimeClass* pThis, DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName);
	typedef DLMethod*(_fastcall* oGetMethod)(DLRuntimeClass* pThis, const dl_char* methodName);

	DLRuntimeClass::DLRuntimeClass()
	{
		FRPG2_CALL(oConstructor, 0x83efd0, this);
	}

	void DLRuntimeClass::AddMethod(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName)
	{
		FRPG2_CALL(oAddMethod, 0x83f7c0, this, pMethodInvoker, methodName, wMethodName);
	}

	DLMethod* DLRuntimeClass::GetMethod(const dl_char* methodName)
	{
		return FRPG2_CALL(oGetMethod, 0x840470, this, methodName);
	}
}
