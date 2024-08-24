////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Window/VideoMode.h>
#include <SFML/Window/VideoMode.hpp>
#include <CSFML/Internal.hpp>


////////////////////////////////////////////////////////////
sfVideoMode sfVideoMode_getDesktopMode()
{
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    sfVideoMode ret;
    ret.width        = desktop.size.x;
    ret.height       = desktop.size.y;
    ret.bitsPerPixel = desktop.bitsPerPixel;

    return ret;
}


////////////////////////////////////////////////////////////
const sfVideoMode* sfVideoMode_getFullscreenModes(size_t* count)
{
    static std::vector<sfVideoMode> modes;

    // Populate the array on first call
    if (modes.empty())
    {
        const std::vector<sf::VideoMode>& sfmlModes = sf::VideoMode::getFullscreenModes();
        for (const auto& sfmlMode : sfmlModes)
        {
            sfVideoMode mode;
            mode.width        = sfmlMode.size.x;
            mode.height       = sfmlMode.size.y;
            mode.bitsPerPixel = sfmlMode.bitsPerPixel;
            modes.push_back(mode);
        }
    }

    if (count)
        *count = modes.size();

    return !modes.empty() ? modes.data() : nullptr;
}


////////////////////////////////////////////////////////////
bool sfVideoMode_isValid(sfVideoMode mode)
{
    sf::VideoMode videoMode({ mode.width, mode.height }, mode.bitsPerPixel);
    return videoMode.isValid();
}
