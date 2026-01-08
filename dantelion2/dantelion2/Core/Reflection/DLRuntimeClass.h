#pragma once
#include "DLTypeID.h"
#include "DLMethodResolver.inl"
#include "DLMethodInvoker.inl"
#include "DLMethodInvokeContext.h"

namespace DLRF
{
	typedef DLMethodResolver<DLMethodInvokeContext> DLMethod;

	class DLRuntimeClass
	{
		void** _vfptr;
	public:
        template<class T>
        struct NamedInfo 
		{
            T* pItem;
            const dl_char* pName;
            const dl_wchar* pWName;
            dl_size szName;
        };

		struct TypedInfo 
		{
			DLTypeID typeID;
			const DLRuntimeClass* pRC;
		};

		typedef DLUT::DLVector<NamedInfo<DLRuntimeClass>> ClassList;
		typedef DLUT::DLVector<TypedInfo> TypeInfoList;
		typedef DLUT::DLVector<NamedInfo<DLMethod>> MethodList;

		DLRuntimeClass* m_pParentClass;
		DLMethod* m_pConstructor;
		MethodList m_methods;

		DLRuntimeClass();

		void AddMethod(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName);
		DLMethod* GetMethod(const dl_char* methodName);
	};
}
