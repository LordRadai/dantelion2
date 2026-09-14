#include "DLRuntimeClass.h"

namespace DLRF
{
	typedef void(_fastcall* Constructor_t)(DLRuntimeClass*);
	typedef void(_fastcall* AddMethod_t)(DLRuntimeClass*, DLMethodInvoker<DLMethodInvokeContext>*, const dl_char*, const dl_wchar*);
	typedef DLMethod*(_fastcall* FindMethod_t)(DLRuntimeClass*, const dl_char*);
	typedef void(_fastcall* SetParentClass_t)(DLRuntimeClass*, DLRuntimeClass*);

	DLRuntimeClass::DLRuntimeClass() : m_methods(nullptr)
	{
		CALL(Constructor_t, 0x83efd0, this);
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
		CALL(AddMethod_t, 0x83f7c0, this, pMethodInvoker, methodName, wMethodName);
	}

	DLMethod* DLRuntimeClass::FindMethod(const dl_char* methodName)
	{
		return CALL(FindMethod_t, 0x83f640, this, methodName);
	}

	void DLRuntimeClass::SetParentClass(DLRuntimeClass* pParent)
	{
		CALL(SetParentClass_t, 0x83f8f0, this, pParent);
	}
}
