////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2025 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Window/Export.h>

#include <CSFML/System/Vector2.h>
#include <CSFML/Window/Types.h>


////////////////////////////////////////////////////////////
/// \brief Mouse buttons
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfMouseLeft,         ///< The left mouse button
    sfMouseRight,        ///< The right mouse button
    sfMouseMiddle,       ///< The middle (wheel) mouse button
    sfMouseButtonExtra1, ///< The first extra mouse button
    sfMouseButtonExtra2, ///< The second extra mouse button
} sfMouseButton;

enum
{
    sfMouseButtonCount = sfMouseButtonExtra2 + 1 ///< The total number of mouse buttons
};

////////////////////////////////////////////////////////////
/// \brief Mouse wheels
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfMouseVerticalWheel,  ///< The vertical mouse wheel
    sfMouseHorizontalWheel ///< The horizontal mouse wheel
} sfMouseWheel;


////////////////////////////////////////////////////////////
/// \brief Check if a mouse button is pressed
///
/// \param button Button to check
///
/// \return true if the button is pressed, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API bool sfMouse_isButtonPressed(sfMouseButton button);

////////////////////////////////////////////////////////////
/// \brief Get the current position of the mouse
///
/// This function returns the current position of the mouse
/// cursor relative to the given window, or desktop if NULL is passed.
///
/// \param relativeTo Reference window
///
/// \return Position of the mouse cursor, relative to the given window
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfVector2i sfMouse_getPosition(const sfWindow* relativeTo);

////////////////////////////////////////////////////////////
/// \brief Set the current position of the mouse
///
/// This function sets the current position of the mouse
/// cursor relative to the given window, or desktop if NULL is passed.
///
/// \param position   New position of the mouse
/// \param relativeTo Reference window
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfMouse_setPosition(sfVector2i position, const sfWindow* relativeTo);

////////////////////////////////////////////////////////////
/// \brief Get the current position of the mouse relative to a window base
///
/// This function returns the current position of the mouse
/// cursor relative to the given window base, or desktop if NULL is passed.
///
/// \param relativeTo Reference window
///
/// \return Position of the mouse cursor, relative to the given window base
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfVector2i sfMouse_getPositionWindowBase(const sfWindowBase* relativeTo);

////////////////////////////////////////////////////////////
/// \brief Set the current position of the mouse relative to a window base
///
/// This function sets the current position of the mouse
/// cursor relative to the given window base, or desktop if NULL is passed.
///
/// \param position   New position of the mouse
/// \param relativeTo Reference window
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfMouse_setPositionWindowBase(sfVector2i position, const sfWindowBase* relativeTo);
