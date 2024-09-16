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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Audio/SoundChannel.h>

#include <SFML/Audio/SoundStream.hpp>


////////////////////////////////////////////////////////////
// Internal structure of sfSoundStream
////////////////////////////////////////////////////////////
struct sfSoundStream : sf::SoundStream
{
public:
    sfSoundStream(sfSoundStreamGetDataCallback onGetData,
                  sfSoundStreamSeekCallback    onSeek,
                  unsigned int                 channelCount,
                  unsigned int                 sampleRate,
                  sfSoundChannel*              channelMapData,
                  size_t                       channelMapSize,
                  void*                        userData) :
    myGetDataCallback(onGetData),
    mySeekCallback(onSeek),
    myUserData(userData)
    {
        std::vector<sf::SoundChannel> channelMap(channelMapSize);
        for (std::size_t i = 0; i < channelMap.size(); ++i)
            channelMap[i] = static_cast<sf::SoundChannel>(channelMapData[i]);
        initialize(channelCount, sampleRate, channelMap);
    }

    mutable std::vector<sfSoundChannel> Channels;

private:
    bool onGetData(Chunk& data) override
    {
        sfSoundStreamChunk chunk = {nullptr, 0};
        bool               ok    = myGetDataCallback(&chunk, myUserData);

        data.samples     = chunk.samples;
        data.sampleCount = chunk.sampleCount;

        return ok;
    }

    void onSeek(sf::Time timeOffset) override
    {
        if (mySeekCallback)
        {
            sfTime time = {timeOffset.asMicroseconds()};
            mySeekCallback(time, myUserData);
        }
    }

    sfSoundStreamGetDataCallback myGetDataCallback;
    sfSoundStreamSeekCallback    mySeekCallback;
    void*                        myUserData;
};
