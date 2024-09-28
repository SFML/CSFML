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
#include <CSFML/Window/ConvertVideoMode.hpp>
#include <CSFML/Window/VideoMode.h>

#include <SFML/Window/VideoMode.hpp>


////////////////////////////////////////////////////////////
sfVideoMode sfVideoMode_getDesktopMode()
{
    return convertVideoMode(sf::VideoMode::getDesktopMode());
}


////////////////////////////////////////////////////////////
const sfVideoMode* sfVideoMode_getFullscreenModes(size_t* count)
{
    static const auto modes = []
    {
        std::vector<sfVideoMode> videomodes;
        for (const auto& mode : sf::VideoMode::getFullscreenModes())
            videomodes.push_back(convertVideoMode(mode));
        return videomodes;
    }();

    if (count)
        *count = modes.size();

    return !modes.empty() ? modes.data() : nullptr;
}


////////////////////////////////////////////////////////////
bool sfVideoMode_isValid(sfVideoMode mode)
{
    return convertVideoMode(mode).isValid();
}
