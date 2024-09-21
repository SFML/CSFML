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
/// \brief Callable that is provided with sound data for processing
///
/// When the audio engine sources sound data from sound
/// sources it will pass the data through an effects
/// processor if one is set. The sound data will already be
/// converted to the internal floating point format.
///
/// Sound data that is processed this way is provided in
/// frames. Each frame contains 1 floating point sample per
/// channel. If e.g. the data source provides stereo data,
/// each frame will contain 2 floats.
///
/// The effects processor function takes 4 parameters:
///   - The input data frames, channels interleaved
///   - The number of input data frames available
///   - The buffer to write output data frames to, channels interleaved
///   - The number of output data frames that the output buffer can hold
///   - The channel count
///
/// The input and output frame counts are in/out parameters.
///
/// When this function is called, the input count will
/// contain the number of frames available in the input
/// buffer. The output count will contain the size of the
/// output buffer i.e. the maximum number of frames that
/// can be written to the output buffer.
///
/// Attempting to read more frames than the input frame
/// count or write more frames than the output frame count
/// will result in undefined behaviour.
///
/// It is important to note that the channel count of the
/// audio engine currently sourcing data from this sound
/// will always be provided in `frameChannelCount`. This can
/// be different from the channel count of the sound source
/// so make sure to size necessary processing buffers
/// according to the engine channel count and not the sound
/// source channel count.
///
/// When done processing the frames, the input and output
/// frame counts must be updated to reflect the actual
/// number of frames that were read from the input and
/// written to the output.
///
/// The processing function should always try to process as
/// much sound data as possible i.e. always try to fill the
/// output buffer to the maximum. In certain situations for
/// specific effects it can be possible that the input frame
/// count and output frame count aren't equal. As long as
/// the frame counts are updated accordingly this is
/// perfectly valid.
///
/// If the audio engine determines that no audio data is
/// available from the data source, the input data frames
/// pointer is set to `NULL` and the input frame count is
/// set to 0. In this case it is up to the function to
/// decide how to handle the situation. For specific effects
/// e.g. Echo/Delay buffered data might still be able to be
/// written to the output buffer even if there is no longer
/// any input data.
///
/// An important thing to remember is that this function is
/// directly called by the audio engine. Because the audio
/// engine runs on an internal thread of its own, make sure
/// access to shared data is synchronized appropriately.
///
/// Because this function is stored by the `SoundSource`
/// object it will be able to be called as long as the
/// `SoundSource` object hasn't yet been destroyed. Make sure
/// that any data this function references outlives the
/// SoundSource object otherwise use-after-free errors will
/// occur.
///
////////////////////////////////////////////////////////////
typedef void (*sfEffectProcessor)(const float*  inputFrames,
                                  unsigned int* inputFrameCount,
                                  float*        outputFrames,
                                  unsigned int* outputFrameCount,
                                  unsigned int  frameChannelCount);
