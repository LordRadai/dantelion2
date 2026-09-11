#pragma once
#include "DLRandomGeneratorLCG.h"

namespace DLUTD
{
	class DLRandomGeneratorXorshift
	{
	public:
		DLRandomGeneratorXorshift(dl_uint seed = 0);
		void Initialize(dl_uint seed);

        dl_uint Next()
        {
            dl_uint t = m_X ^ (m_X << 11);
            m_X = m_Y;
            m_Y = m_Z;
            m_Z = m_W;
            m_W = m_W ^ (m_W >> 19) ^ t ^ (t >> 8);
            return m_W;
        }

        dl_int GetRandomInt(dl_int min, dl_int max)
        {
            dl_uint r = Next();
            return min + (dl_int)(r % (dl_uint)(max - min + 1));
        }

        dl_float32 GetRandomFloat(dl_float32 min, dl_float32 max)
        {
            dl_uint r = Next();
            dl_float32 t = (dl_float32)r / (dl_float32)0xFFFFFFFFu;
            return min + t * (max - min);
        }
	private:
		dl_uint m_X;
		dl_uint m_Y;
		dl_uint m_Z;
		dl_uint m_W;
	};
}