#pragma once
#include "DLVector.h"

namespace DLMT
{
    class DL_QUATERNION
    {
    public:
        dl_float32 x;
        dl_float32 y;
        dl_float32 z;
        dl_float32 w;

        DL_QUATERNION() = default;
        DL_QUATERNION(dl_float32 x, dl_float32 y, dl_float32 z, dl_float32 w) : x(x), y(y), z(z), w(w) {}

        // Math operations
        dl_float32      Dot(const DL_QUATERNION& other) const;
        dl_float32      Length() const;
        dl_float32      LengthSquared() const;
        DL_QUATERNION   Normalize() const;
        DL_QUATERNION   Conjugate() const;
        DL_QUATERNION   Inverse() const;
        DL_QUATERNION   Lerp(const DL_QUATERNION& other, dl_float32 t) const;
        DL_QUATERNION   Slerp(const DL_QUATERNION& other, dl_float32 t) const;

        // Rotation
        DL_VECTOR3      RotateVector(const DL_VECTOR3& v) const;
        DL_VECTOR3      ToEulerAngles() const;
        dl_float32      GetAngle() const;
        DL_VECTOR3      GetAxis() const;

        // State checks
        bool            IsNormalized(dl_float32 epsilon = 1e-6f) const;
        bool            IsIdentity(dl_float32 epsilon = 1e-6f) const;
        bool            Equals(const DL_QUATERNION& other, dl_float32 epsilon = 1e-6f) const;

        // Static constructors
		static DL_QUATERNION Identity() { return DL_QUATERNION(0.0f, 0.0f, 0.0f, 1.0f); }
        static DL_QUATERNION FromAxisAngle(const DL_VECTOR3& axis, dl_float32 radians);
        static DL_QUATERNION FromEulerAngles(dl_float32 pitch, dl_float32 yaw, dl_float32 roll);
        static DL_QUATERNION FromEulerAngles(const DL_VECTOR3& euler);
        static DL_QUATERNION LookRotation(const DL_VECTOR3& forward, const DL_VECTOR3& up = DL_VECTOR3::Up());
        static DL_QUATERNION CreateReflection(const DL_VECTOR4& plane);

        // Operators
        DL_QUATERNION   operator*(const DL_QUATERNION& other) const;
        DL_QUATERNION& operator*=(const DL_QUATERNION& other);
        DL_QUATERNION   operator*(dl_float32 scalar) const;
        DL_QUATERNION   operator/(dl_float32 scalar) const;
        DL_QUATERNION   operator+(const DL_QUATERNION& other) const;
        DL_QUATERNION   operator-(const DL_QUATERNION& other) const;
        DL_QUATERNION   operator-() const;
        bool            operator==(const DL_QUATERNION& other) const;
        bool            operator!=(const DL_QUATERNION& other) const;
    };

    DL_QUATERNION operator*(dl_float32 scalar, const DL_QUATERNION& q);
}