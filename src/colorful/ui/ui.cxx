#include "ui.hpp"
#include "main_menu.hpp"
#include "utils.hpp"

#include <Cipher/CipherUtils.h>
#include <imgui/imgui.h>

namespace clr::ui
{
    float density;

    void push_theme()
    {
        // Colors
        ImGui::PushStyleColor(ImGuiCol_TitleBg, 0xFF1D1E21);
        ImGui::PushStyleColor(ImGuiCol_TitleBgActive, 0xFF1D1E21);
        ImGui::PushStyleColor(ImGuiCol_TitleBgCollapsed, 0x3F1D1E21);

        ImGui::PushStyleColor(ImGuiCol_WindowBg, 0xFF1D1E21);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, 0xFF1D1E21);

        ImGui::PushStyleColor(ImGuiCol_Border, 0xFF272A35);
        ImGui::PushStyleColor(ImGuiCol_BorderShadow, 0xFF272A35);

        ImGui::PushStyleColor(ImGuiCol_Button, 0xFF272A35);
        ImGui::PushStyleColor(ImGuiCol_ButtonHovered, 0xFF0071FF);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, 0xFF0093FF);

        ImGui::PushStyleColor(ImGuiCol_ResizeGrip, 0xFF272A35);
        ImGui::PushStyleColor(ImGuiCol_ResizeGripHovered, 0xFF0071FF);
        ImGui::PushStyleColor(ImGuiCol_ResizeGripActive, 0xFF272A35);

        // Vars
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, dp(8));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, dp(8));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowTitleAlign, ImVec2(0.5f, 0.5f));

        ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(dp(8), dp(8)));
        ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, dp(8));

        ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(dp(4), dp(4)));
        ImGui::PushStyleVar(ImGuiStyleVar_ItemInnerSpacing, ImVec2(dp(4), dp(4)));
        ImGui::PushStyleVar(ImGuiStyleVar_CellPadding, ImVec2(dp(4), dp(4)));
    }

    void pop_theme()
    {
        ImGui::PopStyleColor(13);
        ImGui::PopStyleVar(8);
    }

    void draw(bool* menu_open)
    {
        push_theme();

        ImGuiStyle& style = ImGui::GetStyle();

        ImGui::SetNextWindowSize(ImVec2(
            style.WindowPadding.x * 2.0f + dp(216) + style.CellPadding.x * 15.0f,
            0.0f
        ), ImGuiCond_Once);
        if (ImGui::Begin("Colorful v" __LIB_VERSION__))
        {
            main_menu::draw(menu_open);
        } ImGui::End();

        pop_theme();
    }
}