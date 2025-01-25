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
            CLR_OUTFIT_SLOT_WING,
            CLR_OUTFIT_SLOT_HAIR,
            CLR_OUTFIT_SLOT_HAT,
            CLR_OUTFIT_SLOT_HORN
            // CLR_OUTFIT_SLOT_FACE
            // CLR_OUTFIT_SLOT_NECK
            // CLR_OUTFIT_SLOT_PROP
        };

        ImGui::TableSetColumnIndex(0);

        for (int i = 0; i < 7; i++)
        {
            if (i == 4)
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

    int draw_dye_picker(const char* label, bool disabled, bool changed, int selected_dye, bool is_secondary)
    {
        using namespace clr::ui::widgets;

        int res = -1;
        const std::vector<const DyeColor*>& base_dyes = get_base_dyes();

        if (ImGui::BeginTable(label, 2))
        {
            ImGui::TableSetupColumn("dye_left", ImGuiTableColumnFlags_WidthFixed, dp(36));
            ImGui::TableSetupColumn("dye_right", ImGuiTableColumnFlags_WidthFixed, dp(36));

            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);

            for (int i = 0; i < base_dyes.size(); i++)
            {
                if (i == 5)
                {
                    ImGui::TableSetColumnIndex(1);
                }

                bool is_selected = selected_dye == base_dyes[i]->primary_dye;

                static constexpr int id_magic = 0x51bda;
                ImGui::PushID(i + id_magic + (is_secondary ? 100 : 0));
                if (i == CLR_DYE_COLOR_NONE)
                {
                    ClrImage img = get_sky_image("UiOutfitNone");

                    ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, dp(18));
                    if (image_button("dye", img, ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec2(0.0f, 0.0f), is_selected || !changed))
                    {
                        res = CLR_DYE_COLOR_NONE;
                    }
                    ImGui::PopStyleVar();
                }
                else
                {
                    ImVec4 color(
                        base_dyes[i]->color.r * 2.2,
                        base_dyes[i]->color.g * 2.2,
                        base_dyes[i]->color.b * 2.2,
                        1.0f
                    );

                    if (color_circle_button("dye", color, ImVec2(0.0f, 0.0f), is_selected, disabled))
                    {
                        res = base_dyes[i]->primary_dye;
                    }
                }
                ImGui::PopID();
            }

            ImGui::EndTable();
        }

        return res;
    }

    inline bool draw_dye_picker11(Outfit* outfit, int* out)
    {
        const DyeColor* dye_color = nullptr;
        bool disabled = false;
        bool changed = false;

        if (!outfit || !outfit->is_primary_dyeable())
        {
            disabled = true;
        }
        else
        {
            changed = outfit->is_primary_dye_changed();
            const Color& current_primary_color = outfit->get_current_primary_dye();
            dye_color = get_dye_by_color(current_primary_color);

            if (out && dye_color)
            {
                *out = dye_color->primary_dye;
            }
        }

        int res = draw_dye_picker(
            "#dye_picker11",
            disabled,
            changed,
            dye_color ? dye_color->primary_dye : 0,
            false
        );

        if (res != -1)
        {
            if (out)
            {
                *out = res;
            }

            return true;
        }

        return false;
    }

    inline bool draw_dye_picker12(Outfit* outfit, int* out)
    {
        const DyeColor* dye_color = nullptr;
        bool disabled = false;
        bool changed = false;

        if (!outfit || !outfit->is_primary_dyeable() || !outfit->is_primary_dye_changed())
        {
            disabled = true;
        }
        else
        {
            changed = true;
            const Color& current_primary_color = outfit->get_current_primary_dye();
            dye_color = get_dye_by_color(current_primary_color);

            if (out && dye_color)
            {
                *out = dye_color->secondary_dye;
            }
        }

        int res = draw_dye_picker(
            "#dye_picker12",
            disabled,
            changed,
            dye_color ? dye_color->secondary_dye : 0,
            true
        );

        if (res != -1)
        {
            if (out)
            {
                *out = res;
            }

            return true;
        }

        return false;
    }

    inline bool draw_dye_picker21(Outfit* outfit, int* out)
    {
        const DyeColor* dye_color = nullptr;
        bool disabled = false;
        bool changed = false;

        if (!outfit || !outfit->is_secondary_dyeable())
        {
            disabled = true;
        }
        else
        {
            changed = outfit->is_secondary_dye_changed();
            const Color& current_secondary_color = outfit->get_current_secondary_dye();
            dye_color = get_dye_by_color(current_secondary_color);

            if (out && dye_color)
            {
                *out = dye_color->primary_dye;
            }
        }

        int res = draw_dye_picker(
            "#dye_picker21",
            disabled,
            changed,
            dye_color ? dye_color->primary_dye : 0,
            false
        );

        if (res != -1)
        {
            if (out)
            {
                *out = res;
            }

            return true;
        }

        return false;
    }

    inline bool draw_dye_picker22(Outfit* outfit, int* out)
    {
        const DyeColor* dye_color = nullptr;
        bool disabled = false;
        bool changed = false;

        if (!outfit || !outfit->is_secondary_dyeable() || !outfit->is_secondary_dye_changed())
        {
            disabled = true;
        }
        else
        {
            changed = true;
            const Color& current_secondary_color = outfit->get_current_secondary_dye();
            dye_color = get_dye_by_color(current_secondary_color);

            if (out && dye_color)
            {
                *out = dye_color->secondary_dye;
            }
        }

        int res = draw_dye_picker(
            "#dye_picker22",
            disabled,
            changed,
            dye_color ? dye_color->secondary_dye : 0,
            true
        );

        if (res != -1)
        {
            if (out)
            {
                *out = res;
            }

            return true;
        }

        return false;
    }

    void draw_content()
    {
        Outfit* outfit = avatar->get_avatar_outfit()->get_outfit(state.active_slot);
        ImGuiStyle& style = ImGui::GetStyle();

        if (ImGui::BeginTable("#dye_tabs", 2))
        {
            ImGui::TableSetupColumn("dyes1", ImGuiTableColumnFlags_WidthFixed, dp(36) * 2 + style.CellPadding.x * 2);
            ImGui::TableSetupColumn("dyes2", ImGuiTableColumnFlags_WidthFixed, dp(36) * 2 + style.CellPadding.x * 2);

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

        if (ImGui::BeginTable("#dye_pickers", 2))
        {
            ImGui::TableSetupColumn("dyes1", ImGuiTableColumnFlags_WidthFixed, dp(72) + style.CellPadding.x * 2);
            ImGui::TableSetupColumn("dyes2", ImGuiTableColumnFlags_WidthFixed, dp(72) + style.CellPadding.x * 2);

            ImGui::TableNextRow();
            ImGui::TableSetColumnIndex(0);
            ImGui::Text("1");
            ImGui::TableSetColumnIndex(1);
            ImGui::Text("2");

            ImGui::TableNextRow();

            int primary_dye = CLR_DYE_COLOR_NONE;
            int secondary_dye = CLR_DYE_COLOR_NONE;
            bool is_clicked = false;

            if (state.selected_dye == 0)
            {
                ImGui::TableSetColumnIndex(0);
                is_clicked |= draw_dye_picker11(outfit, &primary_dye);
                ImGui::TableSetColumnIndex(1);
                is_clicked |= draw_dye_picker12(outfit, &secondary_dye);
            }
            else
            {
                ImGui::TableSetColumnIndex(0);
                is_clicked |= draw_dye_picker21(outfit, &primary_dye);
                ImGui::TableSetColumnIndex(1);
                is_clicked |= draw_dye_picker22(outfit, &secondary_dye);
            }

            if (is_clicked)
            {
                if (primary_dye == CLR_DYE_COLOR_NONE)
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

            ImGui::EndTable();
        }
    }

    void draw_outfit_slot_name()
    {
        switch (state.active_slot)
        {
        case CLR_OUTFIT_SLOT_BODY:
            ImGui::SeparatorText("Pants");
            break;
        case CLR_OUTFIT_SLOT_FEET:
            ImGui::SeparatorText("Boots");
            break;
        case CLR_OUTFIT_SLOT_MASK:
            ImGui::SeparatorText("Masks");
            break;
        case CLR_OUTFIT_SLOT_WING:
            ImGui::SeparatorText("Capes");
            break;
        case CLR_OUTFIT_SLOT_HAIR:
            ImGui::SeparatorText("Hair");
            break;
        case CLR_OUTFIT_SLOT_HAT:
            ImGui::SeparatorText("Hat");
            break;
        case CLR_OUTFIT_SLOT_HORN:
            ImGui::SeparatorText("Horn");
            break;
        default:
            ImGui::SeparatorText("Unknown");
            break;
        }
    }

    void draw(bool* menu_open)
    {
        draw_outfit_slot_name();

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

        ImGui::TextColored(
            ImGui::GetStyle().Colors[ImGuiCol_Button],
            "by: gxost"
        );
    }

}