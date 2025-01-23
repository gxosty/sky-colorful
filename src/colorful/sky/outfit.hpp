#pragma once

#include "outfit_option_offsets.hpp"
#include "color.hpp"
#include <misc/Logger.h>

#include <cstdint>
#include <string>

namespace clr
{
    // Wrapper class for OutfitOption
    class Outfit
    {
    public:
        explicit Outfit(uintptr_t thisptr) : _this{thisptr}
        {
            _name = std::string(get_current_name());
            _primary_dye = get_current_primary_dye();
            _secondary_dye = get_current_secondary_dye();
            _dyeable_primary = *(uint8_t*)(_this + OO_DYEABLE_PRIMARY_OFFSET);
            _dyeable_secondary = *(uint8_t*)(_this + OO_DYEABLE_SECONDARY_OFFSET);
            LOGD("Outfit created");
        }

        const std::string& get_name() const
        {
            return _name;
        }

        bool is_primary_dyeable() const
        {
            return _dyeable_primary != 0;
        }

        bool is_secondary_dyeable() const
        {
            return _dyeable_secondary != 0;
        }

        const Color& get_primary_dye() const
        {
            return _primary_dye;
        }

        const Color& get_secondary_dye() const
        {
            return _secondary_dye;
        }

        bool is_primary_dye_changed() const
        {
            return _primary_dye != get_current_primary_dye();
        }

        const char* get_current_name() const
        {
            if (*(char*)(_this + 17) == 0)
            {
                return *(char**)(_this + 32);
            }

            return (char*)(_this + 17);
        }

        Color& get_current_primary_dye() const
        {
            return *(Color*)(_this + OO_PRIMARY_DYE_OFFSET);
        }

        Color& get_current_secondary_dye() const
        {
            return *(Color*)(_this + OO_SECONDARY_DYE_OFFSET);
        }

    private:
        uintptr_t _this;

        std::string _name;
        Color   _primary_dye;
        Color   _secondary_dye;
        uint8_t _dyeable_primary;
        uint8_t _dyeable_secondary;
    };
}