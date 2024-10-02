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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/System/ConvertVector2.hpp>
#include <CSFML/System/ConvertVector3.hpp>
#include <CSFML/Window/Event.h>

#include <SFML/Window/Event.hpp>

#include <optional>


////////////////////////////////////////////////////////////
// Convert sf::Event to sfEvent
////////////////////////////////////////////////////////////
[[nodiscard]] inline bool convertEvent(const std::optional<sf::Event>& sfmlEvent, sfEvent& event)
{
    if (!sfmlEvent)
        return false;

    if (sfmlEvent->is<sf::Event::Closed>())
    {
        event.type = sfEvtClosed;
    }
    else if (const auto* resized = sfmlEvent->getIf<sf::Event::Resized>())
    {
        event.type      = sfEvtResized;
        event.size.size = convertVector2(resized->size);
    }
    else if (sfmlEvent->is<sf::Event::FocusLost>())
    {
        event.type = sfEvtFocusLost;
    }
    else if (sfmlEvent->is<sf::Event::FocusGained>())
    {
        event.type = sfEvtFocusGained;
    }
    else if (const auto* textEntered = sfmlEvent->getIf<sf::Event::TextEntered>())
    {
        event.type         = sfEvtTextEntered;
        event.text.unicode = textEntered->unicode;
    }
    else if (const auto* keyReleased = sfmlEvent->getIf<sf::Event::KeyReleased>())
    {
        event.type         = sfEvtKeyReleased;
        event.key.code     = static_cast<sfKeyCode>(keyReleased->code);
        event.key.scancode = static_cast<sfScancode>(keyReleased->scancode);
        event.key.alt      = keyReleased->alt;
        event.key.control  = keyReleased->control;
        event.key.shift    = keyReleased->shift;
        event.key.system   = keyReleased->system;
    }
    else if (const auto* keyPressed = sfmlEvent->getIf<sf::Event::KeyPressed>())
    {
        event.type         = sfEvtKeyPressed;
        event.key.code     = static_cast<sfKeyCode>(keyPressed->code);
        event.key.scancode = static_cast<sfScancode>(keyPressed->scancode);
        event.key.alt      = keyPressed->alt;
        event.key.control  = keyPressed->control;
        event.key.shift    = keyPressed->shift;
        event.key.system   = keyPressed->system;
    }
    else if (const auto* mouseWheelScrolled = sfmlEvent->getIf<sf::Event::MouseWheelScrolled>())
    {
        event.type                      = sfEvtMouseWheelScrolled;
        event.mouseWheelScroll.wheel    = static_cast<sfMouseWheel>(mouseWheelScrolled->wheel);
        event.mouseWheelScroll.delta    = mouseWheelScrolled->delta;
        event.mouseWheelScroll.position = convertVector2(mouseWheelScrolled->position);
    }
    else if (const auto* mouseButtonPressed = sfmlEvent->getIf<sf::Event::MouseButtonPressed>())
    {
        event.type                 = sfEvtMouseButtonPressed;
        event.mouseButton.button   = static_cast<sfMouseButton>(mouseButtonPressed->button);
        event.mouseButton.position = convertVector2(mouseButtonPressed->position);
    }
    else if (const auto* mouseButtonReleased = sfmlEvent->getIf<sf::Event::MouseButtonReleased>())
    {
        event.type                 = sfEvtMouseButtonReleased;
        event.mouseButton.button   = static_cast<sfMouseButton>(mouseButtonReleased->button);
        event.mouseButton.position = convertVector2(mouseButtonReleased->position);
    }
    else if (const auto* mouseMoved = sfmlEvent->getIf<sf::Event::MouseMoved>())
    {
        event.type               = sfEvtMouseMoved;
        event.mouseMove.position = convertVector2(mouseMoved->position);
    }
    else if (const auto* mouseMovedRaw = sfmlEvent->getIf<sf::Event::MouseMovedRaw>())
    {
        event.type               = sfEvtMouseMovedRaw;
        event.mouseMoveRaw.delta = convertVector2(mouseMovedRaw->delta);
    }
    else if (sfmlEvent->is<sf::Event::MouseEntered>())
    {
        event.type = sfEvtMouseEntered;
    }
    else if (sfmlEvent->is<sf::Event::MouseLeft>())
    {
        event.type = sfEvtMouseLeft;
    }
    else if (const auto* joystickButtonPressed = sfmlEvent->getIf<sf::Event::JoystickButtonPressed>())
    {
        event.type                      = sfEvtJoystickButtonPressed;
        event.joystickButton.joystickId = joystickButtonPressed->joystickId;
        event.joystickButton.button     = joystickButtonPressed->button;
    }
    else if (const auto* joystickButtonReleased = sfmlEvent->getIf<sf::Event::JoystickButtonReleased>())
    {
        event.type                      = sfEvtJoystickButtonReleased;
        event.joystickButton.joystickId = joystickButtonReleased->joystickId;
        event.joystickButton.button     = joystickButtonReleased->button;
    }
    else if (const auto* joystickMoved = sfmlEvent->getIf<sf::Event::JoystickMoved>())
    {
        event.type                    = sfEvtJoystickMoved;
        event.joystickMove.joystickId = joystickMoved->joystickId;
        event.joystickMove.axis       = static_cast<sfJoystickAxis>(joystickMoved->axis);
        event.joystickMove.position   = joystickMoved->position;
    }
    else if (const auto* joystickConnected = sfmlEvent->getIf<sf::Event::JoystickConnected>())
    {
        event.type                       = sfEvtJoystickConnected;
        event.joystickConnect.joystickId = joystickConnected->joystickId;
    }
    else if (const auto* joystickDisconnected = sfmlEvent->getIf<sf::Event::JoystickDisconnected>())
    {
        event.type                       = sfEvtJoystickDisconnected;
        event.joystickConnect.joystickId = joystickDisconnected->joystickId;
    }
    else if (const auto* touchBegan = sfmlEvent->getIf<sf::Event::TouchBegan>())
    {
        event.type           = sfEvtTouchBegan;
        event.touch.finger   = touchBegan->finger;
        event.touch.position = convertVector2(touchBegan->position);
    }
    else if (const auto* touchMoved = sfmlEvent->getIf<sf::Event::TouchMoved>())
    {
        event.type           = sfEvtTouchMoved;
        event.touch.finger   = touchMoved->finger;
        event.touch.position = convertVector2(touchMoved->position);
    }
    else if (const auto* touchEnded = sfmlEvent->getIf<sf::Event::TouchEnded>())
    {
        event.type           = sfEvtTouchEnded;
        event.touch.finger   = touchEnded->finger;
        event.touch.position = convertVector2(touchEnded->position);
    }
    else if (const auto* sensorChanged = sfmlEvent->getIf<sf::Event::SensorChanged>())
    {
        event.type              = sfEvtSensorChanged;
        event.sensor.sensorType = static_cast<sfSensorType>(sensorChanged->type);
        event.sensor.value      = convertVector3(sensorChanged->value);
    }

    return true;
}
