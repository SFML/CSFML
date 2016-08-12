////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2015 Laurent Gomila (laurent@sfml-dev.org)
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
#include <SFML/Graphics/Shader.h>
#include <SFML/Graphics/ShaderStruct.h>
#include <SFML/Graphics/TextureStruct.h>
#include <SFML/Graphics/ConvertTransform.hpp>
#include <SFML/Internal.h>
#include <SFML/CallbackStream.h>


////////////////////////////////////////////////////////////
sfShader* sfShader_createFromFile(const char* vertexShaderFilename, const char* geometryShaderFilename, const char* fragmentShaderFilename)
{
    bool vertexSuccess = false;
    bool geometrySuccess = false;
    bool fragmentSuccess = false;

    sfShader* shader = new sfShader;
    
    if (vertexShaderFilename)
    {
        vertexSuccess = shader->This.loadFromFile(vertexShaderFilename, sf::Shader::Vertex);
    }

    if (geometryShaderFilename)
    {
        geometrySuccess = shader->This.loadFromFile(geometryShaderFilename, sf::Shader::Geometry);
    }

    if (fragmentShaderFilename)
    {
        fragmentSuccess = shader->This.loadFromFile(fragmentShaderFilename, sf::Shader::Fragment);
    }

    if (!(vertexSuccess || geometrySuccess || fragmentSuccess))
    {
        delete shader;
        shader = NULL;
    }

    return shader;
}


////////////////////////////////////////////////////////////
sfShader* sfShader_createFromMemory(const char* vertexShader, const char* geometryShader, const char* fragmentShader)
{
    bool vertexSuccess = false;
    bool geometrySuccess = false;
    bool fragmentSuccess = false;

    sfShader* shader = new sfShader;

    if (vertexShader)
    {
        vertexSuccess = shader->This.loadFromMemory(vertexShader, sf::Shader::Vertex);
    }

    if (geometryShader)
    {
        geometrySuccess = shader->This.loadFromMemory(geometryShader, sf::Shader::Geometry);
    }

    if (fragmentShader)
    {
        fragmentSuccess = shader->This.loadFromMemory(fragmentShader, sf::Shader::Fragment);
    }

    if (!(vertexSuccess || geometrySuccess || fragmentSuccess))
    {
        delete shader;
        shader = NULL;
    }

    return shader;
}


////////////////////////////////////////////////////////////
sfShader* sfShader_createFromStream(sfInputStream* vertexShaderStream, sfInputStream* geometryShaderStream, sfInputStream* fragmentShaderStream)
{
    bool vertexSuccess = false;
    bool geometrySuccess = false;
    bool fragmentSuccess = false;

    sfShader* shader = new sfShader;

    if (vertexShaderStream)
    {
        CallbackStream stream(vertexShaderStream);
        vertexSuccess = shader->This.loadFromStream(stream, sf::Shader::Vertex);
    }

    if (geometryShaderStream)
    {
        CallbackStream stream(geometryShaderStream);
        geometrySuccess = shader->This.loadFromStream(stream, sf::Shader::Geometry);
    }

    if (fragmentShaderStream)
    {
        CallbackStream stream(fragmentShaderStream);
        fragmentSuccess = shader->This.loadFromStream(stream, sf::Shader::Fragment);
    }

    if (!(vertexSuccess || geometrySuccess || fragmentSuccess))
    {
        delete shader;
        shader = NULL;
    }

    return shader;
}


////////////////////////////////////////////////////////////
void sfShader_destroy(sfShader* shader)
{
    delete shader;
}


////////////////////////////////////////////////////////////
void sfShader_setFloatParameter(sfShader* shader, const char* name, float x)
{
    CSFML_CALL(shader, setParameter(name, x));
}


////////////////////////////////////////////////////////////
void sfShader_setFloat2Parameter(sfShader* shader, const char* name, float x, float y)
{
    CSFML_CALL(shader, setParameter(name, x, y));
}


////////////////////////////////////////////////////////////
void sfShader_setFloat3Parameter(sfShader* shader, const char* name, float x, float y, float z)
{
    CSFML_CALL(shader, setParameter(name, x, y, z));
}


////////////////////////////////////////////////////////////
void sfShader_setFloat4Parameter(sfShader* shader, const char* name, float x, float y, float z, float w)
{
    CSFML_CALL(shader, setParameter(name, x, y, z, w));
}


////////////////////////////////////////////////////////////
void sfShader_setVector2Parameter(sfShader* shader, const char* name, sfVector2f vector)
{
    CSFML_CALL(shader, setParameter(name, sf::Vector2f(vector.x, vector.y)));
}


////////////////////////////////////////////////////////////
void sfShader_setVector3Parameter(sfShader* shader, const char* name, sfVector3f vector)
{
    CSFML_CALL(shader, setParameter(name, sf::Vector3f(vector.x, vector.y, vector.z)));
}


////////////////////////////////////////////////////////////
void sfShader_setColorParameter(sfShader* shader, const char* name, sfColor color)
{
    CSFML_CALL(shader, setParameter(name, sf::Color(color.r, color.g, color.b, color.a)));
}


////////////////////////////////////////////////////////////
void sfShader_setTransformParameter(sfShader* shader, const char* name, sfTransform transform)
{
    CSFML_CALL(shader, setParameter(name, convertTransform(transform)));
}


////////////////////////////////////////////////////////////
void sfShader_setTextureParameter(sfShader* shader, const char* name, const sfTexture* texture)
{
    CSFML_CHECK(texture);
    CSFML_CALL(shader, setParameter(name, *texture->This));
}


////////////////////////////////////////////////////////////
void sfShader_setCurrentTextureParameter(sfShader* shader, const char* name)
{
    CSFML_CALL(shader, setParameter(name, sf::Shader::CurrentTexture));
}


////////////////////////////////////////////////////////////
unsigned int sfShader_getNativeHandle(const sfShader* shader)
{
    CSFML_CALL_RETURN(shader, getNativeHandle(), 0);
}


////////////////////////////////////////////////////////////
void sfShader_bind(const sfShader* shader)
{
    sf::Shader::bind(shader ? &shader->This : NULL);
}


////////////////////////////////////////////////////////////
sfBool sfShader_isAvailable(void)
{
    return sf::Shader::isAvailable() ? sfTrue : sfFalse;
}
