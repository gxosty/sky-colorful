#include "colorful.hpp"
#include "ui/ui.hpp"
#include "sky/dye_colors.hpp"

#include "hooks.cxx"
#include "scans.cxx"

namespace clr
{
    bool initialize()
    {
        if (!hooks::initialize())
            return false;

        if (!scans::initialize())
            return false;

        dyes_initialize();

        return true;
    }

    void draw(bool* menu_open)
    {
        ui::draw(menu_open);
    }
}