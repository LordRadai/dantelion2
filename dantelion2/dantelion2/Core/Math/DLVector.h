#pragma once
#include "Core/Platform/Platform.h"

namespace DLMT
{
	struct DL_VECTOR3;
	struct DL_VECTOR4;

	struct DL_MATRIX22;
	struct DL_MATRIX33;
	struct DL_MATRIX34;
	struct DL_MATRIX43;
	struct DL_MATRIX44;

    struct DL_VECTOR2
    {
        union
        {
             struct { dl_float32 x, y; };
			 dl_float32 v[2];
        };

        DL_VECTOR2() = default;
        DL_VECTOR2(dl_float32 x, dl_float32 y) : x(x), y(y) {}
        DL_VECTOR2(const DL_VECTOR3& v);
        DL_VECTOR2(const DL_VECTOR4& v);

        // Math operations
        dl_float32   Dot(const DL_VECTOR2& other) const;
        dl_float32   Cross(const DL_VECTOR2& other) const;
        dl_float32   Length() const;
        dl_float32   LengthSquared() const;
        DL_VECTOR2   Normalize() const;
        dl_float32   DistanceTo(const DL_VECTOR2& other) const;
        dl_float32   Angle() const;
        dl_float32   AngleTo(const DL_VECTOR2& other) const;
        DL_VECTOR2   Rotate(dl_float32 radians) const;
        DL_VECTOR2   Reflect(const DL_VECTOR2& normal) const;
        DL_VECTOR2   Lerp(const DL_VECTOR2& other, dl_float32 t) const;
        DL_VECTOR2   Clamp(const DL_VECTOR2& min, const DL_VECTOR2& max) const;
        DL_VECTOR2   Abs() const;

        // State checks
        dl_bool         IsNormalized(dl_float32 epsilon = 1e-6f) const;
        dl_bool         IsZero(dl_float32 epsilon = 1e-6f) const;
        dl_bool         Equals(const DL_VECTOR2& other, dl_float32 epsilon = 1e-6f) const;

        // Static constants
		static DL_VECTOR2 Zero() { return DL_VECTOR2(0.0f, 0.0f); }
		static DL_VECTOR2 One() { return DL_VECTOR2(1.0f, 1.0f); }
		static DL_VECTOR2 Up() { return DL_VECTOR2(0.0f, 1.0f); }
		static DL_VECTOR2 Down() { return DL_VECTOR2(0.0f, -1.0f); }
		static DL_VECTOR2 Left() { return DL_VECTOR2(-1.0f, 0.0f); }
		static DL_VECTOR2 Right() { return DL_VECTOR2(1.0f, 0.0f); }

		static DL_VECTOR2 UnitX() { return DL_VECTOR2(1.0f, 0.0f); }
		static DL_VECTOR2 UnitY() { return DL_VECTOR2(0.0f, 1.0f); }

        // Compound assignment operators
        DL_VECTOR2& operator+=(const DL_VECTOR2& other);
        DL_VECTOR2& operator-=(const DL_VECTOR2& other);
        DL_VECTOR2& operator*=(dl_float32 scalar);
        DL_VECTOR2& operator/=(dl_float32 scalar);

        // Arithmetic operators
        DL_VECTOR2  operator+(const DL_VECTOR2& other) const;
        DL_VECTOR2  operator-(const DL_VECTOR2& other) const;
        DL_VECTOR2  operator*(dl_float32 scalar) const;
        DL_VECTOR2  operator/(dl_float32 scalar) const;
        DL_VECTOR2  operator-() const;
        DL_VECTOR2  operator+() const;

		DL_VECTOR2 operator*(const DL_MATRIX22& other) const;
		DL_VECTOR2 operator*(const DL_MATRIX33& other) const;
		DL_VECTOR2 operator*(const DL_MATRIX34& other) const;
		DL_VECTOR2 operator*(const DL_MATRIX44& other) const;
		DL_VECTOR2 operator*(const DL_MATRIX43& other) const;

        // Comparison operators
        dl_bool        operator==(const DL_VECTOR2& other) const;
        dl_bool        operator!=(const DL_VECTOR2& other) const;

        inline dl_float32& operator[](dl_uint32 index) { return v[index]; }
        inline const dl_float32& operator[](dl_uint32 index) const { return v[index]; }
    };

