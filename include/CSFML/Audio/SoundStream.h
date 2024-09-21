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

#include <CSFML/Audio/EffectProcessor.h>
#include <CSFML/Audio/SoundChannel.h>
#include <CSFML/Audio/SoundSourceCone.h>
#include <CSFML/Audio/SoundStatus.h>
#include <CSFML/Audio/Types.h>
#include <CSFML/System/Time.h>
#include <CSFML/System/Vector3.h>

#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief defines the data to fill by the OnGetData callback
///
////////////////////////////////////////////////////////////
typedef struct
{
    int16_t*     samples;     ///< Pointer to the audio samples
    unsigned int sampleCount; ///< Number of samples pointed by Samples
} sfSoundStreamChunk;

typedef bool (*sfSoundStreamGetDataCallback)(sfSoundStreamChunk*, void*); ///< Type of the callback used to get a sound stream data
typedef void (*sfSoundStreamSeekCallback)(sfTime, void*); ///< Type of the callback used to seek in a sound stream


////////////////////////////////////////////////////////////
/// \brief Create a new sound stream
///
/// \param onGetData      Function called when the stream needs more data (can't be NULL)
/// \param onSeek         Function called when the stream seeks (can't be NULL)
/// \param channelCount   Number of channels to use (1 = mono, 2 = stereo)
/// \param sampleRate     Sample rate of the sound (44100 = CD quality)
/// \param channelMapData Pointer to the array of channel map data
/// \param channelMapSize Size of channel map data array
/// \param userData       Data to pass to the callback functions
///
/// \return A new sfSoundStream object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundStream* sfSoundStream_create(
    sfSoundStreamGetDataCallback onGetData,
    sfSoundStreamSeekCallback    onSeek,
    unsigned int                 channelCount,
    unsigned int                 sampleRate,
    sfSoundChannel*              channelMapData,
    size_t                       channelMapSize,
    void*                        userData);

