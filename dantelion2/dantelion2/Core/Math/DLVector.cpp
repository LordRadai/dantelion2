#include <cmath>
#include <algorithm>

#include "DLVector.h"
#include "DLMatrix.h"

namespace DLMT
{
    namespace
    {
        template<typename T>
        constexpr const T& clamp(const T& v, const T& lo, const T& hi) {
            return (v < lo) ? lo : (hi < v) ? hi : v;
        }
    }

    DL_VECTOR2::DL_VECTOR2(const DL_VECTOR3& v) : x(v.x), y(v.y) {}
    DL_VECTOR2::DL_VECTOR2(const DL_VECTOR4& v) : x(v.x), y(v.y) {}

    dl_float32 DL_VECTOR2::Dot(const DL_VECTOR2& other) const
    {
        return this->x * other.x + this->y * other.y;
    }

    dl_float32 DL_VECTOR2::Cross(const DL_VECTOR2& other) const
    {
        return this->x * other.y - this->y * other.x;
    }

    dl_float32 DL_VECTOR2::Length() const
    {
        return sqrtf(this->x * this->x + this->y * this->y);
    }

    dl_float32 DL_VECTOR2::LengthSquared() const
    {
        return this->x * this->x + this->y * this->y;
    }

    DL_VECTOR2 DL_VECTOR2::Normalize() const
    {
        dl_float32 length = this->Length();

        if (length == 0.0f)
            return DL_VECTOR2(0.0f, 0.0f);

        return DL_VECTOR2(this->x / length, this->y / length);
    }

    dl_float32 DL_VECTOR2::DistanceTo(const DL_VECTOR2& other) const
    {
        return (*this - other).Length();
    }

    dl_float32 DL_VECTOR2::Angle() const
    {
        return atan2f(this->y, this->x);
    }

    dl_float32 DL_VECTOR2::AngleTo(const DL_VECTOR2& other) const
    {
        return atan2f(this->Cross(other), this->Dot(other));
    }

    DL_VECTOR2 DL_VECTOR2::Rotate(dl_float32 radians) const
    {
        dl_float32 c = cosf(radians);
        dl_float32 s = sinf(radians);

        return DL_VECTOR2(
            this->x * c - this->y * s,
            this->x * s + this->y * c
        );
    }

    DL_VECTOR2 DL_VECTOR2::Reflect(const DL_VECTOR2& normal) const
    {
        // R = V - 2 * dot(V, N) * N
        return *this - normal * (2.0f * this->Dot(normal));
    }

    DL_VECTOR2 DL_VECTOR2::Lerp(const DL_VECTOR2& other, dl_float32 t) const
    {
        return *this + (other - *this) * t;
    }

    DL_VECTOR2 DL_VECTOR2::Clamp(const DL_VECTOR2& min, const DL_VECTOR2& max) const
    {
        return DL_VECTOR2(
            clamp(this->x, min.x, max.x),
            clamp(this->y, min.y, max.y)
        );
    }

    DL_VECTOR2 DL_VECTOR2::Abs() const
    {
        return DL_VECTOR2(fabsf(this->x), fabsf(this->y));
    }

    bool DL_VECTOR2::IsNormalized(dl_float32 epsilon) const
    {
        return fabsf(this->LengthSquared() - 1.0f) <= epsilon;
    }

    bool DL_VECTOR2::IsZero(dl_float32 epsilon) const
    {
        return fabsf(this->x) <= epsilon && fabsf(this->y) <= epsilon;
    }

    bool DL_VECTOR2::Equals(const DL_VECTOR2& other, dl_float32 epsilon) const
    {
        return fabsf(this->x - other.x) <= epsilon && fabsf(this->y - other.y) <= epsilon;
    }

