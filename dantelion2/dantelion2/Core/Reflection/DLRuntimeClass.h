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

	private:
		DLRuntimeClass* m_pParentClass;
		DLMethod* m_pConstructor;
		MethodList m_methods;

	public:
		DLRuntimeClass();

		virtual ~DLRuntimeClass() {}
		virtual const dl_char* GetName() const = 0;
		virtual const dl_wchar* GetUnicodeName() const = 0;
		// Map the others...

		void AddMethod(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* methodName, const dl_wchar* wMethodName);
		DLMethod* GetMethod(const dl_char* methodName);

		dl_bool IsOfType(const dl_char* typeName) const
		{
			if (strcmp(this->GetName(), typeName) == 0)
				return true;

			return false;
		}

		dl_bool IsOfType(const dl_wchar* typeName) const
		{
			if (wcscmp(this->GetUnicodeName(), typeName) == 0)
				return true;

			return false;
		}
	};
}
