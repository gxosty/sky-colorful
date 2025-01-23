#include "colorful.hpp"
#include "ui/ui.hpp"

#include "hooks.cxx"

namespace clr
{
    bool initialize()
    {
        bool res = hooks::initialize();

        if (!res)
        {
            return false;
        }

        return true;
    }

    void draw(bool* menu_open)
    {
        ui::draw(menu_open);
    }
}