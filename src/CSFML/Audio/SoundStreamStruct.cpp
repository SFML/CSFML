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
#include <CSFML/Audio/SoundStreamStruct.hpp>

bool sfSoundStream::onLoopOriginal(sfSoundStream* music, uint64_t* position)
{
    auto result = music->sf::SoundStream::onLoop();

    if (!result)
    {
        return false;
    }

    *position = *result;
    return true;
}

std::optional<std::uint64_t> sfSoundStream::onLoop()
{
    if (!OnLoopMixin)
        return sf::SoundStream::onLoop();

    std::uint64_t data = 0;

    bool noLoop = OnLoopMixin(onLoopOriginal, this, &data);

    return noLoop ? std::nullopt : std::optional(data);
}