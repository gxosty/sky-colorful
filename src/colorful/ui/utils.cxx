#include "utils.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_internal.h>

namespace clr::ui
{
    ClrImage get_sky_image(const std::string& name)
    {
        ClrImage img;

        UIIcon icon;
        IconLoader::getUIIcon(name, &icon);
        if (icon.textureId != IL_NO_TEXTURE)
        {
            img.texture_id = icon.textureId;
            img.uv0 = icon.uv0;
            img.uv1 = icon.uv1;
            img.size = {0.0f, 0.0f};
            img.type = CLR_SKY_IMAGE_TYPE_ICON;
            return img;
        }

        SkyImage sky_img = IconLoader::getImage(name);
        if (sky_img.textureId != IL_NO_TEXTURE)
        {
            img.texture_id = sky_img.textureId;
            img.size = sky_img.size;
            img.uv0 = {0.0f, 0.0f};
            img.uv1 = {1.0f, 1.0f};
            img.type = CLR_SKY_IMAGE_TYPE_IMAGE;
            return img;
        }

        img.texture_id = IL_NO_TEXTURE;
        return img;
    }

    bool is_item_pressed() {
        if (ImGui::IsItemActive()) {
            // if (ImGui::IsMouseDragging(0)) {
            //     ImGui::ClearActiveID();
            // } else {
                return true;
            // }
        }
        return false;
    }
}