#include "avatar_outfit.hpp"
#include "outfits.hpp"

namespace clr
{
    uintptr_t _avatar_outfit_get_option = 0;

    Outfit* AvatarOutfit::get_outfit(OutfitSlot slot)
    {
        if (!_avatar_outfit_get_option)
            return 0;

        uintptr_t res = ((uintptr_t(*)(uintptr_t, OutfitSlot, uint8_t))_avatar_outfit_get_option)(_this, slot, 0);

        if (!res)
            return 0;

        return get_outfit_by_ptr(res);
    }
}