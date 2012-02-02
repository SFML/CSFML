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
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/SoundBufferStruct.h>
#include <SFML/CallbackStream.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfSoundBuffer* sfSoundBuffer_CreateFromFile(const char* filename)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    if (!buffer->This.LoadFromFile(filename))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}


////////////////////////////////////////////////////////////
sfSoundBuffer* sfSoundBuffer_CreateFromMemory(const void* data, size_t sizeInBytes)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    if (!buffer->This.LoadFromMemory(data, sizeInBytes))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}



////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundBuffer* sfSoundBuffer_CreateFromStream(sfInputStream* stream)
{
    CSFML_CHECK_RETURN(stream, NULL);

    sfSoundBuffer* buffer = new sfSoundBuffer;
    CallbackStream sfmlStream(stream);
    if (!buffer->This.LoadFromStream(sfmlStream))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}


////////////////////////////////////////////////////////////
sfSoundBuffer* sfSoundBuffer_CreateFromSamples(const sfInt16* samples, size_t sampleCount, unsigned int channelsCount, unsigned int sampleRate)
{
    sfSoundBuffer* buffer = new sfSoundBuffer;

    if (!buffer->This.LoadFromSamples(samples, sampleCount, channelsCount, sampleRate))
    {
        delete buffer;
        buffer = NULL;
    }

    return buffer;
}


////////////////////////////////////////////////////////////
sfSoundBuffer* sfSoundBuffer_Copy(sfSoundBuffer* soundBuffer)
{
    CSFML_CHECK_RETURN(soundBuffer, NULL);

    return new sfSoundBuffer(*soundBuffer);
}


////////////////////////////////////////////////////////////
void sfSoundBuffer_Destroy(sfSoundBuffer* soundBuffer)
{
    delete soundBuffer;
}


////////////////////////////////////////////////////////////
sfBool sfSoundBuffer_SaveToFile(const sfSoundBuffer* soundBuffer, const char* filename)
{
    CSFML_CALL_RETURN(soundBuffer, SaveToFile(filename), sfFalse);
}


////////////////////////////////////////////////////////////
const sfInt16* sfSoundBuffer_GetSamples(const sfSoundBuffer* soundBuffer)
{
    CSFML_CALL_RETURN(soundBuffer, GetSamples(), NULL);
}


////////////////////////////////////////////////////////////
size_t sfSoundBuffer_GetSampleCount(const sfSoundBuffer* soundBuffer)
{
    CSFML_CALL_RETURN(soundBuffer, GetSampleCount(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfSoundBuffer_GetSampleRate(const sfSoundBuffer* soundBuffer)
{
    CSFML_CALL_RETURN(soundBuffer, GetSampleRate(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfSoundBuffer_GetChannelCount(const sfSoundBuffer* soundBuffer)
{
    CSFML_CALL_RETURN(soundBuffer, GetChannelCount(), 0);
}


////////////////////////////////////////////////////////////
sfTime sfSoundBuffer_GetDuration(const sfSoundBuffer* soundBuffer)
{
    sfTime time = {0};
    CSFML_CHECK_RETURN(soundBuffer, time);

    time.Microseconds = soundBuffer->This.GetDuration().AsMicroseconds();
    return time;
}
