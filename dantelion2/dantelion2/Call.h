#pragma once
#include "Globals.h"

#define CALL(type, offset, ...) \
    (reinterpret_cast<type>((MODULE_ADDR) + (offset))(__VA_ARGS__))

#define VIRTUAL_CALL(obj, index, type, ...) \
    (reinterpret_cast<type>(((*reinterpret_cast<void***>(obj))[index])))(__VA_ARGS__)