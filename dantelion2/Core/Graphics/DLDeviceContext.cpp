#include "DLDeviceContext.h"

namespace DLGR
{
	ID3D11DeviceContext* DLDeviceContext::GetD3D11DeviceContext()
	{
		return **(ID3D11DeviceContext***)(this + 0xce0);
	}
}