////////////////////////////////////////////////////////////
/// \brief Destroy a sound stream
///
/// \param soundStream Sound stream to destroy
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_destroy(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Start or resume playing a sound stream
///
/// This function starts the stream if it was stopped, resumes
/// it if it was paused, and restarts it from beginning if it
/// was it already playing.
/// This function uses its own thread so that it doesn't block
/// the rest of the program while the music is played.
///
/// \param soundStream Sound stream object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_play(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Pause a sound stream
///
/// This function pauses the stream if it was playing,
/// otherwise (stream already paused or stopped) it has no effect.
///
/// \param soundStream Sound stream object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_pause(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Stop playing a sound stream
///
/// This function stops the stream if it was playing or paused,
/// and does nothing if it was already stopped.
/// It also resets the playing position (unlike sfSoundStream_pause).
///
/// \param soundStream Sound stream object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_stop(sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the current status of a sound stream (stopped, paused, playing)
///
/// \param soundStream Sound stream object
///
/// \return Current status
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundStatus sfSoundStream_getStatus(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Return the number of channels of a sound stream
///
/// 1 channel means a mono sound, 2 means stereo, etc.
///
/// \param soundStream Sound stream object
///
/// \return Number of channels
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API unsigned int sfSoundStream_getChannelCount(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the sample rate of a sound stream
///
/// The sample rate is the number of audio samples played per
/// second. The higher, the better the quality.
///
/// \param soundStream Sound stream object
///
/// \return Sample rate, in number of samples per second
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API unsigned int sfSoundStream_getSampleRate(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the map of position in sample frame to sound channel
///
/// This is used to map a sample in the sample stream to a
/// position during spatialization.
///
/// \param soundStream Sound stream object
/// \param count       Pointer to a variable that will be filled with the number of channels in the map
///
/// \return Map of position in sample frame to sound channel
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundChannel* sfSoundStream_getChannelMap(const sfSoundStream* soundStream, size_t* count);

////////////////////////////////////////////////////////////
/// \brief Set the pitch of a sound stream
///
/// The pitch represents the perceived fundamental frequency
/// of a sound; thus you can make a stream more acute or grave
/// by changing its pitch. A side effect of changing the pitch
/// is to modify the playing speed of the stream as well.
/// The default value for the pitch is 1.
///
/// \param soundStream Sound stream object
/// \param pitch       New pitch to apply to the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setPitch(sfSoundStream* soundStream, float pitch);

////////////////////////////////////////////////////////////
/// \brief Set the pan of the sound
///
/// Using panning, a mono sound can be panned between
/// stereo channels. When the pan is set to -1, the sound
/// is played only on the left channel, when the pan is set
/// to +1, the sound is played only on the right channel.
///
/// \param soundStream Sound stream object
/// \param pan         New pan to apply to the sound [-1, +1]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setPan(sfSoundStream* soundStream, float pan);

////////////////////////////////////////////////////////////
/// \brief Set the volume of a sound stream
///
/// The volume is a value between 0 (mute) and 100 (full volume).
/// The default value for the volume is 100.
///
/// \param soundStream Sound stream object
/// \param volume      Volume of the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setVolume(sfSoundStream* soundStream, float volume);

////////////////////////////////////////////////////////////
/// \brief Set whether spatialization of the sound is enabled
///
/// Spatialization is the application of various effects to
/// simulate a sound being emitted at a virtual position in
/// 3D space and exhibiting various physical phenomena such as
/// directional attenuation and doppler shift.
///
/// \param soundStream Sound stream object
/// \param enabled     `true` to enable spatialization, `false` to disable
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setSpatializationEnabled(sfSoundStream* soundStream, bool enabled);

////////////////////////////////////////////////////////////
/// \brief Set the 3D position of a sound stream in the audio scene
///
/// Only streams with one channel (mono streams) can be
/// spatialized.
/// The default position of a stream is (0, 0, 0).
///
/// \param soundStream Sound stream object
/// \param position    Position of the stream in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setPosition(sfSoundStream* soundStream, sfVector3f position);

////////////////////////////////////////////////////////////
/// \brief Set the 3D direction of the sound in the audio scene
///
/// The direction defines where the sound source is facing
/// in 3D space. It will affect how the sound is attenuated
/// if facing away from the listener.
/// The default direction of a sound is (0, 0, -1).
///
/// \param soundStream Sound stream object
/// \param direction   Direction of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setDirection(sfSoundStream* soundStream, sfVector3f direction);

////////////////////////////////////////////////////////////
/// \brief Set the cone properties of the sound in the audio scene
///
/// The cone defines how directional attenuation is applied.
/// The default cone of a sound is (2 * PI, 2 * PI, 1).
///
/// \param soundStream Sound stream object
/// \param cone        Cone properties of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setCone(sfSoundStream* soundStream, sfSoundSourceCone cone);

////////////////////////////////////////////////////////////
/// \brief Set the 3D velocity of the sound in the audio scene
///
/// The velocity is used to determine how to doppler shift
/// the sound. Sounds moving towards the listener will be
/// perceived to have a higher pitch and sounds moving away
/// from the listener will be perceived to have a lower pitch.
///
/// \param soundStream Sound stream object
/// \param velocity    Velocity of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setVelocity(sfSoundStream* soundStream, sfVector3f velocity);

////////////////////////////////////////////////////////////
/// \brief Set the doppler factor of the sound
///
/// The doppler factor determines how strong the doppler
/// shift will be.
///
/// \param soundStream Sound stream object
/// \param factor      New doppler factor to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setDopplerFactor(sfSoundStream* soundStream, float factor);

////////////////////////////////////////////////////////////
/// \brief Set the directional attenuation factor of the sound
///
/// Depending on the virtual position of an output channel
/// relative to the listener (such as in surround sound
/// setups), sounds will be attenuated when emitting them
/// from certain channels. This factor determines how strong
/// the attenuation based on output channel position
/// relative to the listener is.
///
/// \param soundStream Sound stream object
/// \param factor      New directional attenuation factor to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setDirectionalAttenuationFactor(sfSoundStream* soundStream, float factor);

////////////////////////////////////////////////////////////
/// \brief Make a sound stream's position relative to the listener or absolute
///
/// Making a stream relative to the listener will ensure that it will always
/// be played the same way regardless the position of the listener.
/// This can be useful for non-spatialized streams, streams that are
/// produced by the listener, or streams attached to it.
/// The default value is false (position is absolute).
///
/// \param soundStream Sound stream object
/// \param relative    true to set the position relative, false to set it absolute
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setRelativeToListener(sfSoundStream* soundStream, bool relative);

////////////////////////////////////////////////////////////
/// \brief Set the minimum distance of a sound stream
///
/// The "minimum distance" of a stream is the maximum
/// distance at which it is heard at its maximum volume. Further
/// than the minimum distance, it will start to fade out according
/// to its attenuation factor. A value of 0 ("inside the head
/// of the listener") is an invalid value and is forbidden.
/// The default value of the minimum distance is 1.
///
/// \param soundStream Sound stream object
/// \param distance    New minimum distance of the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setMinDistance(sfSoundStream* soundStream, float distance);

////////////////////////////////////////////////////////////
/// \brief Set the maximum distance of the sound
///
/// The "maximum distance" of a sound is the minimum
/// distance at which it is heard at its minimum volume. Closer
/// than the maximum distance, it will start to fade in according
/// to its attenuation factor.
/// The default value of the maximum distance is the maximum
/// value a float can represent.
///
/// \param soundStream Sound stream object
/// \param distance    New maximum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setMaxDistance(sfSoundStream* soundStream, float distance);

////////////////////////////////////////////////////////////
/// \brief Set the minimum gain of the sound
///
/// When the sound is further away from the listener than
/// the "maximum distance" the attenuated gain is clamped
/// so it cannot go below the minimum gain value.
///
/// \param soundStream Sound stream object
/// \param gain        New minimum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setMinGain(sfSoundStream* soundStream, float gain);

////////////////////////////////////////////////////////////
/// \brief Set the maximum gain of the sound
///
/// When the sound is closer from the listener than
/// the "minimum distance" the attenuated gain is clamped
/// so it cannot go above the maximum gain value.
///
/// \param soundStream Sound stream object
/// \param gain        New maximum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setMaxGain(sfSoundStream* soundStream, float gain);

////////////////////////////////////////////////////////////
/// \brief Set the attenuation factor of a sound stream
///
/// The attenuation is a multiplicative factor which makes
/// the stream more or less loud according to its distance
/// from the listener. An attenuation of 0 will produce a
/// non-attenuated stream, i.e. its volume will always be the same
/// whether it is heard from near or from far. On the other hand,
/// an attenuation value such as 100 will make the stream fade out
/// very quickly as it gets further from the listener.
/// The default value of the attenuation is 1.
///
/// \param soundStream Sound stream object
/// \param attenuation New attenuation factor of the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setAttenuation(sfSoundStream* soundStream, float attenuation);

////////////////////////////////////////////////////////////
/// \brief Change the current playing position of a sound stream
///
/// The playing position can be changed when the stream is
/// either paused or playing.
///
/// \param soundStream Sound stream object
/// \param timeOffset  New playing position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setPlayingOffset(sfSoundStream* soundStream, sfTime timeOffset);

////////////////////////////////////////////////////////////
/// \brief Set whether or not a sound stream should loop after reaching the end
///
/// If set, the stream will restart from beginning after
/// reaching the end and so on, until it is stopped or
/// sfSoundStream_setLooping(stream, false) is called.
/// The default looping state for sound streams is false.
///
/// \param soundStream Sound stream object
/// \param loop        true to play in loop, false to play once
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setLooping(sfSoundStream* soundStream, bool loop);

////////////////////////////////////////////////////////////
/// \brief Get the pitch of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Pitch of the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getPitch(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the pan of the sound
///
/// \param soundStream Sound stream object
///
/// \return Pan of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getPan(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the volume of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Volume of the stream, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getVolume(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Tell whether spatialization of the sound is enabled
///
/// \param soundStream Sound stream object
///
/// \return `true` if spatialization is enabled, `false` if it's disabled
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSoundStream_isSpatializationEnabled(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the 3D position of a sound stream in the audio scene
///
/// \param soundStream Sound stream object
///
/// \return Position of the stream in the world
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfSoundStream_getPosition(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the 3D direction of the sound in the audio scene
///
/// \param soundStream Sound stream object
///
/// \return Direction of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfSoundStream_getDirection(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the cone properties of the sound in the audio scene
///
/// \param soundStream Sound stream object
///
/// \return Cone properties of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundSourceCone sfSoundStream_getCone(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the 3D velocity of the sound in the audio scene
///
/// \param soundStream Sound stream object
///
/// \return Velocity of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfSoundStream_getVelocity(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the doppler factor of the sound
///
/// \param soundStream Sound stream object
///
/// \return Doppler factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getDopplerFactor(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the directional attenuation factor of the sound
///
/// \param soundStream Sound stream object
///
/// \return Directional attenuation factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getDirectionalAttenuationFactor(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Tell whether a sound stream's position is relative to the
///        listener or is absolute
///
/// \param soundStream Sound stream object
///
/// \return true if the position is relative, false if it's absolute
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSoundStream_isRelativeToListener(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the minimum distance of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Minimum distance of the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getMinDistance(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the maximum distance of the sound
///
/// \param soundStream Sound stream object
///
/// \return Maximum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getMaxDistance(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the minimum gain of the sound
///
/// \param soundStream Sound stream object
///
/// \return Minimum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getMinGain(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the maximum gain of the sound
///
/// \param soundStream Sound stream object
///
/// \return Maximum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getMaxGain(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Get the attenuation factor of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Attenuation factor of the stream
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSoundStream_getAttenuation(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a sound stream is in loop mode
///
/// \param soundStream Sound stream object
///
/// \return true if the music is looping, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSoundStream_isLooping(const sfSoundStream* soundStream);

////////////////////////////////////////////////////////////
/// \brief Set the effect processor to be applied to the sound
///
/// The effect processor is a callable that will be called
/// with sound data to be processed.
///
/// \param soundStream Sound stream object
/// \param effectProcessor The effect processor to attach to this sound, attach an empty processor to disable processing
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSoundStream_setEffectProcessor(sfSoundStream* soundStream, sfEffectProcessor effectProcessor);

////////////////////////////////////////////////////////////
/// \brief Get the current playing position of a sound stream
///
/// \param soundStream Sound stream object
///
/// \return Current playing position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfTime sfSoundStream_getPlayingOffset(const sfSoundStream* soundStream);
