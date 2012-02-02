////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
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
#include <SFML/Audio/SoundStream.h>
#include <SFML/Audio/SoundStreamStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfSoundStream* sfSoundStream_Create(sfSoundStreamGetDataCallback onGetData,
                                    sfSoundStreamSeekCallback    onSeek,
                                    unsigned int                 channelCount,
                                    unsigned int                 sampleRate,
                                    void*                        userData)
{
    return new sfSoundStream(onGetData, onSeek, channelCount, sampleRate, userData);
}


////////////////////////////////////////////////////////////
void sfSoundStream_Destroy(sfSoundStream* soundStream)
{
    delete soundStream;
}


////////////////////////////////////////////////////////////
void sfSoundStream_Play(sfSoundStream* soundStream)
{
    CSFML_CALL(soundStream, Play());
}


////////////////////////////////////////////////////////////
void sfSoundStream_Pause(sfSoundStream* soundStream)
{
    CSFML_CALL(soundStream, Pause());
}


////////////////////////////////////////////////////////////
void sfSoundStream_Stop(sfSoundStream* soundStream)
{
    CSFML_CALL(soundStream, Stop());
}


////////////////////////////////////////////////////////////
sfSoundStatus sfSoundStream_GetStatus(const sfSoundStream* soundStream)
{
    CSFML_CHECK_RETURN(soundStream, sfStopped);

    return static_cast<sfSoundStatus>(soundStream->This.GetStatus());
}


////////////////////////////////////////////////////////////
unsigned int sfSoundStream_GetChannelCount(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetChannelCount(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfSoundStream_GetSampleRate(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetSampleRate(), 0);
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetPitch(sfSoundStream* soundStream, float pitch)
{
    CSFML_CALL(soundStream, SetPitch(pitch));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetVolume(sfSoundStream* soundStream, float volume)
{
    CSFML_CALL(soundStream, SetVolume(volume));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetPosition(sfSoundStream* soundStream, float x, float y, float z)
{
    CSFML_CALL(soundStream, SetPosition(x, y, z));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetRelativeToListener(sfSoundStream* soundStream, sfBool relative)
{
    CSFML_CALL(soundStream, SetRelativeToListener(relative == sfTrue));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetMinDistance(sfSoundStream* soundStream, float distance)
{
    CSFML_CALL(soundStream, SetMinDistance(distance));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetAttenuation(sfSoundStream* soundStream, float attenuation)
{
    CSFML_CALL(soundStream, SetAttenuation(attenuation));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetPlayingOffset(sfSoundStream* soundStream, sfTime timeOffset)
{
    CSFML_CALL(soundStream, SetPlayingOffset(sf::Microseconds(timeOffset.Microseconds)));
}


////////////////////////////////////////////////////////////
void sfSoundStream_SetLoop(sfSoundStream* soundStream, sfBool loop)
{
    CSFML_CALL(soundStream, SetLoop(loop == sfTrue));
}


////////////////////////////////////////////////////////////
float sfSoundStream_GetPitch(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetPitch(), 0.f);
}


////////////////////////////////////////////////////////////
float sfSoundStream_GetVolume(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetVolume(), 0.f);
}


////////////////////////////////////////////////////////////
void sfSoundStream_GetPosition(const sfSoundStream* soundStream, float* x, float* y, float* z)
{
    CSFML_CHECK(soundStream);

    sf::Vector3f position = soundStream->This.GetPosition();
    if (x) *x = position.x;
    if (y) *y = position.y;
    if (z) *z = position.z;
}


////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfBool sfSoundStream_IsRelativeToListener(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, IsRelativeToListener(), sfFalse);
}


////////////////////////////////////////////////////////////
float sfSoundStream_GetMinDistance(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetMinDistance(), 0.f);
}


////////////////////////////////////////////////////////////
float sfSoundStream_GetAttenuation(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetAttenuation(), 0.f);
}


////////////////////////////////////////////////////////////
sfBool sfSoundStream_GetLoop(const sfSoundStream* soundStream)
{
    CSFML_CALL_RETURN(soundStream, GetLoop(), sfFalse);
}


////////////////////////////////////////////////////////////
sfTime sfSoundStream_GetPlayingOffset(const sfSoundStream* soundStream)
{
    sfTime time = {0};
    CSFML_CHECK_RETURN(soundStream, time);

    time.Microseconds = soundStream->This.GetPlayingOffset().AsMicroseconds();
    return time;
}
