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
#include <CSFML/Audio/Sound.h>
#include <CSFML/Audio/SoundStruct.hpp>
#include <CSFML/System/ConvertVector3.hpp>


////////////////////////////////////////////////////////////
sfSound* sfSound_create(const sfSoundBuffer* buffer)
{
    assert(buffer);
    return new sfSound{sf::Sound(buffer->This), buffer};
}


////////////////////////////////////////////////////////////
sfSound* sfSound_copy(const sfSound* sound)
{
    assert(sound);
    return new sfSound(*sound);
}


////////////////////////////////////////////////////////////
void sfSound_destroy(const sfSound* sound)
{
    delete sound;
}


////////////////////////////////////////////////////////////
void sfSound_play(sfSound* sound)
{
    assert(sound);
    sound->This.play();
}


////////////////////////////////////////////////////////////
void sfSound_pause(sfSound* sound)
{
    assert(sound);
    sound->This.pause();
}


////////////////////////////////////////////////////////////
void sfSound_stop(sfSound* sound)
{
    assert(sound);
    sound->This.stop();
}


////////////////////////////////////////////////////////////
void sfSound_setBuffer(sfSound* sound, const sfSoundBuffer* buffer)
{
    if (buffer)
    {
        assert(sound);
        sound->This.setBuffer(buffer->This);
        sound->Buffer = buffer;
    }
}


////////////////////////////////////////////////////////////
const sfSoundBuffer* sfSound_getBuffer(const sfSound* sound)
{
    assert(sound);
    return sound->Buffer;
}


////////////////////////////////////////////////////////////
void sfSound_setLooping(sfSound* sound, bool loop)
{
    assert(sound);
    sound->This.setLooping(loop);
}


////////////////////////////////////////////////////////////
bool sfSound_isLooping(const sfSound* sound)
{
    assert(sound);
    return sound->This.isLooping();
}


////////////////////////////////////////////////////////////
sfSoundStatus sfSound_getStatus(const sfSound* sound)
{
    assert(sound);
    return static_cast<sfSoundStatus>(sound->This.getStatus());
}


////////////////////////////////////////////////////////////
void sfSound_setPitch(sfSound* sound, float pitch)
{
    assert(sound);
    sound->This.setPitch(pitch);
}


////////////////////////////////////////////////////////////
void sfSound_setPan(sfSound* sound, float pan)
{
    assert(sound);
    sound->This.setPan(pan);
}


////////////////////////////////////////////////////////////
void sfSound_setVolume(sfSound* sound, float volume)
{
    assert(sound);
    sound->This.setVolume(volume);
}


////////////////////////////////////////////////////////////
void sfSound_setSpatializationEnabled(sfSound* sound, bool enabled)
{
    assert(sound);
    sound->This.setSpatializationEnabled(enabled);
}


////////////////////////////////////////////////////////////
void sfSound_setPosition(sfSound* sound, sfVector3f position)
{
    assert(sound);
    sound->This.setPosition(convertVector3(position));
}


////////////////////////////////////////////////////////////
void sfSound_setDirection(sfSound* sound, sfVector3f direction)
{
    assert(sound);
    sound->This.setDirection(convertVector3(direction));
}


////////////////////////////////////////////////////////////
void sfSound_setCone(sfSound* sound, sfSoundSourceCone cone)
{
    assert(sound);
    sound->This.setCone(convertCone(cone));
}


////////////////////////////////////////////////////////////
void sfSound_setVelocity(sfSound* sound, sfVector3f velocity)
{
    assert(sound);
    sound->This.setVelocity(convertVector3(velocity));
}


////////////////////////////////////////////////////////////
void sfSound_setDopplerFactor(sfSound* sound, float factor)
{
    assert(sound);
    sound->This.setDopplerFactor(factor);
}


////////////////////////////////////////////////////////////
void sfSound_setDirectionalAttenuationFactor(sfSound* sound, float factor)
{
    assert(sound);
    sound->This.setDirectionalAttenuationFactor(factor);
}


////////////////////////////////////////////////////////////
void sfSound_setRelativeToListener(sfSound* sound, bool relative)
{
    assert(sound);
    sound->This.setRelativeToListener(relative);
}


////////////////////////////////////////////////////////////
void sfSound_setMinDistance(sfSound* sound, float distance)
{
    assert(sound);
    sound->This.setMinDistance(distance);
}


////////////////////////////////////////////////////////////
void sfSound_setMaxDistance(sfSound* sound, float distance)
{
    assert(sound);
    sound->This.setMaxDistance(distance);
}


