#include "dye_color.hpp"

#include <array>

#define DYE_COLOR_COUNT 73

namespace clr
{
    const std::array<const DyeColor, DYE_COLOR_COUNT>& get_dyes();
}