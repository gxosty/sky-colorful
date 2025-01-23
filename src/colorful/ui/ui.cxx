#include "ui.hpp"
#include "main_menu.hpp"

#include <imgui/imgui.h>

namespace clr::ui
{
    void push_theme()
    {

    }

    void pop_theme()
    {

    }

    void draw(bool* menu_open)
    {
        push_theme();

        if (ImGui::Begin("Colorful"))
        {
            main_menu::draw(menu_open);
        } ImGui::End();

        pop_theme();
    }
}