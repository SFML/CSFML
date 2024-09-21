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
#include <CSFML/Audio/SoundSourceCone.h>
#include <CSFML/Audio/SoundStatus.h>
#include <CSFML/Audio/Types.h>
#include <CSFML/System/Time.h>
#include <CSFML/System/Vector3.h>


////////////////////////////////////////////////////////////
/// \brief Create a new sound
///
/// \param buffer Sound buffer containing the audio data to play with the sound
///
/// \return A new sfSound object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSound* sfSound_create(const sfSoundBuffer* buffer);

////////////////////////////////////////////////////////////
/// \brief Create a new sound by copying an existing one
///
/// \param sound Sound to copy
///
/// \return A new sfSound object which is a copy of \a sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSound* sfSound_copy(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Destroy a sound
///
/// \param sound Sound to destroy
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_destroy(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Start or resume playing a sound
///
/// This function starts the sound if it was stopped, resumes
/// it if it was paused, and restarts it from beginning if it
/// was it already playing.
/// This function uses its own thread so that it doesn't block
/// the rest of the program while the sound is played.
///
/// \param sound Sound object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_play(sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Pause a sound
///
/// This function pauses the sound if it was playing,
/// otherwise (sound already paused or stopped) it has no effect.
///
/// \param sound Sound object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_pause(sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Stop playing a sound
///
/// This function stops the sound if it was playing or paused,
/// and does nothing if it was already stopped.
/// It also resets the playing position (unlike sfSound_pause).
///
/// \param sound Sound object
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_stop(sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Set the source buffer containing the audio data to play
///
/// It is important to note that the sound buffer is not copied,
/// thus the sfSoundBuffer object must remain alive as long
/// as it is attached to the sound.
///
/// \param sound  Sound object
/// \param buffer Sound buffer to attach to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setBuffer(sfSound* sound, const sfSoundBuffer* buffer);

////////////////////////////////////////////////////////////
/// \brief Get the audio buffer attached to a sound
///
/// \param sound Sound object
///
/// \return Sound buffer attached to the sound (can be NULL)
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API const sfSoundBuffer* sfSound_getBuffer(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Set whether or not a sound should loop after reaching the end
///
/// If set, the sound will restart from beginning after
/// reaching the end and so on, until it is stopped or
/// sfSound_setLooping(sound, false) is called.
/// The default looping state for sounds is false.
///
/// \param sound Sound object
/// \param loop  true to play in loop, false to play once
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setLooping(sfSound* sound, bool loop);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a sound is in loop mode
///
/// \param sound Sound object
///
/// \return true if the sound is looping, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSound_isLooping(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the current status of a sound (stopped, paused, playing)
///
/// \param sound Sound object
///
/// \return Current status
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundStatus sfSound_getStatus(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Set the pitch of a sound
///
/// The pitch represents the perceived fundamental frequency
/// of a sound; thus you can make a sound more acute or grave
/// by changing its pitch. A side effect of changing the pitch
/// is to modify the playing speed of the sound as well.
/// The default value for the pitch is 1.
///
/// \param sound Sound object
/// \param pitch New pitch to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setPitch(sfSound* sound, float pitch);

////////////////////////////////////////////////////////////
/// \brief Set the pan of the sound
///
/// Using panning, a mono sound can be panned between
/// stereo channels. When the pan is set to -1, the sound
/// is played only on the left channel, when the pan is set
/// to +1, the sound is played only on the right channel.
///
/// \param sound Sound object
/// \param pan   New pan to apply to the sound [-1, +1]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setPan(sfSound* sound, float pan);


////////////////////////////////////////////////////////////
/// \brief Set the volume of a sound
///
/// The volume is a value between 0 (mute) and 100 (full volume).
/// The default value for the volume is 100.
///
/// \param sound  Sound object
/// \param volume Volume of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setVolume(sfSound* sound, float volume);

////////////////////////////////////////////////////////////
/// \brief Set whether spatialization of the sound is enabled
///
/// Spatialization is the application of various effects to
/// simulate a sound being emitted at a virtual position in
/// 3D space and exhibiting various physical phenomena such as
/// directional attenuation and doppler shift.
///
/// \param sound   Sound object
/// \param enabled `true` to enable spatialization, `false` to disable
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setSpatializationEnabled(sfSound* sound, bool enabled);

////////////////////////////////////////////////////////////
/// \brief Set the 3D position of a sound in the audio scene
///
/// Only sounds with one channel (mono sounds) can be
/// spatialized.
/// The default position of a sound is (0, 0, 0).
///
/// \param sound    Sound object
/// \param position Position of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setPosition(sfSound* sound, sfVector3f position);

////////////////////////////////////////////////////////////
/// \brief Set the 3D direction of the sound in the audio scene
///
/// The direction defines where the sound source is facing
/// in 3D space. It will affect how the sound is attenuated
/// if facing away from the listener.
/// The default direction of a sound is (0, 0, -1).
///
/// \param sound     Sound object
/// \param direction Direction of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setDirection(sfSound* sound, sfVector3f direction);

////////////////////////////////////////////////////////////
/// \brief Set the cone properties of the sound in the audio scene
///
/// The cone defines how directional attenuation is applied.
/// The default cone of a sound is (2 * PI, 2 * PI, 1).
///
/// \param sound Sound object
/// \param cone  Cone properties of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setCone(sfSound* sound, sfSoundSourceCone cone);

////////////////////////////////////////////////////////////
/// \brief Set the 3D velocity of the sound in the audio scene
///
/// The velocity is used to determine how to doppler shift
/// the sound. Sounds moving towards the listener will be
/// perceived to have a higher pitch and sounds moving away
/// from the listener will be perceived to have a lower pitch.
///
/// \param sound    Sound object
/// \param velocity Velocity of the sound in the scene
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setVelocity(sfSound* sound, sfVector3f velocity);

////////////////////////////////////////////////////////////
/// \brief Set the doppler factor of the sound
///
/// The doppler factor determines how strong the doppler
/// shift will be.
///
/// \param sound  Sound object
/// \param factor New doppler factor to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setDopplerFactor(sfSound* sound, float factor);

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
/// \param sound  Sound object
/// \param factor New directional attenuation factor to apply to the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setDirectionalAttenuationFactor(sfSound* sound, float factor);

////////////////////////////////////////////////////////////
/// \brief Make the sound's position relative to the listener or absolute
///
/// Making a sound relative to the listener will ensure that it will always
/// be played the same way regardless the position of the listener.
/// This can be useful for non-spatialized sounds, sounds that are
/// produced by the listener, or sounds attached to it.
/// The default value is false (position is absolute).
///
/// \param sound    Sound object
/// \param relative true to set the position relative, false to set it absolute
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setRelativeToListener(sfSound* sound, bool relative);

////////////////////////////////////////////////////////////
/// \brief Set the minimum distance of a sound
///
/// The "minimum distance" of a sound is the maximum
/// distance at which it is heard at its maximum volume. Further
/// than the minimum distance, it will start to fade out according
/// to its attenuation factor. A value of 0 ("inside the head
/// of the listener") is an invalid value and is forbidden.
/// The default value of the minimum distance is 1.
///
/// \param sound    Sound object
/// \param distance New minimum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setMinDistance(sfSound* sound, float distance);

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
/// \param sound    Sound object
/// \param distance New maximum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setMaxDistance(sfSound* sound, float distance);

////////////////////////////////////////////////////////////
/// \brief Set the minimum gain of the sound
///
/// When the sound is further away from the listener than
/// the "maximum distance" the attenuated gain is clamped
/// so it cannot go below the minimum gain value.
///
/// \param sound Sound object
/// \param gain  New minimum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setMinGain(sfSound* sound, float gain);

////////////////////////////////////////////////////////////
/// \brief Set the maximum gain of the sound
///
/// When the sound is closer from the listener than
/// the "minimum distance" the attenuated gain is clamped
/// so it cannot go above the maximum gain value.
///
///
/// \param sound Sound object
/// \param gain  New maximum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setMaxGain(sfSound* sound, float gain);

////////////////////////////////////////////////////////////
/// \brief Set the attenuation factor of a sound
///
/// The attenuation is a multiplicative factor which makes
/// the sound more or less loud according to its distance
/// from the listener. An attenuation of 0 will produce a
/// non-attenuated sound, i.e. its volume will always be the same
/// whether it is heard from near or from far. On the other hand,
/// an attenuation value such as 100 will make the sound fade out
/// very quickly as it gets further from the listener.
/// The default value of the attenuation is 1.
///
/// \param sound       Sound object
/// \param attenuation New attenuation factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setAttenuation(sfSound* sound, float attenuation);

////////////////////////////////////////////////////////////
/// \brief Change the current playing position of a sound
///
/// The playing position can be changed when the sound is
/// either paused or playing.
///
/// \param sound      Sound object
/// \param timeOffset New playing position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setPlayingOffset(sfSound* sound, sfTime timeOffset);

////////////////////////////////////////////////////////////
/// \brief Set the effect processor to be applied to the sound
///
/// The effect processor is a callable that will be called
/// with sound data to be processed.
///
/// \param sound           Sound object
/// \param effectProcessor The effect processor to attach to this sound, attach an empty processor to disable processing
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API void sfSound_setEffectProcessor(sfSound* sound, sfEffectProcessor effectProcessor);

////////////////////////////////////////////////////////////
/// \brief Get the pitch of a sound
///
/// \param sound Sound object
///
/// \return Pitch of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getPitch(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the pan of the sound
///
/// \param sound Sound object
///
/// \return Pan of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getPan(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the volume of a sound
///
/// \param sound Sound object
///
/// \return Volume of the sound, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getVolume(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Tell whether spatialization of the sound is enabled
///
/// \param sound Sound object
///
/// \return `true` if spatialization is enabled, `false` if it's disabled
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSound_isSpatializationEnabled(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the 3D position of a sound in the audio scene
///
/// \param sound Sound object
///
/// \return Position of the sound in the world
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfSound_getPosition(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the 3D direction of the sound in the audio scene
///
/// \param sound Sound object
///
/// \return Direction of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfSound_getDirection(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the cone properties of the sound in the audio scene
///
/// \param sound Sound object
///
/// \return Cone properties of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfSoundSourceCone sfSound_getCone(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the 3D velocity of the sound in the audio scene
///
/// \param sound Sound object
///
/// \return Velocity of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfVector3f sfSound_getVelocity(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the doppler factor of the sound
///
/// \param sound Sound object
///
/// \return Doppler factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getDopplerFactor(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the directional attenuation factor of the sound
///
/// \param sound Sound object
///
/// \return Directional attenuation factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getDirectionalAttenuationFactor(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Tell whether a sound's position is relative to the
///        listener or is absolute
///
/// \param sound Sound object
///
/// \return true if the position is relative, false if it's absolute
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API bool sfSound_isRelativeToListener(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the minimum distance of a sound
///
/// \param sound Sound object
///
/// \return Minimum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getMinDistance(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the maximum distance of the sound
///
/// \param sound Sound object
///
/// \return Maximum distance of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getMaxDistance(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the minimum gain of the sound
///
/// \param sound Sound object
///
/// \return Minimum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getMinGain(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the maximum gain of the sound
///
/// \param sound Sound object
///
/// \return Maximum gain of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getMaxGain(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the attenuation factor of a sound
///
/// \param sound Sound object
///
/// \return Attenuation factor of the sound
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API float sfSound_getAttenuation(const sfSound* sound);

////////////////////////////////////////////////////////////
/// \brief Get the current playing position of a sound
///
/// \param sound Sound object
///
/// \return Current playing position
///
////////////////////////////////////////////////////////////
CSFML_AUDIO_API sfTime sfSound_getPlayingOffset(const sfSound* sound);
