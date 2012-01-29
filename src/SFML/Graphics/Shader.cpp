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
#include <SFML/Graphics/Shader.h>
#include <SFML/Graphics/ShaderStruct.h>
#include <SFML/Graphics/TextureStruct.h>
#include <SFML/Graphics/TransformStruct.h>
#include <SFML/Internal.h>
#include <SFML/CallbackStream.h>


////////////////////////////////////////////////////////////
sfShader* sfShader_CreateFromFile(const char* vertexShaderFilename, const char* fragmentShaderFilename)
{
    bool success = false;
    sfShader* shader = new sfShader;
    if (vertexShaderFilename || fragmentShaderFilename)
    {
        if (!vertexShaderFilename)
        {
            // fragment shader only
            success = shader->This.LoadFromFile(fragmentShaderFilename, sf::Shader::Fragment);
        }
        else if (!fragmentShaderFilename)
        {
            // vertex shader only
            success = shader->This.LoadFromFile(vertexShaderFilename, sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            success = shader->This.LoadFromFile(vertexShaderFilename, fragmentShaderFilename);
        }
    }

    if (!success)
    {
        delete shader;
        shader = NULL;
    }

    return shader;
}


////////////////////////////////////////////////////////////
sfShader* sfShader_CreateFromMemory(const char* vertexShader, const char* fragmentShader)
{
    bool success = false;
    sfShader* shader = new sfShader;
    if (vertexShader || fragmentShader)
    {
        if (!vertexShader)
        {
            // fragment shader only
            success = shader->This.LoadFromMemory(fragmentShader, sf::Shader::Fragment);
        }
        else if (!fragmentShader)
        {
            // vertex shader only
            success = shader->This.LoadFromMemory(vertexShader, sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            success = shader->This.LoadFromMemory(vertexShader, fragmentShader);
        }
    }

    if (!success)
    {
        delete shader;
        shader = NULL;
    }

    return shader;
}


////////////////////////////////////////////////////////////
sfShader* sfShader_CreateFromStream(sfInputStream* vertexShaderStream, sfInputStream* fragmentShaderStream)
{
    bool success = false;
    sfShader* shader = new sfShader;
    if (vertexShaderStream || fragmentShaderStream)
    {
        if (!vertexShaderStream)
        {
            // fragment shader only
            CallbackStream stream(fragmentShaderStream);
            success = shader->This.LoadFromStream(stream, sf::Shader::Fragment);
        }
        else if (!fragmentShaderStream)
        {
            // vertex shader only
            CallbackStream stream(vertexShaderStream);
            success = shader->This.LoadFromStream(stream, sf::Shader::Vertex);
        }
        else
        {
            // vertex + fragment shaders
            CallbackStream vertexStream(vertexShaderStream);
            CallbackStream fragmentStream(fragmentShaderStream);
            success = shader->This.LoadFromStream(vertexStream, fragmentStream);
        }
    }

    if (!success)
    {
        delete shader;
        shader = NULL;
    }

    return shader;
}


////////////////////////////////////////////////////////////
void sfShader_Destroy(sfShader* shader)
{
    delete shader;
}


////////////////////////////////////////////////////////////
void sfShader_SetFloatParameter(sfShader* shader, const char* name, float x)
{
    CSFML_CALL(shader, SetParameter(name, x))
}


////////////////////////////////////////////////////////////
void sfShader_SetFloat2Parameter(sfShader* shader, const char* name, float x, float y)
{
    CSFML_CALL(shader, SetParameter(name, x, y))
}


////////////////////////////////////////////////////////////
void sfShader_SetFloat3Parameter(sfShader* shader, const char* name, float x, float y, float z)
{
    CSFML_CALL(shader, SetParameter(name, x, y, z))
}


////////////////////////////////////////////////////////////
void sfShader_SetFloat4Parameter(sfShader* shader, const char* name, float x, float y, float z, float w)
{
    CSFML_CALL(shader, SetParameter(name, x, y, z, w))
}


////////////////////////////////////////////////////////////
void sfShader_SetColorParameter(sfShader* shader, const char* name, sfColor color)
{
    CSFML_CALL(shader, SetParameter(name, sf::Color(color.r, color.g, color.b, color.a)))
}


////////////////////////////////////////////////////////////
void sfShader_SetTransformParameter(sfShader* shader, const char* name, const sfTransform* transform)
{
    CSFML_CALL(shader, SetParameter(name, transform ? transform->This : sf::Transform::Identity))
}


////////////////////////////////////////////////////////////
void sfShader_SetTextureParameter(sfShader* shader, const char* name, const sfTexture* texture)
{
    CSFML_CHECK(texture);
    CSFML_CALL(shader, SetParameter(name, *texture->This))
}


////////////////////////////////////////////////////////////
void sfShader_SetCurrentTextureParameter(sfShader* shader, const char* name)
{
    CSFML_CALL(shader, SetParameter(name, sf::Shader::CurrentTexture))
}


////////////////////////////////////////////////////////////
void sfShader_Bind(const sfShader* shader)
{
    CSFML_CALL(shader, Bind())
}


////////////////////////////////////////////////////////////
void sfShader_Unbind(const sfShader* shader)
{
    CSFML_CALL(shader, Unbind())
}


////////////////////////////////////////////////////////////
sfBool sfShader_IsAvailable(void)
{
    return sf::Shader::IsAvailable() ? sfTrue : sfFalse;
}
