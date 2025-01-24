#pragma once

#include "outfit.hpp"

#include <string>
#include <vector>

namespace clr
{
    const std::vector<Outfit>& get_outfits();
    Outfit* get_outfit_by_name(const std::string& name);
}