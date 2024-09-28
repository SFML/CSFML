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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Audio/Export.h>

#include <CSFML/Audio/SoundChannel.h>
#include <CSFML/Audio/Types.h>
#include <CSFML/System/Time.h>

#include <stddef.h>


typedef bool (*sfSoundRecorderStartCallback)(void*); ///< Type of the callback used when starting a capture
typedef bool (*sfSoundRecorderProcessCallback)(const int16_t*, size_t, void*); ///< Type of the callback used to process audio data
typedef void (*sfSoundRecorderStopCallback)(void*); ///< Type of the callback used when stopping a capture


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
CSFML_AUDIO_API void sfSoundRecorder_destroy(const sfSoundRecorder* soundRecorder);

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
/// \return True, if start of capture was successful
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSoundRecorder_start(sfSoundRecorder* soundRecorder, unsigned int sampleRate);

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
/// \return true if audio capture is supported, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSoundRecorder_isAvailable(void);

////////////////////////////////////////////////////////////
/// \brief Get a list of the names of all available audio capture devices
///
/// This function returns an array of strings (null terminated),
/// containing the names of all available audio capture devices.
/// If no devices are available, then NULL is returned.
///
/// \param count Pointer to a variable that will be filled with the number of modes in the array
///
/// \return An array of strings containing the names
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API const char* const* sfSoundRecorder_getAvailableDevices(size_t* count);

////////////////////////////////////////////////////////////
/// \brief Get the name of the default audio capture device
///
/// This function returns the name of the default audio
/// capture device. If none is available, NULL is returned.
///
/// \return The name of the default audio capture device (null terminated)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API const char* sfSoundRecorder_getDefaultDevice(void);

////////////////////////////////////////////////////////////
/// \brief Set the audio capture device
///
/// This function sets the audio capture device to the device
/// with the given name. It can be called on the fly (i.e:
/// while recording). If you do so while recording and
/// opening the device fails, it stops the recording.
///
/// \param soundRecorder Sound recorder object
/// \param name          The name of the audio capture device
///
/// \return true, if it was able to set the requested device
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSoundRecorder_setDevice(sfSoundRecorder* soundRecorder, const char* name);

////////////////////////////////////////////////////////////
/// \brief Get the name of the current audio capture device
///
/// \param soundRecorder Sound recorder object
///
/// \return The name of the current audio capture device
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API const char* sfSoundRecorder_getDevice(sfSoundRecorder* soundRecorder);

////////////////////////////////////////////////////////////
/// \brief Set the channel count of the audio capture device
///
/// This method allows you to specify the number of channels
/// used for recording. Currently only 16-bit mono and
/// 16-bit stereo are supported.
///
/// \param soundRecorder Sound recorder object
/// \param channelCount  Number of channels. Currently only
///                      mono (1) and stereo (2) are supported.
///
/// \see sfSoundRecorder_getChannelCount
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundRecorder_setChannelCount(sfSoundRecorder* soundRecorder, unsigned int channelCount);

////////////////////////////////////////////////////////////
/// \brief Get the number of channels used by this recorder
///
/// Currently only mono and stereo are supported, so the
/// value is either 1 (for mono) or 2 (for stereo).
///
/// \return Number of channels
///
/// \see sfSoundRecorder_setChannelCount
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API unsigned int sfSoundRecorder_getChannelCount(const sfSoundRecorder* soundRecorder);

////////////////////////////////////////////////////////////
/// \brief Get the map of position in sample frame to sound channel
///
/// This is used to map a sample in the sample stream to a
/// position during spatialization.
///
/// \param soundRecorder Sound recorder object
/// \param count Pointer to a variable that will be filled with the number of channels in the map
///
/// \return Map of position in sample frame to sound channel
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundChannel* sfSoundRecorder_getChannelMap(const sfSoundRecorder* soundRecorder, size_t* count);
