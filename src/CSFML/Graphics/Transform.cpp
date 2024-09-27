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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/Transform.h>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Transform.hpp>

#include <cstring>


////////////////////////////////////////////////////////////
const sfTransform sfTransform_Identity = {
    // clang-format off
    1, 0, 0,
    0, 1, 0,
    0, 0, 1,
    // clang-format on
};


////////////////////////////////////////////////////////////
sfTransform sfTransform_fromMatrix(float a00, float a01, float a02, float a10, float a11, float a12, float a20, float a21, float a22)
{
    // clang-format off
    return {
        a00, a01, a02,
        a10, a11, a12,
        a20, a21, a22,
    };
    // clang-format on
}


////////////////////////////////////////////////////////////
void sfTransform_getMatrix(const sfTransform* transform, float* matrix)
{
    assert(transform);
    sf::Transform converted = convertTransform(*transform);
    if (matrix)
        std::memcpy(matrix, converted.getMatrix(), 16 * sizeof(float));
}


////////////////////////////////////////////////////////////
sfTransform sfTransform_getInverse(const sfTransform* transform)
{
    assert(transform);
    return convertTransform(convertTransform(*transform).getInverse());
}


////////////////////////////////////////////////////////////
sfVector2f sfTransform_transformPoint(const sfTransform* transform, sfVector2f point)
{
    assert(transform);
    return convertVector2(convertTransform(*transform).transformPoint(convertVector2(point)));
}


////////////////////////////////////////////////////////////
sfFloatRect sfTransform_transformRect(const sfTransform* transform, sfFloatRect rectangle)
{
    assert(transform);
    return convertRect(convertTransform(*transform).transformRect(convertRect(rectangle)));
}


////////////////////////////////////////////////////////////
void sfTransform_combine(sfTransform* transform, const sfTransform* other)
{
    assert(transform);
    assert(other);
    *transform = convertTransform(convertTransform(*transform).combine(convertTransform(*other)));
}


////////////////////////////////////////////////////////////
void sfTransform_translate(sfTransform* transform, sfVector2f offset)
{
    assert(transform);
    *transform = convertTransform(convertTransform(*transform).translate(convertVector2(offset)));
}


////////////////////////////////////////////////////////////
void sfTransform_rotate(sfTransform* transform, float angle)
{
    assert(transform);
    *transform = convertTransform(convertTransform(*transform).rotate(sf::degrees(angle)));
}


////////////////////////////////////////////////////////////
void sfTransform_rotateWithCenter(sfTransform* transform, float angle, sfVector2f center)
{
    assert(transform);
    *transform = convertTransform(convertTransform(*transform).rotate(sf::degrees(angle), convertVector2(center)));
}


////////////////////////////////////////////////////////////
void sfTransform_scale(sfTransform* transform, sfVector2f scale)
{
    assert(transform);
    *transform = convertTransform(convertTransform(*transform).scale(convertVector2(scale)));
}


////////////////////////////////////////////////////////////
void sfTransform_scaleWithCenter(sfTransform* transform, sfVector2f scale, sfVector2f center)
{
    assert(transform);
    *transform = convertTransform(convertTransform(*transform).scale(convertVector2(scale), convertVector2(center)));
}


////////////////////////////////////////////////////////////
bool sfTransform_equal(sfTransform* left, sfTransform* right)
{
    assert(left);
    assert(right);

    for (int i = 0; i < 9; ++i)
    {
        if (left->matrix[i] != right->matrix[i])
            return false;
    }
    return true;
}
