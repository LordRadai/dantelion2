#pragma once
#include "Core/Platform/Platform.h"

namespace DLMT
{
    template <typename T>
    inline T DLClamp(T value, T min, T max) 
    {
        if (value < min) return min;
        if (value > max) return max;
        return value;
    }
}