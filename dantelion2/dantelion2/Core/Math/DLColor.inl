#include "DLColor.h"

namespace DLMT
{
	inline DL_COLOR_F4::DL_COLOR_F4(const DLMT2::DL_COLOR_U8& color)
	{
		x = static_cast<dl_float32>(color.b) / 255.0f;
		y = static_cast<dl_float32>(color.g) / 255.0f;
		z = static_cast<dl_float32>(color.r) / 255.0f;
		w = static_cast<dl_float32>(color.a) / 255.0f;
	}

	inline DL_COLOR_F4::DL_COLOR_F4(const DL_COLOR_32& color)
	{
		x = static_cast<dl_float32>(color.b) / 255.0f;
		y = static_cast<dl_float32>(color.g) / 255.0f;
		z = static_cast<dl_float32>(color.r) / 255.0f;
		w = static_cast<dl_float32>(color.a) / 255.0f;
	}

	inline DL_COLOR_F4& DL_COLOR_F4::operator=(const DL_COLOR_32& color)
	{
		x = static_cast<dl_float32>(color.b) / 255.0f;
		y = static_cast<dl_float32>(color.g) / 255.0f;
		z = static_cast<dl_float32>(color.r) / 255.0f;
		w = static_cast<dl_float32>(color.a) / 255.0f;

		return *this;
	}

	inline DL_COLOR_F4& DL_COLOR_F4::operator=(const DLMT2::DL_COLOR_U8& color)
	{
		x = static_cast<dl_float32>(color.b) / 255.0f;
		y = static_cast<dl_float32>(color.g) / 255.0f;
		z = static_cast<dl_float32>(color.r) / 255.0f;
		w = static_cast<dl_float32>(color.a) / 255.0f;

		return *this;
	}

	inline DL_COLOR_32::DL_COLOR_32(dl_uint32 color)
	{
		c = color;
	}

	inline DL_COLOR_32::DL_COLOR_32(dl_uint8 _r, dl_uint8 _g, dl_uint8 _b, dl_uint8 _a)
	{
		b = _b;
		g = _g;
		r = _r;
		a = _a;
	}

	inline DL_COLOR_32::DL_COLOR_32(const dl_float32* pColor)
	{
		b = static_cast<dl_uint32>(pColor[0] * 255.0f);
		g = static_cast<dl_uint32>(pColor[1] * 255.0f);
		r = static_cast<dl_uint32>(pColor[2] * 255.0f);
		a = static_cast<dl_uint32>(pColor[3] * 255.0f);
	}

	inline DL_COLOR_32::DL_COLOR_32(DLMT2::DL_COLOR_U8 color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	inline DL_COLOR_32::DL_COLOR_32(DL_COLOR_F4& color)
	{
		b = static_cast<dl_uint32>(color.x * 255.0f);
		g = static_cast<dl_uint32>(color.y * 255.0f);
		r = static_cast<dl_uint32>(color.z * 255.0f);
		a = static_cast<dl_uint32>(color.w * 255.0f);
	}

	inline DL_COLOR_32::operator dl_uint32(void)
	{
		return c;
	}

	inline DL_COLOR_32& DL_COLOR_32::operator=(const dl_uint32 Color)
	{
		c = Color;
		return *this;
	}

	inline DL_COLOR_32& DL_COLOR_32::operator=(const DL_COLOR_32& Color)
	{
		c = Color.c;
		return *this;
	}
}

namespace DLMT2
{
	inline DL_COLOR_U8::DL_COLOR_U8(dl_uchar _r, dl_uchar _g, dl_uchar _b, dl_uchar _a)
	{
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}

	inline DL_COLOR_U8::DL_COLOR_U8(const DLMT::DL_COLOR_32& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	inline DL_COLOR_U8::DL_COLOR_U8(const DLMT::DL_COLOR_F4& color)
	{
		r = static_cast<dl_uchar>(color.x * 255.0f);
		g = static_cast<dl_uchar>(color.y * 255.0f);
		b = static_cast<dl_uchar>(color.z * 255.0f);
		a = static_cast<dl_uchar>(color.w * 255.0f);
	}

	inline DL_COLOR_U8& DL_COLOR_U8::operator=(const DLMT::DL_COLOR_32& color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
		return *this;
	}

	inline DL_COLOR_U8& DL_COLOR_U8::operator=(const DLMT::DL_COLOR_F4& color)
	{
		r = static_cast<dl_uchar>(color.x * 255.0f);
		g = static_cast<dl_uchar>(color.y * 255.0f);
		b = static_cast<dl_uchar>(color.z * 255.0f);
		a = static_cast<dl_uchar>(color.w * 255.0f);
		return *this;
	}
}