#pragma once

#include "../utils.hpp"

namespace clr::ui::widgets
{
    bool image_button(
        const char* label,
        const ClrImage& image,
        const ImVec4& tint_color = ImVec4(1.0f, 1.0f, 1.0f, 1.0f),
        const ImVec2& size = ImVec2(0.0f, 0.0f),
        bool active = false
    );
}