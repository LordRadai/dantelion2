#pragma once
#include "Core/CGBuffer.h"
#include "DLGPUResource.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLGR
{
	class DLIndexBuffer : public DLGPUResource
	{
		DLCG2::CGBuffer* m_pCGBuffer;
		dl_int m_bufferSize;
		dl_int iVar10;
		dl_pointer pVar11;

	public:
		ID3D11Buffer* GetDXBuffer() const { return m_pCGBuffer->GetDXBuffer(); }
		dl_int GetBufferSize() const { return m_bufferSize; }
	};
}