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
#include <SFML/Audio/Music.h>
#include <SFML/Audio/MusicStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfMusic* sfMusic_CreateFromFile(const char* filename)
{
    sfMusic* music = new sfMusic;
    if (!music->This.OpenFromFile(filename))
    {
        delete music;
        music = NULL;
    }

    return music;
}


////////////////////////////////////////////////////////////
sfMusic* sfMusic_CreateFromMemory(const void* data, size_t sizeInBytes)
{
    sfMusic* music = new sfMusic;
    if (!music->This.OpenFromMemory(data, sizeInBytes))
    {
        delete music;
        music = NULL;
    }

    return music;
}


////////////////////////////////////////////////////////////
sfMusic* sfMusic_CreateFromStream(sfInputStream* stream)
{
    CSFML_CHECK_RETURN(stream, NULL);

    sfMusic* music = new sfMusic;
    music->Stream = CallbackStream(stream);
    if (!music->This.OpenFromStream(music->Stream))
    {
        delete music;
        music = NULL;
    }

    return music;
}


////////////////////////////////////////////////////////////
void sfMusic_Destroy(sfMusic* music)
{
    delete music;
}


////////////////////////////////////////////////////////////
void sfMusic_SetLoop(sfMusic* music, sfBool loop)
{
    CSFML_CALL(music, SetLoop(loop != 0));
}


////////////////////////////////////////////////////////////
sfBool sfMusic_GetLoop(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetLoop(), sfFalse);
}


////////////////////////////////////////////////////////////
sfTime sfMusic_GetDuration(const sfMusic* music)
{
    sfTime time = {0};
    CSFML_CHECK_RETURN(music, time);

    time.Microseconds = music->This.GetDuration().AsMicroseconds();
    return time;
}


////////////////////////////////////////////////////////////
void sfMusic_Play(sfMusic* music)
{
    CSFML_CALL(music, Play());
}


////////////////////////////////////////////////////////////
void sfMusic_Pause(sfMusic* music)
{
    CSFML_CALL(music, Pause());
}


////////////////////////////////////////////////////////////
void sfMusic_Stop(sfMusic* music)
{
    CSFML_CALL(music, Stop());
}


////////////////////////////////////////////////////////////
unsigned int sfMusic_GetChannelCount(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetChannelCount(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfMusic_GetSampleRate(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetSampleRate(), 0);
}


////////////////////////////////////////////////////////////
sfSoundStatus sfMusic_GetStatus(const sfMusic* music)
{
    CSFML_CHECK_RETURN(music, sfStopped);

    return static_cast<sfSoundStatus>(music->This.GetStatus());
}


////////////////////////////////////////////////////////////
sfTime sfMusic_GetPlayingOffset(const sfMusic* music)
{
    sfTime time = {0};
    CSFML_CHECK_RETURN(music, time);

    time.Microseconds = music->This.GetPlayingOffset().AsMicroseconds();
    return time;
}


////////////////////////////////////////////////////////////
void sfMusic_SetPitch(sfMusic* music, float pitch)
{
    CSFML_CALL(music, SetPitch(pitch));
}


////////////////////////////////////////////////////////////
void sfMusic_SetVolume(sfMusic* music, float volume)
{
    CSFML_CALL(music, SetVolume(volume));
}


////////////////////////////////////////////////////////////
void sfMusic_SetPosition(sfMusic* music, sfVector3f position)
{
    CSFML_CALL(music, SetPosition(sf::Vector3f(position.x, position.y, position.z)));
}


////////////////////////////////////////////////////////////
void sfMusic_SetRelativeToListener(sfMusic* music, sfBool relative)
{
    CSFML_CALL(music, SetRelativeToListener(relative == sfTrue));
}


////////////////////////////////////////////////////////////
void sfMusic_SetMinDistance(sfMusic* music, float distance)
{
    CSFML_CALL(music, SetMinDistance(distance));
}


////////////////////////////////////////////////////////////
void sfMusic_SetAttenuation(sfMusic* music, float attenuation)
{
    CSFML_CALL(music, SetAttenuation(attenuation));
}


////////////////////////////////////////////////////////////
void sfMusic_SetPlayingOffset(sfMusic* music, sfTime timeOffset)
{
    CSFML_CALL(music, SetPlayingOffset(sf::Microseconds(timeOffset.Microseconds)));
}


////////////////////////////////////////////////////////////
float sfMusic_GetPitch(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetPitch(), 0.f);
}


////////////////////////////////////////////////////////////
float sfMusic_GetVolume(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetVolume(), 0.f);
}


////////////////////////////////////////////////////////////
sfVector3f sfMusic_GetPosition(const sfMusic* music)
{
    sfVector3f position = {0, 0, 0};
    CSFML_CHECK_RETURN(music, position);

    sf::Vector3f sfmlPos = music->This.GetPosition();
    position.x = sfmlPos.x;
    position.y = sfmlPos.y;
    position.z = sfmlPos.z;

    return position;
}


////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfBool sfMusic_IsRelativeToListener(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, IsRelativeToListener(), sfFalse);
}


////////////////////////////////////////////////////////////
float sfMusic_GetMinDistance(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetMinDistance(), 0.f);
}


////////////////////////////////////////////////////////////
float sfMusic_GetAttenuation(const sfMusic* music)
{
    CSFML_CALL_RETURN(music, GetAttenuation(), 0.f);
}
