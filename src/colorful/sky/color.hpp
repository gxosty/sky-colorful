#pragma once

namespace clr
{
    struct Color
    {
        float r, g, b, a;

        friend bool operator==(const Color& c1, const Color& c2)
        {
            return (
                (c1.r == c2.r) &&
                (c1.g == c2.g) &&
                (c1.b == c2.b) &&
                (c1.a == c2.a)
            );
        }
    };
}