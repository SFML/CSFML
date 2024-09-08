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
#include <CSFML/Graphics/Shape.h>
#include <CSFML/Graphics/TextureStruct.hpp>
#include <CSFML/Graphics/Transform.h>
#include <CSFML/System/ConvertVector2.hpp>

#include <SFML/Graphics/Shape.hpp>


////////////////////////////////////////////////////////////
// Internal structure of sfShape
////////////////////////////////////////////////////////////
struct sfShape : sf::Shape
{
    sfShape(sfShapeGetPointCountCallback getPointCount, sfShapeGetPointCallback getPoint, void* userData) :
    myGetPointCountCallback(getPointCount),
    myGetPointCallback(getPoint),
    myUserData(userData)
    {
    }

    std::size_t getPointCount() const override
    {
        return myGetPointCountCallback(myUserData);
    }

    sf::Vector2f getPoint(std::size_t index) const override
    {
        return convertVector2(myGetPointCallback(index, myUserData));
    }

    using sf::Shape::update;

    sfShapeGetPointCountCallback myGetPointCountCallback;
    sfShapeGetPointCallback      myGetPointCallback;
    void*                        myUserData;
    const sfTexture*             Texture{};
    mutable sfTransform          Transform{};
    mutable sfTransform          InverseTransform{};
};
