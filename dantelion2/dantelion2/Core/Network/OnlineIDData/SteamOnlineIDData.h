#pragma once
#include "OnlineIDData.h"

namespace DLNRD
{
	class SteamOnlineIDData : public OnlineIDData
	{
		dl_uint64 m_steamID;
		dl_wchar m_steamIDString[18];
	};
}