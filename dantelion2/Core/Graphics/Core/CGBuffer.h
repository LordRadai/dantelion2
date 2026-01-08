#pragma once
#include "CGResource.h"
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include <d3d11.h>

namespace DLCG2
{
	class CGBuffer : public CGResource
	{
		ID3D11Buffer* m_pDXBuffer;
		dl_pointer m_pVar20;

	public:
		ID3D11Buffer* GetDXBuffer() const { return m_pDXBuffer; }
	};
}