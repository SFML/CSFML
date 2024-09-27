////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/Color.h>

#include <algorithm>


////////////////////////////////////////////////////////////
const sfColor sfBlack       = sfColor_fromRGB(0, 0, 0);
const sfColor sfWhite       = sfColor_fromRGB(255, 255, 255);
const sfColor sfRed         = sfColor_fromRGB(255, 0, 0);
const sfColor sfGreen       = sfColor_fromRGB(0, 255, 0);
const sfColor sfBlue        = sfColor_fromRGB(0, 0, 255);
const sfColor sfYellow      = sfColor_fromRGB(255, 255, 0);
const sfColor sfMagenta     = sfColor_fromRGB(255, 0, 255);
const sfColor sfCyan        = sfColor_fromRGB(0, 255, 255);
const sfColor sfTransparent = sfColor_fromRGBA(0, 0, 0, 0);


////////////////////////////////////////////////////////////
sfColor sfColor_fromRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    return {red, green, blue, 255};
}


////////////////////////////////////////////////////////////
sfColor sfColor_fromRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
    return {red, green, blue, alpha};
}


////////////////////////////////////////////////////////////
sfColor sfColor_fromInteger(uint32_t color)
{
    return {
        static_cast<uint8_t>((color & 0xff000000) >> 24),
        static_cast<uint8_t>((color & 0x00ff0000) >> 16),
        static_cast<uint8_t>((color & 0x0000ff00) >> 8),
        static_cast<uint8_t>((color & 0x000000ff) >> 0),
    };
}


////////////////////////////////////////////////////////////
uint32_t sfColor_toInteger(sfColor color)
{
    return static_cast<uint32_t>((color.r << 24) | (color.g << 16) | (color.b << 8) | color.a);
}


////////////////////////////////////////////////////////////
sfColor sfColor_add(sfColor color1, sfColor color2)
{
    return {
        static_cast<uint8_t>(std::min(color1.r + color2.r, 255)),
        static_cast<uint8_t>(std::min(color1.g + color2.g, 255)),
        static_cast<uint8_t>(std::min(color1.b + color2.b, 255)),
        static_cast<uint8_t>(std::min(color1.a + color2.a, 255)),
    };
}


////////////////////////////////////////////////////////////
sfColor sfColor_subtract(sfColor color1, sfColor color2)
{
    return {
        static_cast<uint8_t>(std::max(color1.r - color2.r, 0)),
        static_cast<uint8_t>(std::max(color1.g - color2.g, 0)),
        static_cast<uint8_t>(std::max(color1.b - color2.b, 0)),
        static_cast<uint8_t>(std::max(color1.a - color2.a, 0)),
    };
}


////////////////////////////////////////////////////////////
sfColor sfColor_modulate(sfColor color1, sfColor color2)
{
    return {
        static_cast<uint8_t>(color1.r * color2.r / 255),
        static_cast<uint8_t>(color1.g * color2.g / 255),
        static_cast<uint8_t>(color1.b * color2.b / 255),
        static_cast<uint8_t>(color1.a * color2.a / 255),
    };
}
