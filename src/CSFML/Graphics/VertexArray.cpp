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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/ConvertRect.hpp>
#include <CSFML/Graphics/VertexArray.h>
#include <CSFML/Graphics/VertexArrayStruct.hpp>


////////////////////////////////////////////////////////////
sfVertexArray* sfVertexArray_create()
{
    return new sfVertexArray;
}


////////////////////////////////////////////////////////////
sfVertexArray* sfVertexArray_copy(const sfVertexArray* vertexArray)
{
    assert(vertexArray);
    return new sfVertexArray(*vertexArray);
}


////////////////////////////////////////////////////////////
void sfVertexArray_destroy(const sfVertexArray* vertexArray)
{
    delete vertexArray;
}


////////////////////////////////////////////////////////////
size_t sfVertexArray_getVertexCount(const sfVertexArray* vertexArray)
{
    assert(vertexArray);
    return vertexArray->getVertexCount();
}


////////////////////////////////////////////////////////////
sfVertex* sfVertexArray_getVertex(sfVertexArray* vertexArray, size_t index)
{
    assert(vertexArray);

    // the cast is safe, sfVertex has to be binary compatible with sf::Vertex
    return reinterpret_cast<sfVertex*>(&(*vertexArray)[index]);
}


////////////////////////////////////////////////////////////
void sfVertexArray_clear(sfVertexArray* vertexArray)
{
    assert(vertexArray);
    vertexArray->clear();
}


////////////////////////////////////////////////////////////
void sfVertexArray_resize(sfVertexArray* vertexArray, size_t vertexCount)
{
    assert(vertexArray);
    vertexArray->resize(vertexCount);
}


////////////////////////////////////////////////////////////
void sfVertexArray_append(sfVertexArray* vertexArray, sfVertex vertex)
{
    // the cast is safe, sfVertex has to be binary compatible with sf::Vertex
    assert(vertexArray);
    vertexArray->append(reinterpret_cast<sf::Vertex&>(vertex));
}


////////////////////////////////////////////////////////////
void sfVertexArray_setPrimitiveType(sfVertexArray* vertexArray, sfPrimitiveType type)
{
    assert(vertexArray);
    vertexArray->setPrimitiveType(static_cast<sf::PrimitiveType>(type));
}


////////////////////////////////////////////////////////////
sfPrimitiveType sfVertexArray_getPrimitiveType(const sfVertexArray* vertexArray)
{
    assert(vertexArray);
    return static_cast<sfPrimitiveType>(vertexArray->getPrimitiveType());
}


////////////////////////////////////////////////////////////
sfFloatRect sfVertexArray_getBounds(const sfVertexArray* vertexArray)
{
    assert(vertexArray);
    return convertRect(vertexArray->getBounds());
}
