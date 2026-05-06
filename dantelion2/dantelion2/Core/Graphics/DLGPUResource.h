#pragma once
#include "DLGfxReferenceCountObject.h"
#include "DLDrawDevice.h"
#include "Core/Platform/Platform.h"

namespace DLGR
{
	class DLGPUResource : public DLGfxReferenceCountObject
	{
	public:
		virtual dl_int GetType() = 0;
		virtual dl_bool IsEnabled() = 0;
		virtual DLCG2::CGResource* GetCGResource() { return nullptr; }
		virtual dl_int GetResourceType() { return 0; }
		virtual void GetUserData() {}

	protected:
		DLDrawDevice* m_pDrawDevice;
		dl_int iVar20;
	};
}