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
#include <CSFML/Audio/Music.h>
#include <CSFML/Audio/MusicStruct.hpp>
#include <CSFML/System/ConvertVector3.hpp>


////////////////////////////////////////////////////////////
sfMusic* sfMusic_createFromFile(const char* filename)
{
    sfMusic* music = new sfMusic;
    if (!music->This.openFromFile(filename))
    {
        delete music;
        music = nullptr;
    }

    return music;
}


////////////////////////////////////////////////////////////
sfMusic* sfMusic_createFromMemory(const void* data, size_t sizeInBytes)
{
    sfMusic* music = new sfMusic;
    if (!music->This.openFromMemory(data, sizeInBytes))
    {
        delete music;
        music = nullptr;
    }

    return music;
}


////////////////////////////////////////////////////////////
sfMusic* sfMusic_createFromStream(sfInputStream* stream)
{
    assert(stream);

    sfMusic* music = new sfMusic;
    music->Stream  = CallbackStream(stream);
    if (!music->This.openFromStream(music->Stream))
    {
        delete music;
        music = nullptr;
    }

    return music;
}


////////////////////////////////////////////////////////////
void sfMusic_destroy(sfMusic* music)
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
void sfMusic_setVolume(sfMusic* music, float volume)
{
    assert(music);
    music->This.setVolume(volume);
}


////////////////////////////////////////////////////////////
void sfMusic_setPosition(sfMusic* music, sfVector3f position)
{
    assert(music);
    music->This.setPosition(convertVector3(position));
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
float sfMusic_getVolume(const sfMusic* music)
{
    assert(music);
    return music->This.getVolume();
}


////////////////////////////////////////////////////////////
sfVector3f sfMusic_getPosition(const sfMusic* music)
{
    assert(music);
    return convertVector3(music->This.getPosition());
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
float sfMusic_getAttenuation(const sfMusic* music)
{
    assert(music);
    return music->This.getAttenuation();
}
