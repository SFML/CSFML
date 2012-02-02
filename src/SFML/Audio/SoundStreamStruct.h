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

#ifndef SFML_SOUNDSTREAMSTRUCT_H
#define SFML_SOUNDSTREAMSTRUCT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio/SoundStream.hpp>


////////////////////////////////////////////////////////////
// Helper class implementing the callback forwarding from
// C++ to C in sfSoundStream
////////////////////////////////////////////////////////////
class sfSoundStreamImpl : public sf::SoundStream
{
public :

    sfSoundStreamImpl(sfSoundStreamGetDataCallback onGetData,
                      sfSoundStreamSeekCallback    onSeek,
                      unsigned int                 channelCount,
                      unsigned int                 sampleRate,
                      void*                        userData) :
    myGetDataCallback(onGetData),
    mySeekCallback   (onSeek),
    myUserData       (userData)
    {
        Initialize(channelCount, sampleRate);
    }

private :

    virtual bool OnGetData(Chunk& data)
    {
        sfSoundStreamChunk chunk = {NULL, 0};
        bool ok = (myGetDataCallback(&chunk, myUserData) == sfTrue);

        data.Samples     = chunk.Samples;
        data.SampleCount = chunk.SampleCount;

        return ok;
    }

    virtual void OnSeek(sf::Time timeOffset)
    {
        if (mySeekCallback)
            mySeekCallback(sfMicroseconds(timeOffset.AsMicroseconds()), myUserData);
    }

    sfSoundStreamGetDataCallback myGetDataCallback;
    sfSoundStreamSeekCallback    mySeekCallback;
    void*                        myUserData;
};


////////////////////////////////////////////////////////////
// Internal structure of sfSoundStream
////////////////////////////////////////////////////////////
struct sfSoundStream
{
    sfSoundStream(sfSoundStreamGetDataCallback onGetData,
                  sfSoundStreamSeekCallback    onSeek,
                  unsigned int                 channelCount,
                  unsigned int                 sampleRate,
                  void*                        userData) :
    This(onGetData, onSeek, channelCount, sampleRate, userData)
    {
    }

    sfSoundStreamImpl This;
};


#endif // SFML_SOUNDSTREAMSTRUCT_H
