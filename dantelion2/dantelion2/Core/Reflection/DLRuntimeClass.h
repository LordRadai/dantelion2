#pragma once
#include "DLTypeID.h"
#include "DLMethodResolver.inl"
#include "DLMethodInvoker.inl"
#include "DLMethodInvokeContext.h"
#include "DLRuntimeConstructionContext.h"
#include "DLDynamicPtr.h"

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

	protected:
		DLRuntimeClass* m_pParentClass;
		DLMethod* m_pConstructor;
		MethodList m_methods;

	public:
		DLRuntimeClass();

		virtual ~DLRuntimeClass() {}
		virtual const dl_char* GetName() const = 0;
		virtual const dl_wchar* GetUnicodeName() const = 0;
		virtual DLTypeID GetTypeID() const = 0;
		virtual DLTypeID GetConstTypeID() const = 0;
		virtual DLTypeID GetPointerTypeID() const = 0;
		virtual DLTypeID GetConstPointerTypeID() const = 0;
		virtual dl_bool IsPrimitiveType() const = 0;
		virtual void Delete(DLRawDynamicPtr& ptr, DLKR::DLAllocator* pAllocator) const = 0;
		virtual dl_uint GetSizeOf() const = 0;
		virtual void AddInvoker(DLMethodInvoker<DLMethodInvokeContext>* pMethodInvoker, const dl_char* name, const dl_wchar* wName);
		virtual void AddInvoker(DLMethodResolver<DLRuntimeConstructionContext>* pMethodResolver, const dl_char* name, const dl_wchar* wName);

		typedef void(_fastcall* Destructor_t)(DLRuntimeClass*);
		typedef const dl_char*(_fastcall* GetName_t)(const DLRuntimeClass*);
		typedef const dl_wchar*(_fastcall* GetUnicodeName_t)(const DLRuntimeClass*);
		typedef DLTypeID(_fastcall* GetTypeID_t)(const DLRuntimeClass*);
		typedef DLTypeID(_fastcall* GetConstTypeID_t)(const DLRuntimeClass*);
		typedef DLTypeID(_fastcall* GetPointerTypeID_t)(const DLRuntimeClass*);
		typedef DLTypeID(_fastcall* GetConstPointerTypeID_t)(const DLRuntimeClass*);
		typedef dl_bool(_fastcall* IsPrimitiveType_t)(const DLRuntimeClass*);
		typedef void(_fastcall* Delete_t)(const DLRuntimeClass*, DLRawDynamicPtr&, DLKR::DLAllocator*);
		typedef dl_uint(_fastcall* GetSizeOf_t)(const DLRuntimeClass*);
		typedef void(_fastcall* AddInvoker_t)(DLRuntimeClass*, DLMethodInvoker<DLMethodInvokeContext>*, const dl_char*, const dl_wchar*);
		typedef void(_fastcall* AddInvokerRt_t)(DLRuntimeClass*, DLMethodResolver<DLRuntimeConstructionContext>*, const dl_char*, const dl_wchar*);

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
