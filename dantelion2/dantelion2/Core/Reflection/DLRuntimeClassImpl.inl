#pragma once
#include "DLRuntimeClass.h"
#include "DLTypeID.h"
#include "Call.h"

namespace DLRF
{
	template<typename T, dl_bool isPrimitive = false>
	class DLRuntimeClassImpl : public DLRuntimeClass
	{
	public:
		DLRuntimeClassImpl(const char* name, const wchar_t* wName) : DLRuntimeClass(), m_Name(name), m_UnicodeName(wName)
		{
		}

		const dl_char* GetName(void) const override { return m_Name; }
		const dl_wchar* GetUnicodeName(void) const override { return m_UnicodeName; }
		DLTypeID GetTypeID(void) const override { return DLRFD::StaticTypeIDResolver<T>::Evaluate(); }
		DLTypeID GetConstTypeID(void) const override { return DLRFD::StaticTypeIDResolver<const T>::Evaluate(); }
		DLTypeID GetPointerTypeID(void) const override { return DLRFD::StaticTypeIDResolver<T*>::Evaluate(); }
		DLTypeID GetConstPointerTypeID(void) const override { return DLRFD::StaticTypeIDResolver<const T*>::Evaluate(); }
		void Delete(DLRawDynamicPtr& pObject, DLKR::DLAllocator* pA) const override {}
		dl_bool IsPrimitiveType(void) const override { return isPrimitive; }
		dl_uint GetSizeOf(void) const override { return sizeof(T); }
	private:
		const dl_char* m_Name;
		const dl_wchar* m_UnicodeName;
	};
}