    DL_VECTOR2& DL_VECTOR2::operator+=(const DL_VECTOR2& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    DL_VECTOR2& DL_VECTOR2::operator-=(const DL_VECTOR2& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        return *this;
    }

    DL_VECTOR2& DL_VECTOR2::operator*=(dl_float32 scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        return *this;
    }

    DL_VECTOR2& DL_VECTOR2::operator/=(dl_float32 scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        return *this;
    }

    DL_VECTOR2 DL_VECTOR2::operator+(const DL_VECTOR2& other) const
    {
        return DL_VECTOR2(this->x + other.x, this->y + other.y);
    }

    DL_VECTOR2 DL_VECTOR2::operator-(const DL_VECTOR2& other) const
    {
        return DL_VECTOR2(this->x - other.x, this->y - other.y);
    }

    DL_VECTOR2 DL_VECTOR2::operator*(dl_float32 scalar) const
    {
        return DL_VECTOR2(this->x * scalar, this->y * scalar);
    }

    DL_VECTOR2 DL_VECTOR2::operator/(dl_float32 scalar) const
    {
        return DL_VECTOR2(this->x / scalar, this->y / scalar);
    }

    DL_VECTOR2 DL_VECTOR2::operator-() const
    {
        return DL_VECTOR2(-this->x, -this->y);
    }

    DL_VECTOR2 DL_VECTOR2::operator+() const
    {
        return *this;
    }

    DL_VECTOR2 DL_VECTOR2::operator*(const DL_MATRIX22& other) const
    {
        return DL_VECTOR2(
            this->x * other.m00 + this->y * other.m10,
            this->x * other.m01 + this->y * other.m11
        );
	}

    DL_VECTOR2 DL_VECTOR2::operator*(const DL_MATRIX33& other) const
    {
        return DL_VECTOR2(
            this->x * other.m00 + this->y * other.m10 + other.m20,
            this->x * other.m01 + this->y * other.m11 + other.m21
        );
	}

    DL_VECTOR2 DL_VECTOR2::operator*(const DL_MATRIX34& other) const
    {
        return DL_VECTOR2(
            this->x * other.m00 + this->y * other.m10 + other.m20,
            this->x * other.m01 + this->y * other.m11 + other.m21
        );
    }

    DL_VECTOR2 DL_VECTOR2::operator*(const DL_MATRIX44& other) const
    {
        return DL_VECTOR2(
            this->x * other.m00 + this->y * other.m10 + other.m20,
            this->x * other.m01 + this->y * other.m11 + other.m21
        );
	}

	DL_VECTOR2 DL_VECTOR2::operator*(const DL_MATRIX43& other) const
    {
        return DL_VECTOR2(
            this->x * other.m00 + this->y * other.m10 + other.m20,
            this->x * other.m01 + this->y * other.m11 + other.m21
        );
    }

    bool DL_VECTOR2::operator==(const DL_VECTOR2& other) const
    {
        return this->x == other.x && this->y == other.y;
    }

    bool DL_VECTOR2::operator!=(const DL_VECTOR2& other) const
    {
        return this->x != other.x || this->y != other.y;
    }

    DL_VECTOR2 operator*(dl_float32 scalar, const DL_VECTOR2& vec)
    {
        return DL_VECTOR2(scalar * vec.x, scalar * vec.y);
    }

    DL_VECTOR2 operator/(dl_float32 scalar, const DL_VECTOR2& vec)
    {
        return DL_VECTOR2(scalar / vec.x, scalar / vec.y);
    }

	DL_VECTOR3::DL_VECTOR3(const DL_VECTOR4& v) : x(v.x), y(v.y), z(v.z) {}

    dl_float32 DL_VECTOR3::Dot(const DL_VECTOR3& other) const
    {
        return this->x * other.x + this->y * other.y + this->z * other.z;
    }

    DL_VECTOR3 DL_VECTOR3::Cross(const DL_VECTOR3& other) const
    {
        return DL_VECTOR3(
            this->y * other.z - this->z * other.y,
            this->z * other.x - this->x * other.z,
            this->x * other.y - this->y * other.x
        );
    }

    dl_float32 DL_VECTOR3::Length() const
    {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z);
    }

