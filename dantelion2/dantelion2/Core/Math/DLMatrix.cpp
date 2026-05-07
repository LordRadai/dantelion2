#include "DLMatrix.h"
#include <memory.h>

namespace DLMT
{
	DL_MATRIX22 DL_MATRIX22::DL_IDENTITY_MATRIX = 
        DL_MATRIX22(1.0f, 0.0f, 
                    0.0f, 1.0f);

    DL_MATRIX33 DL_MATRIX33::DL_IDENTITY_MATRIX = 
        DL_MATRIX33(1.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f,
		            0.0f, 0.0f, 1.0f);

    DL_MATRIX34 DL_MATRIX34::DL_IDENTITY_MATRIX = 
        DL_MATRIX34(1.0f, 0.0f, 0.0f, 0.0f,
                    0.0f, 1.0f, 0.0f, 0.0f,
		            0.0f, 0.0f, 1.0f, 0.0f);

    DL_MATRIX43 DL_MATRIX43::DL_IDENTITY_MATRIX = 
        DL_MATRIX43(1.0f, 0.0f, 0.0f,
		            0.0f, 1.0f, 0.0f,
		            0.0f, 0.0f, 1.0f,
		            0.0f, 0.0f, 0.0f);

    DL_MATRIX44 DL_MATRIX44::DL_IDENTITY_MATRIX = 
        DL_MATRIX44(1.0f, 0.0f, 0.0f, 0.0f,
		            0.0f, 1.0f, 0.0f, 0.0f,
		            0.0f, 0.0f, 1.0f, 0.0f,
                    0.0f, 0.0f, 0.0f, 1.0f);

