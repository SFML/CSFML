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

#ifndef SFML_INTERNAL_WINDOW_HPP
#define SFML_INTERNAL_WINDOW_HPP

#include <SFML/Window.h>
#include <SFML/Window.hpp>

namespace in
{

////////////////////////////////////////////////////////////
inline sfContextSettings sfContextSettings_zeroed()
{
    return sfContextSettings { 0, 0, 0, 0, 0, 0, sfFalse };
}

inline void sfContextSettings_setFromCpp(sfContextSettings& self,
                                         const sf::ContextSettings& cpp)
{
    self.depthBits = cpp.depthBits;
    self.stencilBits = cpp.stencilBits;
    self.antialiasingLevel = cpp.antialiasingLevel;
    self.majorVersion = cpp.majorVersion;
    self.minorVersion = cpp.minorVersion;
    self.attributeFlags = cpp.attributeFlags;
    self.sRgbCapable = cpp.sRgbCapable ? sfTrue : sfFalse;
}

inline void sfContextSettings_setToCpp(const sfContextSettings& self,
                                       sf::ContextSettings& cpp)
{
    cpp.depthBits = self.depthBits;
    cpp.stencilBits = self.stencilBits;
    cpp.antialiasingLevel = self.antialiasingLevel;
    cpp.majorVersion = self.majorVersion;
    cpp.minorVersion = self.minorVersion;
    cpp.attributeFlags = self.attributeFlags;
    cpp.sRgbCapable = self.sRgbCapable == sfTrue;
}

}

#endif // SFML_INTERNAL_WINDOW_HPP
