#include "outfits.hpp"

namespace clr
{
    std::vector<Outfit> _outfits;

    const std::vector<Outfit>& get_outfits()
    {
        return _outfits;
    }

    Outfit* get_outfit_by_ptr(uintptr_t outfit_option_ptr)
    {
        for (auto& outfit : _outfits)
        {
            if (outfit.get_ptr() == outfit_option_ptr)
            {
                return &outfit;
            }
        }

        return nullptr;
    }

    Outfit* get_outfit_by_name(const std::string& name, OutfitSlot slot)
    {
        for (auto& outfit : _outfits)
        {
            if ((slot != -1) && (outfit.get_slot() != slot))
            {
                // small optimization
                continue;
            }

            if (outfit.get_name() == name)
            {
                return &outfit;
            }
        }

        return nullptr;
    }
}