#pragma once

#include "color.hpp"

#include <cstdint>
#include <string>

// The ID of colors
#define CLR_DYE_COLOR_NONE    0
#define CLR_DYE_COLOR_RED     1
#define CLR_DYE_COLOR_YELLOW  2
#define CLR_DYE_COLOR_GREEN   3
#define CLR_DYE_COLOR_CYAN    4
#define CLR_DYE_COLOR_BLUE    5
#define CLR_DYE_COLOR_MAGENTA 6
#define CLR_DYE_COLOR_BLACK   7
#define CLR_DYE_COLOR_WHITE   8

namespace clr
{
    struct DyeColor
    {
        const char* name;
        uint8_t primary_dye;
        uint8_t secondary_dye;
        Color color;
        uint8_t id;
    };
}