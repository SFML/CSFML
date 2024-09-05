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
#include <CSFML/CallbackStream.hpp>
#include <CSFML/Graphics/ConvertTransform.hpp>
#include <CSFML/Graphics/Shader.h>
#include <CSFML/Graphics/ShaderStruct.hpp>
#include <CSFML/Graphics/TextureStruct.hpp>


////////////////////////////////////////////////////////////
sfShader* sfShader_createFromFile(const char* vertexShaderFilename,
                                  const char* geometryShaderFilename,
                                  const char* fragmentShaderFilename)
{
    bool       success = false;
    sf::Shader shader;
    if (vertexShaderFilename || geometryShaderFilename || fragmentShaderFilename)
    {
        if (!geometryShaderFilename)
        {
            if (!vertexShaderFilename)
            {
                // fragment shader only
                success = shader.loadFromFile(fragmentShaderFilename, sf::Shader::Type::Fragment);
            }
            else if (!fragmentShaderFilename)
            {
                // vertex shader only
                success = shader.loadFromFile(vertexShaderFilename, sf::Shader::Type::Vertex);
            }
            else
            {
                // vertex + fragment shaders
                success = shader.loadFromFile(vertexShaderFilename, fragmentShaderFilename);
            }
        }
        else
        {
            if (!vertexShaderFilename && !fragmentShaderFilename)
            {
                // geometry shader only
                success = shader.loadFromFile(geometryShaderFilename, sf::Shader::Type::Geometry);
            }
            else
            {
                // vertex + geometry + fragment shaders
                success = shader.loadFromFile(vertexShaderFilename, geometryShaderFilename, fragmentShaderFilename);
            }
        }
    }

    if (!success)
        return nullptr;

    return new sfShader{std::move(shader)};
}


////////////////////////////////////////////////////////////
sfShader* sfShader_createFromMemory(const char* vertexShader, const char* geometryShader, const char* fragmentShader)
{
    bool       success = false;
    sf::Shader shader;
    if (vertexShader || geometryShader || fragmentShader)
    {
        if (!geometryShader)
        {
            if (!vertexShader)
            {
                // fragment shader only
                success = shader.loadFromMemory(fragmentShader, sf::Shader::Type::Fragment);
            }
            else if (!fragmentShader)
            {
                // vertex shader only
                success = shader.loadFromMemory(vertexShader, sf::Shader::Type::Vertex);
            }
            else
            {
                // vertex + fragment shaders
                success = shader.loadFromMemory(vertexShader, fragmentShader);
            }
        }
        else
        {
            if (!vertexShader && !fragmentShader)
            {
                // geometry shader only
                success = shader.loadFromMemory(geometryShader, sf::Shader::Type::Geometry);
            }
            else
            {
                // vertex + geometry + fragment shaders
                success = shader.loadFromMemory(vertexShader, geometryShader, fragmentShader);
            }
        }
    }

    if (!success)
        return nullptr;

    return new sfShader{std::move(shader)};
}


////////////////////////////////////////////////////////////
sfShader* sfShader_createFromStream(sfInputStream* vertexShaderStream,
                                    sfInputStream* geometryShaderStream,
                                    sfInputStream* fragmentShaderStream)
{
    bool       success = false;
    sf::Shader shader;
    if (vertexShaderStream || geometryShaderStream || fragmentShaderStream)
    {
        if (!geometryShaderStream)
        {
            if (!vertexShaderStream)
            {
                // fragment shader only
                CallbackStream stream(fragmentShaderStream);
                success = shader.loadFromStream(stream, sf::Shader::Type::Fragment);
            }
            else if (!fragmentShaderStream)
            {
                // vertex shader only
                CallbackStream stream(vertexShaderStream);
                success = shader.loadFromStream(stream, sf::Shader::Type::Vertex);
            }
            else
            {
                // vertex + fragment shaders
                CallbackStream vertexStream(vertexShaderStream);
                CallbackStream fragmentStream(fragmentShaderStream);
                success = shader.loadFromStream(vertexStream, fragmentStream);
            }
        }
        else
        {
            CallbackStream geometryStream(geometryShaderStream);
            if (!vertexShaderStream && !fragmentShaderStream)
            {
                // geometry shader only
                success = shader.loadFromStream(geometryStream, sf::Shader::Type::Geometry);
            }
            else
            {
                // vertex + geometry + fragment shaders
                CallbackStream vertexStream(vertexShaderStream);
                CallbackStream fragmentStream(fragmentShaderStream);
                success = shader.loadFromStream(vertexStream, geometryStream, fragmentStream);
            }
        }
    }

    if (!success)
        return nullptr;

    return new sfShader{std::move(shader)};
}


