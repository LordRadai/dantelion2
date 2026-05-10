#include <cmath>
#include <algorithm>
#include "DLQuaternion.h"

// -------------------------------------------------------------------------
// Math operations
// -------------------------------------------------------------------------

namespace DLMT
{
    namespace
    {
        template<typename T>
        constexpr const T& clamp(const T& v, const T& lo, const T& hi) {
            return (v < lo) ? lo : (hi < v) ? hi : v;
        }
    }

    dl_float32 DL_QUATERNION::Dot(const DL_QUATERNION& other) const
    {
        return this->x * other.x + this->y * other.y + this->z * other.z + this->w * other.w;
    }

    dl_float32 DL_QUATERNION::Length() const
    {
        return sqrtf(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
    }

    dl_float32 DL_QUATERNION::LengthSquared() const
    {
        return this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w;
    }

    DL_QUATERNION DL_QUATERNION::Normalize() const
    {
        dl_float32 length = this->Length();

        if (length == 0.0f)
            return DL_QUATERNION::Identity();

        return DL_QUATERNION(this->x / length, this->y / length, this->z / length, this->w / length);
    }

    DL_QUATERNION DL_QUATERNION::Conjugate() const
    {
        return DL_QUATERNION(-this->x, -this->y, -this->z, this->w);
    }

    DL_QUATERNION DL_QUATERNION::Inverse() const
    {
        dl_float32 lengthSq = this->LengthSquared();

        if (lengthSq == 0.0f)
            return DL_QUATERNION::Identity();

        return this->Conjugate() / lengthSq;
    }

    DL_QUATERNION DL_QUATERNION::Lerp(const DL_QUATERNION& other, dl_float32 t) const
    {
        // Ensure we lerp along the shortest path
        DL_QUATERNION target = this->Dot(other) < 0.0f ? -other : other;
        return DL_QUATERNION(
            this->x + (target.x - this->x) * t,
            this->y + (target.y - this->y) * t,
            this->z + (target.z - this->z) * t,
            this->w + (target.w - this->w) * t
        ).Normalize();
    }

    DL_QUATERNION DL_QUATERNION::Slerp(const DL_QUATERNION& other, dl_float32 t) const
    {
        dl_float32 dot = clamp(this->Dot(other), -1.0f, 1.0f);

        // Ensure shortest path
        DL_QUATERNION target = dot < 0.0f ? -other : other;
        if (dot < 0.0f) dot = -dot;

        // Fall back to lerp when quaternions are very close to avoid division by zero
        if (dot > 0.9995f)
            return this->Lerp(target, t);

        dl_float32 theta = acosf(dot);
        dl_float32 sinTheta = sinf(theta);

        dl_float32 a = sinf((1.0f - t) * theta) / sinTheta;
        dl_float32 b = sinf(t * theta) / sinTheta;

        return DL_QUATERNION(
            this->x * a + target.x * b,
            this->y * a + target.y * b,
            this->z * a + target.z * b,
            this->w * a + target.w * b
        );
    }

    // -------------------------------------------------------------------------
    // Rotation
    // -------------------------------------------------------------------------

    DL_VECTOR3 DL_QUATERNION::RotateVector(const DL_VECTOR3& v) const
    {
        // Optimised: v' = v + 2W(Q x v) + 2(Q x (Q x v))
        // where Q is the vector part of the quaternion
        DL_VECTOR3 q(this->x, this->y, this->z);
        DL_VECTOR3 t = q.Cross(v) * 2.0f;
        return v + t * this->w + q.Cross(t);
    }

    DL_VECTOR3 DL_QUATERNION::ToEulerAngles() const
    {
        DL_VECTOR3 euler;

        // Pitch (x)
        dl_float32 sinP = 2.0f * (this->w * this->x + this->y * this->z);
        dl_float32 cosP = 1.0f - 2.0f * (this->x * this->x + this->y * this->y);
        euler.x = atan2f(sinP, cosP);

        // Yaw (y)
        dl_float32 sinY = 2.0f * (this->w * this->y - this->z * this->x);
        sinY = clamp(sinY, -1.0f, 1.0f);
        euler.y = asinf(sinY);

        // Roll (z)
        dl_float32 sinR = 2.0f * (this->w * this->z + this->x * this->y);
        dl_float32 cosR = 1.0f - 2.0f * (this->y * this->y + this->z * this->z);
        euler.z = atan2f(sinR, cosR);

        return euler;
    }

    dl_float32 DL_QUATERNION::GetAngle() const
    {
        return 2.0f * acosf(clamp(this->w, -1.0f, 1.0f));
    }

    DL_VECTOR3 DL_QUATERNION::GetAxis() const
    {
        dl_float32 sinHalfAngle = sqrtf(1.0f - this->w * this->w);

        if (sinHalfAngle < 1e-6f)
            return DL_VECTOR3::Up();

        return DL_VECTOR3(this->x / sinHalfAngle, this->y / sinHalfAngle, this->z / sinHalfAngle);
    }

    // -------------------------------------------------------------------------
    // State checks
    // -------------------------------------------------------------------------

    bool DL_QUATERNION::IsNormalized(dl_float32 epsilon) const
    {
        return fabsf(this->LengthSquared() - 1.0f) <= epsilon;
    }

    bool DL_QUATERNION::IsIdentity(dl_float32 epsilon) const
    {
        return fabsf(this->x) <= epsilon
            && fabsf(this->y) <= epsilon
            && fabsf(this->z) <= epsilon
            && fabsf(this->w - 1.0f) <= epsilon;
    }

    bool DL_QUATERNION::Equals(const DL_QUATERNION& other, dl_float32 epsilon) const
    {
        // Two quaternions represent the same rotation if q == other or q == -other
        return (fabsf(this->x - other.x) <= epsilon
            && fabsf(this->y - other.y) <= epsilon
            && fabsf(this->z - other.z) <= epsilon
            && fabsf(this->w - other.w) <= epsilon)
            || (fabsf(this->x + other.x) <= epsilon
                && fabsf(this->y + other.y) <= epsilon
                && fabsf(this->z + other.z) <= epsilon
                && fabsf(this->w + other.w) <= epsilon);
    }

    // -------------------------------------------------------------------------
    // Static constructors
    // -------------------------------------------------------------------------

    DL_QUATERNION DL_QUATERNION::FromAxisAngle(const DL_VECTOR3& axis, dl_float32 radians)
    {
        dl_float32 halfAngle = radians * 0.5f;
        dl_float32 s = sinf(halfAngle);

        DL_VECTOR3 normalizedAxis = axis.Normalize();

        return DL_QUATERNION(
            normalizedAxis.x * s,
            normalizedAxis.y * s,
            normalizedAxis.z * s,
            cosf(halfAngle)
        );
    }

    DL_QUATERNION DL_QUATERNION::FromEulerAngles(dl_float32 pitch, dl_float32 yaw, dl_float32 roll)
    {
        dl_float32 halfPitch = pitch * 0.5f;
        dl_float32 halfYaw = yaw * 0.5f;
        dl_float32 halfRoll = roll * 0.5f;

        dl_float32 cp = cosf(halfPitch), sp = sinf(halfPitch);
        dl_float32 cy = cosf(halfYaw), sy = sinf(halfYaw);
        dl_float32 cr = cosf(halfRoll), sr = sinf(halfRoll);

        return DL_QUATERNION(
            cp * sy * sr + sp * cy * cr,  // x
            cp * sy * cr - sp * cy * sr,  // y  
            cp * cy * sr - sp * sy * cr,  // z -- note: some conventions negate these; adjust to match your coordinate system
            cp * cy * cr + sp * sy * sr   // w
        );
    }

    DL_QUATERNION DL_QUATERNION::FromEulerAngles(const DL_VECTOR3& euler)
    {
        return DL_QUATERNION::FromEulerAngles(euler.x, euler.y, euler.z);
    }

    DL_QUATERNION DL_QUATERNION::LookRotation(const DL_VECTOR3& forward, const DL_VECTOR3& up)
    {
        DL_VECTOR3 f = forward.Normalize();
        DL_VECTOR3 r = up.Cross(f).Normalize();
        DL_VECTOR3 u = f.Cross(r);

        dl_float32 trace = r.x + u.y + f.z;

        if (trace > 0.0f)
        {
            dl_float32 s = 0.5f / sqrtf(trace + 1.0f);
            return DL_QUATERNION(
                (u.z - f.y) * s,
                (f.x - r.z) * s,
                (r.y - u.x) * s,
                0.25f / s
            );
        }
        else if (r.x > u.y && r.x > f.z)
        {
            dl_float32 s = 2.0f * sqrtf(1.0f + r.x - u.y - f.z);
            return DL_QUATERNION(
                0.25f * s,
                (u.x + r.y) / s,
                (f.x + r.z) / s,
                (u.z - f.y) / s
            );
        }
        else if (u.y > f.z)
        {
            dl_float32 s = 2.0f * sqrtf(1.0f + u.y - r.x - f.z);
            return DL_QUATERNION(
                (u.x + r.y) / s,
                0.25f * s,
                (f.y + u.z) / s,
                (f.x - r.z) / s
            );
        }
        else
        {
            dl_float32 s = 2.0f * sqrtf(1.0f + f.z - r.x - u.y);
            return DL_QUATERNION(
                (f.x + r.z) / s,
                (f.y + u.z) / s,
                0.25f * s,
                (r.y - u.x) / s
            );
        }
    }

    // -------------------------------------------------------------------------
    // Operators
    // -------------------------------------------------------------------------

    DL_QUATERNION DL_QUATERNION::operator*(const DL_QUATERNION& other) const
    {
        return DL_QUATERNION(
            this->w * other.x + this->x * other.w + this->y * other.z - this->z * other.y,
            this->w * other.y - this->x * other.z + this->y * other.w + this->z * other.x,
            this->w * other.z + this->x * other.y - this->y * other.x + this->z * other.w,
            this->w * other.w - this->x * other.x - this->y * other.y - this->z * other.z
        );
    }

    DL_QUATERNION& DL_QUATERNION::operator*=(const DL_QUATERNION& other)
    {
        *this = *this * other;
        return *this;
    }

    DL_QUATERNION DL_QUATERNION::operator*(dl_float32 scalar) const
    {
        return DL_QUATERNION(this->x * scalar, this->y * scalar, this->z * scalar, this->w * scalar);
    }

    DL_QUATERNION DL_QUATERNION::operator/(dl_float32 scalar) const
    {
        return DL_QUATERNION(this->x / scalar, this->y / scalar, this->z / scalar, this->w / scalar);
    }

    DL_QUATERNION DL_QUATERNION::operator+(const DL_QUATERNION& other) const
    {
        return DL_QUATERNION(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
    }

    DL_QUATERNION DL_QUATERNION::operator-(const DL_QUATERNION& other) const
    {
        return DL_QUATERNION(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
    }

    DL_QUATERNION DL_QUATERNION::operator-() const
    {
        return DL_QUATERNION(-this->x, -this->y, -this->z, -this->w);
    }

    bool DL_QUATERNION::operator==(const DL_QUATERNION& other) const
    {
        return this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w;
    }

    bool DL_QUATERNION::operator!=(const DL_QUATERNION& other) const
    {
        return this->x != other.x || this->y != other.y || this->z != other.z || this->w != other.w;
    }

    // -------------------------------------------------------------------------
    // Free-function scalar operators
    // -------------------------------------------------------------------------

    DL_QUATERNION operator*(dl_float32 scalar, const DL_QUATERNION& q)
    {
        return DL_QUATERNION(scalar * q.x, scalar * q.y, scalar * q.z, scalar * q.w);
    }
}