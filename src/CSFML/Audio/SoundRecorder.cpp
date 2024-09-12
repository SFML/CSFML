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
#include <CSFML/Audio/SoundRecorder.h>
#include <CSFML/Audio/SoundRecorderStruct.hpp>

#include <cassert>


////////////////////////////////////////////////////////////
sfSoundRecorder* sfSoundRecorder_create(sfSoundRecorderStartCallback   onStart,
                                        sfSoundRecorderProcessCallback onProcess,
                                        sfSoundRecorderStopCallback    onStop,
                                        void*                          userData)
{
    return new sfSoundRecorder(onStart, onProcess, onStop, userData);
}


////////////////////////////////////////////////////////////
void sfSoundRecorder_destroy(const sfSoundRecorder* soundRecorder)
{
    delete soundRecorder;
}


////////////////////////////////////////////////////////////
bool sfSoundRecorder_start(sfSoundRecorder* soundRecorder, unsigned int sampleRate)
{
    assert(soundRecorder);
    return soundRecorder->This.start(sampleRate);
}


////////////////////////////////////////////////////////////
void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);
    soundRecorder->This.stop();
}


////////////////////////////////////////////////////////////
unsigned int sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);
    return soundRecorder->This.getSampleRate();
}


////////////////////////////////////////////////////////////
bool sfSoundRecorder_isAvailable()
{
    return sf::SoundRecorder::isAvailable();
}


////////////////////////////////////////////////////////////
const char** sfSoundRecorder_getAvailableDevices(size_t* count)
{
    static std::vector<std::string> stringDevices = sf::SoundRecorder::getAvailableDevices();
    static std::vector<const char*> cstringDevices;

    if (cstringDevices.empty() && !stringDevices.empty())
    {
        for (const auto& stringDevice : stringDevices)
        {
            cstringDevices.push_back(stringDevice.c_str());
        }
    }

    if (count)
        *count = cstringDevices.size();

    return !cstringDevices.empty() ? cstringDevices.data() : nullptr;
}


////////////////////////////////////////////////////////////
const char* sfSoundRecorder_getDefaultDevice()
{
    static std::string defaultDevice = sf::SoundRecorder::getDefaultDevice();

    return !defaultDevice.empty() ? defaultDevice.c_str() : nullptr;
}


////////////////////////////////////////////////////////////
bool sfSoundRecorder_setDevice(sfSoundRecorder* soundRecorder, const char* name)
{
    assert(soundRecorder);
    return soundRecorder->This.setDevice(name);
}


////////////////////////////////////////////////////////////
const char* sfSoundRecorder_getDevice(sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);

    soundRecorder->DeviceName = soundRecorder->This.getDevice();

    return soundRecorder->DeviceName.c_str();
}


////////////////////////////////////////////////////////////
void sfSoundRecorder_setChannelCount(sfSoundRecorder* soundRecorder, unsigned int channelCount)
{
    assert(soundRecorder);
    soundRecorder->This.setChannelCount(channelCount);
}


////////////////////////////////////////////////////////////
unsigned int sfSoundRecorder_getChannelCount(const sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);
    return soundRecorder->This.getChannelCount();
}
