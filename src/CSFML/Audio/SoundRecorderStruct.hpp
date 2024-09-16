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
#include <CSFML/Audio/SoundRecorder.h>

#include <SFML/Audio/SoundRecorder.hpp>


////////////////////////////////////////////////////////////
// Internal structure of sfSoundRecorder
////////////////////////////////////////////////////////////
struct sfSoundRecorder : sf::SoundRecorder
{
public:
    sfSoundRecorder(sfSoundRecorderStartCallback   onStart,
                    sfSoundRecorderProcessCallback onProcess,
                    sfSoundRecorderStopCallback    onStop,
                    void*                          userData) :
    myStartCallback(onStart),
    myProcessCallback(onProcess),
    myStopCallback(onStop),
    myUserData(userData)
    {
    }

    mutable std::vector<sfSoundChannel> Channels;
    std::string                         DeviceName;

private:
    bool onStart() override
    {
        if (myStartCallback)
            return myStartCallback(myUserData);
        else
            return true;
    }

    bool onProcessSamples(const std::int16_t* samples, std::size_t sampleCount) override
    {
        if (myProcessCallback)
            return myProcessCallback(samples, sampleCount, myUserData);
        else
            return true;
    }

    void onStop() override
    {
        if (myStopCallback)
            myStopCallback(myUserData);
    }

    sfSoundRecorderStartCallback   myStartCallback;
    sfSoundRecorderProcessCallback myProcessCallback;
    sfSoundRecorderStopCallback    myStopCallback;
    void*                          myUserData;
};
