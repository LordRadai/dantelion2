#pragma once
#include "PlayerData.h"

namespace DLNRD
{
	class SteamPlayerData : public PlayerData
	{
	public:
		dl_wchar m_steamID[33];
	};
}
