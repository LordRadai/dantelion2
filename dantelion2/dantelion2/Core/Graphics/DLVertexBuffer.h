#pragma once
#include "Core/CGBuffer.h"
#include "DLGPUResource.h"
#include "Core/Platform/Platform.h"

namespace DLGR
{
	class DLVertexBuffer : public DLGPUResource
	{
		DLCG2::CGBuffer* m_pCGBuffer;
		dl_uint m_bufferSize;
		dl_uint m_iVar34;
		dl_int16 m_sVar38;
		dl_pointer m_pVar40;
		dl_pointer m_pVar48;
		dl_float32* m_pVertices;

	public:
		ID3D11Buffer* GetDXBuffer() const { return m_pCGBuffer->GetDXBuffer(); }
		dl_uint GetBufferSize() const { return m_bufferSize; }
	};
}