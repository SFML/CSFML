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

#ifndef SFML_VIEW_H
#define SFML_VIEW_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>


////////////////////////////////////////////////////////////
/// \brief Create a default view
///
/// This function creates a default view of (0, 0, 1000, 1000)
///
/// \return A new sfView object
///
////////////////////////////////////////////////////////////
CSFML_API sfView* sfView_Create(void);

////////////////////////////////////////////////////////////
/// \brief Construct a view from a rectangle
///
/// \param rectangle Rectangle defining the zone to display
///
/// \return A new sfView object
///
////////////////////////////////////////////////////////////
CSFML_API sfView* sfView_CreateFromRect(sfFloatRect rectangle);

////////////////////////////////////////////////////////////
/// \brief Copy an existing view
///
/// \param view View to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_API sfView* sfView_Copy(sfView* view);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing view
///
/// \param view View to destroy
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_Destroy(sfView* view);

////////////////////////////////////////////////////////////
/// \brief Set the center of a view
///
/// \param view View object
/// \param x    X coordinate of the new center
/// \param y    Y coordinate of the new center
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_SetCenter(sfView* view, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Set the size of a view
///
/// \param view   View object
/// \param width  New width of the view
/// \param height New height of the view
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_SetSize(sfView* view, float width, float height);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of a view
///
/// The default rotation of a view is 0 degree.
///
/// \param view  View object
/// \param angle New angle, in degrees
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_SetRotation(sfView* view, float angle);

////////////////////////////////////////////////////////////
/// \brief Set the target viewport of a view
///
/// The viewport is the rectangle into which the contents of the
/// view are displayed, expressed as a factor (between 0 and 1)
/// of the size of the RenderTarget to which the view is applied.
/// For example, a view which takes the left side of the target would
/// be defined by a rect of (0, 0, 0.5, 1).
/// By default, a view has a viewport which covers the entire target.
///
/// \param view     View object
/// \param viewport New viewport rectangle
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_SetViewport(sfView* view, sfFloatRect viewport);

////////////////////////////////////////////////////////////
/// \brief Reset a view to the given rectangle
///
/// Note that this function resets the rotation angle to 0.
///
/// \param view      View object
/// \param rectangle Rectangle defining the zone to display
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_Reset(sfView* view, sfFloatRect rectangle);

////////////////////////////////////////////////////////////
/// \brief Get the center of a view
///
/// \param view View object
/// \param x    Returned X coordinate of the center
/// \param y    Returned Y coordinate of the center
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_GetCenter(const sfView* view, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the size of a view
///
/// \param view   View object
/// \param width  Returned width
/// \param height Returned height
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_GetSize(const sfView* view, float* width, float* height);

////////////////////////////////////////////////////////////
/// \brief Get the current orientation of a view
///
/// \param view View object
///
/// \return Rotation angle of the view, in degrees
///
////////////////////////////////////////////////////////////
CSFML_API float sfView_GetRotation(const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Get the target viewport rectangle of a view
///
/// \param view View object
///
/// \return Viewport rectangle, expressed as a factor of the target size
///
////////////////////////////////////////////////////////////
CSFML_API sfFloatRect sfView_GetViewport(const sfView* view);

////////////////////////////////////////////////////////////
/// \brief Move a view relatively to its current position
///
/// \param view    View object
/// \param offsetX X coordinate of the move offset
/// \param offsetY Y coordinate of the move offset
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_Move(sfView* view, float offsetX, float offsetY);

////////////////////////////////////////////////////////////
/// \brief Rotate a view relatively to its current orientation
///
/// \param view  View object
/// \param angle Angle to rotate, in degrees
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_Rotate(sfView* view, float angle);

////////////////////////////////////////////////////////////
/// \brief Resize a view rectangle relatively to its current size
///
/// Resizing the view simulates a zoom, as the zone displayed on
/// screen grows or shrinks.
/// \a factor is a multiplier:
/// \li 1 keeps the size unchanged
/// \li > 1 makes the view bigger (objects appear smaller)
/// \li < 1 makes the view smaller (objects appear bigger)
///
/// \param view   View object
/// \param factor Zoom factor to apply
///
////////////////////////////////////////////////////////////
CSFML_API void sfView_Zoom(sfView* view, float factor);


#endif // SFML_VIEW_H
