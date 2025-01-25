#include "image_button.hpp"

#include <imgui/imgui.h>

namespace clr::ui::widgets
{
    bool image_button(
        const char* label,
        const ClrImage& image,
        const ImVec4& tint_color,
        const ImVec2& _size,
        bool active
    ) {
        bool is_clicked = false;
        ImDrawList* draw_list = ImGui::GetWindowDrawList();
        ImGuiStyle& style = ImGui::GetStyle();

        ImVec2 pos = ImGui::GetCursorScreenPos();
        // for now `_size` does nothing
        ImVec2 size{
            dp(36),
            dp(36)
        };
        ImVec2 end_pos{
            pos.x + size.x,
            pos.y + size.y
        };

        ImVec2 image_pos{
            pos.x + dp(4),
            pos.y + dp(4)
        };

        ImVec2 image_end_pos{
            end_pos.x - dp(4),
            end_pos.y - dp(4)
        };

        if (ImGui::InvisibleButton(label, size))
        {
            is_clicked = true;
        }

        ImVec4 button_color = style.Colors[ImGuiCol_Button];

        if (is_item_pressed())
        {
            button_color = style.Colors[ImGuiCol_ButtonHovered];
        }

        draw_list->AddRectFilled(
            pos,
            end_pos,
            ImGui::ColorConvertFloat4ToU32(button_color),
            style.FrameRounding
        );

        if (active)
        {
            draw_list->AddRect(
                pos,
                end_pos,
                ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_ButtonActive]),
                style.FrameRounding,
                0,
                dp(1)
            );
        }

        draw_list->AddImage(
            image.texture_id,
            image_pos,
            image_end_pos,
            image.uv0,
            image.uv1,
            ImGui::ColorConvertFloat4ToU32(tint_color)
        );

        return is_clicked;
    }
}