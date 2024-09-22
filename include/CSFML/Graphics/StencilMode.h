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
#include <CSFML/Graphics/Export.h>


////////////////////////////////////////////////////////
/// \brief Enumeration of the stencil test comparisons that can be performed
///
/// The comparisons are mapped directly to their OpenGL equivalents,
/// specified by `glStencilFunc()`.
////////////////////////////////////////////////////////
typedef enum
{
    sfStencilComparisonNever, //!< The stencil test never passes
    sfStencilComparisonLess,  //!< The stencil test passes if the new value is less than the value in the stencil buffer
    sfStencilComparisonLessEqual, //!< The stencil test passes if the new value is less than or equal to the value in the stencil buffer
    sfStencilComparisonGreater, //!< The stencil test passes if the new value is greater than the value in the stencil buffer
    sfStencilComparisonGreaterEqual, //!< The stencil test passes if the new value is greater than or equal to the value in the stencil buffer
    sfStencilComparisonEqual, //!< The stencil test passes if the new value is strictly equal to the value in the stencil buffer
    sfStencilComparisonNotEqual, //!< The stencil test passes if the new value is strictly unequal to the value in the stencil buffer
    sfStencilComparisonAlways //!< The stencil test always passes
} sfStencilComparison;


////////////////////////////////////////////////////////
/// \brief Enumeration of the stencil buffer update operations
///
/// The update operations are mapped directly to their OpenGL equivalents,
/// specified by `glStencilOp()`.
////////////////////////////////////////////////////////
typedef enum
{
    sfStencilUpdateOperationKeep, //!< If the stencil test passes, the value in the stencil buffer is not modified
    sfStencilUpdateOperationZero, //!< If the stencil test passes, the value in the stencil buffer is set to zero
    sfStencilUpdateOperationReplace, //!< If the stencil test passes, the value in the stencil buffer is set to the new value
    sfStencilUpdateOperationIncrement, //!< If the stencil test passes, the value in the stencil buffer is incremented and if required clamped
    sfStencilUpdateOperationDecrement, //!< If the stencil test passes, the value in the stencil buffer is decremented and if required clamped
    sfStencilUpdateOperationInvert, //!< If the stencil test passes, the value in the stencil buffer is bitwise inverted
} sfStencilUpdateOperation;


////////////////////////////////////////////////////////
/// \brief Stencil value type (also used as a mask)
///
////////////////////////////////////////////////////////
typedef struct
{
    unsigned int value; //!< The stored stencil value
} sfStencilValue;


////////////////////////////////////////////////////////////
/// \brief Stencil modes for drawing
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfStencilComparison      stencilComparison;      //!< The comparison we're performing the stencil test with
    sfStencilUpdateOperation stencilUpdateOperation; //!< The update operation to perform if the stencil test passes
    sfStencilValue           stencilReference;       //!< The reference value we're performing the stencil test with
    sfStencilValue stencilMask; //!< The mask to apply to both the reference value and the value in the stencil buffer
    bool           stencilOnly; //!< Whether we should update the color buffer in addition to the stencil buffer
} sfStencilMode;

////////////////////////////////////////////////////////////
/// \brief Define the default values for a StencilMode
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfStencilMode sfStencilMode_default;
