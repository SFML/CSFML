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
#include <SFML/Graphics/VertexArray.h>
#include <SFML/Graphics/VertexArrayStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfVertexArray* sfVertexArray_Create(void)
{
    return new sfVertexArray;
}


////////////////////////////////////////////////////////////
sfVertexArray* sfVertexArray_Copy(sfVertexArray* vertexArray)
{
    CSFML_CHECK_RETURN(vertexArray, NULL);

    return new sfVertexArray(*vertexArray);
}


////////////////////////////////////////////////////////////
void sfVertexArray_Destroy(sfVertexArray* vertexArray)
{
    delete vertexArray;
}


////////////////////////////////////////////////////////////
unsigned int sfVertexArray_GetVertexCount(const sfVertexArray* vertexArray)
{
    CSFML_CALL_RETURN(vertexArray, GetVertexCount(), 0);
}


////////////////////////////////////////////////////////////
sfVertex* sfVertexArray_GetVertex(sfVertexArray* vertexArray, unsigned int index)
{
    CSFML_CHECK_RETURN(vertexArray, NULL);

    // the cast is safe, sfVertex has to be binary compatible with sf::Vertex
    return reinterpret_cast<sfVertex*>(&vertexArray->This[index]);
}


////////////////////////////////////////////////////////////
void sfVertexArray_Clear(sfVertexArray* vertexArray)
{
    CSFML_CALL(vertexArray, Clear());
}


////////////////////////////////////////////////////////////
void sfVertexArray_Resize(sfVertexArray* vertexArray, unsigned int vertexCount)
{
    CSFML_CALL(vertexArray, Resize(vertexCount));
}


////////////////////////////////////////////////////////////
void sfVertexArray_Append(sfVertexArray* vertexArray, sfVertex vertex)
{
    // the cast is safe, sfVertex has to be binary compatible with sf::Vertex
    CSFML_CALL(vertexArray, Append(reinterpret_cast<sf::Vertex&>(vertex)));
}


////////////////////////////////////////////////////////////
void sfVertexArray_SetPrimitiveType(sfVertexArray* vertexArray, sfPrimitiveType type)
{
    CSFML_CALL(vertexArray, SetPrimitiveType(static_cast<sf::PrimitiveType>(type)));
}


////////////////////////////////////////////////////////////
sfPrimitiveType sfVertexArray_GetPrimitiveType(sfVertexArray* vertexArray)
{
    CSFML_CHECK_RETURN(vertexArray, sfPoints);
    return static_cast<sfPrimitiveType>(vertexArray->This.GetPrimitiveType());
}


////////////////////////////////////////////////////////////
sfFloatRect sfVertexArray_GetBounds(sfVertexArray* vertexArray)
{
    sfFloatRect rect = {0, 0, 0, 0};
    CSFML_CHECK_RETURN(vertexArray, rect);

    sf::FloatRect sfmlRect = vertexArray->This.GetBounds();
    rect.Left = sfmlRect.Left;
    rect.Top = sfmlRect.Top;
    rect.Width = sfmlRect.Width;
    rect.Height = sfmlRect.Height;

    return rect;
}
