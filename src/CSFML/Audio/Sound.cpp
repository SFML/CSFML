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
void sfSound_destroy(sfSound* sound)
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
void sfSound_setVolume(sfSound* sound, float volume)
{
    assert(sound);
    sound->This.setVolume(volume);
}


////////////////////////////////////////////////////////////
void sfSound_setPosition(sfSound* sound, sfVector3f position)
{
    assert(sound);
    sound->This.setPosition(convertVector3(position));
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
float sfSound_getPitch(const sfSound* sound)
{
    assert(sound);
    return sound->This.getPitch();
}


////////////////////////////////////////////////////////////
float sfSound_getVolume(const sfSound* sound)
{
    assert(sound);
    return sound->This.getVolume();
}


////////////////////////////////////////////////////////////
sfVector3f sfSound_getPosition(const sfSound* sound)
{
    assert(sound);
    return convertVector3(sound->This.getPosition());
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
