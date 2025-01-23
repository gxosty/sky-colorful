#include "outfit_options.hpp"

namespace clr
{
    std::vector<Outfit> _outfits;

    const std::vector<Outfit>& get_outfits()
    {
        return _outfits;
    }

    Outfit* get_outfit_by_name(const std::string& name)
    {
        for (auto& outfit : _outfits)
        {
            if (outfit.get_name() == name)
            {
                return &outfit;
            }
        }

        return nullptr;
    }
}