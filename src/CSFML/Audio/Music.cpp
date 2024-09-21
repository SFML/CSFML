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
#include <CSFML/Audio/ConvertCone.hpp>
#include <CSFML/Audio/Music.h>
#include <CSFML/Audio/MusicStruct.hpp>
#include <CSFML/System/ConvertVector3.hpp>

#include <SFML/Audio/SoundChannel.hpp>

#include <cstring>

////////////////////////////////////////////////////////////
sfMusic* sfMusic_createFromFile(const char* filename)
{
    assert(filename);

    sf::Music music;
    if (!music.openFromFile(filename))
        return nullptr;

    return new sfMusic{std::move(music), {}, {}};
}


////////////////////////////////////////////////////////////
sfMusic* sfMusic_createFromMemory(const void* data, size_t sizeInBytes)
{
    sf::Music music;
    if (!music.openFromMemory(data, sizeInBytes))
        return nullptr;

    return new sfMusic{std::move(music), {}, {}};
}


////////////////////////////////////////////////////////////
sfMusic* sfMusic_createFromStream(sfInputStream* stream)
{
    assert(stream);

    auto music = std::make_unique<sfMusic>(sfMusic{{}, {}, {stream}});
    if (!music->This.openFromStream(music->Stream))
        return nullptr;

    return music.release();
}


////////////////////////////////////////////////////////////
void sfMusic_destroy(const sfMusic* music)
{
    delete music;
}


////////////////////////////////////////////////////////////
void sfMusic_setLooping(sfMusic* music, bool loop)
{
    assert(music);
    music->This.setLooping(loop != 0);
}


////////////////////////////////////////////////////////////
bool sfMusic_isLooping(const sfMusic* music)
{
    assert(music);
    return music->This.isLooping();
}


////////////////////////////////////////////////////////////
void sfMusic_setEffectProcessor(sfMusic* music, sfEffectProcessor effectProcessor)
{
    assert(music);

    if (!effectProcessor)
    {
        music->This.setEffectProcessor(nullptr);
    }
    else
    {
        music->This.setEffectProcessor(
            [effectProcessor](const float*  inputFrames,
                              unsigned int& inputFrameCount,
                              float*        outputFrames,
                              unsigned int& outputFrameCount,
                              unsigned int  frameChannelCount)
            { effectProcessor(inputFrames, &inputFrameCount, outputFrames, &outputFrameCount, frameChannelCount); });
    }
}


////////////////////////////////////////////////////////////
sfTime sfMusic_getDuration(const sfMusic* music)
{
    assert(music);
    return {music->This.getDuration().asMicroseconds()};
}


////////////////////////////////////////////////////////////
sfTimeSpan sfMusic_getLoopPoints(const sfMusic* music)
{
    assert(music);
    const auto [offset, length] = music->This.getLoopPoints();
    return {{offset.asMicroseconds()}, {length.asMicroseconds()}};
}


////////////////////////////////////////////////////////////
void sfMusic_setLoopPoints(sfMusic* music, sfTimeSpan timePoints)
{
    assert(music);
    music->This.setLoopPoints(
        {sf::microseconds(timePoints.offset.microseconds), sf::microseconds(timePoints.length.microseconds)});
}


////////////////////////////////////////////////////////////
void sfMusic_play(sfMusic* music)
{
    assert(music);
    music->This.play();
}


////////////////////////////////////////////////////////////
void sfMusic_pause(sfMusic* music)
{
    assert(music);
    music->This.pause();
}


////////////////////////////////////////////////////////////
void sfMusic_stop(sfMusic* music)
{
    assert(music);
    music->This.stop();
}


////////////////////////////////////////////////////////////
unsigned int sfMusic_getChannelCount(const sfMusic* music)
{
    assert(music);
    return music->This.getChannelCount();
}


////////////////////////////////////////////////////////////
unsigned int sfMusic_getSampleRate(const sfMusic* music)
{
    assert(music);
    return music->This.getSampleRate();
}


////////////////////////////////////////////////////////////
const sfSoundChannel* sfMusic_getChannelMap(const sfMusic* music, size_t* count)
{
    assert(music);
    assert(count);

    const auto channels = music->This.getChannelMap();

    music->Channels.resize(channels.size());
    std::memcpy(music->Channels.data(), channels.data(), sizeof(sfSoundChannel) * channels.size());

    *count = music->Channels.size();
    return music->Channels.data();
}


////////////////////////////////////////////////////////////
sfSoundStatus sfMusic_getStatus(const sfMusic* music)
{
    assert(music);
    return static_cast<sfSoundStatus>(music->This.getStatus());
}


////////////////////////////////////////////////////////////
sfTime sfMusic_getPlayingOffset(const sfMusic* music)
{
    assert(music);
    return {music->This.getPlayingOffset().asMicroseconds()};
}


////////////////////////////////////////////////////////////
void sfMusic_setPitch(sfMusic* music, float pitch)
{
    assert(music);
    music->This.setPitch(pitch);
}


////////////////////////////////////////////////////////////
void sfMusic_setPan(sfMusic* music, float pan)
{
    assert(music);
    music->This.setPan(pan);
}


////////////////////////////////////////////////////////////
void sfMusic_setVolume(sfMusic* music, float volume)
{
    assert(music);
    music->This.setVolume(volume);
}


