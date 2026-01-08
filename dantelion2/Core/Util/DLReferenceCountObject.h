#pragma once

namespace DLUT
{
	class DLReferenceCountObject
	{
		void** _vfptr;
	protected:
		int m_nRefCount;

	public:
		void Ref();
		void Unref();
	};
}