    DL_MATRIX22::DL_MATRIX22(DL_MATRIX44_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX43_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX34_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_MATRIX33_PARAMTYPE rhs) : m00(rhs.m00), m01(rhs.m01), m10(rhs.m10), m11(rhs.m11) {}
    DL_MATRIX22::DL_MATRIX22(const dl_float32* pf) { memcpy(m, pf, sizeof(dl_float32) * 4); }
    DL_MATRIX22::DL_MATRIX22(const dl_float32 _m[][2]) { memcpy(m, _m, sizeof(dl_float32) * 4); }
    DL_MATRIX22::DL_MATRIX22(dl_float32 _m00, dl_float32 _m01, dl_float32 _m10, dl_float32 _m11)
        : m00(_m00), m01(_m01), m10(_m10), m11(_m11) {}
    DL_MATRIX22::DL_MATRIX22(DL_VECTOR2_PARAMTYPE r0, DL_VECTOR2_PARAMTYPE r1) { R[0] = r0; R[1] = r1; }

    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m10 = rhs.m10; m11 = rhs.m11; return *this; }
    DL_MATRIX22& DL_MATRIX22::operator=(DL_MATRIX22_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }

    dl_float32& DL_MATRIX22::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX22::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR2& DL_MATRIX22::operator[](dl_int32 r) { return R[r]; }
    const DL_VECTOR2& DL_MATRIX22::operator[](dl_int32 r) const { return R[r]; }

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

    DL_VECTOR2& DL_MATRIX22::GetRow(dl_uint32 r) { return R[r]; }
    const DL_VECTOR2& DL_MATRIX22::GetRow(dl_uint32 r) const { return R[r]; }
    void DL_MATRIX22::GetRow(DL_VECTOR2& vOut, dl_uint32 r) const { vOut = R[r]; }
    DL_VECTOR2 DL_MATRIX22::GetCol(dl_uint32 c) const { return DL_VECTOR2(m[0][c], m[1][c]); }
    void DL_MATRIX22::GetCol(DL_VECTOR2& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; }

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
    DL_MATRIX33::DL_MATRIX33(DL_VECTOR3_PARAMTYPE r0, DL_VECTOR3_PARAMTYPE r1, DL_VECTOR3_PARAMTYPE r2) { R[0] = r0; R[1] = r1; R[2] = r2; }

    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX33_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX33& DL_MATRIX33::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = 0; m20 = 0; m21 = 0; m22 = 1.0f; return *this; }

    dl_float32& DL_MATRIX33::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX33::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR3& DL_MATRIX33::operator[](dl_int32 r) { return R[r]; }
    const DL_VECTOR3& DL_MATRIX33::operator[](dl_int32 r) const { return R[r]; }

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

    DL_VECTOR3& DL_MATRIX33::GetRow(dl_uint32 r) { return R[r]; }
    const DL_VECTOR3& DL_MATRIX33::GetRow(dl_uint32 r) const { return R[r]; }
    void DL_MATRIX33::GetRow(DL_VECTOR3& vOut, dl_uint32 r) const { vOut = R[r]; }
    DL_VECTOR3 DL_MATRIX33::GetCol(dl_uint32 c) const { return DL_VECTOR3(m[0][c], m[1][c], m[2][c]); }
    void DL_MATRIX33::GetCol(DL_VECTOR3& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; vOut.z = m[2][c]; }

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
    DL_MATRIX34::DL_MATRIX34(DL_VECTOR4AL_PARAMTYPE r0, DL_VECTOR4AL_PARAMTYPE r1, DL_VECTOR4AL_PARAMTYPE r2) { R[0] = r0; R[1] = r1; R[2] = r2; }

    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = rhs.m03; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = rhs.m13; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = rhs.m23; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX34_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; return *this; }
    DL_MATRIX34& DL_MATRIX34::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = 0; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = 0; m13 = 0; m20 = 0; m21 = 0; m22 = 1.0f; m23 = 0; return *this; }

    dl_float32& DL_MATRIX34::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX34::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR4AL& DL_MATRIX34::operator[](dl_int32 r) { return R[r]; }
    const DL_VECTOR4AL& DL_MATRIX34::operator[](dl_int32 r) const { return R[r]; }

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

    DL_VECTOR4AL& DL_MATRIX34::GetRow(dl_uint32 r) { return R[r]; }
    const DL_VECTOR4AL& DL_MATRIX34::GetRow(dl_uint32 r) const { return R[r]; }
    void DL_MATRIX34::GetRow(DL_VECTOR4AL& vOut, dl_uint32 r) const { vOut = R[r]; }
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
    DL_MATRIX43::DL_MATRIX43(DL_VECTOR4AL_PARAMTYPE c0, DL_VECTOR4AL_PARAMTYPE c1, DL_VECTOR4AL_PARAMTYPE c2) { C[0] = c0; C[1] = c1; C[2] = c2; }

    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX43_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX44_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20; m30 = rhs.m30; m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21; m31 = rhs.m31; m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22; m32 = rhs.m32; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20; m30 = 0; m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21; m31 = 0; m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22; m32 = 0; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = rhs.m20; m30 = 0; m01 = rhs.m01; m11 = rhs.m11; m21 = rhs.m21; m31 = 0; m02 = rhs.m02; m12 = rhs.m12; m22 = rhs.m22; m32 = 0; return *this; }
    DL_MATRIX43& DL_MATRIX43::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m10 = rhs.m10; m20 = 0; m30 = 0; m01 = rhs.m01; m11 = rhs.m11; m21 = 0; m31 = 0; m02 = 0; m12 = 0; m22 = 1.0f; m32 = 0; return *this; }

    dl_float32& DL_MATRIX43::operator()(dl_uint32 c, dl_uint32 r) { return m[c][r]; }
    const dl_float32& DL_MATRIX43::operator()(dl_uint32 c, dl_uint32 r) const { return m[c][r]; }
    DL_VECTOR4AL& DL_MATRIX43::operator[](dl_int32 c) { return C[c]; }
    const DL_VECTOR4AL& DL_MATRIX43::operator[](dl_int32 c) const { return C[c]; }

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
    DL_VECTOR4AL& DL_MATRIX43::GetCol(dl_uint32 c) { return C[c]; }
    const DL_VECTOR4AL& DL_MATRIX43::GetCol(dl_uint32 c) const { return C[c]; }
    void DL_MATRIX43::GetCol(DL_VECTOR4AL& vOut, dl_uint32 c) const { vOut = C[c]; }

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
    DL_MATRIX44::DL_MATRIX44(DL_VECTOR4AL_PARAMTYPE r0, DL_VECTOR4AL_PARAMTYPE r1, DL_VECTOR4AL_PARAMTYPE r2, DL_VECTOR4AL_PARAMTYPE r3) { R[0] = r0; R[1] = r1; R[2] = r2; R[3] = r3; }

    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX44_PARAMTYPE rhs) { memcpy(m, rhs.m, sizeof(m)); return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX43_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; m30 = rhs.m30; m31 = rhs.m31; m32 = rhs.m32; m33 = 1.0f; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX34_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = rhs.m03; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = rhs.m13; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = rhs.m23; m30 = 0; m31 = 0; m32 = 0; m33 = 1.0f; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX33_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = rhs.m02; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = rhs.m12; m13 = 0; m20 = rhs.m20; m21 = rhs.m21; m22 = rhs.m22; m23 = 0; m30 = 0; m31 = 0; m32 = 0; m33 = 1.0f; return *this; }
    DL_MATRIX44& DL_MATRIX44::operator=(DL_MATRIX22_PARAMTYPE rhs) { m00 = rhs.m00; m01 = rhs.m01; m02 = 0; m03 = 0; m10 = rhs.m10; m11 = rhs.m11; m12 = 0; m13 = 0; m20 = 0; m21 = 0; m22 = 1.0f; m23 = 0; m30 = 0; m31 = 0; m32 = 0; m33 = 1.0f; return *this; }

    dl_float32& DL_MATRIX44::operator()(dl_uint32 r, dl_uint32 c) { return m[r][c]; }
    const dl_float32& DL_MATRIX44::operator()(dl_uint32 r, dl_uint32 c) const { return m[r][c]; }
    DL_VECTOR4AL& DL_MATRIX44::operator[](dl_int32 r) { return R[r]; }
    const DL_VECTOR4AL& DL_MATRIX44::operator[](dl_int32 r) const { return R[r]; }

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

    DL_VECTOR4AL& DL_MATRIX44::GetRow(dl_uint32 r) { return R[r]; }
    const DL_VECTOR4AL& DL_MATRIX44::GetRow(dl_uint32 r) const { return R[r]; }
    void DL_MATRIX44::GetRow(DL_VECTOR4AL& vOut, dl_uint32 r) const { vOut = R[r]; }
    DL_VECTOR4AL DL_MATRIX44::GetCol(dl_uint32 c) const { return DL_VECTOR4AL(m[0][c], m[1][c], m[2][c], m[3][c]); }
    void DL_MATRIX44::GetCol(DL_VECTOR4AL& vOut, dl_uint32 c) const { vOut.x = m[0][c]; vOut.y = m[1][c]; vOut.z = m[2][c]; vOut.w = m[3][c]; }
}