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
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfSound* sfSound_Create(void)
{
    return new sfSound;
}


////////////////////////////////////////////////////////////
sfSound* sfSound_Copy(sfSound* sound)
{
    CSFML_CHECK_RETURN(sound, NULL);

    return new sfSound(*sound);
}


////////////////////////////////////////////////////////////
void sfSound_Destroy(sfSound* sound)
{
    delete sound;
}


////////////////////////////////////////////////////////////
void sfSound_Play(sfSound* sound)
{
    CSFML_CALL(sound, Play())
}


////////////////////////////////////////////////////////////
void sfSound_Pause(sfSound* sound)
{
    CSFML_CALL(sound, Pause())
}


////////////////////////////////////////////////////////////
void sfSound_Stop(sfSound* sound)
{
    CSFML_CALL(sound, Stop())
}


////////////////////////////////////////////////////////////
void sfSound_SetBuffer(sfSound* sound, const sfSoundBuffer* buffer)
{
    if (buffer)
    {
        CSFML_CALL(sound, SetBuffer(buffer->This))
        sound->Buffer = buffer;
    }
}


////////////////////////////////////////////////////////////
const sfSoundBuffer* sfSound_GetBuffer(const sfSound* sound)
{
    CSFML_CHECK_RETURN(sound, NULL)

    return sound->Buffer;
}


////////////////////////////////////////////////////////////
void sfSound_SetLoop(sfSound* sound, sfBool loop)
{
    CSFML_CALL(sound, SetLoop(loop == sfTrue))
}


////////////////////////////////////////////////////////////
sfBool sfSound_GetLoop(const sfSound* sound)
{
    CSFML_CALL_RETURN(sound, GetLoop(), sfFalse)
}


////////////////////////////////////////////////////////////
sfSoundStatus sfSound_GetStatus(const sfSound* sound)
{
    CSFML_CHECK_RETURN(sound, sfStopped);

    return static_cast<sfSoundStatus>(sound->This.GetStatus());
}


////////////////////////////////////////////////////////////
void sfSound_SetPitch(sfSound* sound, float pitch)
{
    CSFML_CALL(sound, SetPitch(pitch))
}


////////////////////////////////////////////////////////////
void sfSound_SetVolume(sfSound* sound, float volume)
{
    CSFML_CALL(sound, SetVolume(volume))
}


////////////////////////////////////////////////////////////
void sfSound_SetPosition(sfSound* sound, float x, float y, float z)
{
    CSFML_CALL(sound, SetPosition(sf::Vector3f(x, y, z)))
}


////////////////////////////////////////////////////////////
void sfSound_SetRelativeToListener(sfSound* sound, sfBool relative)
{
    CSFML_CALL(sound, SetRelativeToListener(relative == sfTrue));
}


////////////////////////////////////////////////////////////
void sfSound_SetMinDistance(sfSound* sound, float distance)
{
    CSFML_CALL(sound, SetMinDistance(distance));
}


////////////////////////////////////////////////////////////
void sfSound_SetAttenuation(sfSound* sound, float attenuation)
{
    CSFML_CALL(sound, SetAttenuation(attenuation));
}


////////////////////////////////////////////////////////////
void sfSound_SetPlayingOffset(sfSound* sound, sfTime timeOffset)
{
    CSFML_CALL(sound, SetPlayingOffset(sf::Microseconds(timeOffset.Microseconds)));
}


////////////////////////////////////////////////////////////
float sfSound_GetPitch(const sfSound* sound)
{
    CSFML_CALL_RETURN(sound, GetPitch(), 0.f)
}


////////////////////////////////////////////////////////////
float sfSound_GetVolume(const sfSound* sound)
{
    CSFML_CALL_RETURN(sound, GetVolume(), 0.f)
}


////////////////////////////////////////////////////////////
void sfSound_GetPosition(const sfSound* sound, float* x, float* y, float* z)
{
    CSFML_CHECK(sound);

    sf::Vector3f position = sound->This.GetPosition();
    if (x) *x = position.x;
    if (y) *y = position.y;
    if (z) *z = position.z;
}


////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfBool sfSound_IsRelativeToListener(const sfSound* sound)
{
    CSFML_CALL_RETURN(sound, IsRelativeToListener(), sfFalse);
}


////////////////////////////////////////////////////////////
float sfSound_GetMinDistance(const sfSound* sound)
{
    CSFML_CALL_RETURN(sound, GetMinDistance(), 0.f);
}


////////////////////////////////////////////////////////////
float sfSound_GetAttenuation(const sfSound* sound)
{
    CSFML_CALL_RETURN(sound, GetAttenuation(), 0.f);
}


////////////////////////////////////////////////////////////
sfTime sfSound_GetPlayingOffset(const sfSound* sound)
{
    sfTime time = {0};
    CSFML_CHECK_RETURN(sound, time);

    time.Microseconds = sound->This.GetPlayingOffset().AsMicroseconds();
    return time;
}
