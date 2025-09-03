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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Graphics/Export.h>

#include <CSFML/Graphics/Color.h>
#include <CSFML/Graphics/Glsl.h>
#include <CSFML/Graphics/Transform.h>
#include <CSFML/Graphics/Types.h>
#include <CSFML/System/InputStream.h>
#include <CSFML/System/Vector2.h>
#include <CSFML/System/Vector3.h>

#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Load the vertex, geometry and fragment shaders from files
///
/// This function loads the vertex, geometry and fragment
/// shaders. Pass NULL if you don't want to load
/// a specific shader.
/// The sources must be text files containing valid shaders
/// in GLSL language. GLSL is a C-like language dedicated to
/// OpenGL shaders; you'll probably need to read a good documentation
/// for it before writing your own shaders.
///
/// \param vertexShaderFilename   Path of the vertex shader file to load, or NULL to skip this shader
/// \param geometryShaderFilename Path of the geometry shader file to load, or NULL to skip this shader
/// \param fragmentShaderFilename Path of the fragment shader file to load, or NULL to skip this shader
///
/// \return A new sfShader object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfShader* sfShader_createFromFile(const char* vertexShaderFilename,
                                                     const char* geometryShaderFilename,
                                                     const char* fragmentShaderFilename);

////////////////////////////////////////////////////////////
/// \brief Load the vertex, geometry and fragment shaders from source code in memory
///
/// This function loads the vertex, geometry and fragment
/// shaders. Pass NULL if you don't want to load
/// a specific shader.
/// The sources must be valid shaders in GLSL language. GLSL is
/// a C-like language dedicated to OpenGL shaders; you'll
/// probably need to read a good documentation for it before
/// writing your own shaders.
///
/// \param vertexShader   String containing the source code of the vertex shader, or NULL to skip this shader
/// \param geometryShader String containing the source code of the geometry shader, or NULL to skip this shader
/// \param fragmentShader String containing the source code of the fragment shader, or NULL to skip this shader
///
/// \return A new sfShader object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfShader* sfShader_createFromMemory(const char* vertexShader,
                                                       const char* geometryShader,
                                                       const char* fragmentShader);

////////////////////////////////////////////////////////////
/// \brief Load the vertex, geometry and fragment shaders from custom streams
///
/// This function loads the vertex, geometry and fragment
/// shaders. Pass NULL if you don't want to load
/// a specific shader.
/// The source codes must be valid shaders in GLSL language.
/// GLSL is a C-like language dedicated to OpenGL shaders;
/// you'll probably need to read a good documentation for
/// it before writing your own shaders.
///
/// \param vertexShaderStream   Source stream to read the vertex shader from, or NULL to skip this shader
/// \param geometryShaderStream Source stream to read the geometry shader from, or NULL to skip this shader
/// \param fragmentShaderStream Source stream to read the fragment shader from, or NULL to skip this shader
///
/// \return A new sfShader object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfShader* sfShader_createFromStream(sfInputStream* vertexShaderStream,
                                                       sfInputStream* geometryShaderStream,
                                                       sfInputStream* fragmentShaderStream);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing shader