    dl_float32 DL_VECTOR3::LengthSquared() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z;
    }

    DL_VECTOR3 DL_VECTOR3::Normalize() const
    {
        dl_float32 length = this->Length();

        if (length == 0.0f)
            return DL_VECTOR3(0.0f, 0.0f, 0.0f);

        return DL_VECTOR3(this->x / length, this->y / length, this->z / length);
    }

    dl_float32 DL_VECTOR3::DistanceTo(const DL_VECTOR3& other) const
    {
        return (*this - other).Length();
    }

    dl_float32 DL_VECTOR3::Angle() const
    {
        return atan2f(sqrtf(this->x * this->x + this->y * this->y), this->z);
    }

    dl_float32 DL_VECTOR3::AngleTo(const DL_VECTOR3& other) const
    {
        dl_float32 denom = this->Length() * other.Length();

        if (denom == 0.0f)
            return 0.0f;

        return acosf(clamp(this->Dot(other) / denom, -1.0f, 1.0f));
    }

    DL_VECTOR3 DL_VECTOR3::Rotate(const DL_VECTOR3& axis, dl_float32 radians) const
    {
        // Rodrigues' rotation formula
        // R(v) = v*cos(t) + (axis x v)*sin(t) + axis*(axis . v)*(1 - cos(t))
        dl_float32 c = cosf(radians);
        dl_float32 s = sinf(radians);
        dl_float32 dot = axis.Dot(*this);

        return *this * c + axis.Cross(*this) * s + axis * dot * (1.0f - c);
    }

    DL_VECTOR3 DL_VECTOR3::Reflect(const DL_VECTOR3& normal) const
    {
        return *this - normal * (2.0f * this->Dot(normal));
    }

    DL_VECTOR3 DL_VECTOR3::Lerp(const DL_VECTOR3& other, dl_float32 t) const
    {
        return *this + (other - *this) * t;
    }

    DL_VECTOR3 DL_VECTOR3::Clamp(const DL_VECTOR3& min, const DL_VECTOR3& max) const
    {
        return DL_VECTOR3(
            clamp(this->x, min.x, max.x),
            clamp(this->y, min.y, max.y),
            clamp(this->z, min.z, max.z)
        );
    }

    DL_VECTOR3 DL_VECTOR3::Abs() const
    {
        return DL_VECTOR3(fabsf(this->x), fabsf(this->y), fabsf(this->z));
    }

    DL_VECTOR2 DL_VECTOR3::ToVector2() const
    {
        return DL_VECTOR2(this->x, this->y);
    }

    bool DL_VECTOR3::IsNormalized(dl_float32 epsilon) const
    {
        return fabsf(this->LengthSquared() - 1.0f) <= epsilon;
    }

    bool DL_VECTOR3::IsZero(dl_float32 epsilon) const
    {
        return fabsf(this->x) <= epsilon && fabsf(this->y) <= epsilon && fabsf(this->z) <= epsilon;
    }

    bool DL_VECTOR3::Equals(const DL_VECTOR3& other, dl_float32 epsilon) const
    {
        return fabsf(this->x - other.x) <= epsilon
            && fabsf(this->y - other.y) <= epsilon
            && fabsf(this->z - other.z) <= epsilon;
    }

    DL_VECTOR3& DL_VECTOR3::operator+=(const DL_VECTOR3& other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        return *this;
    }

    DL_VECTOR3& DL_VECTOR3::operator-=(const DL_VECTOR3& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        return *this;
    }

    DL_VECTOR3& DL_VECTOR3::operator*=(dl_float32 scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        return *this;
    }

    DL_VECTOR3& DL_VECTOR3::operator/=(dl_float32 scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        return *this;
    }

    DL_VECTOR3 DL_VECTOR3::operator+(const DL_VECTOR3& other) const
    {
        return DL_VECTOR3(this->x + other.x, this->y + other.y, this->z + other.z);
    }

    DL_VECTOR3 DL_VECTOR3::operator-(const DL_VECTOR3& other) const
    {
        return DL_VECTOR3(this->x - other.x, this->y - other.y, this->z - other.z);
    }

    DL_VECTOR3 DL_VECTOR3::operator*(dl_float32 scalar) const
    {
        return DL_VECTOR3(this->x * scalar, this->y * scalar, this->z * scalar);
    }

    DL_VECTOR3 DL_VECTOR3::operator/(dl_float32 scalar) const
    {
        return DL_VECTOR3(this->x / scalar, this->y / scalar, this->z / scalar);
    }

    DL_VECTOR3 DL_VECTOR3::operator-() const
    {
        return DL_VECTOR3(-this->x, -this->y, -this->z);
    }

    DL_VECTOR3 DL_VECTOR3::operator+() const
    {
        return *this;
    }

    DL_VECTOR3 DL_VECTOR3::operator*(const DL_MATRIX33& other) const
    {
        return DL_VECTOR3(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22
        );
    }

    DL_VECTOR3 DL_VECTOR3::operator*(const DL_MATRIX34& other) const
    {
        return DL_VECTOR3(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22
        );
	}

    DL_VECTOR3 DL_VECTOR3::operator*(const DL_MATRIX44& other) const
    {
        return DL_VECTOR3(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22
        );
	}

    DL_VECTOR3 DL_VECTOR3::operator*(const DL_MATRIX43& other) const
    {
        return DL_VECTOR3(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22
        );
	}

    bool DL_VECTOR3::operator==(const DL_VECTOR3& other) const
    {
        return this->x == other.x && this->y == other.y && this->z == other.z;
    }

    bool DL_VECTOR3::operator!=(const DL_VECTOR3& other) const
    {
        return this->x != other.x || this->y != other.y || this->z != other.z;
    }

    DL_VECTOR3 operator*(dl_float32 scalar, const DL_VECTOR3& vec)
    {
        return DL_VECTOR3(scalar * vec.x, scalar * vec.y, scalar * vec.z);
    }

    DL_VECTOR3 operator/(dl_float32 scalar, const DL_VECTOR3& vec)
    {
        return DL_VECTOR3(scalar / vec.x, scalar / vec.y, scalar / vec.z);
    }

    dl_float32 DL_VECTOR4::Dot(const DL_VECTOR4& other) const
    {
        return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
    }

    dl_float32 DL_VECTOR4::Length() const
    {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    dl_float32 DL_VECTOR4::LengthSquared() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
    }

    DL_VECTOR4 DL_VECTOR4::Normalize() const
    {
        dl_float32 length = this->Length();

        if (length == 0.0f)
            return DL_VECTOR4(0.0f, 0.0f, 0.0f, 0.0f);

        return DL_VECTOR4(this->x / length, this->y / length, this->z / length, this->w / length);
    }

    dl_float32 DL_VECTOR4::DistanceTo(const DL_VECTOR4& other) const
    {
        return (*this - other).Length();
    }

    DL_VECTOR4 DL_VECTOR4::Lerp(const DL_VECTOR4& other, dl_float32 t) const
    {
        return *this + (other - *this) * t;
    }

    DL_VECTOR4 DL_VECTOR4::Clamp(const DL_VECTOR4& min, const DL_VECTOR4& max) const
    {
        return DL_VECTOR4(
            clamp(this->x, min.x, max.x),
            clamp(this->y, min.y, max.y),
            clamp(this->z, min.z, max.z),
            clamp(this->w, min.w, max.w)
        );
    }

    DL_VECTOR4 DL_VECTOR4::Abs() const
    {
        return DL_VECTOR4(fabsf(this->x), fabsf(this->y), fabsf(this->z), fabsf(this->w));
    }

    DL_VECTOR2 DL_VECTOR4::ToVector2() const
    {
        return DL_VECTOR2(this->x, this->y);
    }

    DL_VECTOR3 DL_VECTOR4::ToVector3() const
    {
        return DL_VECTOR3(this->x, this->y, this->z);
    }

    DL_VECTOR3 DL_VECTOR4::PerspectiveDivide() const
    {
        if (this->w == 0.0f)
            return DL_VECTOR3(this->x, this->y, this->z);

        return DL_VECTOR3(this->x / this->w, this->y / this->w, this->z / this->w);
    }

    bool DL_VECTOR4::IsNormalized(dl_float32 epsilon) const
    {
        return fabsf(this->LengthSquared() - 1.0f) <= epsilon;
    }

    bool DL_VECTOR4::IsZero(dl_float32 epsilon) const
    {
        return fabsf(this->x) <= epsilon && fabsf(this->y) <= epsilon
            && fabsf(this->z) <= epsilon && fabsf(this->w) <= epsilon;
    }

    bool DL_VECTOR4::Equals(const DL_VECTOR4& other, dl_float32 epsilon) const
    {
        return fabsf(this->x - other.x) <= epsilon
            && fabsf(this->y - other.y) <= epsilon
            && fabsf(this->z - other.z) <= epsilon
            && fabsf(this->w - other.w) <= epsilon;
    }

    DL_VECTOR4& DL_VECTOR4::operator+=(const DL_VECTOR4& other)
    {
        this->x += other.x;
        this->y += other.y;
        this->z += other.z;
        this->w += other.w;
        return *this;
    }

    DL_VECTOR4& DL_VECTOR4::operator-=(const DL_VECTOR4& other)
    {
        this->x -= other.x;
        this->y -= other.y;
        this->z -= other.z;
        this->w -= other.w;
        return *this;
    }

    DL_VECTOR4& DL_VECTOR4::operator*=(dl_float32 scalar)
    {
        this->x *= scalar;
        this->y *= scalar;
        this->z *= scalar;
        this->w *= scalar;
        return *this;
    }

    DL_VECTOR4& DL_VECTOR4::operator/=(dl_float32 scalar)
    {
        this->x /= scalar;
        this->y /= scalar;
        this->z /= scalar;
        this->w /= scalar;
        return *this;
    }

    DL_VECTOR4 DL_VECTOR4::operator+(const DL_VECTOR4& other) const
    {
        return DL_VECTOR4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
    }

    DL_VECTOR4 DL_VECTOR4::operator-(const DL_VECTOR4& other) const
    {
        return DL_VECTOR4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
    }

    DL_VECTOR4 DL_VECTOR4::operator*(dl_float32 scalar) const
    {
        return DL_VECTOR4(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
    }

    DL_VECTOR4 DL_VECTOR4::operator/(dl_float32 scalar) const
    {
        return DL_VECTOR4(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
    }

    DL_VECTOR4 DL_VECTOR4::operator-() const
    {
        return DL_VECTOR4(-this->x, -this->y, -this->z, -this->w);
    }

    DL_VECTOR4 DL_VECTOR4::operator+() const
    {
        return *this;
    }

    DL_VECTOR4 DL_VECTOR4::operator*(const DL_MATRIX22& other) const
    {
        return DL_VECTOR4(
            this->x * other.m00 + this->y * other.m10,
            this->x * other.m01 + this->y * other.m11,
            this->z,
            this->w
        );
    }

    DL_VECTOR4 DL_VECTOR4::operator*(const DL_MATRIX33& other) const
    {
        return DL_VECTOR4(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22,
            this->w
        );
	}

    DL_VECTOR4 DL_VECTOR4::operator*(const DL_MATRIX34& other) const
    {
        return DL_VECTOR4(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22,
            this->x * other.m03 + this->y * other.m13 + this->z * other.m23 + this->w * 1.f);
    }

    DL_VECTOR4 DL_VECTOR4::operator*(const DL_MATRIX44& other) const
    {
        return DL_VECTOR4(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20 + this->w * other.m30,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21 + this->w * other.m31,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22 + this->w * other.m32,
            this->x * other.m03 + this->y * other.m13 + this->z * other.m23 + this->w * other.m33
        );
	}

    DL_VECTOR4 DL_VECTOR4::operator*(const DL_MATRIX43& other) const
    {
        return DL_VECTOR4(
            this->x * other.m00 + this->y * other.m10 + this->z * other.m20 + this->w * other.m30,
            this->x * other.m01 + this->y * other.m11 + this->z * other.m21 + this->w * other.m31,
            this->x * other.m02 + this->y * other.m12 + this->z * other.m22 + this->w * other.m32,
            this->x * other.m30 + this->y * other.m31 + this->z * other.m32 + this->w * 1.f
		);
    }

    bool DL_VECTOR4::operator==(const DL_VECTOR4& other) const
    {
        return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
    }

    bool DL_VECTOR4::operator!=(const DL_VECTOR4& other) const
    {
        return this->x != other.x || this->y != other.y || this->z != other.z || this->w != other.w;
    }

    DL_VECTOR4 operator*(dl_float32 scalar, const DL_VECTOR4& vec)
    {
        return DL_VECTOR4(scalar * vec.x, scalar * vec.y, scalar * vec.z, scalar * vec.w);
    }

    DL_VECTOR4 operator/(dl_float32 scalar, const DL_VECTOR4& vec)
    {
        return DL_VECTOR4(scalar / vec.x, scalar / vec.y, scalar / vec.z, scalar / vec.w);
    }
}