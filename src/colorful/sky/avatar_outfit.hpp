#pragma once

#include "outfit.hpp"

#include <cstdint>

namespace clr
{
    class AvatarOutfit
    {
    public:
        AvatarOutfit(uintptr_t thisptr) : _this{thisptr} {}

        // gets outfit option first and converts it to `Outfit`
        Outfit* get_outfit(OutfitSlot slot);

    private:
        uintptr_t _this;
    };
}