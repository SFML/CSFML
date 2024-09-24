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
#include <CSFML/System/InputStream.h>
#include <CSFML/System/Time.h>
#include <CSFML/System/Vector3.h>

#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Structure defining a time range
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfTime offset; ///< The beginning offset of the time range
    sfTime length; ///< The length of the time range
} sfTimeSpan;


////////////////////////////////////////////////////////////
/// \brief Create a new music and load it from a file
///
/// This function doesn't start playing the music (call
/// sfMusic_play to do so).
/// Here is a complete list of all the supported audio formats:
/// ogg, wav, flac, mp3, aiff, au, raw, paf, svx, nist, voc, ircam,
/// w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
///
/// \param filename Path of the music file to open
///
/// \return A new sfMusic object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfMusic* sfMusic_createFromFile(const char* filename);

////////////////////////////////////////////////////////////
/// \brief Create a new music and load it from a file in memory
///
/// This function doesn't start playing the music (call
/// sfMusic_play to do so).
/// Here is a complete list of all the supported audio formats:
/// ogg, wav, flac, mp3, aiff, au, raw, paf, svx, nist, voc, ircam,
/// w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
///
/// \param data        Pointer to the file data in memory
/// \param sizeInBytes Size of the data to load, in bytes
///
/// \return A new sfMusic object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfMusic* sfMusic_createFromMemory(const void* data, size_t sizeInBytes);

////////////////////////////////////////////////////////////
/// \brief Create a new music and load it from a custom stream
///
/// This function doesn't start playing the music (call
/// sfMusic_play to do so).
/// Here is a complete list of all the supported audio formats:
/// ogg, wav, flac, mp3, aiff, au, raw, paf, svx, nist, voc, ircam,
/// w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
///
/// \param stream Source stream to read from
///
/// \return A new sfMusic object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfMusic* sfMusic_createFromStream(sfInputStream* stream);

