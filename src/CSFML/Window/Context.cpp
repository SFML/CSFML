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
#include <CSFML/Window/Context.h>
#include <CSFML/Window/ContextStruct.hpp>
#include <CSFML/Window/ConvertContextSettings.hpp>


////////////////////////////////////////////////////////////
sfContext* sfContext_create()
{
    return new sfContext;
}


////////////////////////////////////////////////////////////
void sfContext_destroy(const sfContext* context)
{
    delete context;
}


////////////////////////////////////////////////////////////
bool sfContext_isExtensionAvailable(const char* name)
{
    assert(name);
    return sf::Context::isExtensionAvailable(name);
}


////////////////////////////////////////////////////////////
bool sfContext_setActive(sfContext* context, bool active)
{
    assert(context);
    return context->setActive(active);
}


////////////////////////////////////////////////////////////
sfGlFunctionPointer sfContext_getFunction(const char* name)
{
    return sf::Context::getFunction(name);
}


////////////////////////////////////////////////////////////
sfContextSettings sfContext_getSettings(const sfContext* context)
{
    assert(context);
    return convertContextSettings(context->getSettings());
}


////////////////////////////////////////////////////////////
uint64_t sfContext_getActiveContextId()
{
    return sf::Context::getActiveContextId();
}
