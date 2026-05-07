#pragma once
#include "DLVector.h"
#include "Core/Platform/Platform.h"

namespace DLMT2
{
	struct DL_COLOR_U8;
}

namespace DLMT
{
	struct DL_COLOR_32;

	struct DL_COLOR_F4 : public DL_VECTOR4
	{
		DL_COLOR_F4() = default;
		DL_COLOR_F4(dl_float32 r, dl_float32 g, dl_float32 b, dl_float32 a) : DL_VECTOR4(r, g, b, a) {}
		DL_COLOR_F4(const DL_VECTOR4& v) : DL_VECTOR4(v) {}
		DL_COLOR_F4(const DLMT2::DL_COLOR_U8& color);
		DL_COLOR_F4(const DL_COLOR_32& color);

		DL_COLOR_F4& operator=(const DL_COLOR_32& color);
		DL_COLOR_F4& operator=(const DLMT2::DL_COLOR_U8& color);
	};

	struct DL_COLOR_32
	{
		union
		{
			struct
			{
				dl_uint32 r : 8;
				dl_uint32 g : 8;
				dl_uint32 b : 8;
				dl_uint32 a : 8;
			};

			dl_uint32 c;
		};

		DL_COLOR_32(void) {}
		DL_COLOR_32(dl_uint32 color);
		DL_COLOR_32(dl_float32 _r, dl_float32 _g, dl_float32 _b, dl_float32 _a);
		DL_COLOR_32(dl_uint32 _r, dl_uint32 _g, dl_uint32 _b, dl_uint32 _a);
		DL_COLOR_32(const dl_float32* pColor);
		DL_COLOR_32(DLMT2::DL_COLOR_U8 color);
		DL_COLOR_32(DL_COLOR_F4& color);

		operator dl_uint32(void);
		DL_COLOR_32& operator = (const dl_uint32 color);
		DL_COLOR_32& operator = (const DL_COLOR_32& color);
	};
}

namespace DLMT2
{
	struct DL_COLOR_U8
	{
		dl_uchar a;
		dl_uchar b;
		dl_uchar g;
		dl_uchar r;

		DL_COLOR_U8() = default;
		DL_COLOR_U8(dl_uchar _r, dl_uchar _g, dl_uchar _b, dl_uchar _a);
		DL_COLOR_U8(const DLMT::DL_COLOR_32& color);
		DL_COLOR_U8(const DLMT::DL_COLOR_F4& color);

		bool operator!=(const DL_COLOR_U8& other) const
		{
			return this->a != other.a || this->b != other.b || this->g != other.g || this->r != other.r;
		}

		bool operator==(const DL_COLOR_U8& other) const
		{
			return this->a == other.a && this->b == other.b && this->g == other.g && this->r == other.r;
		}

		DL_COLOR_U8& operator=(const DLMT::DL_COLOR_32& color);
		DL_COLOR_U8& operator=(const DLMT::DL_COLOR_F4& color);
	};
}