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
#include <CSFML/Audio/SoundStream.h>
#include <CSFML/Audio/SoundStreamStruct.hpp>
#include <CSFML/System/ConvertVector3.hpp>


////////////////////////////////////////////////////////////
sfSoundStream* sfSoundStream_create(
    sfSoundStreamGetDataCallback onGetData,
    sfSoundStreamSeekCallback    onSeek,
    unsigned int                 channelCount,
    unsigned int                 sampleRate,
    sfSoundChannel*              channelMapData,
    size_t                       channelMapSize,
    void*                        userData)
{
    return new sfSoundStream(onGetData, onSeek, channelCount, sampleRate, channelMapData, channelMapSize, userData);
}


////////////////////////////////////////////////////////////
void sfSoundStream_destroy(sfSoundStream* soundStream)
{
    delete soundStream;
}


////////////////////////////////////////////////////////////
void sfSoundStream_play(sfSoundStream* soundStream)
{
    assert(soundStream);
    soundStream->This.play();
}


////////////////////////////////////////////////////////////
void sfSoundStream_pause(sfSoundStream* soundStream)
{
    assert(soundStream);
    soundStream->This.pause();
}


////////////////////////////////////////////////////////////
void sfSoundStream_stop(sfSoundStream* soundStream)
{
    assert(soundStream);
    soundStream->This.stop();
}


////////////////////////////////////////////////////////////
sfSoundStatus sfSoundStream_getStatus(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return static_cast<sfSoundStatus>(soundStream->This.getStatus());
}


////////////////////////////////////////////////////////////
unsigned int sfSoundStream_getChannelCount(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.getChannelCount();
}


////////////////////////////////////////////////////////////
unsigned int sfSoundStream_getSampleRate(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.getSampleRate();
}


////////////////////////////////////////////////////////////
void sfSoundStream_setPitch(sfSoundStream* soundStream, float pitch)
{
    assert(soundStream);
    soundStream->This.setPitch(pitch);
}


////////////////////////////////////////////////////////////
void sfSoundStream_setVolume(sfSoundStream* soundStream, float volume)
{
    assert(soundStream);
    soundStream->This.setVolume(volume);
}


////////////////////////////////////////////////////////////
void sfSoundStream_setPosition(sfSoundStream* soundStream, sfVector3f position)
{
    assert(soundStream);
    soundStream->This.setPosition(convertVector3(position));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setRelativeToListener(sfSoundStream* soundStream, bool relative)
{
    assert(soundStream);
    soundStream->This.setRelativeToListener(relative);
}


////////////////////////////////////////////////////////////
void sfSoundStream_setMinDistance(sfSoundStream* soundStream, float distance)
{
    assert(soundStream);
    soundStream->This.setMinDistance(distance);
}


////////////////////////////////////////////////////////////
void sfSoundStream_setAttenuation(sfSoundStream* soundStream, float attenuation)
{
    assert(soundStream);
    soundStream->This.setAttenuation(attenuation);
}


////////////////////////////////////////////////////////////
void sfSoundStream_setPlayingOffset(sfSoundStream* soundStream, sfTime timeOffset)
{
    assert(soundStream);
    soundStream->This.setPlayingOffset(sf::microseconds(timeOffset.microseconds));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setLooping(sfSoundStream* soundStream, bool loop)
{
    assert(soundStream);
    soundStream->This.setLooping(loop);
}


////////////////////////////////////////////////////////////
float sfSoundStream_getPitch(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.getPitch();
}


////////////////////////////////////////////////////////////
float sfSoundStream_getVolume(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.getVolume();
}


////////////////////////////////////////////////////////////
sfVector3f sfSoundStream_getPosition(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return convertVector3(soundStream->This.getPosition());
}


////////////////////////////////////////////////////////////
bool sfSoundStream_isRelativeToListener(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.isRelativeToListener();
}


////////////////////////////////////////////////////////////
float sfSoundStream_getMinDistance(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.getMinDistance();
}


////////////////////////////////////////////////////////////
float sfSoundStream_getAttenuation(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.getAttenuation();
}


////////////////////////////////////////////////////////////
bool sfSoundStream_isLooping(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return soundStream->This.isLooping();
}


////////////////////////////////////////////////////////////
sfTime sfSoundStream_getPlayingOffset(const sfSoundStream* soundStream)
{
    assert(soundStream);
    return {soundStream->This.getPlayingOffset().asMicroseconds()};
}
