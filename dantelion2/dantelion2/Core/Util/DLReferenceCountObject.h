#pragma once

namespace DLUT
{
	class DLReferenceCountObject
	{
	protected:
		int m_nRefCount;

	public:
		DLReferenceCountObject() : m_nRefCount(0) {}

		virtual void Destroy() = 0;

		void AddRef();
		void UnRef();

		typedef void(_fastcall* Destroy_t)(DLReferenceCountObject*);
	};
}