#include "color_circle_button.hpp"

#include <imgui/imgui.h>

namespace clr::ui::widgets
{
    bool color_circle_button(
        const char* label,
        const ImVec4& color,
        const ImVec2& _size,
        bool active,
        bool disabled
    ) {
        bool is_clicked = false;
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImGuiStyle& style = ImGui::GetStyle();

        if (disabled)
        {
            active = false;
        }

        float radius = dp(18);

        ImVec2 pos = ImGui::GetCursorScreenPos();
        // for now `_size` does nothing
        ImVec2 size{
            radius * 2.0f,
            radius * 2.0f
        };

        ImVec2 center{
            pos.x + radius,
            pos.y + radius
        };

        if (ImGui::InvisibleButton(label, size) && !disabled)
        {
            is_clicked = true;
        }

        ImVec4 button_color = color;

        if (disabled)
        {
            button_color = ImVec4(
                button_color.x * 0.3f,
                button_color.y * 0.3f,
                button_color.z * 0.3f,
                button_color.w
            );
        }
        else if (is_item_pressed())
        {
            button_color = ImVec4(
                button_color.x + 0.1f,
                button_color.y + 0.1f,
                button_color.z + 0.1f,
                button_color.w
            );
        }

        draw_list->AddCircleFilled(
            center,
            radius,
            ImGui::ColorConvertFloat4ToU32(button_color)
        );

        if (active)
        {
            draw_list->AddCircle(
                center,
                radius,
                IM_COL32_WHITE,
                0,
                dp(2)
            );
        }

        return is_clicked;
    }
}