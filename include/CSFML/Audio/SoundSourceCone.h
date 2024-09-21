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
/// \brief Structure defining the properties of a directional cone
///
/// Sounds will play at gain 1 when the listener
/// is positioned within the inner angle of the cone.
/// Sounds will play at `outerGain` when the listener is
/// positioned outside the outer angle of the cone.
/// The gain declines linearly from 1 to `outerGain` as the
/// listener moves from the inner angle to the outer angle.
///
////////////////////////////////////////////////////////////
typedef struct
{
    float innerAngle; //!< Inner angle, in degrees
    float outerAngle; //!< Outer angle, in degrees
    float outerGain;  //!< Outer gain
} sfSoundSourceCone;
