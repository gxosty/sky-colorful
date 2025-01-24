#include "main_menu.hpp"
#include "utils.hpp"
#include "widgets/image_button.hpp"
#include "widgets/color_circle_button.hpp"
#include "../sky/avatar.hpp"
#include "../sky/outfits.hpp"
#include "../sky/dye_colors.hpp"

#include <imgui/imgui.h>

namespace clr::ui::main_menu
{
    static struct __main_menu_state__
    {
        OutfitSlot active_slot = CLR_OUTFIT_SLOT_BODY;
        uint8_t selected_dye = 0; // which part of the outfit is being colored
    } state;

    void draw_outfit_slots()
    {
        using namespace clr::ui::widgets;

        const OutfitSlot slots[] = {
            CLR_OUTFIT_SLOT_BODY,
            CLR_OUTFIT_SLOT_FEET,
            CLR_OUTFIT_SLOT_MASK,
            CLR_OUTFIT_SLOT_FACE,
            CLR_OUTFIT_SLOT_NECK,
            CLR_OUTFIT_SLOT_HAIR,
            CLR_OUTFIT_SLOT_HAT,
            CLR_OUTFIT_SLOT_HORN,
            CLR_OUTFIT_SLOT_WING,
            CLR_OUTFIT_SLOT_PROP
        };

        ImGui::TableSetColumnIndex(0);

        for (int i = 0; i < 10; i++)
        {
            if (i == 5)
            {
                ImGui::TableSetColumnIndex(1);
            }

            OutfitSlot slot = slots[i];
            ClrImage outfit_icon;
            ImVec4 outfit_icon_color{1.0f, 1.0f, 1.0f, 1.0f};
            Outfit* outfit = avatar->get_avatar_outfit()->get_outfit(slot);

            if (outfit)
            {
                outfit_icon = get_sky_image(outfit->get_icon_name());
                auto& color = outfit->get_icon_color();
                outfit_icon_color.x = color.r * 1.4f;
                outfit_icon_color.y = color.g * 1.4f;
                outfit_icon_color.z = color.b * 1.4f;
                outfit_icon_color.w = color.a;
            }
            else
            {
                outfit_icon = get_sky_image("UiOutfitNone");
            }

            static constexpr int id_magic = 0x1f3ab2;
            ImGui::PushID(slot + id_magic);
            if (image_button("slot", outfit_icon, outfit_icon_color, ImVec2(0.0f, 0.0f), state.active_slot == slot))
            {
                state.active_slot = slot;
                Outfit* new_outfit = avatar->get_avatar_outfit()->get_outfit(slot);

                if (!new_outfit || !new_outfit->is_secondary_dyeable())
                {
                    state.selected_dye = 0;
                }
            }
            ImGui::PopID();
        }
    }

