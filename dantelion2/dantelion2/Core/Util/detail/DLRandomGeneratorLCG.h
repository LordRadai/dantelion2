#pragma once
#include "Core/Platform/Platform.h"

namespace DLUTD
{
	class DLRandomGeneratorLCG
	{
		dl_size m_value;
	public:
		DLRandomGeneratorLCG(dl_size seed = 0) : m_value(seed) {}
		
		dl_size GetValue() const { return m_value; }
	};
}