    // Free-function scalar operators
    DL_VECTOR2 operator*(dl_float32 scalar, const DL_VECTOR2& vec);
    DL_VECTOR2 operator/(dl_float32 scalar, const DL_VECTOR2& vec);

	__declspec(align(16))
	struct DL_VECTOR2AL : public DL_VECTOR2
    {
        DL_VECTOR2AL() = default;
		DL_VECTOR2AL(dl_float32 x, dl_float32 y) : DL_VECTOR2(x, y) {}
		DL_VECTOR2AL(DL_VECTOR2& vec) : DL_VECTOR2(vec) {}
	};

    struct DL_VECTOR3
    {
        union
        {
			struct { dl_float32 x, y, z; };
			dl_float32 v[3];
        };

        DL_VECTOR3() = default;
        DL_VECTOR3(dl_float32 x, dl_float32 y, dl_float32 z) : x(x), y(y), z(z) {}
        DL_VECTOR3(const DL_VECTOR4& v);

        explicit DL_VECTOR3(const DL_VECTOR2& v, dl_float32 z = 0.0f) : x(v.x), y(v.y), z(z) {}

        // Math operations
        dl_float32  Dot(const DL_VECTOR3& other) const;
        DL_VECTOR3  Cross(const DL_VECTOR3& other) const;
        dl_float32  Length() const;
        dl_float32  LengthSquared() const;
        DL_VECTOR3  Normalize() const;
        dl_float32  DistanceTo(const DL_VECTOR3& other) const;
        dl_float32  Angle() const;
        dl_float32  AngleTo(const DL_VECTOR3& other) const;
        DL_VECTOR3  Rotate(const DL_VECTOR3& axis, dl_float32 radians) const;
        DL_VECTOR3  Reflect(const DL_VECTOR3& normal) const;
        DL_VECTOR3  Lerp(const DL_VECTOR3& other, dl_float32 t) const;
        DL_VECTOR3  Clamp(const DL_VECTOR3& min, const DL_VECTOR3& max) const;
        DL_VECTOR3  Abs() const;

        // Conversion
        DL_VECTOR2  ToVector2() const;

        // State checks
        dl_bool        IsNormalized(dl_float32 epsilon = 1e-6f) const;
        dl_bool        IsZero(dl_float32 epsilon = 1e-6f) const;
        dl_bool        Equals(const DL_VECTOR3& other, dl_float32 epsilon = 1e-6f) const;

        // Static constants
		static DL_VECTOR3 Zero() { return DL_VECTOR3(0.0f, 0.0f, 0.0f); }
		static DL_VECTOR3 One() { return DL_VECTOR3(1.0f, 1.0f, 1.0f); }
		static DL_VECTOR3 Up() { return DL_VECTOR3(0.0f, 1.0f, 0.0f); }
		static DL_VECTOR3 Down() { return DL_VECTOR3(0.0f, -1.0f, 0.0f); }
		static DL_VECTOR3 Left() { return DL_VECTOR3(-1.0f, 0.0f, 0.0f); }
		static DL_VECTOR3 Right() { return DL_VECTOR3(1.0f, 0.0f, 0.0f); }
		static DL_VECTOR3 Forward() { return DL_VECTOR3(0.0f, 0.0f, 1.0f); }
		static DL_VECTOR3 Backward() { return DL_VECTOR3(0.0f, 0.0f, -1.0f); }

		static DL_VECTOR3 UnitX() { return DL_VECTOR3(1.0f, 0.0f, 0.0f); }
		static DL_VECTOR3 UnitY() { return DL_VECTOR3(0.0f, 1.0f, 0.0f); }
		static DL_VECTOR3 UnitZ() { return DL_VECTOR3(0.0f, 0.0f, 1.0f); }

        // Compound assignment operators
        DL_VECTOR3& operator+=(const DL_VECTOR3& other);
        DL_VECTOR3& operator-=(const DL_VECTOR3& other);
        DL_VECTOR3& operator*=(dl_float32 scalar);
        DL_VECTOR3& operator/=(dl_float32 scalar);