////////////////////////////////////////////////////////////
/// \brief Destroy a music
///
/// \param music Music to destroy
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_destroy(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Set whether or not a music should loop after reaching the end
///
/// If set, the music will restart from beginning after
/// reaching the end and so on, until it is stopped or
/// sfMusic_setLooping(music, false) is called.
/// The default looping state for musics is false.
///
/// \param music Music object
/// \param loop  true to play in loop, false to play once
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setLooping(sfMusic* music, bool loop);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a music is in loop mode
///
/// \param music Music object
///
/// \return true if the music is looping, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfMusic_isLooping(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Set the effect processor to be applied to the sound
///
/// The effect processor is a callable that will be called
/// with sound data to be processed.
///
/// \param music           Music object
/// \param effectProcessor The effect processor to attach to this sound, attach a null processor to disable processing
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setEffectProcessor(sfMusic* music, sfEffectProcessor effectProcessor);

////////////////////////////////////////////////////////////
/// \brief Get the total duration of a music
///
/// \param music Music object
///
/// \return Music duration
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfTime sfMusic_getDuration(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the positions of the of the sound's looping sequence
///
/// \param music Music object
///
/// \return Loop Time position class.
///
/// \warning Since sfMusic_setLoopPoints() performs some adjustments on the
/// provided values and rounds them to internal samples, a call to
/// sfMusic_getLoopPoints() is not guaranteed to return the same times passed
/// into a previous call to sfMusic_setLoopPoints(). However, it is guaranteed
/// to return times that will map to the valid internal samples of
/// this Music if they are later passed to sfMusic_setLoopPoints().
///
/// \see setLoopPoints
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfTimeSpan sfMusic_getLoopPoints(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Sets the beginning and end of the sound's looping sequence using sfTime
///
/// Loop points allow one to specify a pair of positions such that, when the music
/// is enabled for looping, it will seamlessly seek to the beginning whenever it
/// encounters the end. Valid ranges for timePoints.offset and timePoints.length are
/// [0, Dur) and (0, Dur-offset] respectively, where Dur is the value returned by sfMusic_getDuration().
/// Note that the EOF "loop point" from the end to the beginning of the stream is still honored,
/// in case the caller seeks to a point after the end of the loop range. This function can be
/// safely called at any point after a stream is opened, and will be applied to a playing sound
/// without affecting the current playing offset.
///
/// \warning Setting the loop points while the stream's status is Paused
/// will set its status to Stopped. The playing offset will be unaffected.
///
/// \param music      Music object
/// \param timePoints The definition of the loop. Can be any time points within the sound's length
///
/// \see getLoopPoints
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setLoopPoints(sfMusic* music, sfTimeSpan timePoints);

////////////////////////////////////////////////////////////
/// \brief Start or resume playing a music
///
/// This function starts the music if it was stopped, resumes
/// it if it was paused, and restarts it from beginning if it
/// was it already playing.
/// This function uses its own thread so that it doesn't block
/// the rest of the program while the music is played.
///
/// \param music Music object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_play(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Pause a music
///
/// This function pauses the music if it was playing,
/// otherwise (music already paused or stopped) it has no effect.
///
/// \param music Music object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_pause(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Stop playing a music
///
/// This function stops the music if it was playing or paused,
/// and does nothing if it was already stopped.
/// It also resets the playing position (unlike sfMusic_pause).
///
/// \param music Music object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_stop(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Return the number of channels of a music
///
/// 1 channel means a mono sound, 2 means stereo, etc.
///
/// \param music Music object
///
/// \return Number of channels
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API unsigned int sfMusic_getChannelCount(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the sample rate of a music
///
/// The sample rate is the number of audio samples played per
/// second. The higher, the better the quality.
///
/// \param music Music object
///
/// \return Sample rate, in number of samples per second
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API unsigned int sfMusic_getSampleRate(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the map of position in sample frame to sound channel
///
/// This is used to map a sample in the sample stream to a
/// position during spatialization.
///
/// \param music Music object
/// \param count Pointer to a variable that will be filled with the number of channels in the map
///
/// \return Map of position in sample frame to sound channel
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API const sfSoundChannel* sfMusic_getChannelMap(const sfMusic* music, size_t* count);

////////////////////////////////////////////////////////////
/// \brief Get the current status of a music (stopped, paused, playing)
///
/// \param music Music object
///
/// \return Current status
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundStatus sfMusic_getStatus(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the current playing position of a music
///
/// \param music Music object
///
/// \return Current playing position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfTime sfMusic_getPlayingOffset(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Set the pitch of a music
///
/// The pitch represents the perceived fundamental frequency
/// of a sound; thus you can make a music more acute or grave
/// by changing its pitch. A side effect of changing the pitch
/// is to modify the playing speed of the music as well.
/// The default value for the pitch is 1.
///
/// \param music Music object
/// \param pitch New pitch to apply to the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setPitch(sfMusic* music, float pitch);

////////////////////////////////////////////////////////////
/// \brief Set the pan of the sound
///
/// Using panning, a mono sound can be panned between
/// stereo channels. When the pan is set to -1, the sound
/// is played only on the left channel, when the pan is set
/// to +1, the sound is played only on the right channel.
///
/// \param music Music object
/// \param pan   New pan to apply to the sound [-1, +1]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setPan(sfMusic* music, float pan);

////////////////////////////////////////////////////////////
/// \brief Set the volume of a music
///
/// The volume is a value between 0 (mute) and 100 (full volume).
/// The default value for the volume is 100.
///
/// \param music  Music object
/// \param volume Volume of the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setVolume(sfMusic* music, float volume);

////////////////////////////////////////////////////////////
/// \brief Set whether spatialization of the sound is enabled
///
/// Spatialization is the application of various effects to
/// simulate a sound being emitted at a virtual position in
/// 3D space and exhibiting various physical phenomena such as
/// directional attenuation and doppler shift.
///
/// \param music   Music object
/// \param enabled `true` to enable spatialization, `false` to disable
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setSpatializationEnabled(sfMusic* music, bool enabled);

////////////////////////////////////////////////////////////
/// \brief Set the 3D position of a music in the audio scene
///
/// Only musics with one channel (mono musics) can be
/// spatialized.
/// The default position of a music is (0, 0, 0).
///
/// \param music    Music object
/// \param position Position of the music in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setPosition(sfMusic* music, sfVector3f position);

////////////////////////////////////////////////////////////
/// \brief Set the 3D direction of the sound in the audio scene
///
/// The direction defines where the sound source is facing
/// in 3D space. It will affect how the sound is attenuated
/// if facing away from the listener.
/// The default direction of a sound is (0, 0, -1).
///
/// \param music     Music object
/// \param direction Direction of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setDirection(sfMusic* music, sfVector3f direction);

////////////////////////////////////////////////////////////
/// \brief Set the cone properties of the sound in the audio scene
///
/// The cone defines how directional attenuation is applied.
/// The default cone of a sound is (2 * PI, 2 * PI, 1).
///
/// \param music Music object
/// \param cone  Cone properties of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setCone(sfMusic* music, sfSoundSourceCone cone);

////////////////////////////////////////////////////////////
/// \brief Set the 3D velocity of the sound in the audio scene
///
/// The velocity is used to determine how to doppler shift
/// the sound. Sounds moving towards the listener will be
/// perceived to have a higher pitch and sounds moving away
/// from the listener will be perceived to have a lower pitch.
///
/// \param music    Music object
/// \param velocity Velocity of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setVelocity(sfMusic* music, sfVector3f velocity);

////////////////////////////////////////////////////////////
/// \brief Set the doppler factor of the sound
///
/// The doppler factor determines how strong the doppler
/// shift will be.
///
/// \param music  Music object
/// \param factor New doppler factor to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setDopplerFactor(sfMusic* music, float factor);

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
/// \param music  Music object
/// \param factor New directional attenuation factor to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setDirectionalAttenuationFactor(sfMusic* music, float factor);

////////////////////////////////////////////////////////////
/// \brief Make a musics's position relative to the listener or absolute
///
/// Making a music relative to the listener will ensure that it will always
/// be played the same way regardless the position of the listener.
/// This can be useful for non-spatialized musics, musics that are
/// produced by the listener, or musics attached to it.
/// The default value is false (position is absolute).
///
/// \param music    Music object
/// \param relative true to set the position relative, false to set it absolute
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setRelativeToListener(sfMusic* music, bool relative);

////////////////////////////////////////////////////////////
/// \brief Set the minimum distance of a music
///
/// The "minimum distance" of a music is the maximum
/// distance at which it is heard at its maximum volume. Further
/// than the minimum distance, it will start to fade out according
/// to its attenuation factor. A value of 0 ("inside the head
/// of the listener") is an invalid value and is forbidden.
/// The default value of the minimum distance is 1.
///
/// \param music    Music object
/// \param distance New minimum distance of the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setMinDistance(sfMusic* music, float distance);

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
/// \param music    Music object
/// \param distance New maximum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setMaxDistance(sfMusic* music, float distance);

////////////////////////////////////////////////////////////
/// \brief Set the minimum gain of the sound
///
/// When the sound is further away from the listener than
/// the "maximum distance" the attenuated gain is clamped
/// so it cannot go below the minimum gain value.
///
/// \param music Music object
/// \param gain  New minimum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setMinGain(sfMusic* music, float gain);

////////////////////////////////////////////////////////////
/// \brief Set the maximum gain of the sound
///
/// When the sound is closer from the listener than
/// the "minimum distance" the attenuated gain is clamped
/// so it cannot go above the maximum gain value.
///
/// \param music Music object
/// \param gain  New maximum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setMaxGain(sfMusic* music, float gain);

////////////////////////////////////////////////////////////
/// \brief Set the attenuation factor of a music
///
/// The attenuation is a multiplicative factor which makes
/// the music more or less loud according to its distance
/// from the listener. An attenuation of 0 will produce a
/// non-attenuated music, i.e. its volume will always be the same
/// whether it is heard from near or from far. On the other hand,
/// an attenuation value such as 100 will make the music fade out
/// very quickly as it gets further from the listener.
/// The default value of the attenuation is 1.
///
/// \param music       Music object
/// \param attenuation New attenuation factor of the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setAttenuation(sfMusic* music, float attenuation);

////////////////////////////////////////////////////////////
/// \brief Change the current playing position of a music
///
/// The playing position can be changed when the music is
/// either paused or playing.
///
/// \param music      Music object
/// \param timeOffset New playing position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfMusic_setPlayingOffset(sfMusic* music, sfTime timeOffset);

////////////////////////////////////////////////////////////
/// \brief Get the pitch of a music
///
/// \param music Music object
///
/// \return Pitch of the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getPitch(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the pan of the sound
///
/// \param music Music object
///
/// \return Pan of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getPan(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Tell whether spatialization of the sound is enabled
///
/// \param music Music object
///
/// \return `true` if spatialization is enabled, `false` if it's disabled
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfMusic_isSpatializationEnabled(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the volume of a music
///
/// \param music Music object
///
/// \return Volume of the music, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getVolume(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the 3D position of a music in the audio scene
///
/// \param music Music object
///
/// \return Position of the music in the world
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfMusic_getPosition(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the 3D direction of the sound in the audio scene
///
/// \param music Music object
///
/// \return Direction of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfMusic_getDirection(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the cone properties of the sound in the audio scene
///
/// \param music Music object
///
/// \return Cone properties of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundSourceCone sfMusic_getCone(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the 3D velocity of the sound in the audio scene
///
/// \param music Music object
///
/// \return Velocity of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfMusic_getVelocity(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the doppler factor of the sound
///
/// \param music Music object
///
/// \return Doppler factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getDopplerFactor(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the directional attenuation factor of the sound
///
/// \param music Music object
///
/// \return Directional attenuation factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getDirectionalAttenuationFactor(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Tell whether a music's position is relative to the
///        listener or is absolute
///
/// \param music Music object
///
/// \return true if the position is relative, false if it's absolute
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfMusic_isRelativeToListener(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the minimum distance of a music
///
/// \param music Music object
///
/// \return Minimum distance of the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getMinDistance(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the maximum distance of the sound
///
/// \param music Music object
///
/// \return Maximum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getMaxDistance(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the minimum gain of the sound
///
/// \param music Music object
///
/// \return Minimum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getMinGain(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the maximum gain of the sound
///
/// \param music Music object
///
/// \return Maximum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getMaxGain(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the attenuation factor of a music
///
/// \param music Music object
///
/// \return Attenuation factor of the music
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfMusic_getAttenuation(const sfMusic* music);
