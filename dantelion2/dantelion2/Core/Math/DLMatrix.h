#pragma once
#include "Core/Platform/Platform.h"
#include "DLVector.h"
#include "DLQuaternion.h"
#include "DLColor.h"

namespace DLMT
{
	struct DL_MATRIX44;
	struct DL_MATRIX43;
	struct DL_MATRIX34;
	struct DL_MATRIX33;
	struct DL_MATRIX22;

    struct DL_MATRIX22
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE; 
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE; 
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE; 
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE; 
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE; 
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE; 
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE; 
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE; 
        typedef const DL_MATRIX34 DL_MATRIX34_PARAMTYPE; 
        typedef const DL_MATRIX43 DL_MATRIX43_PARAMTYPE; 
        typedef const DL_MATRIX44 DL_MATRIX44_PARAMTYPE; 
        typedef const DL_QUATERNION DL_QUATERNION_PARAMTYPE; 
        typedef const DL_COLOR_F4 DL_COLOR_F4_PARAMTYPE; 

        union
        {
            DL_VECTOR2 R[2];
            struct
            {
                dl_float32 m00, m01;
                dl_float32 m10, m11;
            };
            dl_float32 m[2][2];
        };

        DL_MATRIX22(void) {}
        explicit DL_MATRIX22(DL_MATRIX44_PARAMTYPE rhs);
        explicit DL_MATRIX22(DL_MATRIX43_PARAMTYPE rhs);
        explicit DL_MATRIX22(DL_MATRIX34_PARAMTYPE rhs);
        explicit DL_MATRIX22(DL_MATRIX33_PARAMTYPE rhs);
        explicit DL_MATRIX22(const dl_float32* pf);
        explicit DL_MATRIX22(const dl_float32 _m[][2]);
        DL_MATRIX22(dl_float32 _m00, dl_float32 _m01,
            dl_float32 _m10, dl_float32 _m11);
        DL_MATRIX22(DL_VECTOR2_PARAMTYPE r0, DL_VECTOR2_PARAMTYPE r1);
        ~DL_MATRIX22(void) {}

