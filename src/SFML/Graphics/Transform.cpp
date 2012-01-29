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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/TransformStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfTransform* sfTransform_Create(void)
{
    return new sfTransform;
}


////////////////////////////////////////////////////////////
sfTransform* sfTransform_CreateFromMatrix(float a00, float a01, float a02,
                                          float a10, float a11, float a12,
                                          float a20, float a21, float a22)
{
    sfTransform* transform = new sfTransform;
    transform->This = sf::Transform(a00, a01, a02, a10, a11, a12, a20, a21, a22);
    return transform;
}


////////////////////////////////////////////////////////////
sfTransform* sfTransform_Copy(sfTransform* transform)
{
    CSFML_CHECK_RETURN(transform, NULL);

    return new sfTransform(*transform);
}


////////////////////////////////////////////////////////////
void sfTransform_Destroy(sfTransform* transform)
{
    delete transform;
}


////////////////////////////////////////////////////////////
const float* sfTransform_GetMatrix(const sfTransform* transform)
{
    CSFML_CALL_RETURN(transform, GetMatrix(), NULL);
}


////////////////////////////////////////////////////////////
void sfTransform_GetInverse(const sfTransform* transform, sfTransform* result)
{
    CSFML_CHECK(transform);

    if (result)
        result->This = transform->This.GetInverse();
}


////////////////////////////////////////////////////////////
void sfTransform_TransformPoint(const sfTransform* transform, float x, float y, float* transformedX, float* transformedY)
{
    CSFML_CHECK(transform);

    sf::Vector2f point = transform->This.TransformPoint(x, y);

    if (transformedX)
        *transformedX = point.x;
    if (transformedY)
        *transformedY = point.y;
}


////////////////////////////////////////////////////////////
void sfTransform_TransformRect(const sfTransform* transform, sfFloatRect rectangle, sfFloatRect* transformedRectangle)
{
    CSFML_CHECK(transform);

    sf::FloatRect rect = transform->This.TransformRect(sf::FloatRect(rectangle.Left, rectangle.Top, rectangle.Width, rectangle.Height));

    if (transformedRectangle)
    {
        transformedRectangle->Left = rect.Left;
        transformedRectangle->Top = rect.Top;
        transformedRectangle->Width = rect.Width;
        transformedRectangle->Height = rect.Height;
    }
}


////////////////////////////////////////////////////////////
void sfTransform_Combine(const sfTransform* left, const sfTransform* right, sfTransform* result)
{
    CSFML_CHECK(left);
    CSFML_CHECK(right);

    if (result)
        result->This = left->This.Combine(right->This);
}


////////////////////////////////////////////////////////////
void sfTransform_Translate(sfTransform* transform, float x, float y)
{
    CSFML_CALL(transform, Translate(x, y));
}


////////////////////////////////////////////////////////////
void sfTransform_Rotate(sfTransform* transform, float angle)
{
    CSFML_CALL(transform, Rotate(angle));
}


////////////////////////////////////////////////////////////
void sfTransform_RotateWithCenter(sfTransform* transform, float angle, float centerX, float centerY)
{
    CSFML_CALL(transform, Rotate(angle, centerX, centerY));
}


////////////////////////////////////////////////////////////
void sfTransform_Scale(sfTransform* transform, float scaleX, float scaleY)
{
    CSFML_CALL(transform, Scale(scaleX, scaleY));
}


////////////////////////////////////////////////////////////
void sfTransform_ScaleWithCenter(sfTransform* transform, float scaleX, float scaleY, float centerX, float centerY)
{
    CSFML_CALL(transform, Scale(scaleX, scaleY, centerX, centerY));
}
