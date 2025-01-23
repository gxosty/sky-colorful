#pragma once

#include <cstdint>
#include <string>

namespace clr
{
    struct DyeColor
    {
        const char* name;
        const char* primary_dye;
        const char* secondary_dye;
        Color color;
        uint8_t id;
    };
}