#pragma once
#include "DLResourceLoadEvent.h"
#include "DLResourceFileHandle.h"

namespace DLRS
{
	class DLResourceFileLoadEvent : public DLRS::DLResourceLoadEvent
	{
	public:
		DLResourceFileHandle m_fileHandle;

		DLResourceFileLoadEvent();
	};
}