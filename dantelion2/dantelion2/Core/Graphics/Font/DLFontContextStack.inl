#pragma once
#include "DLFontContextHolder.inl"

namespace DLGR
{
	template<class Ctx>
	class DLFontContextStack : DLFontContextHolder<Ctx>
	{
		dl_pointer m_pVar8;
		dl_uint8 m_Data[88];

	public:
		virtual ~DLFontContextStack() override;

		// Empty for now
		virtual Ctx* GetContext() override { return nullptr; }
		virtual Ctx* GetContext() const override { return nullptr; }
	};
}