#include "main_menu.hpp"
#include "../outfit_options.hpp"
#include "../sky/dye_color_defs.hpp"

#include <imgui/imgui.h>

namespace clr::ui::main_menu
{
    void draw(bool* menu_open)
    {
        ImGui::Text("MainMenu");
        auto outfit = clr::get_outfit_by_name("CharSkyKid_Wing_ClassicOne_Default");

        if (!outfit)
        {
            ImGui::Text("outfit == nullptr");
        }
        else
        {
            Color& color = outfit->get_current_primary_dye();
            ImGui::ColorEdit3("primary_dye", (float*)&color.r);
        }
    }
}