        DL_MATRIX22& operator = (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX22& operator = (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX22& operator = (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX22& operator = (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX22& operator = (DL_MATRIX22_PARAMTYPE rhs);

        dl_float32& operator () (dl_uint32 r, dl_uint32 c);
        const dl_float32& operator () (dl_uint32 r, dl_uint32 c) const;

        DL_VECTOR2& operator [] (dl_int32 r);
        const DL_VECTOR2& operator [] (dl_int32 r) const;

        DL_MATRIX22& operator *= (DL_MATRIX22_PARAMTYPE rhs);
        DL_MATRIX22& operator += (DL_MATRIX22_PARAMTYPE rhs);
        DL_MATRIX22& operator -= (DL_MATRIX22_PARAMTYPE rhs);
        DL_MATRIX22& operator *= (dl_float32 _s);
        DL_MATRIX22& operator /= (dl_float32 _s);

        DL_MATRIX22 operator + () const;
        DL_MATRIX22 operator - () const;

        DL_VECTOR2 operator * (DL_VECTOR2_PARAMTYPE _vec) const;
        DL_MATRIX22 operator * (DL_MATRIX22_PARAMTYPE rhs) const;
        DL_MATRIX22 operator + (DL_MATRIX22_PARAMTYPE rhs) const;
        DL_MATRIX22 operator - (DL_MATRIX22_PARAMTYPE rhs) const;
        DL_MATRIX22 operator * (dl_float32 _s) const;
        DL_MATRIX22 operator / (dl_float32 _s) const;

        friend DL_MATRIX22 operator * (dl_float32 _s, DL_MATRIX22_PARAMTYPE rhs);

        dl_bool operator == (DL_MATRIX22_PARAMTYPE rhs) const;
        dl_bool operator != (DL_MATRIX22_PARAMTYPE rhs) const;

        DL_VECTOR2& GetRow(dl_uint32 r);
        const DL_VECTOR2& GetRow(dl_uint32 r) const;
        void GetRow(DL_VECTOR2& vOut, dl_uint32 r) const;
        DL_VECTOR2 GetCol(dl_uint32 c) const;
        void GetCol(DL_VECTOR2& vOut, dl_uint32 c) const;
    };

    struct DL_MATRIX33
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE; 
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE; 
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE; 
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE; 
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE; 
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE; 
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE; 
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE; 
        typedef const DL_MATRIX34 DL_MATRIX34_PARAMTYPE; 
        typedef const DL_MATRIX43 DL_MATRIX43_PARAMTYPE; 
        typedef const DL_MATRIX44 DL_MATRIX44_PARAMTYPE; 
        typedef const DL_QUATERNION DL_QUATERNION_PARAMTYPE; 
        typedef const DL_COLOR_F4 DL_COLOR_F4_PARAMTYPE; 

        union
        {
            DL_VECTOR3 R[3];
            struct
            {
                dl_float32 m00, m01, m02;
                dl_float32 m10, m11, m12;
                dl_float32 m20, m21, m22;
            };
            dl_float32 m[3][3];
        };

        DL_MATRIX33(void) {}
        explicit DL_MATRIX33(DL_MATRIX44_PARAMTYPE rhs);
        explicit DL_MATRIX33(DL_MATRIX43_PARAMTYPE rhs);
        explicit DL_MATRIX33(DL_MATRIX34_PARAMTYPE rhs);
        explicit DL_MATRIX33(DL_MATRIX22_PARAMTYPE rhs);
        explicit DL_MATRIX33(const dl_float32* pf);
        explicit DL_MATRIX33(const dl_float32 _m[][3]);
        DL_MATRIX33(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02,
            dl_float32 _m10, dl_float32 _m11, dl_float32 _m12,
            dl_float32 _m20, dl_float32 _m21, dl_float32 _m22);
        DL_MATRIX33(DL_VECTOR3_PARAMTYPE r0,
            DL_VECTOR3_PARAMTYPE r1,
            DL_VECTOR3_PARAMTYPE r2);
        ~DL_MATRIX33(void) {}

        DL_MATRIX33& operator = (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX33& operator = (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX33& operator = (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX33& operator = (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX33& operator = (DL_MATRIX22_PARAMTYPE rhs);

        dl_float32& operator () (dl_uint32 r, dl_uint32 c);
        const dl_float32& operator () (dl_uint32 r, dl_uint32 c) const;

        DL_VECTOR3& operator [] (dl_int32 r);
        const DL_VECTOR3& operator [] (dl_int32 r) const;

        DL_MATRIX33& operator *= (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX33& operator += (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX33& operator -= (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX33& operator *= (dl_float32 _s);
        DL_MATRIX33& operator /= (dl_float32 _s);

        DL_MATRIX33 operator + () const;
        DL_MATRIX33 operator - () const;

        DL_VECTOR3 operator * (DL_VECTOR3_PARAMTYPE _vec) const;
        DL_VECTOR4AL operator * (DL_VECTOR4AL_PARAMTYPE _vec) const;
        DL_MATRIX33 operator * (DL_MATRIX33_PARAMTYPE rhs) const;
        DL_MATRIX33 operator + (DL_MATRIX33_PARAMTYPE rhs) const;
        DL_MATRIX33 operator - (DL_MATRIX33_PARAMTYPE rhs) const;
        DL_MATRIX33 operator * (dl_float32 _s) const;
        DL_MATRIX33 operator / (dl_float32 _s) const;

        friend DL_MATRIX33 operator * (dl_float32 _s, DL_MATRIX33_PARAMTYPE rhs);

        dl_bool operator == (DL_MATRIX33_PARAMTYPE rhs) const;
        dl_bool operator != (DL_MATRIX33_PARAMTYPE rhs) const;

        DL_VECTOR3& GetRow(dl_uint32 r);
        const DL_VECTOR3& GetRow(dl_uint32 r) const;
        void GetRow(DL_VECTOR3& vOut, dl_uint32 r) const;
        DL_VECTOR3 GetCol(dl_uint32 c) const;
        void GetCol(DL_VECTOR3& vOut, dl_uint32 c) const;
    };

    struct DL_MATRIX34
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE;
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE;
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE;
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE;
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE;
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE;
        typedef const DL_MATRIX34 DL_MATRIX34_PARAMTYPE;
        typedef const DL_MATRIX43 DL_MATRIX43_PARAMTYPE;
        typedef const DL_MATRIX44 DL_MATRIX44_PARAMTYPE;
        typedef const DL_QUATERNION DL_QUATERNION_PARAMTYPE;
        typedef const DL_COLOR_F4 DL_COLOR_F4_PARAMTYPE;

        union
        {
            DL_VECTOR4AL R[3];
            struct
            {
                dl_float32 m00, m01, m02, m03;
                dl_float32 m10, m11, m12, m13;
                dl_float32 m20, m21, m22, m23;
            };
            dl_float32 m[3][4];
        };

        DL_MATRIX34(void) {}
        DL_MATRIX34(const DL_MATRIX34& rhs);
        explicit DL_MATRIX34(DL_MATRIX44_PARAMTYPE rhs);
        explicit DL_MATRIX34(DL_MATRIX43_PARAMTYPE rhs);
        explicit DL_MATRIX34(DL_MATRIX33_PARAMTYPE rhs);
        explicit DL_MATRIX34(DL_MATRIX22_PARAMTYPE rhs);
        explicit DL_MATRIX34(const dl_float32* pf);
        explicit DL_MATRIX34(const dl_float32 _m[][4]);
        DL_MATRIX34(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02, dl_float32 _m03,
            dl_float32 _m10, dl_float32 _m11, dl_float32 _m12, dl_float32 _m13,
            dl_float32 _m20, dl_float32 _m21, dl_float32 _m22, dl_float32 _m23);
        DL_MATRIX34(DL_VECTOR4AL_PARAMTYPE r0,
            DL_VECTOR4AL_PARAMTYPE r1,
            DL_VECTOR4AL_PARAMTYPE r2);
        ~DL_MATRIX34(void) {}

        DL_MATRIX34& operator = (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX34& operator = (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX34& operator = (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX34& operator = (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX34& operator = (DL_MATRIX22_PARAMTYPE rhs);

        dl_float32& operator () (dl_uint32 r, dl_uint32 c);
        const dl_float32& operator () (dl_uint32 r, dl_uint32 c) const;

        DL_VECTOR4AL& operator [] (dl_int32 r);
        const DL_VECTOR4AL& operator [] (dl_int32 r) const;

        DL_MATRIX34& operator *= (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX34& operator += (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX34& operator -= (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX34& operator *= (dl_float32 _s);
        DL_MATRIX34& operator /= (dl_float32 _s);

        DL_MATRIX34 operator + () const;
        DL_MATRIX34 operator - () const;

        DL_VECTOR4AL operator * (DL_VECTOR4AL_PARAMTYPE _vec) const;
        DL_MATRIX34 operator * (DL_MATRIX34_PARAMTYPE rhs) const;
        DL_MATRIX34 operator + (DL_MATRIX34_PARAMTYPE rhs) const;
        DL_MATRIX34 operator - (DL_MATRIX34_PARAMTYPE rhs) const;
        DL_MATRIX34 operator * (dl_float32 _s) const;
        DL_MATRIX34 operator / (dl_float32 _s) const;

        friend DL_MATRIX34 operator * (dl_float32 _s, DL_MATRIX34_PARAMTYPE rhs);

        dl_bool operator == (DL_MATRIX34_PARAMTYPE rhs) const;
        dl_bool operator != (DL_MATRIX34_PARAMTYPE rhs) const;

        DL_VECTOR4AL& GetRow(dl_uint32 r);
        const DL_VECTOR4AL& GetRow(dl_uint32 r) const;
        void GetRow(DL_VECTOR4AL& vOut, dl_uint32 r) const;
        DL_VECTOR3AL GetCol(dl_uint32 c) const;
        void GetCol(DL_VECTOR3AL& vOut, dl_uint32 c) const;
    };

    struct DL_MATRIX43
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE;
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE;
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE;
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE;
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE;
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE;
        typedef const DL_MATRIX34 DL_MATRIX34_PARAMTYPE;
        typedef const DL_MATRIX43 DL_MATRIX43_PARAMTYPE;
        typedef const DL_MATRIX44 DL_MATRIX44_PARAMTYPE;
        typedef const DL_QUATERNION DL_QUATERNION_PARAMTYPE;
        typedef const DL_COLOR_F4 DL_COLOR_F4_PARAMTYPE;

        union
        {
            DL_VECTOR4AL C[3];
            struct
            {
                dl_float32 m00, m10, m20, m30;
                dl_float32 m01, m11, m21, m31;
                dl_float32 m02, m12, m22, m32;
            };
            dl_float32 m[3][4];
        };

        DL_MATRIX43(void) {}
        DL_MATRIX43(const DL_MATRIX43& rhs);
        explicit DL_MATRIX43(DL_MATRIX44_PARAMTYPE rhs);
        explicit DL_MATRIX43(DL_MATRIX34_PARAMTYPE rhs);
        explicit DL_MATRIX43(DL_MATRIX33_PARAMTYPE rhs);
        explicit DL_MATRIX43(DL_MATRIX22_PARAMTYPE rhs);
        explicit DL_MATRIX43(const dl_float32* pf);
        explicit DL_MATRIX43(const dl_float32 _m[][4]);
        DL_MATRIX43(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02,
            dl_float32 _m10, dl_float32 _m11, dl_float32 _m12,
            dl_float32 _m20, dl_float32 _m21, dl_float32 _m22,
            dl_float32 _m30, dl_float32 _m31, dl_float32 _m32);
        DL_MATRIX43(DL_VECTOR4AL_PARAMTYPE c0,
            DL_VECTOR4AL_PARAMTYPE c1,
            DL_VECTOR4AL_PARAMTYPE c2);
        ~DL_MATRIX43(void) {}

        DL_MATRIX43& operator = (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX43& operator = (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX43& operator = (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX43& operator = (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX43& operator = (DL_MATRIX22_PARAMTYPE rhs);

        dl_float32& operator () (dl_uint32 c, dl_uint32 r);
        const dl_float32& operator () (dl_uint32 c, dl_uint32 r) const;

        DL_VECTOR4AL& operator [] (dl_int32 c);
        const DL_VECTOR4AL& operator [] (dl_int32 c) const;

        DL_MATRIX43& operator *= (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX43& operator += (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX43& operator -= (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX43& operator *= (dl_float32 _s);
        DL_MATRIX43& operator /= (dl_float32 _s);

        DL_MATRIX43 operator + () const;
        DL_MATRIX43 operator - () const;

        DL_VECTOR4AL operator * (DL_VECTOR4AL_PARAMTYPE _vec) const;
        DL_MATRIX43 operator * (DL_MATRIX43_PARAMTYPE rhs) const;
        DL_MATRIX43 operator + (DL_MATRIX43_PARAMTYPE rhs) const;
        DL_MATRIX43 operator - (DL_MATRIX43_PARAMTYPE rhs) const;
        DL_MATRIX43 operator * (dl_float32 _s) const;
        DL_MATRIX43 operator / (dl_float32 _s) const;

        friend DL_MATRIX43 operator * (dl_float32 _s, DL_MATRIX43_PARAMTYPE rhs);

        dl_bool operator == (DL_MATRIX43_PARAMTYPE rhs) const;
        dl_bool operator != (DL_MATRIX43_PARAMTYPE rhs) const;

        DL_VECTOR3AL GetRow(dl_uint32 r) const;
        void GetRow(DL_VECTOR3AL& vOut, dl_uint32 r) const;
        DL_VECTOR4AL& GetCol(dl_uint32 c);
        const DL_VECTOR4AL& GetCol(dl_uint32 c) const;
        void GetCol(DL_VECTOR4AL& vOut, dl_uint32 c) const;
    };

    struct DL_MATRIX44
    {
        typedef const DL_VECTOR2& DL_VECTOR2_PARAMTYPE;
        typedef const DL_VECTOR3& DL_VECTOR3_PARAMTYPE;
        typedef const DL_VECTOR4& DL_VECTOR4_PARAMTYPE;
        typedef const DL_VECTOR2AL DL_VECTOR2AL_PARAMTYPE;
        typedef const DL_VECTOR3AL DL_VECTOR3AL_PARAMTYPE;
        typedef const DL_VECTOR4AL DL_VECTOR4AL_PARAMTYPE;
        typedef const DL_MATRIX22& DL_MATRIX22_PARAMTYPE;
        typedef const DL_MATRIX33& DL_MATRIX33_PARAMTYPE;
        typedef const DL_MATRIX34 DL_MATRIX34_PARAMTYPE;
        typedef const DL_MATRIX43 DL_MATRIX43_PARAMTYPE;
        typedef const DL_MATRIX44 DL_MATRIX44_PARAMTYPE;
        typedef const DL_QUATERNION DL_QUATERNION_PARAMTYPE;
        typedef const DL_COLOR_F4 DL_COLOR_F4_PARAMTYPE;

        union
        {
            DL_VECTOR4AL R[4];
            struct
            {
                dl_float32 m00, m01, m02, m03;
                dl_float32 m10, m11, m12, m13;
                dl_float32 m20, m21, m22, m23;
                dl_float32 m30, m31, m32, m33;
            };
            dl_float32 m[4][4];
        };

        DL_MATRIX44(void) {}
        DL_MATRIX44(const DL_MATRIX44& rhs);
        explicit DL_MATRIX44(DL_MATRIX43_PARAMTYPE rhs);
        explicit DL_MATRIX44(DL_MATRIX34_PARAMTYPE rhs);
        explicit DL_MATRIX44(DL_MATRIX33_PARAMTYPE rhs);
        explicit DL_MATRIX44(DL_MATRIX22_PARAMTYPE rhs);
        explicit DL_MATRIX44(const dl_float32* pf);
        explicit DL_MATRIX44(const dl_float32 _m[][4]);
        DL_MATRIX44(dl_float32 _m00, dl_float32 _m01, dl_float32 _m02, dl_float32 m03,
            dl_float32 _m10, dl_float32 _m11, dl_float32 _m12, dl_float32 m13,
            dl_float32 _m20, dl_float32 _m21, dl_float32 _m22, dl_float32 m23,
            dl_float32 _m30, dl_float32 _m31, dl_float32 _m32, dl_float32 m33);
        DL_MATRIX44(DL_VECTOR4AL_PARAMTYPE r0,
            DL_VECTOR4AL_PARAMTYPE r1,
            DL_VECTOR4AL_PARAMTYPE r2,
            DL_VECTOR4AL_PARAMTYPE r3);
        ~DL_MATRIX44(void) {}

        DL_MATRIX44& operator = (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX44& operator = (DL_MATRIX43_PARAMTYPE rhs);
        DL_MATRIX44& operator = (DL_MATRIX34_PARAMTYPE rhs);
        DL_MATRIX44& operator = (DL_MATRIX33_PARAMTYPE rhs);
        DL_MATRIX44& operator = (DL_MATRIX22_PARAMTYPE rhs);

        dl_float32& operator () (dl_uint32 r, dl_uint32 c);
        const dl_float32& operator () (dl_uint32 r, dl_uint32 c) const;

        DL_VECTOR4AL& operator [] (dl_int32 r);
        const DL_VECTOR4AL& operator [] (dl_int32 r) const;

        DL_MATRIX44& operator *= (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX44& operator += (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX44& operator -= (DL_MATRIX44_PARAMTYPE rhs);
        DL_MATRIX44& operator *= (dl_float32 _s);
        DL_MATRIX44& operator /= (dl_float32 _s);

        DL_MATRIX44 operator + () const;
        DL_MATRIX44 operator - () const;

        DL_VECTOR4AL operator * (DL_VECTOR4AL_PARAMTYPE _vec) const;
        DL_MATRIX44 operator * (DL_MATRIX44_PARAMTYPE rhs) const;
        DL_MATRIX44 operator + (DL_MATRIX44_PARAMTYPE rhs) const;
        DL_MATRIX44 operator - (DL_MATRIX44_PARAMTYPE rhs) const;
        DL_MATRIX44 operator * (dl_float32 _s) const;
        DL_MATRIX44 operator / (dl_float32 _s) const;

        friend DL_MATRIX44 operator * (dl_float32 _s, DL_MATRIX44_PARAMTYPE rhs);

        dl_bool operator == (DL_MATRIX44_PARAMTYPE rhs) const;
        dl_bool operator != (DL_MATRIX44_PARAMTYPE rhs) const;

        DL_VECTOR4AL& GetRow(dl_uint32 r);
        const DL_VECTOR4AL& GetRow(dl_uint32 r) const;
        void GetRow(DL_VECTOR4AL& vOut, dl_uint32 r) const;
        DL_VECTOR4AL GetCol(dl_uint32 c) const;
        void GetCol(DL_VECTOR4AL& vOut, dl_uint32 c) const;
    };
}