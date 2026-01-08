#pragma once
#include <d3d11.h>

namespace DLGR
{
	class DLDeviceContext
	{
	public:
		ID3D11DeviceContext* GetD3D11DeviceContext();
	};
}