////////////////////////////////////////////////////////////
void sfShader_destroy(sfShader* shader)
{
    delete shader;
}


////////////////////////////////////////////////////////////
void sfShader_setFloatUniform(sfShader* shader, const char* name, float x)
{
    assert(shader);
    shader->This.setUniform(name, x);
}


////////////////////////////////////////////////////////////
void sfShader_setVec2Uniform(sfShader* shader, const char* name, sfGlslVec2 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Vec2(vector.x, vector.y));
}


////////////////////////////////////////////////////////////
void sfShader_setVec3Uniform(sfShader* shader, const char* name, sfGlslVec3 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Vec3(vector.x, vector.y, vector.z));
}


////////////////////////////////////////////////////////////
void sfShader_setVec4Uniform(sfShader* shader, const char* name, sfGlslVec4 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Vec4(vector.x, vector.y, vector.z, vector.w));
}


////////////////////////////////////////////////////////////
void sfShader_setColorUniform(sfShader* shader, const char* name, sfColor color)
{
    sfGlslVec4 vec4;
    vec4.x = color.r / 255.f;
    vec4.y = color.g / 255.f;
    vec4.z = color.b / 255.f;
    vec4.w = color.a / 255.f;

    sfShader_setVec4Uniform(shader, name, vec4);
}

////////////////////////////////////////////////////////////
void sfShader_setIntUniform(sfShader* shader, const char* name, int x)
{
    assert(shader);
    shader->This.setUniform(name, x);
}


////////////////////////////////////////////////////////////
void sfShader_setIvec2Uniform(sfShader* shader, const char* name, sfGlslIvec2 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Ivec2(vector.x, vector.y));
}


////////////////////////////////////////////////////////////
void sfShader_setIvec3Uniform(sfShader* shader, const char* name, sfGlslIvec3 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Ivec3(vector.x, vector.y, vector.z));
}


////////////////////////////////////////////////////////////
void sfShader_setIvec4Uniform(sfShader* shader, const char* name, sfGlslIvec4 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Ivec4(vector.x, vector.y, vector.z, vector.w));
}


////////////////////////////////////////////////////////////
void sfShader_setIntColorUniform(sfShader* shader, const char* name, sfColor color)
{
    sfGlslIvec4 ivec4;
    ivec4.x = static_cast<int>(color.r);
    ivec4.y = static_cast<int>(color.g);
    ivec4.z = static_cast<int>(color.b);
    ivec4.w = static_cast<int>(color.a);

    sfShader_setIvec4Uniform(shader, name, ivec4);
}

////////////////////////////////////////////////////////////
void sfShader_setBoolUniform(sfShader* shader, const char* name, bool x)
{
    assert(shader);
    shader->This.setUniform(name, x);
}


////////////////////////////////////////////////////////////
void sfShader_setBvec2Uniform(sfShader* shader, const char* name, sfGlslBvec2 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Bvec2(vector.x, vector.y));
}


////////////////////////////////////////////////////////////
void sfShader_setBvec3Uniform(sfShader* shader, const char* name, sfGlslBvec3 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Bvec3(vector.x, vector.y, vector.z));
}


