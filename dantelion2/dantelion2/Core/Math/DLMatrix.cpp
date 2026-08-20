#include "DLMatrix.h"
#include <memory.h>
#include <cmath>
#include "DLConstants.h"

namespace DLMT
{
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX44_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX43_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX34_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX33_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(const dl_float32* pf) { memcpy(m, pf, sizeof(dl_float32) * 4); }
    DL_MATRIX22::DL_MATRIX22(const dl_float32 _m[][2]) { memcpy(m, _m, sizeof(dl_float32) * 4); }
    DL_MATRIX22::DL_MATRIX22(dl_float32 _m00, dl_float32 _m01, dl_float32 _m10, dl_float32 _m11)
        : m00(_m00), m01(_m01), m10(_m10), m11(_m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_VECTOR2_PARAMTYPE r0, DL_VECTOR2_PARAMTYPE r1) { m[0][0] = r0.x; m[0][1] = r0.y; m[1][0] = r1.x; m[1][1] = r1.y; }

    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX22_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }

    dl_float32& DL_MATRIX22::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX22::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR2& DL_MATRIX22::operator[](dl_int32 r) { return *(DL_VECTOR2*)m[r]; }
    const DL_VECTOR2& DL_MATRIX22::operator[](dl_int32 r) const { return *(const DL_VECTOR2*)m[r]; }

    DL_MATRIX22& DL_MATRIX22::operator*=(DL_MATRIX22_PARAMTYPE rhs) { return (*this = *this * rhs); }
    DL_MATRIX22& DL_MATRIX22::operator+=(DL_MATRIX22_PARAMTYPE rhs) { m00 += rhs.m00; m01 += rhs.m01; m10 += rhs.m10; m11 += rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator-=(DL_MATRIX22_PARAMTYPE rhs) { m00 -= rhs.m00; m01 -= rhs.m01; m10 -= rhs.m10; m11 -= rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator*=(dl_float32 _s) { m00 *= _s; m01 *= _s; m10 *= _s; m11 *= _s; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator/=(dl_float32 _s) { dl_float32 inv = 1.0f / _s; return (*this *= inv); }

    DL_MATRIX22 DL_MATRIX22::operator+() const { return *this; }
    DL_MATRIX22 DL_MATRIX22::operator-() const { return DL_MATRIX22(-m00, -m01, -m10, -m11); }

    DL_VECTOR2 DL_MATRIX22::operator*(DL_VECTOR2_PARAMTYPE v) const { return DL_VECTOR2(m00 * v.x + m01 * v.y, m10 * v.x + m11 * v.y); }
    DL_MATRIX22 DL_MATRIX22::operator*(DL_MATRIX22_PARAMTYPE rhs) const {
        return DL_MATRIX22(m00 * rhs.m00 + m01 * rhs.m10, m00 * rhs.m01 + m01 * rhs.m11,
            m10 * rhs.m00 + m11 * rhs.m10, m10 * rhs.m01 + m11 * rhs.m11);
    }
    DL_MATRIX22 DL_MATRIX22::operator+(DL_MATRIX22_PARAMTYPE rhs) const { DL_MATRIX22 res(*this); return res += rhs; }
    DL_MATRIX22 DL_MATRIX22::operator-(DL_MATRIX22_PARAMTYPE rhs) const { DL_MATRIX22 res(*this); return res -= rhs; }
    DL_MATRIX22 DL_MATRIX22::operator*(dl_float32 _s) const { DL_MATRIX22 res(*this); return res *= _s; }
    DL_MATRIX22 DL_MATRIX22::operator/(dl_float32 _s) const { DL_MATRIX22 res(*this); return res /= _s; }

    DL_MATRIX22 operator*(dl_float32 _s, DL_MATRIX22::DL_MATRIX22_PARAMTYPE rhs) { return rhs * _s; }
    dl_bool DL_MATRIX22::operator==(DL_MATRIX22_PARAMTYPE rhs) const { return memcmp(m, rhs.m, sizeof(m)) == 0; }
    dl_bool DL_MATRIX22::operator!=(DL_MATRIX22_PARAMTYPE rhs) const { return !(*this == rhs); }

    DL_VECTOR2& DL_MATRIX22::GetRow(dl_uint32 r) { return *(DL_VECTOR2*)m[r]; }
    const DL_VECTOR2& DL_MATRIX22::GetRow(dl_uint32 r) const { return *(const DL_VECTOR2*)m[r]; }
    void DL_MATRIX22::GetRow(DL_VECTOR2& vOut, dl_uint32 r) const { vOut = *(const DL_VECTOR2*)m[r]; }
    DL_VECTOR2 DL_MATRIX22::GetCol(dl_uint32 c) const { return DL_VECTOR2(m[0][c], m[1][c]); }
    void DL_MATRIX22::GetCol(DL_VECTOR2& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; }

	DL_MATRIX22 DL_MATRIX22::Transpose() const { return DL_MATRIX22(m00, m10, m01, m11); }
	DL_MATRIX22 DL_MATRIX22::Inverse() const
	{
		dl_float32 det = m00 * m11 - m01 * m10;
		if (det == 0.0f) return DL_MATRIX22(); // Return identity matrix if not invertible
		dl_float32 invDet = 1.0f / det;
		return DL_MATRIX22(m11 * invDet, -m01 * invDet, -m10 * invDet, m00 * invDet);
	}

    // =========================================================================
    // DL_MATRIX33 Implementation
    // =========================================================================

    DL_MATRIX33::DL_MATRIX33(DL_MATRIX44_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22) {}
    DL_MATRIX33::DL_MATRIX33(DL_MATRIX43_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22) {}
    DL_MATRIX33::DL_MATRIX33(DL_MATRIX34_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22) {}
    DL_MATRIX33::DL_MATRIX33(DL_MATRIX22_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(0), m10(rhs.m10), m11(rhs.m11), m12(0), m20(0), m21(0), m22(1.0f) {}
    DL_MATRIX33::DL_MATRIX33(const dl_float32* pf) { memcpy(m, pf, sizeof(dl_float32) * 9); }
    DL_MATRIX33::DL_MATRIX33(const dl_float32 _m[][3]) { memcpy(m, _m, sizeof(dl_float32) * 9); }
    DL_MATRIX33::DL_MATRIX33(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02, dl_float32 _m10, dl_float32 _m11, dl_float32 _m12, dl_float32 _m20, dl_float32 _m21, dl_float32 _m22)
        : m00(_m00), m01(_m01), m02(_m02), m10(_m10), m11(_m11), m12(_m12), m20(_m20), m21(_m21), m22(_m22) {}
    DL_MATRIX33::DL_MATRIX33(DL_VECTOR3_PARAMTYPE r0, DL_VECTOR3_PARAMTYPE r1, DL_VECTOR3_PARAMTYPE r2) { m[0][0] = r0.x; m[0][1] = r0.y; m[0][2] = r0.z; m[1][0] = r1.x; m[1][1] = r1.y; m[1][2] = r1.z; m[2][0] = r2.x; m[2][1] = r2.y; m[2][2] = r2.z; }

    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX33_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = 0; m20 = 0; m21 = 0; m22 = 1.0f; return *this; }

    dl_float32& DL_MATRIX33::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX33::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR3& DL_MATRIX33::operator[](dl_int32 r) { return *(DL_VECTOR3*)m[r]; }
    const DL_VECTOR3& DL_MATRIX33::operator[](dl_int32 r) const { return *(const DL_VECTOR3*)m[r]; }

    DL_MATRIX33& DL_MATRIX33::operator*=(DL_MATRIX33_PARAMTYPE rhs) { return (*this = *this * rhs); }
    DL_MATRIX33& DL_MATRIX33::operator+=(DL_MATRIX33_PARAMTYPE rhs) { for (int i = 0; i < 9; ++i) (&m00)[i] += (&rhs.m00)[i]; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator-=(DL_MATRIX33_PARAMTYPE rhs) { for (int i = 0; i < 9; ++i) (&m00)[i] -= (&rhs.m00)[i]; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator*=(dl_float32 _s) { for (int i = 0; i < 9; ++i) (&m00)[i] *= _s; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator/=(dl_float32 _s) { dl_float32 inv = 1.0f / _s; return (*this *= inv); }

    DL_MATRIX33 DL_MATRIX33::operator+() const { return *this; }
    DL_MATRIX33 DL_MATRIX33::operator-() const { DL_MATRIX33 res; for (int i = 0; i < 9; ++i) (&res.m00)[i] = -(&m00)[i]; return res; }

    DL_VECTOR3 DL_MATRIX33::operator*(DL_VECTOR3_PARAMTYPE v) const {
        return DL_VECTOR3(m00 * v.x + m01 * v.y + m02 * v.z, m10 * v.x + m11 * v.y + m12 * v.z, m20 * v.x + m21 * v.y + m22 * v.z);
    }
    DL_VECTOR4AL DL_MATRIX33::operator*(DL_VECTOR4AL_PARAMTYPE v) const {
        return DL_VECTOR4AL(m00 * v.x + m01 * v.y + m02 * v.z, m10 * v.x + m11 * v.y + m12 * v.z, m20 * v.x + m21 * v.y + m22 * v.z, v.w);
    }
    DL_MATRIX33 DL_MATRIX33::operator*(DL_MATRIX33_PARAMTYPE rhs) const {
        DL_MATRIX33 res;
        for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) res.m[i][j] = m[i][0] * rhs.m[0][j] + m[i][1] * rhs.m[1][j] + m[i][2] * rhs.m[2][j];
        return res;
    }
    DL_MATRIX33 DL_MATRIX33::operator+(DL_MATRIX33_PARAMTYPE rhs) const { DL_MATRIX33 res(*this); return res += rhs; }
    DL_MATRIX33 DL_MATRIX33::operator-(DL_MATRIX33_PARAMTYPE rhs) const { DL_MATRIX33 res(*this); return res -= rhs; }
    DL_MATRIX33 DL_MATRIX33::operator*(dl_float32 _s) const { DL_MATRIX33 res(*this); return res *= _s; }
    DL_MATRIX33 DL_MATRIX33::operator/(dl_float32 _s) const { DL_MATRIX33 res(*this); return res /= _s; }

    DL_MATRIX33 operator*(dl_float32 _s, DL_MATRIX33::DL_MATRIX33_PARAMTYPE rhs) { return rhs * _s; }
    dl_bool DL_MATRIX33::operator==(DL_MATRIX33_PARAMTYPE rhs) const { return memcmp(m, rhs.m, sizeof(m)) == 0; }
    dl_bool DL_MATRIX33::operator!=(DL_MATRIX33_PARAMTYPE rhs) const { return !(*this == rhs); }

    DL_VECTOR3& DL_MATRIX33::GetRow(dl_uint32 r) { return *(DL_VECTOR3*)m[r]; }
    const DL_VECTOR3& DL_MATRIX33::GetRow(dl_uint32 r) const { return *(const DL_VECTOR3*)m[r]; }
    void DL_MATRIX33::GetRow(DL_VECTOR3& vOut, dl_uint32 r) const { vOut = *(const DL_VECTOR3*)m[r]; }
    DL_VECTOR3 DL_MATRIX33::GetCol(dl_uint32 c) const { return DL_VECTOR3(m[0][c], m[1][c], m[2][c]); }
    void DL_MATRIX33::GetCol(DL_VECTOR3& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; vOut.z = m[2][c]; }

	DL_MATRIX33 DL_MATRIX33::Transpose() const {
		return DL_MATRIX33(m00, m10, m20, m01, m11, m21, m02, m12, m22);
	}

	DL_MATRIX33 DL_MATRIX33::Inverse() const {
		dl_float32 det = m00 * (m11 * m22 - m12 * m21) - m01 * (m10 * m22 - m12 * m20) + m02 * (m10 * m21 - m11 * m20);
		if (det == 0.0f) return DL_MATRIX33(); // Return identity matrix if not invertible
		dl_float32 invDet = 1.0f / det;
		return DL_MATRIX33(
			(m11 * m22 - m12 * m21) * invDet,
			(m02 * m21 - m01 * m22) * invDet,
			(m01 * m12 - m02 * m11) * invDet,
			(m12 * m20 - m10 * m22) * invDet,
			(m00 * m22 - m02 * m20) * invDet,
			(m02 * m10 - m00 * m12) * invDet,
			(m10 * m21 - m11 * m20) * invDet,
			(m01 * m20 - m00 * m21) * invDet,
			(m00 * m11 - m01 * m10) * invDet
		);
	}

    // =========================================================================
    // DL_MATRIX34 Implementation
    // =========================================================================

    DL_MATRIX34::DL_MATRIX34(const DL_MATRIX34& rhs) { memcpy(m, rhs.m, sizeof(m)); }
    DL_MATRIX34::DL_MATRIX34(DL_MATRIX44_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(rhs.m03), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(rhs.m13), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(rhs.m23) {}
    DL_MATRIX34::DL_MATRIX34(DL_MATRIX43_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(0), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(0), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(0) {}
    DL_MATRIX34::DL_MATRIX34(DL_MATRIX33_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(0), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(0), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(0) {}
    DL_MATRIX34::DL_MATRIX34(DL_MATRIX22_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(0), m03(0), m10(rhs.m10), m11(rhs.m11), m12(0), m13(0), m20(0), m21(0), m22(1.0f), m23(0) {}
    DL_MATRIX34::DL_MATRIX34(const dl_float32* pf) { memcpy(m, pf, sizeof(dl_float32) * 12); }
    DL_MATRIX34::DL_MATRIX34(const dl_float32 _m[][4]) { memcpy(m, _m, sizeof(dl_float32) * 12); }
    DL_MATRIX34::DL_MATRIX34(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02, dl_float32 _m03, dl_float32 _m10, dl_float32 _m11, dl_float32 _m12, dl_float32 _m13, dl_float32 _m20, dl_float32 _m21, dl_float32 _m22, dl_float32 _m23)
        : m00(_m00), m01(_m01), m02(_m02), m03(_m03), m10(_m10), m11(_m11), m12(_m12), m13(_m13), m20(_m20), m21(_m21), m22(_m22), m23(_m23) {}
    DL_MATRIX34::DL_MATRIX34(DL_VECTOR4AL_PARAMTYPE r0, DL_VECTOR4AL_PARAMTYPE r1, DL_VECTOR4AL_PARAMTYPE r2) { m[0][0] = r0.x; m[0][1] = r0.y; m[0][2] = r0.z; m[0][3] = r0.w; m[1][0] = r1.x; m[1][1] = r1.y; m[1][2] = r1.z; m[1][3] = r1.w; m[2][0] = r2.x; m[2][1] = r2.y; m[2][2] = r2.z; m[2][3] = r2.w; }

    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = rhs.m03; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = rhs.m13; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = rhs.m23; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX34_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = 0; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = 0; m13 = 0; m20 = 0; m21 = 0; m22 = 1.0f; m23 = 0; return *this; }

    dl_float32& DL_MATRIX34::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX34::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR4AL& DL_MATRIX34::operator[](dl_int32 r) { return *(DL_VECTOR4AL*)m[r]; }
    const DL_VECTOR4AL& DL_MATRIX34::operator[](dl_int32 r) const { return *(const DL_VECTOR4AL*)m[r]; }

    DL_MATRIX34& DL_MATRIX34::operator*=(DL_MATRIX34_PARAMTYPE rhs) { return (*this = *this * rhs); }
    DL_MATRIX34& DL_MATRIX34::operator+=(DL_MATRIX34_PARAMTYPE rhs) { for (int i = 0; i < 12; ++i) (&m00)[i] += (&rhs.m00)[i]; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator-=(DL_MATRIX34_PARAMTYPE rhs) { for (int i = 0; i < 12; ++i) (&m00)[i] -= (&rhs.m00)[i]; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator*=(dl_float32 _s) { for (int i = 0; i < 12; ++i) (&m00)[i] *= _s; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator/=(dl_float32 _s) { dl_float32 inv = 1.0f / _s; return (*this *= inv); }

    DL_MATRIX34 DL_MATRIX34::operator+() const { return *this; }
    DL_MATRIX34 DL_MATRIX34::operator-() const { DL_MATRIX34 res; for (int i = 0; i < 12; ++i) (&res.m00)[i] = -(&m00)[i]; return res; }

    DL_VECTOR4AL DL_MATRIX34::operator*(DL_VECTOR4AL_PARAMTYPE v) const {
        return DL_VECTOR4AL(m00 * v.x + m01 * v.y + m02 * v.z + m03 * v.w, m10 * v.x + m11 * v.y + m12 * v.z + m13 * v.w, m20 * v.x + m21 * v.y + m22 * v.z + m23 * v.w, v.w);
    }
    DL_MATRIX34 DL_MATRIX34::operator*(DL_MATRIX34_PARAMTYPE rhs) const {
        DL_MATRIX34 res; // Note: 3x4 * 3x4 is generally not defined; assuming multiplication by the square 3x3 part + translation
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) res.m[i][j] = m[i][0] * rhs.m[0][j] + m[i][1] * rhs.m[1][j] + m[i][2] * rhs.m[2][j];
            res.m[i][3] = m[i][0] * rhs.m[0][3] + m[i][1] * rhs.m[1][3] + m[i][2] * rhs.m[2][3] + m[i][3];
        }
        return res;
    }
    DL_MATRIX34 DL_MATRIX34::operator+(DL_MATRIX34_PARAMTYPE rhs) const { DL_MATRIX34 res(*this); return res += rhs; }
    DL_MATRIX34 DL_MATRIX34::operator-(DL_MATRIX34_PARAMTYPE rhs) const { DL_MATRIX34 res(*this); return res -= rhs; }
    DL_MATRIX34 DL_MATRIX34::operator*(dl_float32 _s) const { DL_MATRIX34 res(*this); return res *= _s; }
    DL_MATRIX34 DL_MATRIX34::operator/(dl_float32 _s) const { DL_MATRIX34 res(*this); return res /= _s; }

    DL_MATRIX34 operator*(dl_float32 _s, DL_MATRIX34::DL_MATRIX34_PARAMTYPE rhs) { return rhs * _s; }
    dl_bool DL_MATRIX34::operator==(DL_MATRIX34_PARAMTYPE rhs) const { return memcmp(m, rhs.m, sizeof(m)) == 0; }
    dl_bool DL_MATRIX34::operator!=(DL_MATRIX34_PARAMTYPE rhs) const { return !(*this == rhs); }

    DL_VECTOR4AL& DL_MATRIX34::GetRow(dl_uint32 r) { return *(DL_VECTOR4AL*)m[r]; }
    const DL_VECTOR4AL& DL_MATRIX34::GetRow(dl_uint32 r) const { return *(const DL_VECTOR4AL*)m[r]; }
    void DL_MATRIX34::GetRow(DL_VECTOR4AL& vOut, dl_uint32 r) const { vOut = *(const DL_VECTOR4AL*)m[r]; }
    DL_VECTOR3AL DL_MATRIX34::GetCol(dl_uint32 c) const { return DL_VECTOR3AL(m[0][c], m[1][c], m[2][c]); }
    void DL_MATRIX34::GetCol(DL_VECTOR3AL& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; vOut.z = m[2][c]; }

    // =========================================================================
    // DL_MATRIX43 Implementation
    // =========================================================================
    // NOTE: Based on the union, this is stored as Column[3]

    DL_MATRIX43::DL_MATRIX43(const DL_MATRIX43& rhs) { memcpy(m, rhs.m, sizeof(m)); }
    DL_MATRIX43::DL_MATRIX43(DL_MATRIX44_PARAMTYPE rhs) : m00(rhs.m00), m10(rhs.m10), m20(rhs.m20), m30(rhs.m30), m01(rhs.m01), m11(rhs.m11), m21(rhs.m21), m31(rhs.m31), m02(rhs.m02), m12(rhs.m12), m22(rhs.m22), m32(rhs.m32) {}
    DL_MATRIX43::DL_MATRIX43(DL_MATRIX34_PARAMTYPE rhs) : m00(rhs.m00), m10(rhs.m10), m20(rhs.m20), m30(0), m01(rhs.m01), m11(rhs.m11), m21(rhs.m21), m31(0), m02(rhs.m02), m12(rhs.m12), m22(rhs.m22), m32(0) {}
    DL_MATRIX43::DL_MATRIX43(DL_MATRIX33_PARAMTYPE rhs) : m00(rhs.m00), m10(rhs.m10), m20(rhs.m20), m30(0), m01(rhs.m01), m11(rhs.m11), m21(rhs.m21), m31(0), m02(rhs.m02), m12(rhs.m12), m22(rhs.m22), m32(0) {}
    DL_MATRIX43::DL_MATRIX43(DL_MATRIX22_PARAMTYPE rhs) : m00(rhs.m00), m10(rhs.m10), m20(0), m30(0), m01(rhs.m01), m11(rhs.m11), m21(0), m31(0), m02(0), m12(0), m22(1.0f), m32(0) {}
    DL_MATRIX43::DL_MATRIX43(const dl_float32* pf) { memcpy(m, pf, sizeof(dl_float32) * 12); }
    DL_MATRIX43::DL_MATRIX43(const dl_float32 _m[][4]) { memcpy(m, _m, sizeof(dl_float32) * 12); }
    DL_MATRIX43::DL_MATRIX43(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02, dl_float32 _m10, dl_float32 _m11, dl_float32 _m12, dl_float32 _m20, dl_float32 _m21, dl_float32 _m22, dl_float32 _m30, dl_float32 _m31, dl_float32 _m32)
        : m00(_m00), m01(_m01), m02(_m02), m10(_m10), m11(_m11), m12(_m12), m20(_m20), m21(_m21), m22(_m22), m30(_m30), m31(_m31), m32(_m32) {}
    DL_MATRIX43::DL_MATRIX43(DL_VECTOR4AL_PARAMTYPE c0, DL_VECTOR4AL_PARAMTYPE c1, DL_VECTOR4AL_PARAMTYPE c2) { m[0][0] = c0.x; m[0][1] = c0.y; m[0][2] = c0.z; m[0][3] = c0.w; m[1][0] = c1.x; m[1][1] = c1.y; m[1][2] = c1.z; m[1][3] = c1.w; m[2][0] = c2.x; m[2][1] = c2.y; m[2][2] = c2.z; m[2][3] = c2.w; }

    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX43_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20; m30 = rhs.m30; m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21; m31 = rhs.m31; m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22; m32 = rhs.m32; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20; m30 = 0; m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21; m31 = 0; m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22; m32 = 0; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20; m30 = 0; m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21; m31 = 0; m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22; m32 = 0; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = 0; m30 = 0; m01 = rhs.m01; m11 = rhs.m11; m21 = 0; m31 = 0; m02 = 0; m12 = 0; m22 = 1.0f; m32 = 0; return *this; }

    dl_float32& DL_MATRIX43::operator()(dl_uint32 c, dl_uint32 r) { return m[c][r]; }
    const dl_float32& DL_MATRIX43::operator()(dl_uint32 c, dl_uint32 r) const { return m[c][r]; }
    DL_VECTOR4AL& DL_MATRIX43::operator[](dl_int32 c) { return *(DL_VECTOR4AL*)m[c]; }
    const DL_VECTOR4AL& DL_MATRIX43::operator[](dl_int32 c) const { return *(const DL_VECTOR4AL*)m[c]; }

    DL_MATRIX43& DL_MATRIX43::operator*=(DL_MATRIX43_PARAMTYPE rhs) { return (*this = *this * rhs); }
    DL_MATRIX43& DL_MATRIX43::operator+=(DL_MATRIX43_PARAMTYPE rhs) { for (int i = 0; i < 12; ++i) (&m00)[i] += (&rhs.m00)[i]; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator-=(DL_MATRIX43_PARAMTYPE rhs) { for (int i = 0; i < 12; ++i) (&m00)[i] -= (&rhs.m00)[i]; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator*=(dl_float32 _s) { for (int i = 0; i < 12; ++i) (&m00)[i] *= _s; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator/=(dl_float32 _s) { dl_float32 inv = 1.0f / _s; return (*this *= inv); }

    DL_MATRIX43 DL_MATRIX43::operator+() const { return *this; }
    DL_MATRIX43 DL_MATRIX43::operator-() const { DL_MATRIX43 res; for (int i = 0; i < 12; ++i) (&res.m00)[i] = -(&m00)[i]; return res; }

    DL_VECTOR4AL DL_MATRIX43::operator*(DL_VECTOR4AL_PARAMTYPE v) const {
        return DL_VECTOR4AL(m00 * v.x + m01 * v.y + m02 * v.z, m10 * v.x + m11 * v.y + m12 * v.z, m20 * v.x + m21 * v.y + m22 * v.z, m30 * v.x + m31 * v.y + m32 * v.z);
    }
    DL_MATRIX43 DL_MATRIX43::operator*(DL_MATRIX43_PARAMTYPE rhs) const {
        DL_MATRIX43 res;
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 3; ++j) res.m[j][i] = m[0][i] * rhs.m[j][0] + m[1][i] * rhs.m[j][1] + m[2][i] * rhs.m[j][2];
        return res;
    }
    DL_MATRIX43 DL_MATRIX43::operator+(DL_MATRIX43_PARAMTYPE rhs) const { DL_MATRIX43 res(*this); return res += rhs; }
    DL_MATRIX43 DL_MATRIX43::operator-(DL_MATRIX43_PARAMTYPE rhs) const { DL_MATRIX43 res(*this); return res -= rhs; }
    DL_MATRIX43 DL_MATRIX43::operator*(dl_float32 _s) const { DL_MATRIX43 res(*this); return res *= _s; }
    DL_MATRIX43 DL_MATRIX43::operator/(dl_float32 _s) const { DL_MATRIX43 res(*this); return res /= _s; }

    DL_MATRIX43 operator*(dl_float32 _s, DL_MATRIX43::DL_MATRIX43_PARAMTYPE rhs) { return rhs * _s; }
    dl_bool DL_MATRIX43::operator==(DL_MATRIX43_PARAMTYPE rhs) const { return memcmp(m, rhs.m, sizeof(m)) == 0; }
    dl_bool DL_MATRIX43::operator!=(DL_MATRIX43_PARAMTYPE rhs) const { return !(*this == rhs); }

    DL_VECTOR3AL DL_MATRIX43::GetRow(dl_uint32 r) const { return DL_VECTOR3AL(m[0][r], m[1][r], m[2][r]); }
    void DL_MATRIX43::GetRow(DL_VECTOR3AL& vOut, dl_uint32 r) const { vOut.x = m[0][r]; vOut.y = m[1][r]; vOut.z = m[2][r]; }
    DL_VECTOR4AL& DL_MATRIX43::GetCol(dl_uint32 c) { return *(DL_VECTOR4AL*)m[c]; }
    const DL_VECTOR4AL& DL_MATRIX43::GetCol(dl_uint32 c) const { return *(const DL_VECTOR4AL*)m[c]; }
    void DL_MATRIX43::GetCol(DL_VECTOR4AL& vOut, dl_uint32 c) const { vOut = *(const DL_VECTOR4AL*)m[c]; }

    // =========================================================================
    // DL_MATRIX44 Implementation
    // =========================================================================

    DL_MATRIX44::DL_MATRIX44(const DL_MATRIX44& rhs) { memcpy(m, rhs.m, sizeof(m)); }
    DL_MATRIX44::DL_MATRIX44(DL_MATRIX43_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(0), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(0), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(0), m30(rhs.m30), m31(rhs.m31), m32(rhs.m32), m33(1.0f) {}
    DL_MATRIX44::DL_MATRIX44(DL_MATRIX34_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(rhs.m03), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(rhs.m13), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(rhs.m23), m30(0), m31(0), m32(0), m33(1.0f) {}
    DL_MATRIX44::DL_MATRIX44(DL_MATRIX33_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(rhs.m02), m03(0), m10(rhs.m10), m11(rhs.m11), m12(rhs.m12), m13(0), m20(rhs.m20), m21(rhs.m21), m22(rhs.m22), m23(0), m30(0), m31(0), m32(0), m33(1.0f) {}
    DL_MATRIX44::DL_MATRIX44(DL_MATRIX22_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m02(0), m03(0), m10(rhs.m10), m11(rhs.m11), m12(0), m13(0), m20(0), m21(0), m22(1.0f), m23(0), m30(0), m31(0), m32(0), m33(1.0f) {}
    DL_MATRIX44::DL_MATRIX44(const dl_float32* pf) { memcpy(m, pf, sizeof(dl_float32) * 16); }
    DL_MATRIX44::DL_MATRIX44(const dl_float32 _m[][4]) { memcpy(m, _m, sizeof(dl_float32) * 16); }
    DL_MATRIX44::DL_MATRIX44(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02, dl_float32 _m03, dl_float32 _m10, dl_float32 _m11, dl_float32 _m12, dl_float32 _m13, dl_float32 _m20, dl_float32 _m21, dl_float32 _m22, dl_float32 _m23, dl_float32 _m30, dl_float32 _m31, dl_float32 _m32, dl_float32 _m33)
        : m00(_m00), m01(_m01), m02(_m02), m03(_m03), m10(_m10), m11(_m11), m12(_m12), m13(_m13), m20(_m20), m21(_m21), m22(_m22), m23(_m23), m30(_m30), m31(_m31), m32(_m32), m33(_m33) {}
    DL_MATRIX44::DL_MATRIX44(DL_VECTOR4AL_PARAMTYPE r0, DL_VECTOR4AL_PARAMTYPE r1, DL_VECTOR4AL_PARAMTYPE r2, DL_VECTOR4AL_PARAMTYPE r3) { m[0][0] = r0.x; m[0][1] = r0.y; m[0][2] = r0.z; m[0][3] = r0.w; m[1][0] = r1.x; m[1][1] = r1.y; m[1][2] = r1.z; m[1][3] = r1.w; m[2][0] = r2.x; m[2][1] = r2.y; m[2][2] = r2.z; m[2][3] = r2.w; m[3][0] = r3.x; m[3][1] = r3.y; m[3][2] = r3.z; m[3][3] = r3.w; }

    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX44_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; m30 = rhs.m30; m31 = rhs.m31; m32 = rhs.m32; m33 = 1.0f; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = rhs.m03; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = rhs.m13; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = rhs.m23; m30 = 0; m31 = 0; m32 = 0; m33 = 1.0f; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; m30 = 0; m31 = 0; m32 = 0; m33 = 1.0f; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = 0; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = 0; m13 = 0; m20 = 0; m21 = 0; m22 = 1.0f; m23 = 0; m30 = 0; m31 = 0; m32 = 0; m33 = 1.0f; return *this; }

    dl_float32& DL_MATRIX44::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX44::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR4AL& DL_MATRIX44::operator[](dl_int32 r) { return *(DL_VECTOR4AL*)m[r]; }
    const DL_VECTOR4AL& DL_MATRIX44::operator[](dl_int32 r) const { return *(const DL_VECTOR4AL*)m[r]; }

    DL_MATRIX44& DL_MATRIX44::operator*=(DL_MATRIX44_PARAMTYPE rhs) { return (*this = *this * rhs); }
    DL_MATRIX44& DL_MATRIX44::operator+=(DL_MATRIX44_PARAMTYPE rhs) { for (int i = 0; i < 16; ++i) (&m00)[i] += (&rhs.m00)[i]; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator-=(DL_MATRIX44_PARAMTYPE rhs) { for (int i = 0; i < 16; ++i) (&m00)[i] -= (&rhs.m00)[i]; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator*=(dl_float32 _s) { for (int i = 0; i < 16; ++i) (&m00)[i] *= _s; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator/=(dl_float32 _s) { dl_float32 inv = 1.0f / _s; return (*this *= inv); }

    DL_MATRIX44 DL_MATRIX44::operator+() const { return *this; }
    DL_MATRIX44 DL_MATRIX44::operator-() const { DL_MATRIX44 res; for (int i = 0; i < 16; ++i) (&res.m00)[i] = -(&m00)[i]; return res; }

    DL_VECTOR4AL DL_MATRIX44::operator*(DL_VECTOR4AL_PARAMTYPE v) const {
        return DL_VECTOR4AL(m00 * v.x + m01 * v.y + m02 * v.z + m03 * v.w, m10 * v.x + m11 * v.y + m12 * v.z + m13 * v.w, m20 * v.x + m21 * v.y + m22 * v.z + m23 * v.w, m30 * v.x + m31 * v.y + m32 * v.z + m33 * v.w);
    }
    DL_MATRIX44 DL_MATRIX44::operator*(DL_MATRIX44_PARAMTYPE rhs) const {
        DL_MATRIX44 res;
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) res.m[i][j] = m[i][0] * rhs.m[0][j] + m[i][1] * rhs.m[1][j] + m[i][2] * rhs.m[2][j] + m[i][3] * rhs.m[3][j];
        return res;
    }
    DL_MATRIX44 DL_MATRIX44::operator+(DL_MATRIX44_PARAMTYPE rhs) const { DL_MATRIX44 res(*this); return res += rhs; }
    DL_MATRIX44 DL_MATRIX44::operator-(DL_MATRIX44_PARAMTYPE rhs) const { DL_MATRIX44 res(*this); return res -= rhs; }
    DL_MATRIX44 DL_MATRIX44::operator*(dl_float32 _s) const { DL_MATRIX44 res(*this); return res *= _s; }
    DL_MATRIX44 DL_MATRIX44::operator/(dl_float32 _s) const { DL_MATRIX44 res(*this); return res /= _s; }

    DL_MATRIX44 operator*(dl_float32 _s, DL_MATRIX44::DL_MATRIX44_PARAMTYPE rhs) { return rhs * _s; }
    dl_bool DL_MATRIX44::operator==(DL_MATRIX44_PARAMTYPE rhs) const { return memcmp(m, rhs.m, sizeof(m)) == 0; }
    dl_bool DL_MATRIX44::operator!=(DL_MATRIX44_PARAMTYPE rhs) const { return !(*this == rhs); }

    DL_VECTOR4AL& DL_MATRIX44::GetRow(dl_uint32 r) { return *(DL_VECTOR4AL*)m[r]; }
    const DL_VECTOR4AL& DL_MATRIX44::GetRow(dl_uint32 r) const { return *(const DL_VECTOR4AL*)m[r]; }
    void DL_MATRIX44::GetRow(DL_VECTOR4AL& vOut, dl_uint32 r) const { vOut = *(const DL_VECTOR4AL*)m[r]; }
    DL_VECTOR4AL DL_MATRIX44::GetCol(dl_uint32 c) const { return DL_VECTOR4AL(m[0][c], m[1][c], m[2][c], m[3][c]); }
    void DL_MATRIX44::GetCol(DL_VECTOR4AL& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; vOut.z = m[2][c]; vOut.w = m[3][c]; }

    dl_float32 DL_MATRIX44::GetScale() const {
		return std::sqrtf(m00 * m00 + m10 * m10 + m20 * m20);
    }

    DL_VECTOR4AL DL_MATRIX44::GetTranslation() const {
        return DL_VECTOR4AL(m30, m31, m32, m33);
    }

    DL_MATRIX33 DL_MATRIX44::GetRotation() const {
        return DL_MATRIX33(m00, m01, m02, m10, m11, m12, m20, m21, m22);
    }

	DL_MATRIX44 DL_MATRIX44::Transpose() const {
		return DL_MATRIX44(m00, m10, m20, m30, m01, m11, m21, m31, m02, m12, m22, m32, m03, m13, m23, m33);
	}

    DL_MATRIX44 DL_MATRIX44::Inverse() const {
        dl_float32 m00 = this->m00, m01 = this->m01, m02 = this->m02, m03 = this->m03;
        dl_float32 m10 = this->m10, m11 = this->m11, m12 = this->m12, m13 = this->m13;
        dl_float32 m20 = this->m20, m21 = this->m21, m22 = this->m22, m23 = this->m23;
        dl_float32 m30 = this->m30, m31 = this->m31, m32 = this->m32, m33 = this->m33;

        dl_float32 coef00 = m22 * m33 - m23 * m32;
        dl_float32 coef02 = m21 * m33 - m23 * m31;
        dl_float32 coef03 = m21 * m32 - m22 * m31;

        dl_float32 coef04 = m20 * m33 - m23 * m30;
        dl_float32 coef06 = m20 * m32 - m22 * m30;
        dl_float32 coef07 = m20 * m31 - m21 * m30;

        dl_float32 det00 = m11 * coef00 - m12 * coef02 + m13 * coef03;
        dl_float32 det01 = m10 * coef00 - m12 * coef04 + m13 * coef06;
        dl_float32 det02 = m10 * coef02 - m11 * coef04 + m13 * coef07;
        dl_float32 det03 = m10 * coef03 - m11 * coef06 + m12 * coef07;

        dl_float32 det = m00 * det00 - m01 * det01 + m02 * det02 - m03 * det03;

        if (std::abs(det) < 1e-8f) return DL_MATRIX44(); // Return identity or zero matrix

        dl_float32 invDet = 1.0f / det;

        // Adjugate matrix calculations
        return DL_MATRIX44(
            det00 * invDet,
            -(m01 * coef00 - m02 * coef02 + m03 * coef03) * invDet,
            (m01 * (m12 * m33 - m13 * m32) - m02 * (m11 * m33 - m13 * m31) + m03 * (m11 * m32 - m12 * m31)) * invDet,
            -(m01 * (m12 * m23 - m13 * m22) - m02 * (m11 * m23 - m13 * m21) + m03 * (m11 * m22 - m12 * m21)) * invDet,

            -det01 * invDet,
            (m00 * coef00 - m02 * coef04 + m03 * coef06) * invDet,
            -(m00 * (m12 * m33 - m13 * m32) - m02 * (m10 * m33 - m13 * m30) + m03 * (m10 * m32 - m12 * m30)) * invDet,
            (m00 * (m12 * m23 - m13 * m22) - m02 * (m10 * m23 - m13 * m20) + m03 * (m10 * m22 - m12 * m20)) * invDet,

            det02 * invDet,
            -(m00 * coef02 - m01 * coef04 + m03 * coef07) * invDet,
            (m00 * (m11 * m33 - m13 * m31) - m01 * (m10 * m33 - m13 * m30) + m03 * (m10 * m31 - m11 * m30)) * invDet,
            -(m00 * (m11 * m23 - m13 * m21) - m01 * (m10 * m23 - m13 * m20) + m03 * (m10 * m21 - m11 * m20)) * invDet,

            -det03 * invDet,
            (m00 * coef03 - m01 * coef06 + m02 * coef07) * invDet,
            -(m00 * (m11 * m32 - m12 * m31) - m01 * (m10 * m32 - m12 * m30) + m02 * (m10 * m31 - m11 * m30)) * invDet,
            (m00 * (m11 * m22 - m12 * m21) - m01 * (m10 * m22 - m12 * m20) + m02 * (m10 * m21 - m11 * m20)) * invDet
        );
    }

    DL_VECTOR4AL& DL_MATRIX44::R(dl_int idx)
    {
		return *reinterpret_cast<DL_VECTOR4AL*>(&m[idx][0]);
    }

    DL_VECTOR4AL& DL_MATRIX44::C(dl_int idx)
    {
        return *reinterpret_cast<DL_VECTOR4AL*>(&m[0][idx]);
    }

    DL_MATRIX44 DL_MATRIX44::CreateTranslation(const DLMT::DL_VECTOR4AL& translation) {
        DL_MATRIX44 result = DL_IDENTITY_MATRIX44;
        result.m30 = translation.x;
        result.m31 = translation.y;
        result.m32 = translation.z;
        return result;
    }

	DL_MATRIX44 DL_MATRIX44::CreateRotationX(dl_float32 angle) {
		dl_float32 c = std::cos(angle);
		dl_float32 s = std::sin(angle);
		return DL_MATRIX44(
			1, 0, 0, 0,
			0, c, -s, 0,
			0, s, c, 0,
			0, 0, 0, 1
		);
	}

	DL_MATRIX44 DL_MATRIX44::CreateRotationY(dl_float32 angle) {
		dl_float32 c = std::cos(angle);
		dl_float32 s = std::sin(angle);
		return DL_MATRIX44(
			c, 0, s, 0,
			0, 1, 0, 0,
			-s, 0, c, 0,
			0, 0, 0, 1
		);
	}

	DL_MATRIX44 DL_MATRIX44::CreateRotationZ(dl_float32 angle) {
		dl_float32 c = std::cos(angle);
		dl_float32 s = std::sin(angle);
		return DL_MATRIX44(
			c, -s, 0, 0,
			s, c, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		);
	}

    DL_MATRIX44 DL_MATRIX44::CreateScale(dl_float32 scale) {
        DL_MATRIX44 result = DL_IDENTITY_MATRIX44;
        result.m00 = scale;
        result.m11 = scale;
        result.m22 = scale;
        return result;
    }

    DL_MATRIX44 DL_MATRIX44::CreateTransform(const DLMT::DL_VECTOR4AL& translation, const DLMT::DL_QUATERNION& rotation, dl_float32 scale) {
        DL_MATRIX44 result;
        dl_float32 xx = rotation.x * rotation.x;
        dl_float32 yy = rotation.y * rotation.y;
        dl_float32 zz = rotation.z * rotation.z;

        dl_float32 xy = rotation.x * rotation.y;
        dl_float32 xz = rotation.x * rotation.z;
        dl_float32 yz = rotation.y * rotation.z;

        dl_float32 wx = rotation.w * rotation.x;
        dl_float32 wy = rotation.w * rotation.y;
        dl_float32 wz = rotation.w * rotation.z;

        result.m[0][0] = scale * (1.0f - 2.0f * (yy + zz));
        result.m[0][1] = scale * (2.0f * (xy + wz));
        result.m[0][2] = scale * (2.0f * (xz - wy));
        result.m[0][3] = 0.0f;

        result.m[1][0] = scale * (2.0f * (xy - wz));
        result.m[1][1] = scale * (1.0f - 2.0f * (xx + zz));
        result.m[1][2] = scale * (2.0f * (yz + wx));
        result.m[1][3] = 0.0f;

        result.m[2][0] = scale * (2.0f * (xz + wy));
        result.m[2][1] = scale * (2.0f * (yz - wx));
        result.m[2][2] = scale * (1.0f - 2.0f * (xx + yy));
        result.m[2][3] = 0.0f;

        result.m[3][0] = translation.x;
        result.m[3][1] = translation.y;
        result.m[3][2] = translation.z;
        result.m[3][3] = 1.0f;

        return result;
    }

    DL_MATRIX44 DL_MATRIX44::FromTwoVectors(const DLMT::DL_VECTOR4AL& from, const DLMT::DL_VECTOR4AL& to) {
        DL_MATRIX44 result = DL_IDENTITY_MATRIX44;

        DL_VECTOR3 euler = DL_VECTOR3(0, 0, 0);
        DL_VECTOR3 diff = to - from;

        if (diff.x == 0 && diff.z == 0)
        {
            if (diff.y >= 0)
                result = CreateRotationZ(PI);
            else
                result = CreateRotationZ(0);

            return result;
        }

        float distance = diff.Length();

        euler.y = asin(diff.y / distance);

        float distance_xz = distance * cos(euler.y);

        euler.x = acos(diff.x / distance_xz);
        euler.z = acos(diff.z / distance_xz);

        DLMT::DL_MATRIX44 rot_x = DLMT::DL_MATRIX44::CreateRotationX(-euler.x);
        DLMT::DL_MATRIX44 rot_y = DLMT::DL_MATRIX44::CreateRotationY(-euler.y);
        DLMT::DL_MATRIX44 rot_z = DLMT::DL_MATRIX44::CreateRotationZ(-euler.z);

        result = rot_x * result;
        result = rot_y * result;
        result = rot_z * result;

        return result;
    }

    // --- Off-Center Perspective ---
    DL_MATRIX44 DL_MATRIX44::PerspectiveOffCenterLH_GL(dl_float32 l, dl_float32 r, dl_float32 b, dl_float32 t, dl_float32 n, dl_float32 f) {
        return DL_MATRIX44(
            2 * n / (r - l), 0, (r + l) / (r - l), 0,
            0, 2 * n / (t - b), (t + b) / (t - b), 0,
            0, 0, (f + n) / (f - n), -(2 * f * n) / (f - n),
            0, 0, 1, 0
        );
    }

    DL_MATRIX44 DL_MATRIX44::PerspectiveOffCenterRH_GL(dl_float32 l, dl_float32 r, dl_float32 b, dl_float32 t, dl_float32 n, dl_float32 f) {
        return DL_MATRIX44(
            2 * n / (r - l), 0, (r + l) / (r - l), 0,
            0, 2 * n / (t - b), (t + b) / (t - b), 0,
            0, 0, -(f + n) / (f - n), -(2 * f * n) / (f - n),
            0, 0, -1, 0
        );
    }

    // --- Off-Center Orthographic ---
    DL_MATRIX44 DL_MATRIX44::OrthographicOffCenterLH_GL(dl_float32 l, dl_float32 r, dl_float32 b, dl_float32 t, dl_float32 n, dl_float32 f) {
        return DL_MATRIX44(
            2 / (r - l), 0, 0, -(r + l) / (r - l),
            0, 2 / (t - b), 0, -(t + b) / (t - b),
            0, 0, 2 / (f - n), -(f + n) / (f - n),
            0, 0, 0, 1
        );
    }

    DL_MATRIX44 DL_MATRIX44::OrthographicOffCenterRH_GL(dl_float32 l, dl_float32 r, dl_float32 b, dl_float32 t, dl_float32 n, dl_float32 f) {
        return DL_MATRIX44(
            2 / (r - l), 0, 0, -(r + l) / (r - l),
            0, 2 / (t - b), 0, -(t + b) / (t - b),
            0, 0, -2 / (f - n), -(f + n) / (f - n),
            0, 0, 0, 1
        );
    }

    // --- Field of View Perspective ---
    DL_MATRIX44 DL_MATRIX44::PerspectiveFovLH_GL(dl_float32 fovY, dl_float32 aspect, dl_float32 n, dl_float32 f) {
        dl_float32 tanHalfFov = tanf(fovY * 0.5f);
        dl_float32 t = n * tanHalfFov;
        dl_float32 r = t * aspect;
        return PerspectiveOffCenterLH_GL(-r, r, -t, t, n, f);
    }

    DL_MATRIX44 DL_MATRIX44::PerspectiveFovRH_GL(dl_float32 fovY, dl_float32 aspect, dl_float32 n, dl_float32 f) {
        dl_float32 tanHalfFov = tanf(fovY * 0.5f);
        dl_float32 t = n * tanHalfFov;
        dl_float32 r = t * aspect;
        return PerspectiveOffCenterRH_GL(-r, r, -t, t, n, f);
    }
}