        // Arithmetic operators
        DL_VECTOR3  operator+(const DL_VECTOR3& other) const;
        DL_VECTOR3  operator-(const DL_VECTOR3& other) const;
        DL_VECTOR3  operator*(dl_float32 scalar) const;
        DL_VECTOR3  operator/(dl_float32 scalar) const;
        DL_VECTOR3  operator-() const;
        DL_VECTOR3  operator+() const;

        DL_VECTOR3 operator*(const DL_MATRIX22& other) const;
        DL_VECTOR3 operator*(const DL_MATRIX33& other) const;
        DL_VECTOR3 operator*(const DL_MATRIX34& other) const;
        DL_VECTOR3 operator*(const DL_MATRIX44& other) const;
        DL_VECTOR3 operator*(const DL_MATRIX43& other) const;

        // Comparison operators
        dl_bool        operator==(const DL_VECTOR3& other) const;
        dl_bool        operator!=(const DL_VECTOR3& other) const;

        inline dl_float32& operator[](dl_uint32 index) { return v[index]; }
        inline const dl_float32& operator[](dl_uint32 index) const { return v[index]; }
    };

    DL_VECTOR3 operator*(dl_float32 scalar, const DL_VECTOR3& vec);
    DL_VECTOR3 operator/(dl_float32 scalar, const DL_VECTOR3& vec);

	__declspec(align(16))
    struct DL_VECTOR3AL : public DL_VECTOR3
    {
        DL_VECTOR3AL() = default;
        DL_VECTOR3AL(dl_float32 x, dl_float32 y, dl_float32 z) : DL_VECTOR3(x, y, z) {}
        DL_VECTOR3AL(const DL_VECTOR3& vec) : DL_VECTOR3(vec) {}

		explicit DL_VECTOR3AL(const DL_VECTOR2& v, dl_float32 z = 0.0f) : DL_VECTOR3(v, z) {}
	};

    struct DL_VECTOR4
    {
        union
        {
			struct { dl_float32 x, y, z, w; };
			dl_float32 v[4];
        };

        DL_VECTOR4() = default;
        DL_VECTOR4(dl_float32 x, dl_float32 y, dl_float32 z, dl_float32 w) : x(x), y(y), z(z), w(w) {}

        explicit DL_VECTOR4(const DL_VECTOR2& v, dl_float32 z = 0.0f, dl_float32 w = 0.0f) : x(v.x), y(v.y), z(z), w(w) {}
        explicit DL_VECTOR4(const DL_VECTOR3& v, dl_float32 w = 0.0f) : x(v.x), y(v.y), z(v.z), w(w) {}

        // Math operations
        dl_float32  Dot(const DL_VECTOR4& other) const;
        dl_float32  Length() const;
        dl_float32  LengthSquared() const;
        DL_VECTOR4  Normalize() const;
        dl_float32  DistanceTo(const DL_VECTOR4& other) const;
        DL_VECTOR4  Lerp(const DL_VECTOR4& other, dl_float32 t) const;
        DL_VECTOR4  Clamp(const DL_VECTOR4& min, const DL_VECTOR4& max) const;
        DL_VECTOR4  Abs() const;

        // Conversion
        DL_VECTOR2  ToVector2() const;
        DL_VECTOR3  ToVector3() const;
        DL_VECTOR3  PerspectiveDivide() const;

        // State checks
        bool        IsNormalized(dl_float32 epsilon = 1e-6f) const;
        bool        IsZero(dl_float32 epsilon = 1e-6f) const;
        bool        Equals(const DL_VECTOR4& other, dl_float32 epsilon = 1e-6f) const;

        // Compound assignment operators
        DL_VECTOR4& operator+=(const DL_VECTOR4& other);
        DL_VECTOR4& operator-=(const DL_VECTOR4& other);
        DL_VECTOR4& operator*=(dl_float32 scalar);
        DL_VECTOR4& operator/=(dl_float32 scalar);

        // Arithmetic operators
        DL_VECTOR4  operator+(const DL_VECTOR4& other) const;
        DL_VECTOR4  operator-(const DL_VECTOR4& other) const;
        DL_VECTOR4  operator*(dl_float32 scalar) const;
        DL_VECTOR4  operator/(dl_float32 scalar) const;
        DL_VECTOR4  operator-() const;
        DL_VECTOR4  operator+() const;

