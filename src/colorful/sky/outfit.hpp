#pragma once

#include "outfit_option_offsets.hpp"
#include "color.hpp"
#include <misc/Logger.h>

#include <cstdint>
#include <string>

typedef uint32_t OutfitSlot;

#define CLR_OUTFIT_SLOT_BODY 0
#define CLR_OUTFIT_SLOT_WING 1
#define CLR_OUTFIT_SLOT_HAIR 2
#define CLR_OUTFIT_SLOT_MASK 3
#define CLR_OUTFIT_SLOT_NECK 4
#define CLR_OUTFIT_SLOT_FEET 5
#define CLR_OUTFIT_SLOT_HORN 6
#define CLR_OUTFIT_SLOT_ARMS 7
#define CLR_OUTFIT_SLOT_PROP 8
#define CLR_OUTFIT_SLOT_HAT  9
#define CLR_OUTFIT_SLOT_UNDEFINED -1
#define CLR_OUTFIT_SLOT_FACE CLR_OUTFIT_SLOT_UNDEFINED

namespace clr
{
    // Wrapper class for OutfitOption
    class Outfit
    {
    public:
        explicit Outfit(uintptr_t thisptr) : _this{thisptr}
        {
            _name = std::string(get_current_name());
            _icon_name = std::string(get_current_icon_name());
            _slot = CLR_OUTFIT_SLOT_UNDEFINED; // for now we don't need it
            _primary_dye = get_current_primary_dye();
            _secondary_dye = get_current_secondary_dye();
            _icon_color = get_current_icon_color();
            _dyeable_primary = *(uint8_t*)(_this + CLR_OO_DYEABLE_PRIMARY_OFFSET);
            _dyeable_secondary = *(uint8_t*)(_this + CLR_OO_DYEABLE_SECONDARY_OFFSET);
        }

        static OutfitSlot get_outfit_slot(const std::string& slot_type)
        {
            if (slot_type == "body") { return CLR_OUTFIT_SLOT_BODY; }
            if (slot_type == "wing") { return CLR_OUTFIT_SLOT_WING; }
            if (slot_type == "hair") { return CLR_OUTFIT_SLOT_HAIR; }
            if (slot_type == "mask") { return CLR_OUTFIT_SLOT_MASK; }
            if (slot_type == "neck") { return CLR_OUTFIT_SLOT_NECK; }
            if (slot_type == "feet") { return CLR_OUTFIT_SLOT_FEET; }
            if (slot_type == "horn") { return CLR_OUTFIT_SLOT_HORN; }
            if (slot_type == "arms") { return CLR_OUTFIT_SLOT_ARMS; }
            if (slot_type == "prop") { return CLR_OUTFIT_SLOT_PROP; }
            if (slot_type == "hat" ) { return CLR_OUTFIT_SLOT_HAT;  }

            return CLR_OUTFIT_SLOT_UNDEFINED;
        }

        uintptr_t get_ptr() const
        {
            return _this;
        }

        const std::string& get_name() const
        {
            return _name;
        }

        const std::string& get_icon_name() const
        {
            return _icon_name;
        }

        OutfitSlot get_slot() const
        {
            return _slot;
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

        const Color& get_icon_color() const
        {
            return _icon_color;
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

        const char* get_current_icon_name() const
        {
            if (*(char*)(_this + 89) == 0)
            {
                return *(char**)(_this + 104);
            }

            return (char*)(_this + 89);
        }

        Color& get_current_primary_dye() const
        {
            return *(Color*)(_this + CLR_OO_PRIMARY_DYE_OFFSET);
        }

        Color& get_current_secondary_dye() const
        {
            return *(Color*)(_this + CLR_OO_SECONDARY_DYE_OFFSET);
        }

        Color& get_current_icon_color() const
        {
            return *(Color*)(_this + CLR_OO_ICON_COLOR_OFFSET);
        }

    private:
        uintptr_t _this;

        std::string _name;
        OutfitSlot  _slot;

        Color       _primary_dye;
        Color       _secondary_dye;

        std::string _icon_name;
        Color       _icon_color;

        uint8_t     _dyeable_primary;
        uint8_t     _dyeable_secondary;
    };
}