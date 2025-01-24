#pragma once

#include <string>
#include <Cipher/CipherUtils.h>
#include <iconloader/IconLoader.h>

#define CLR_SKY_IMAGE_TYPE_ICON 0
#define CLR_SKY_IMAGE_TYPE_IMAGE 1

namespace clr::ui
{
    struct ClrImage
    {
        ImTextureID texture_id;
        ImVec2 size;
        ImVec2 uv0;
        ImVec2 uv1;
        uint8_t type;
    };

    ClrImage get_sky_image(const std::string& name);

    bool is_item_pressed();

    inline float dp(float sz)
    {
        return CipherUtils::get_DeviceInfo().density * sz;
    }
}