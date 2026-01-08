#include "DLResourceLoadEvent.h"
#include "FileOperation/FileReadOperation.h"

namespace DLRS
{
	const dl_wchar* DLResourceLoadEvent::GetFilePath() const
	{
		return m_pFileReadOperation->GetFilePath();
	}

	dl_uint DLResourceLoadEvent::GetFileSize() const
	{
		return m_pFileReadOperation->GetFileSize();
	}
}