////////////////////////////////////////////////////////////
void sfMusic_setSpatializationEnabled(sfMusic* music, bool enabled)
{
    assert(music);
    music->This.setSpatializationEnabled(enabled);
}


////////////////////////////////////////////////////////////
void sfMusic_setPosition(sfMusic* music, sfVector3f position)
{
    assert(music);
    music->This.setPosition(convertVector3(position));
}


////////////////////////////////////////////////////////////
void sfMusic_setDirection(sfMusic* music, sfVector3f position)
{
    assert(music);
    music->This.setDirection(convertVector3(position));
}


////////////////////////////////////////////////////////////
void sfMusic_setCone(sfMusic* music, sfSoundSourceCone cone)
{
    assert(music);
    music->This.setCone(convertCone(cone));
}


////////////////////////////////////////////////////////////
void sfMusic_setVelocity(sfMusic* music, sfVector3f velocity)
{
    assert(music);
    music->This.setVelocity(convertVector3(velocity));
}


////////////////////////////////////////////////////////////
void sfMusic_setDopplerFactor(sfMusic* music, float factor)
{
    assert(music);
    music->This.setDopplerFactor(factor);
}


////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setDirectionalAttenuationFactor(sfMusic* music, float factor)
{
    assert(music);
    music->This.setDirectionalAttenuationFactor(factor);
}


////////////////////////////////////////////////////////////
void sfMusic_setRelativeToListener(sfMusic* music, bool relative)
{
    assert(music);
    music->This.setRelativeToListener(relative);
}


////////////////////////////////////////////////////////////
void sfMusic_setMinDistance(sfMusic* music, float distance)
{
    assert(music);
    music->This.setMinDistance(distance);
}


////////////////////////////////////////////////////////////
void sfMusic_setMaxDistance(sfMusic* music, float distance)
{
    assert(music);
    music->This.setMaxDistance(distance);
}


////////////////////////////////////////////////////////////
void sfMusic_setMinGain(sfMusic* music, float gain)
{
    assert(music);
    music->This.setMinGain(gain);
}


////////////////////////////////////////////////////////////
void sfMusic_setMaxGain(sfMusic* music, float gain)
{
    assert(music);
    music->This.setMaxGain(gain);
}


////////////////////////////////////////////////////////////
void sfMusic_setAttenuation(sfMusic* music, float attenuation)
{
    assert(music);
    music->This.setAttenuation(attenuation);
}


////////////////////////////////////////////////////////////
void sfMusic_setPlayingOffset(sfMusic* music, sfTime timeOffset)
{
    assert(music);
    music->This.setPlayingOffset(sf::microseconds(timeOffset.microseconds));
}


////////////////////////////////////////////////////////////
float sfMusic_getPitch(const sfMusic* music)
{
    assert(music);
    return music->This.getPitch();
}


////////////////////////////////////////////////////////////
float sfMusic_getPan(const sfMusic* music)
{
    assert(music);
    return music->This.getPan();
}


////////////////////////////////////////////////////////////
float sfMusic_getVolume(const sfMusic* music)
{
    assert(music);
    return music->This.getVolume();
}


////////////////////////////////////////////////////////////
bool sfMusic_isSpatializationEnabled(const sfMusic* music)
{
    assert(music);
    return music->This.isSpatializationEnabled();
}


////////////////////////////////////////////////////////////
sfVector3f sfMusic_getPosition(const sfMusic* music)
{
    assert(music);
    return convertVector3(music->This.getPosition());
}


////////////////////////////////////////////////////////////
sfVector3f sfMusic_getDirection(const sfMusic* music)
{
    assert(music);
    return convertVector3(music->This.getDirection());
}


////////////////////////////////////////////////////////////
sfSoundSourceCone sfMusic_getCone(const sfMusic* music)
{
    assert(music);
    return convertCone(music->This.getCone());
}


////////////////////////////////////////////////////////////
sfVector3f sfMusic_getVelocity(const sfMusic* music)
{
    assert(music);
    return convertVector3(music->This.getVelocity());
}


////////////////////////////////////////////////////////////
float sfMusic_getDopplerFactor(const sfMusic* music)
{
    assert(music);
    return music->This.getDopplerFactor();
}


////////////////////////////////////////////////////////////
float sfMusic_getDirectionalAttenuationFactor(const sfMusic* music)
{
    assert(music);
    return music->This.getDirectionalAttenuationFactor();
}


////////////////////////////////////////////////////////////
bool sfMusic_isRelativeToListener(const sfMusic* music)
{
    assert(music);
    return music->This.isRelativeToListener();
}


////////////////////////////////////////////////////////////
float sfMusic_getMinDistance(const sfMusic* music)
{
    assert(music);
    return music->This.getMinDistance();
}


////////////////////////////////////////////////////////////
float sfMusic_getMaxDistance(const sfMusic* music)
{
    assert(music);
    return music->This.getMaxDistance();
}


////////////////////////////////////////////////////////////
float sfMusic_getMinGain(const sfMusic* music)
{
    assert(music);
    return music->This.getMinGain();
}


////////////////////////////////////////////////////////////
float sfMusic_getMaxGain(const sfMusic* music)
{
    assert(music);
    return music->This.getMinGain();
}


////////////////////////////////////////////////////////////
float sfMusic_getAttenuation(const sfMusic* music)
{
    assert(music);
    return music->This.getAttenuation();
}
