////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila (laurent@sfml-dev.org)
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
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Internal.h>


namespace
{
sfVector2f toCType(const sf::Vector2f& vector)
{
    sfVector2f vec = {vector.x, vector.y};
    return vec;
}

sfVector2i toCType(const sf::Vector2i& vector)
{
    sfVector2i vec = {vector.x, vector.y};
    return vec;
}
}

////////////////////////////////////////////////////////////
/// Check if a point is inside a rectangle's area
////////////////////////////////////////////////////////////
bool sfFloatRect_contains(const sfFloatRect* rect, float x, float y)
{
    CSFML_CHECK_RETURN(rect, false);
    return sf::FloatRect({ rect->left, rect->top }, { rect->width, rect->height }).contains({ x, y });
}
bool sfIntRect_contains(const sfIntRect* rect, int x, int y)
{
    CSFML_CHECK_RETURN(rect, false);
    return sf::IntRect({ rect->left, rect->top }, { rect->width, rect->height }).contains({ x, y });
}


////////////////////////////////////////////////////////////
/// Check intersection between two rectangles
////////////////////////////////////////////////////////////
bool sfFloatRect_intersects(const sfFloatRect* rect1, const sfFloatRect* rect2, sfFloatRect* intersection)
{
    CSFML_CHECK_RETURN(rect1, false);
    CSFML_CHECK_RETURN(rect2, false);

    sf::FloatRect SFMLRect1({ rect1->left, rect1->top }, { rect1->width, rect1->height });
    sf::FloatRect SFMLRect2({ rect2->left, rect2->top }, { rect2->width, rect2->height });

    if (intersection)
    {
        std::optional<sf::FloatRect> overlap = SFMLRect1.findIntersection(SFMLRect2);

        if (overlap)
        {
            intersection->left = overlap->left;
            intersection->top = overlap->top;
            intersection->width = overlap->width;
            intersection->height = overlap->height;
        }

        return overlap.has_value();
    }
    else
    {
        return SFMLRect1.findIntersection(SFMLRect2).has_value();
    }
}
bool sfIntRect_intersects(const sfIntRect* rect1, const sfIntRect* rect2, sfIntRect* intersection)
{
    CSFML_CHECK_RETURN(rect1, false);
    CSFML_CHECK_RETURN(rect2, false);

    sf::IntRect SFMLRect1({ rect1->left, rect1->top }, { rect1->width, rect1->height });
    sf::IntRect SFMLRect2({ rect2->left, rect2->top }, { rect2->width, rect2->height });

    if (intersection)
    {
        std::optional<sf::IntRect> overlap = SFMLRect1.findIntersection(SFMLRect2);

        if (overlap)
        {
            intersection->left = overlap->left;
            intersection->top = overlap->top;
            intersection->width = overlap->width;
            intersection->height = overlap->height;
        }

        return overlap.has_value();
    }
    else
    {
        return SFMLRect1.findIntersection(SFMLRect2).has_value();
    }
}


////////////////////////////////////////////////////////////
/// Get the position of the rectangle's top-left corner
////////////////////////////////////////////////////////////
sfVector2f sfFloatRect_getPosition(const sfFloatRect* rect)
{
    return toCType(sf::FloatRect({ rect->left, rect->top }, { rect->width, rect->height }).getPosition());
}
sfVector2i sfIntRect_getPosition(const sfIntRect* rect)
{
    return toCType(sf::IntRect({ rect->left, rect->top }, { rect->width, rect->height }).getPosition());
}


////////////////////////////////////////////////////////////
/// Get the size of the rectangle
////////////////////////////////////////////////////////////
sfVector2f sfFloatRect_getSize(const sfFloatRect* rect)
{
    return toCType(sf::FloatRect({ rect->left, rect->top }, { rect->width, rect->height }).getSize());
}
sfVector2i sfIntRect_getSize(const sfIntRect* rect)
{
    return toCType(sf::IntRect({ rect->left, rect->top }, { rect->width, rect->height }).getSize());
}
