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
#include <CSFML/Graphics/Rect.h>
#include <SFML/Graphics/Rect.hpp>
#include <CSFML/Internal.hpp>


////////////////////////////////////////////////////////////
/// Check if a point is inside a rectangle's area
////////////////////////////////////////////////////////////
bool sfFloatRect_contains(const sfFloatRect* rect, float x, float y)
{
    CSFML_CHECK_RETURN(rect, false);
    return sf::FloatRect({ rect->position.x, rect->position.y }, { rect->size.x, rect->size.y }).contains({ x, y });
}
bool sfIntRect_contains(const sfIntRect* rect, int x, int y)
{
    CSFML_CHECK_RETURN(rect, false);
    return sf::IntRect({ rect->position.x, rect->position.y }, { rect->size.x, rect->size.y }).contains({ x, y });
}


////////////////////////////////////////////////////////////
/// Check intersection between two rectangles
////////////////////////////////////////////////////////////
bool sfFloatRect_intersects(const sfFloatRect* rect1, const sfFloatRect* rect2, sfFloatRect* intersection)
{
    CSFML_CHECK_RETURN(rect1, false);
    CSFML_CHECK_RETURN(rect2, false);

    sf::FloatRect SFMLRect1({ rect1->position.x, rect1->position.y }, { rect1->size.x, rect1->size.y });
    sf::FloatRect SFMLRect2({ rect2->position.x, rect2->position.y }, { rect2->size.x, rect2->size.y });

    if (intersection)
    {
        std::optional<sf::FloatRect> overlap = SFMLRect1.findIntersection(SFMLRect2);

        if (overlap)
        {
            intersection->position.x = overlap->position.x;
            intersection->position.y = overlap->position.y;
            intersection->size.x = overlap->size.x;
            intersection->size.y = overlap->size.y;
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

    sf::IntRect SFMLRect1({ rect1->position.x, rect1->position.y }, { rect1->size.x, rect1->size.y });
    sf::IntRect SFMLRect2({ rect2->position.x, rect2->position.y }, { rect2->size.x, rect2->size.y });

    if (intersection)
    {
        std::optional<sf::IntRect> overlap = SFMLRect1.findIntersection(SFMLRect2);

        if (overlap)
        {
            intersection->position.x = overlap->position.x;
            intersection->position.y = overlap->position.y;
            intersection->size.x = overlap->size.x;
            intersection->size.y = overlap->size.y;
        }

        return overlap.has_value();
    }
    else
    {
        return SFMLRect1.findIntersection(SFMLRect2).has_value();
    }
}
