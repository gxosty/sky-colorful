#include "dye_color.hpp"

#include <array>
#include <vector>

#define CLR_DYE_COLOR_COUNT 73

namespace clr
{
    void dyes_initialize();
    const std::array<const DyeColor, CLR_DYE_COLOR_COUNT>& get_dyes();
    const std::vector<const DyeColor*>& get_base_dyes();
    const DyeColor* get_base_dye_by_ids(uint8_t primary_dye, uint8_t secondary_dye);
    const DyeColor* get_dye_by_color(const Color& color);
    const DyeColor* get_dye_by_ids(uint8_t primary_dye, uint8_t secondary_dye);
}