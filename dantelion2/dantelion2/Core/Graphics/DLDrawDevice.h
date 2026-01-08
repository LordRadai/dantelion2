#pragma once
#include "DLDeviceContext.h"
#include "dantelion2/FRPG2Globals.h"

namespace DLGR
{
	class DLDrawDevice : public DLDeviceContext
	{
	public:
	};

#define DL_DRAW_DEVICE					(*(DLDrawDevice**)(MODULE_ADDR + 0x16751f0))
}