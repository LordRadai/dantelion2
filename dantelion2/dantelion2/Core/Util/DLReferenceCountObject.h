#pragma once

namespace DLUT
{
	class DLReferenceCountObject
	{
	protected:
		int m_nRefCount = 0;

	public:
		virtual void Destroy() = 0;

		void AddRef();
		void UnRef();

		typedef void(_fastcall* Destroy_t)(DLReferenceCountObject*);
	};
}