////////////////////////////////////////////////////////////
void sfSound_setMinGain(sfSound* sound, float gain)
{
    assert(sound);
    sound->This.setMinGain(gain);
}


////////////////////////////////////////////////////////////
void sfSound_setMaxGain(sfSound* sound, float gain)
{
    assert(sound);
    sound->This.setMaxGain(gain);
}


////////////////////////////////////////////////////////////
void sfSound_setAttenuation(sfSound* sound, float attenuation)
{
    assert(sound);
    sound->This.setAttenuation(attenuation);
}


////////////////////////////////////////////////////////////
void sfSound_setPlayingOffset(sfSound* sound, sfTime timeOffset)
{
    assert(sound);
    sound->This.setPlayingOffset(sf::microseconds(timeOffset.microseconds));
}


////////////////////////////////////////////////////////////
void sfSound_setEffectProcessor(sfSound* sound, sfEffectProcessor effectProcessor)
{
    assert(sound);

    if (!effectProcessor)
    {
        sound->This.setEffectProcessor(nullptr);
    }
    else
    {
        sound->This.setEffectProcessor(
            [effectProcessor](const float*  inputFrames,
                              unsigned int& inputFrameCount,
                              float*        outputFrames,
                              unsigned int& outputFrameCount,
                              unsigned int  frameChannelCount)
            { effectProcessor(inputFrames, &inputFrameCount, outputFrames, &outputFrameCount, frameChannelCount); });
    }
}


////////////////////////////////////////////////////////////
float sfSound_getPitch(const sfSound* sound)
{
    assert(sound);
    return sound->This.getPitch();
}


////////////////////////////////////////////////////////////
float sfSound_getPan(const sfSound* sound)
{
    assert(sound);
    return sound->This.getPan();
}


////////////////////////////////////////////////////////////
float sfSound_getVolume(const sfSound* sound)
{
    assert(sound);
    return sound->This.getVolume();
}


////////////////////////////////////////////////////////////
bool sfSound_isSpatializationEnabled(const sfSound* sound)
{
    assert(sound);
    return sound->This.isSpatializationEnabled();
}


////////////////////////////////////////////////////////////
sfVector3f sfSound_getPosition(const sfSound* sound)
{
    assert(sound);
    return convertVector3(sound->This.getPosition());
}


////////////////////////////////////////////////////////////
sfVector3f sfSound_getDirection(const sfSound* sound)
{
    assert(sound);
    return convertVector3(sound->This.getDirection());
}


////////////////////////////////////////////////////////////
sfSoundSourceCone sfSound_getCone(const sfSound* sound)
{
    assert(sound);
    return convertCone(sound->This.getCone());
}


////////////////////////////////////////////////////////////
sfVector3f sfSound_getVelocity(const sfSound* sound)
{
    assert(sound);
    return convertVector3(sound->This.getVelocity());
}


////////////////////////////////////////////////////////////
float sfSound_getDopplerFactor(const sfSound* sound)
{
    assert(sound);
    return sound->This.getDopplerFactor();
}


////////////////////////////////////////////////////////////
float sfSound_getDirectionalAttenuationFactor(const sfSound* sound)
{
    assert(sound);
    return sound->This.getDopplerFactor();
}


////////////////////////////////////////////////////////////
bool sfSound_isRelativeToListener(const sfSound* sound)
{
    assert(sound);
    return sound->This.isRelativeToListener();
}


////////////////////////////////////////////////////////////
float sfSound_getMinDistance(const sfSound* sound)
{
    assert(sound);
    return sound->This.getMinDistance();
}


////////////////////////////////////////////////////////////
float sfSound_getMaxDistance(const sfSound* sound)
{
    assert(sound);
    return sound->This.getMaxDistance();
}


////////////////////////////////////////////////////////////
float sfSound_getMinGain(const sfSound* sound)
{
    assert(sound);
    return sound->This.getMinGain();
}


////////////////////////////////////////////////////////////
float sfSound_getMaxGain(const sfSound* sound)
{
    assert(sound);
    return sound->This.getMaxGain();
}


////////////////////////////////////////////////////////////
float sfSound_getAttenuation(const sfSound* sound)
{
    assert(sound);
    return sound->This.getAttenuation();
}


////////////////////////////////////////////////////////////
sfTime sfSound_getPlayingOffset(const sfSound* sound)
{
    assert(sound);
    return {sound->This.getPlayingOffset().asMicroseconds()};
}
