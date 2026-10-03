////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2026 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/System/Time.h>

#include <stdbool.h>


////////////////////////////////////////////////////////////
/// \brief Predicate that returns true to continue or false to time out
///
/// \param userData User data stored in the sfTimeoutWithPredicate
///
/// \return True to continue, false to time out
///
////////////////////////////////////////////////////////////
typedef bool (*sfTimeoutPredicate)(void* userData);

////////////////////////////////////////////////////////////
/// \brief Hybrid of a timeout and a continuation predicate
///
/// Functions taking a timeout parameter that is specified
/// solely by a time cannot be easily interrupted. A predicate
/// allows interrupting the operation at any time, e.g. when
/// the user cancels it.
///
/// If \a predicate is NULL, the operation times out after
/// \a timeout (0 meaning no timeout). If \a predicate is set,
/// \a timeout is ignored and the operation times out once the
/// predicate returns false. The predicate is checked every
/// \a period, a period of 0 checks it every millisecond.
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfTime             timeout;   ///< Time to time out after, if no predicate is set
    sfTimeoutPredicate predicate; ///< Predicate that returns true to continue or false to time out, can be NULL
    void*              userData;  ///< User data passed to the predicate
    sfTime             period;    ///< The period between checks of the predicate
} sfTimeoutWithPredicate;
