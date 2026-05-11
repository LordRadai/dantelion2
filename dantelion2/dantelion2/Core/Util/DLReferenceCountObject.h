#pragma once

namespace DLUT
{
	class DLReferenceCountObject
	{
	protected:
		int m_nRefCount;

	public:
		virtual void Destroy() = 0;

		void Ref();
		void Unref();

		typedef void(_fastcall* Destroy_t)(DLReferenceCountObject*);
	};
}