////////////////////////////////////////////////////////////
void sfShader_setBvec4Uniform(sfShader* shader, const char* name, sfGlslBvec4 vector)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Bvec4(vector.x, vector.y, vector.z, vector.w));
}


////////////////////////////////////////////////////////////
void sfShader_setMat3Uniform(sfShader* shader, const char* name, const sfGlslMat3* matrix)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Mat3(matrix->array));
}


////////////////////////////////////////////////////////////
void sfShader_setMat4Uniform(sfShader* shader, const char* name, const sfGlslMat4* matrix)
{
    assert(shader);
    shader->This.setUniform(name, sf::Glsl::Mat4(matrix->array));
}


////////////////////////////////////////////////////////////
void sfShader_setTextureUniform(sfShader* shader, const char* name, const sfTexture* texture)
{
    assert(shader);
    shader->This.setUniform(name, *texture->This);
}


////////////////////////////////////////////////////////////
void sfShader_setCurrentTextureUniform(sfShader* shader, const char* name)
{
    assert(shader);
    shader->This.setUniform(name, sf::Shader::CurrentTexture);
}


////////////////////////////////////////////////////////////
void sfShader_setFloatUniformArray(sfShader* shader, const char* name, const float* scalarArray, size_t length)
{
    assert(shader);
    shader->This.setUniformArray(name, scalarArray, length);
}


////////////////////////////////////////////////////////////
void sfShader_setVec2UniformArray(sfShader* shader, const char* name, const sfGlslVec2* vectorArray, size_t length)
{
    assert(shader);
    shader->This.setUniformArray(name, reinterpret_cast<const sf::Glsl::Vec2*>(vectorArray), length);
}


////////////////////////////////////////////////////////////
void sfShader_setVec3UniformArray(sfShader* shader, const char* name, const sfGlslVec3* vectorArray, size_t length)
{
    assert(shader);
    shader->This.setUniformArray(name, reinterpret_cast<const sf::Glsl::Vec3*>(vectorArray), length);
}


////////////////////////////////////////////////////////////
void sfShader_setVec4UniformArray(sfShader* shader, const char* name, const sfGlslVec4* vectorArray, size_t length)
{
    assert(shader);
    shader->This.setUniformArray(name, reinterpret_cast<const sf::Glsl::Vec4*>(vectorArray), length);
}


////////////////////////////////////////////////////////////
void sfShader_setMat3UniformArray(sfShader* shader, const char* name, const sfGlslMat3* matrixArray, size_t length)
{
    assert(shader);
    shader->This.setUniformArray(name, reinterpret_cast<const sf::Glsl::Mat3*>(matrixArray), length);
}


////////////////////////////////////////////////////////////
void sfShader_setMat4UniformArray(sfShader* shader, const char* name, const sfGlslMat4* matrixArray, size_t length)
{
    assert(shader);
    shader->This.setUniformArray(name, reinterpret_cast<const sf::Glsl::Mat4*>(matrixArray), length);
}


////////////////////////////////////////////////////////////
void sfShader_setTextureParameter(sfShader* shader, const char* name, const sfTexture* texture)
{
    assert(shader);
    assert(texture);
    shader->This.setUniform(name, *texture->This);
}


////////////////////////////////////////////////////////////
unsigned int sfShader_getNativeHandle(const sfShader* shader)
{
    assert(shader);
    return shader->This.getNativeHandle();
}


////////////////////////////////////////////////////////////
void sfShader_bind(const sfShader* shader)
{
    sf::Shader::bind(shader ? &shader->This : nullptr);
}


////////////////////////////////////////////////////////////
bool sfShader_isAvailable()
{
    return sf::Shader::isAvailable();
}


////////////////////////////////////////////////////////////
bool sfShader_isGeometryAvailable()
{
    return sf::Shader::isGeometryAvailable();
}
