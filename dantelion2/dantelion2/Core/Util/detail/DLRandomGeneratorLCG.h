#pragma once
#include "Core/Platform/Platform.h"

namespace DLUTD
{
	class DLRandomGeneratorLCG
	{
		dl_size m_value;
	public:
		DLRandomGeneratorLCG() {}
		void Initialize(dl_size seed);
		
		dl_size GetValue() const { return m_value; }
	};
}