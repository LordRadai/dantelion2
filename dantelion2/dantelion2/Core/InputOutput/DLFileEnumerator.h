#pragma once
#include "Core/Text/DLPathString.h"

namespace DLIO
{
	class DLFileEnumeratorSPI;

	class DLFileEnumerator
	{
	public:
		typedef dl_bool(_fastcall* GetNextFile_t)(DLFileEnumerator*, DLTX::DLPathString&);

		DLFileEnumerator();
		virtual ~DLFileEnumerator();

		virtual dl_bool GetNextFile(DLTX::DLPathString& path);

	private:
		DLTX::DLPathString m_Directory;
		void* m_Handle;
		DLFileEnumeratorSPI* m_pSPI;

		DLFileEnumerator(const DLFileEnumerator&);
		DLFileEnumerator& operator=(const DLFileEnumerator&);
	};
}
