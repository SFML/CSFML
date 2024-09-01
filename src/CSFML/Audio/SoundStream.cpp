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
#include <CSFML/Audio/SoundStream.h>
#include <CSFML/Audio/SoundStreamStruct.hpp>
#include <CSFML/Internal.hpp>
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
    CSFML_CALL(soundStream, play());
}


////////////////////////////////////////////////////////////
void sfSoundStream_pause(sfSoundStream* soundStream)
{
    CSFML_CALL(soundStream, pause());
}


////////////////////////////////////////////////////////////
void sfSoundStream_stop(sfSoundStream* soundStream)
{
    CSFML_CALL(soundStream, stop());
}


////////////////////////////////////////////////////////////
sfSoundStatus sfSoundStream_getStatus(const sfSoundStream* soundStream)
{
    CSFML_CHECK_RETURN(soundStream, sfStopped);

    return static_cast<sfSoundStatus>(soundStream->This.getStatus());
}


////////////////////////////////////////////////////////////
unsigned int sfSoundStream_getChannelCount(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, getChannelCount(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfSoundStream_getSampleRate(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, getSampleRate(), 0);
}


////////////////////////////////////////////////////////////
void sfSoundStream_setPitch(sfSoundStream* soundStream, float pitch)
{
    CSFML_CALL(soundStream, setPitch(pitch));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setVolume(sfSoundStream* soundStream, float volume)
{
    CSFML_CALL(soundStream, setVolume(volume));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setPosition(sfSoundStream* soundStream, sfVector3f position)
{
    CSFML_CALL(soundStream, setPosition(convertVector3(position)));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setRelativeToListener(sfSoundStream* soundStream, bool relative)
{
    CSFML_CALL(soundStream, setRelativeToListener(relative));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setMinDistance(sfSoundStream* soundStream, float distance)
{
    CSFML_CALL(soundStream, setMinDistance(distance));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setAttenuation(sfSoundStream* soundStream, float attenuation)
{
    CSFML_CALL(soundStream, setAttenuation(attenuation));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setPlayingOffset(sfSoundStream* soundStream, sfTime timeOffset)
{
    CSFML_CALL(soundStream, setPlayingOffset(sf::microseconds(timeOffset.microseconds)));
}


////////////////////////////////////////////////////////////
void sfSoundStream_setLooping(sfSoundStream* soundStream, bool loop)
{
    CSFML_CALL(soundStream, setLooping(loop));
}


////////////////////////////////////////////////////////////
float sfSoundStream_getPitch(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, getPitch(), 0.f);
}


////////////////////////////////////////////////////////////
float sfSoundStream_getVolume(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, getVolume(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector3f sfSoundStream_getPosition(const sfSoundStream* soundStream)
{
    CSFML_CHECK_RETURN(soundStream, {});

    return convertVector3(soundStream->This.getPosition());
}


////////////////////////////////////////////////////////////
bool sfSoundStream_isRelativeToListener(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, isRelativeToListener(), false);
}


////////////////////////////////////////////////////////////
float sfSoundStream_getMinDistance(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, getMinDistance(), 0.f);
}


////////////////////////////////////////////////////////////
float sfSoundStream_getAttenuation(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, getAttenuation(), 0.f);
}


////////////////////////////////////////////////////////////
bool sfSoundStream_isLooping(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, isLooping(), false);
}


////////////////////////////////////////////////////////////
sfTime sfSoundStream_getPlayingOffset(const sfSoundStream* soundStream)
{
    sfTime time = {0};
    CSFML_CHECK_RETURN(soundStream, time);

    time.microseconds = soundStream->This.getPlayingOffset().asMicroseconds();
    return time;
}