        DL_VECTOR4 operator*(const DL_MATRIX22& other) const;
        DL_VECTOR4 operator*(const DL_MATRIX33& other) const;
        DL_VECTOR4 operator*(const DL_MATRIX34& other) const;
        DL_VECTOR4 operator*(const DL_MATRIX44& other) const;
        DL_VECTOR4 operator*(const DL_MATRIX43& other) const;

        // Comparison operators
        bool        operator==(const DL_VECTOR4& other) const;
        bool        operator!=(const DL_VECTOR4& other) const;

        inline dl_float32& operator[](dl_uint32 index) { return v[index]; }
        inline const dl_float32& operator[](dl_uint32 index) const { return v[index]; }
    };

    DL_VECTOR4 operator*(dl_float32 scalar, const DL_VECTOR4& vec);
    DL_VECTOR4 operator/(dl_float32 scalar, const DL_VECTOR4& vec);

	__declspec(align(16))
    struct DL_VECTOR4AL : public DL_VECTOR4
    {
		DL_VECTOR4AL() = default;
        DL_VECTOR4AL(dl_float32 x, dl_float32 y, dl_float32 z, dl_float32 w) : DL_VECTOR4(x, y, z, w) {}
        DL_VECTOR4AL(const DL_VECTOR4& vec) : DL_VECTOR4(vec) {}

        explicit DL_VECTOR4AL(const DL_VECTOR2& v, dl_float32 z = 0.0f, dl_float32 w = 0.0f) : DL_VECTOR4(v, z, w) {}
		explicit DL_VECTOR4AL(const DL_VECTOR3& v, dl_float32 w = 0.0f) : DL_VECTOR4(v, w) {}
	};

	static DL_VECTOR2 DL_VECTOR2_ZERO = DL_VECTOR2(0.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_ZERO = DL_VECTOR3(0.0f, 0.0f, 0.0f);
    static DL_VECTOR4 DL_VECTOR4_ZERO = DL_VECTOR4(0.0f, 0.0f, 0.0f, 0.0f);

	static DL_VECTOR2 DL_VECTOR2_ONE = DL_VECTOR2(1.0f, 1.0f);
	static DL_VECTOR3 DL_VECTOR3_ONE = DL_VECTOR3(1.0f, 1.0f, 1.0f);
	static DL_VECTOR4 DL_VECTOR4_ONE = DL_VECTOR4(1.0f, 1.0f, 1.0f, 1.0f);

	static DL_VECTOR3 DL_VECTOR3_UP = DL_VECTOR3(0.0f, 1.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_DOWN = DL_VECTOR3(0.0f, -1.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_LEFT = DL_VECTOR3(-1.0f, 0.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_RIGHT = DL_VECTOR3(1.0f, 0.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_FORWARD = DL_VECTOR3(0.0f, 0.0f, 1.0f);
	static DL_VECTOR3 DL_VECTOR3_BACKWARD = DL_VECTOR3(0.0f, 0.0f, -1.0f);

	static DL_VECTOR2 DL_VECTOR2_UNITX = DL_VECTOR2(1.0f, 0.0f);
	static DL_VECTOR2 DL_VECTOR2_UNITY = DL_VECTOR2(0.0f, 1.0f);

	static DL_VECTOR3 DL_VECTOR3_UNITX = DL_VECTOR3(1.0f, 0.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_UNITY = DL_VECTOR3(0.0f, 1.0f, 0.0f);
	static DL_VECTOR3 DL_VECTOR3_UNITZ = DL_VECTOR3(0.0f, 0.0f, 1.0f);

	static DL_VECTOR4 DL_VECTOR4_UNITX = DL_VECTOR4(1.0f, 0.0f, 0.0f, 0.0f);
	static DL_VECTOR4 DL_VECTOR4_UNITY = DL_VECTOR4(0.0f, 1.0f, 0.0f, 0.0f);
	static DL_VECTOR4 DL_VECTOR4_UNITZ = DL_VECTOR4(0.0f, 0.0f, 1.0f, 0.0f);
	static DL_VECTOR4 DL_VECTOR4_UNITW = DL_VECTOR4(0.0f, 0.0f, 0.0f, 1.0f);
}