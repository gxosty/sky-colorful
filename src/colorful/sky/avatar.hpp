#pragma once

#include "avatar_outfit.hpp"

#include <cstdint>

namespace clr
{
    class Avatar
    {
    public:
        Avatar(uintptr_t thisptr) : _this{thisptr} {}

        AvatarOutfit* get_avatar_outfit()
        {
            if (!_avatar_outfit)
            {
                _avatar_outfit = new AvatarOutfit(*(uintptr_t*)(_this + 88));
            }

            return _avatar_outfit;
        }

    private:
        uintptr_t _this;
        AvatarOutfit* _avatar_outfit = nullptr;
    };

    extern Avatar* avatar;
}