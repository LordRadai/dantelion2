#pragma once
#include "Core/Platform/Platform.h"

namespace DLGR
{
	template<class Ctx>
	class DLFontContextHolder
	{
	public:
		virtual ~DLFontContextHolder() {}
		virtual Ctx* GetContext() = 0;
		virtual Ctx* GetContext() const = 0;
	};
}