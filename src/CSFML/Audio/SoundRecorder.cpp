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
#include <cstring>


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
    return soundRecorder->start(sampleRate);
}


////////////////////////////////////////////////////////////
void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);
    soundRecorder->stop();
}


////////////////////////////////////////////////////////////
unsigned int sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);
    return soundRecorder->getSampleRate();
}


////////////////////////////////////////////////////////////
bool sfSoundRecorder_isAvailable()
{
    return sf::SoundRecorder::isAvailable();
}


////////////////////////////////////////////////////////////
const char* const* sfSoundRecorder_getAvailableDevices(size_t* count)
{
    static const auto cstringDevices = []
    {
        static const std::vector<std::string> stringDevices = sf::SoundRecorder::getAvailableDevices();
        std::vector<const char*>              devices;
        devices.reserve(stringDevices.size());
        for (const auto& stringDevice : stringDevices)
            devices.push_back(stringDevice.c_str());
        return devices;
    }();

    if (count)
        *count = cstringDevices.size();

    return !cstringDevices.empty() ? cstringDevices.data() : nullptr;
}


////////////////////////////////////////////////////////////
const char* sfSoundRecorder_getDefaultDevice()
{
    static const std::string defaultDevice = sf::SoundRecorder::getDefaultDevice();

    return !defaultDevice.empty() ? defaultDevice.c_str() : nullptr;
}


////////////////////////////////////////////////////////////
bool sfSoundRecorder_setDevice(sfSoundRecorder* soundRecorder, const char* name)
{
    assert(soundRecorder);
    assert(name);
    return soundRecorder->setDevice(name);
}


////////////////////////////////////////////////////////////
const char* sfSoundRecorder_getDevice(sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);

    soundRecorder->DeviceName = soundRecorder->getDevice();

    return soundRecorder->DeviceName.c_str();
}


////////////////////////////////////////////////////////////
void sfSoundRecorder_setChannelCount(sfSoundRecorder* soundRecorder, unsigned int channelCount)
{
    assert(soundRecorder);
    soundRecorder->setChannelCount(channelCount);
}


////////////////////////////////////////////////////////////
unsigned int sfSoundRecorder_getChannelCount(const sfSoundRecorder* soundRecorder)
{
    assert(soundRecorder);
    return soundRecorder->getChannelCount();
}


////////////////////////////////////////////////////////////
sfSoundChannel* sfSoundRecorder_getChannelMap(const sfSoundRecorder* soundRecorder, size_t* count)
{
    assert(soundRecorder);
    assert(count);

    const auto channels = soundRecorder->getChannelMap();

    soundRecorder->Channels.resize(channels.size());
    std::memcpy(soundRecorder->Channels.data(), channels.data(), sizeof(sfSoundChannel) * channels.size());

    *count = soundRecorder->Channels.size();
    return soundRecorder->Channels.data();
}
