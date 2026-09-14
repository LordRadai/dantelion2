#pragma once
#include "Core/Platform/Platform.h"

namespace DLUT
{
	template<class _ClassType>
	class DLSingleton
	{
	public:
		static _ClassType* GetInstance()
		{
			if (!s_bCreated)
				return _MakeInstance();

			return s_pInstance;
		}

		static void DestroyInstance()
		{
			_DestroyInstance();
		}

	private:
		static _ClassType* _MakeInstance()
		{
			if (!s_bCreated)
			{
				s_pInstance = new _ClassType();
				s_bCreated = true;
			}

			return s_pInstance;
		}

		static void _DestroyInstance()
		{
			if (s_bCreated)
			{
				delete s_pInstance;
				s_pInstance = nullptr;
				s_bCreated = false;
			}
		}

		static _ClassType* s_pInstance;
		static dl_bool s_bCreated;
	};
}