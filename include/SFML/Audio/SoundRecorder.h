////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2013 Laurent Gomila (laurent.gom@gmail.com)
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

#ifndef SFML_SOUNDRECORDER_H
#define SFML_SOUNDRECORDER_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio/Export.h>
#include <SFML/Audio/Types.h>
#include <stddef.h>


typedef sfBool (*sfSoundRecorderStartCallback)(void*);                           ///< Type of the callback used when starting a capture
typedef sfBool (*sfSoundRecorderProcessCallback)(const sfInt16*, size_t, void*); ///< Type of the callback used to process audio data
typedef void   (*sfSoundRecorderStopCallback)(void*);                            ///< Type of the callback used when stopping a capture


////////////////////////////////////////////////////////////
/// \brief Construct a new sound recorder from callback functions
///
/// \param onStart   Callback function which will be called when a new capture starts (can be NULL)
/// \param onProcess Callback function which will be called each time there's audio data to process
/// \param onStop    Callback function which will be called when the current capture stops (can be NULL)
/// \param userData  Data to pass to the callback function (can be NULL)
///
/// \return A new sfSoundRecorder object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundRecorder* sfSoundRecorder_create(sfSoundRecorderStartCallback   onStart,
                                                        sfSoundRecorderProcessCallback onProcess,
                                                        sfSoundRecorderStopCallback    onStop,
                                                        void*                          userData);

////////////////////////////////////////////////////////////
/// \brief Destroy a sound recorder
///
/// \param soundRecorder Sound recorder to destroy
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundRecorder_destroy(sfSoundRecorder* soundRecorder);

////////////////////////////////////////////////////////////
/// \brief Start the capture of a sound recorder
///
/// The \a sampleRate parameter defines the number of audio samples
/// captured per second. The higher, the better the quality
/// (for example, 44100 samples/sec is CD quality).
/// This function uses its own thread so that it doesn't block
/// the rest of the program while the capture runs.
/// Please note that only one capture can happen at the same time.
///
/// \param soundRecorder Sound recorder object
/// \param sampleRate    Desired capture rate, in number of samples per second
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundRecorder_start(sfSoundRecorder* soundRecorder, unsigned int sampleRate);

////////////////////////////////////////////////////////////
/// \brief Stop the capture of a sound recorder
///
/// \param soundRecorder Sound recorder object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundRecorder_stop(sfSoundRecorder* soundRecorder);

////////////////////////////////////////////////////////////
/// \brief Get the sample rate of a sound recorder
///
/// The sample rate defines the number of audio samples
/// captured per second. The higher, the better the quality
/// (for example, 44100 samples/sec is CD quality).
///
/// \param soundRecorder Sound recorder object
///
/// \return Sample rate, in samples per second
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API unsigned int sfSoundRecorder_getSampleRate(const sfSoundRecorder* soundRecorder);

////////////////////////////////////////////////////////////
/// \brief Check if the system supports audio capture
///
/// This function should always be called before using
/// the audio capture features. If it returns false, then
/// any attempt to use sfSoundRecorder will fail.
///
/// \return sfTrue if audio capture is supported, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfBool sfSoundRecorder_isAvailable(void);


#endif // SFML_SOUNDRECORDER_H