    inline void draw_dye_picker(bool is_secondary, int table_column_index, Outfit* outfit)
    {
        using namespace clr::ui::widgets;

        Color* outfit_color = nullptr;
        bool disabled = true;
        bool not_changed = true;
        const std::vector<const DyeColor*>& base_dyes = get_base_dyes();
        const DyeColor* dye_color = nullptr;
        uint8_t primary_dye = CLR_DYE_COLOR_NONE;
        uint8_t secondary_dye = CLR_DYE_COLOR_NONE;

        if (outfit)
        {
            if (state.selected_dye == 0)
            {
                outfit_color = &outfit->get_current_primary_dye();
                disabled = !outfit->is_primary_dyeable() || outfit->get_name().ends_with("_None");
            }
            else
            {
                outfit_color = &outfit->get_current_secondary_dye();
                disabled = !outfit->is_secondary_dyeable() || outfit->get_name().ends_with("_None");
            }
            if (
                ((state.selected_dye == 0) && outfit->is_primary_dye_changed()) ||
                ((state.selected_dye == 1) && outfit->is_secondary_dye_changed())
            ) {
                const DyeColor* _dye_color = outfit_color ? get_dye_by_color(*outfit_color) : nullptr;
                if (_dye_color)
                {
                    primary_dye = _dye_color->primary_dye;
                    secondary_dye = _dye_color->secondary_dye;

                    if (!is_secondary)
                    {
                        dye_color = get_base_dye_by_ids(primary_dye, CLR_DYE_COLOR_NONE);
                    }
                    else
                    {
                        dye_color = get_base_dye_by_ids(secondary_dye, CLR_DYE_COLOR_NONE);
                    }

                    not_changed = false;
                }
            }
            else
            {
                not_changed = true;
            }
        }

        if (is_secondary && (get_base_dye_by_ids(primary_dye, CLR_DYE_COLOR_NONE)->primary_dye == CLR_DYE_COLOR_NONE))
        {
            disabled = true;
        }

        ImGui::TableSetColumnIndex(table_column_index);
        for (int i = 0; i < base_dyes.size(); i++)
        {
            if (((base_dyes.size() + 1) / 2) == i)
            {
                ImGui::TableSetColumnIndex(table_column_index + 1);
            }

            ImVec4 color(
                base_dyes[i]->color.r * 2.2,
                base_dyes[i]->color.g * 2.2,
                base_dyes[i]->color.b * 2.2,
                1.0f
            );

            bool is_selected = dye_color && (dye_color->id == base_dyes[i]->id);
            bool is_clicked = false;

            static constexpr int id_magic = 0x51bdda;
            ImGui::PushID(i + id_magic + (is_secondary ? 100 : 0));
            if (i == CLR_DYE_COLOR_NONE)
            {
                ClrImage img = get_sky_image("UiOutfitNone");

                ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, dp(18));
                if (image_button("dye", img, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec2(0.0f, 0.0f), is_selected || not_changed))
                {
                    if (!is_secondary)
                    {
                        primary_dye = CLR_DYE_COLOR_NONE;
                        secondary_dye = CLR_DYE_COLOR_NONE;
                    }
                    else
                    {
                        secondary_dye = CLR_DYE_COLOR_NONE;
                    }

                    is_clicked = true;
                }
                ImGui::PopStyleVar();
            }
            else
            {
                if (color_circle_button("dye", color, ImVec2(0.0f, 0.0f), is_selected, disabled))
                {
                    if (!is_secondary)
                    {
                        primary_dye = base_dyes[i]->primary_dye;
                    }
                    else
                    {
                        secondary_dye = base_dyes[i]->primary_dye;
                    }

                    is_clicked = true;
                }
            }
            ImGui::PopID();

            if (is_clicked)
            {
                if ((primary_dye == CLR_DYE_COLOR_NONE) && (secondary_dye == CLR_DYE_COLOR_NONE))
                {
                    if (state.selected_dye == 0)
                    {
                        outfit->restore_primary_dye();
                    }
                    else
                    {
                        outfit->restore_secondary_dye();
                    }
                }
                else
                {
                    auto new_dye = get_dye_by_ids(primary_dye, secondary_dye);

                    if (state.selected_dye == 0)
                    {
                        outfit->set_current_primary_dye(new_dye->color);
                    }
                    else
                    {
                        outfit->set_current_secondary_dye(new_dye->color);
                    }
                }
            }
        }
    }

    void draw_content()
    {
        Outfit* outfit = avatar->get_avatar_outfit()->get_outfit(state.active_slot);
        ImGuiStyle& style = ImGui::GetStyle();

        if (ImGui::BeginTable("#dye_tabs", 2))
        {
            ImGui::TableSetupColumn("dyes11", ImGuiTableColumnFlags_WidthFixed, dp(36) * 2 + style.CellPadding.x * 2);
            ImGui::TableSetupColumn("dyes12", ImGuiTableColumnFlags_WidthFixed, dp(36) * 2 + style.CellPadding.x * 2);

            ImGui::TableNextRow();

            ImGui::TableSetColumnIndex(0);

            if (state.selected_dye == 0)
                ImGui::PushStyleColor(ImGuiCol_Button, style.Colors[ImGuiCol_ButtonHovered]);

            if (ImGui::Button("Primary", ImVec2(-0.1f, 0.0f)))
            {
                state.selected_dye = 0;
            }

            if (state.selected_dye == 0)
                ImGui::PopStyleColor();

            ImGui::TableSetColumnIndex(1);

            if (outfit && outfit->is_secondary_dyeable())
            {
                if (state.selected_dye == 1)
                    ImGui::PushStyleColor(ImGuiCol_Button, style.Colors[ImGuiCol_ButtonHovered]);

                if (ImGui::Button("Secondary", ImVec2(-0.1f, 0.0f)))
                {
                    state.selected_dye = 1;
                }

                if (state.selected_dye == 1)
                    ImGui::PopStyleColor();
            }

            ImGui::EndTable();
        }

        ImGui::Separator();

        if (ImGui::BeginTable("#dye_picker", 4))
        {
            ImGui::TableSetupColumn("dyes11", ImGuiTableColumnFlags_WidthFixed, dp(36));
            ImGui::TableSetupColumn("dyes12", ImGuiTableColumnFlags_WidthFixed, dp(36));
            ImGui::TableSetupColumn("dyes21", ImGuiTableColumnFlags_WidthFixed, dp(36));
            ImGui::TableSetupColumn("dyes22", ImGuiTableColumnFlags_WidthFixed, dp(36));

            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("1");
            ImGui::TableSetColumnIndex(2);
            ImGui::Text("2");

            ImGui::TableNextRow();
            draw_dye_picker(false, 0, outfit);
            draw_dye_picker(true, 2, outfit);

            ImGui::EndTable();
        }
    }

    void draw(bool* menu_open)
    {
        if (ImGui::BeginTable("#main_content", 3))
        {
            // ImGui::TableSetupColumn("outfit_slots", ImGuiTableColumnFlags_WidthFixed, 100);
            ImGui::TableSetupColumn("outfit_slots1", ImGuiTableColumnFlags_WidthFixed, dp(36));
            ImGui::TableSetupColumn("outfit_slots2", ImGuiTableColumnFlags_WidthFixed, dp(36));
            ImGui::TableSetupColumn("content", ImGuiTableColumnFlags_WidthStretch);

            ImGui::TableNextRow();

            draw_outfit_slots();

            ImGui::TableSetColumnIndex(2);
            draw_content();

            ImGui::EndTable();
        }
    }
}