///
/// \param shader Shader to delete
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_destroy(const sfShader* shader);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p float uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param x      Value of the float scalar
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setFloatUniform(sfShader* shader, const char* name, float x);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p vec2 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the vec2 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setVec2Uniform(sfShader* shader, const char* name, sfGlslVec2 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p vec3 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the vec3 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setVec3Uniform(sfShader* shader, const char* name, sfGlslVec3 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p vec4 uniform
///
/// sfColor objects can be passed to this function via
/// the use of sfGlslVec4_fromsfColor(sfColor);
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the vec4 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setVec4Uniform(sfShader* shader, const char* name, sfGlslVec4 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p vec4 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param color  Value of the vec4 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setColorUniform(sfShader* shader, const char* name, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p int uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param x      Value of the integer scalar
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setIntUniform(sfShader* shader, const char* name, int x);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p ivec2 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the ivec2 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setIvec2Uniform(sfShader* shader, const char* name, sfGlslIvec2 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p ivec3 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the ivec3 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setIvec3Uniform(sfShader* shader, const char* name, sfGlslIvec3 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p ivec4 uniform
///
/// sfColor objects can be passed to this function via
/// the use of sfGlslIvec4_fromsfColor(sfColor);
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the ivec4 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setIvec4Uniform(sfShader* shader, const char* name, sfGlslIvec4 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p ivec4 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param color  Value of the ivec4 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setIntColorUniform(sfShader* shader, const char* name, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p bool uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param x      Value of the bool scalar
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setBoolUniform(sfShader* shader, const char* name, bool x);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p bvec2 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the bvec2 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setBvec2Uniform(sfShader* shader, const char* name, sfGlslBvec2 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p Bvec3 uniform
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the Bvec3 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setBvec3Uniform(sfShader* shader, const char* name, sfGlslBvec3 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p bvec4 uniform
///
/// sfColor objects can be passed to this function via
/// the use of sfGlslIvec4_fromsfColor(sfColor);
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param vector Value of the bvec4 vector
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setBvec4Uniform(sfShader* shader, const char* name, sfGlslBvec4 vector);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p mat3 matrix
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param matrix Value of the mat3 matrix
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setMat3Uniform(sfShader* shader, const char* name, const sfGlslMat3* matrix);

////////////////////////////////////////////////////////////
/// \brief Specify value for \p mat4 matrix
///
/// \param shader Shader object
/// \param name   Name of the uniform variable in GLSL
/// \param matrix Value of the mat4 matrix
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setMat4Uniform(sfShader* shader, const char* name, const sfGlslMat4* matrix);

////////////////////////////////////////////////////////////
/// \brief Specify a texture as \p sampler2D uniform
///
/// \a name is the name of the variable to change in the shader.
/// The corresponding parameter in the shader must be a 2D texture
/// (\p sampler2D GLSL type).
///
/// Example:
/// \code
/// uniform sampler2D the_texture; // this is the variable in the shader
/// \endcode
/// \code
/// sfTexture texture;
/// ...
/// sfShader_setTextureUniform(shader, "the_texture", &texture);
/// \endcode
/// It is important to note that \a texture must remain alive as long
/// as the shader uses it, no copy is made internally.
///
/// To use the texture of the object being drawn, which cannot be
/// known in advance, you can pass the special value
/// sf::Shader::CurrentTexture:
/// \code
/// shader.setUniform("the_texture", sf::Shader::CurrentTexture).
/// \endcode
///
/// \param shader  Shader object
/// \param name    Name of the texture in the shader
/// \param texture Texture to assign
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setTextureUniform(sfShader* shader, const char* name, const sfTexture* texture);

////////////////////////////////////////////////////////////
/// \brief Specify current texture as \p sampler2D uniform
///
/// This overload maps a shader texture variable to the
/// texture of the object being drawn, which cannot be
/// known in advance.
/// The corresponding parameter in the shader must be a 2D texture
/// (\p sampler2D GLSL type).
///
/// Example:
/// \code
/// uniform sampler2D current; // this is the variable in the shader
/// \endcode
/// \code
/// sfShader_setCurrentTextureUniform(shader, "current");
/// \endcode
///
/// \param shader Shader object
/// \param name   Name of the texture in the shader
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setCurrentTextureUniform(sfShader* shader, const char* name);

////////////////////////////////////////////////////////////
/// \brief Specify values for \p float[] array uniform
///
/// \param shader      Shader object
/// \param name        Name of the uniform variable in GLSL
/// \param scalarArray pointer to array of \p float values
/// \param length      Number of elements in the array
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setFloatUniformArray(sfShader* shader, const char* name, const float* scalarArray, size_t length);

////////////////////////////////////////////////////////////
/// \brief Specify values for \p vec2[] array uniform
///
/// \param shader      Shader object
/// \param name        Name of the uniform variable in GLSL
/// \param vectorArray pointer to array of \p vec2 values
/// \param length      Number of elements in the array
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setVec2UniformArray(sfShader* shader, const char* name, const sfGlslVec2* vectorArray, size_t length);

////////////////////////////////////////////////////////////
/// \brief Specify values for \p vec3[] array uniform
///
/// \param shader      Shader object
/// \param name        Name of the uniform variable in GLSL
/// \param vectorArray pointer to array of \p vec3 values
/// \param length      Number of elements in the array
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setVec3UniformArray(sfShader* shader, const char* name, const sfGlslVec3* vectorArray, size_t length);

////////////////////////////////////////////////////////////
/// \brief Specify values for \p vec4[] array uniform
///
/// \param shader      Shader object
/// \param name        Name of the uniform variable in GLSL
/// \param vectorArray pointer to array of \p vec4 values
/// \param length      Number of elements in the array
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setVec4UniformArray(sfShader* shader, const char* name, const sfGlslVec4* vectorArray, size_t length);

////////////////////////////////////////////////////////////
/// \brief Specify values for \p mat3[] array uniform
///
/// \param shader      Shader object
/// \param name        Name of the uniform variable in GLSL
/// \param matrixArray pointer to array of \p mat3 values
/// \param length      Number of elements in the array
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setMat3UniformArray(sfShader* shader, const char* name, const sfGlslMat3* matrixArray, size_t length);

////////////////////////////////////////////////////////////
/// \brief Specify values for \p mat4[] array uniform
///
/// \param shader      Shader object
/// \param name        Name of the uniform variable in GLSL
/// \param matrixArray pointer to array of \p mat4 values
/// \param length      Number of elements in the array
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_setMat4UniformArray(sfShader* shader, const char* name, const sfGlslMat4* matrixArray, size_t length);

////////////////////////////////////////////////////////////
/// \brief Get the underlying OpenGL handle of the shader.
///
/// You shouldn't need to use this function, unless you have
/// very specific stuff to implement that SFML doesn't support,
/// or implement a temporary workaround until a bug is fixed.
///
/// \param shader Shader object
///
/// \return OpenGL handle of the shader or 0 if not yet loaded
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API unsigned int sfShader_getNativeHandle(const sfShader* shader);

////////////////////////////////////////////////////////////
/// \brief Bind a shader for rendering (activate it)
///
/// This function is not part of the graphics API, it mustn't be
/// used when drawing SFML entities. It must be used only if you
/// mix sfShader with OpenGL code.
///
/// \code
/// sfShader *s1, *s2;
/// ...
/// sfShader_bind(s1);
/// // draw OpenGL stuff that use s1...
/// sfShader_bind(s2);
/// // draw OpenGL stuff that use s2...
/// sfShader_bind(0);
/// // draw OpenGL stuff that use no shader...
/// \endcode
///
/// \param shader Shader to bind, can be null to use no shader
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfShader_bind(const sfShader* shader);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not the system supports shaders
///
/// This function should always be called before using
/// the shader features. If it returns false, then
/// any attempt to use sfShader will fail.
///
/// \return true if the system can use shaders, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfShader_isAvailable(void);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not the system supports geometry shaders
///
/// This function should always be called before using
/// the geometry shader features. If it returns false, then
/// any attempt to use sfShader geometry shader features will fail.
///
/// This function can only return true if isAvailable() would also
/// return true, since shaders in general have to be supported in
/// order for geometry shaders to be supported as well.
///
/// Note: The first call to this function, whether by your
/// code or SFML will result in a context switch.
///
/// \return True if geometry shaders are supported, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API bool sfShader_isGeometryAvailable(void);
