#pragma once
#include "FileLoader.h"

namespace DLRSD
{
	class CacheableFileLoader : public FileLoader
	{
		dl_char m_data[496];
	};
}
