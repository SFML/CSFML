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

#ifndef SFML_CONVERTEVENT_H
#define SFML_CONVERTEVENT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Event.h>


////////////////////////////////////////////////////////////
// Define a function to convert a sf::Event to a sfEvent
////////////////////////////////////////////////////////////
inline void convertEvent(const sf::Event& sfmlEvent, sfEvent* event)
{
    // Convert its type
    event->type = static_cast<sfEventType>(sfmlEvent.type);

    // Fill its fields
    switch (event->type)
    {
        case sfEvtResized :
            event->size.width  = sfmlEvent.size.width;
            event->size.height = sfmlEvent.size.height;
            break;

        case sfEvtTextEntered :
            event->text.unicode = sfmlEvent.text.unicode;
            break;

        case sfEvtKeyReleased :
        case sfEvtKeyPressed :
            event->key.code     = static_cast<sfKeyCode>(sfmlEvent.key.code);
            event->key.scancode = static_cast<sfScancode>(sfmlEvent.key.scancode);
            event->key.alt      = sfmlEvent.key.alt     ? sfTrue : sfFalse;
            event->key.control  = sfmlEvent.key.control ? sfTrue : sfFalse;
            event->key.shift    = sfmlEvent.key.shift   ? sfTrue : sfFalse;
            event->key.system   = sfmlEvent.key.system  ? sfTrue : sfFalse;
            break;

        case sfEvtMouseWheelMoved :
            event->mouseWheel.delta = sfmlEvent.mouseWheel.delta;
            event->mouseWheel.x     = sfmlEvent.mouseWheel.x;
            event->mouseWheel.y     = sfmlEvent.mouseWheel.y;
            break;

        case sfEvtMouseWheelScrolled :
            event->mouseWheelScroll.wheel = static_cast<sfMouseWheel>(sfmlEvent.mouseWheelScroll.wheel);
            event->mouseWheelScroll.delta = sfmlEvent.mouseWheelScroll.delta;
            event->mouseWheelScroll.x     = sfmlEvent.mouseWheelScroll.x;
            event->mouseWheelScroll.y     = sfmlEvent.mouseWheelScroll.y;
            break;

        case sfEvtMouseButtonPressed :
        case sfEvtMouseButtonReleased :
            event->mouseButton.button = static_cast<sfMouseButton>(sfmlEvent.mouseButton.button);
            event->mouseButton.x      = sfmlEvent.mouseButton.x;
            event->mouseButton.y      = sfmlEvent.mouseButton.y;
            break;

        case sfEvtMouseMoved :
            event->mouseMove.x = sfmlEvent.mouseMove.x;
            event->mouseMove.y = sfmlEvent.mouseMove.y;
            break;

        case sfEvtJoystickButtonPressed :
        case sfEvtJoystickButtonReleased :
            event->joystickButton.joystickId = sfmlEvent.joystickButton.joystickId;
            event->joystickButton.button     = sfmlEvent.joystickButton.button;
            break;

        case sfEvtJoystickMoved :
            event->joystickMove.joystickId = sfmlEvent.joystickMove.joystickId;
            event->joystickMove.axis       = static_cast<sfJoystickAxis>(sfmlEvent.joystickMove.axis);
            event->joystickMove.position   = sfmlEvent.joystickMove.position;
            break;

        case sfEvtJoystickConnected :
        case sfEvtJoystickDisconnected :
            event->joystickConnect.joystickId = sfmlEvent.joystickConnect.joystickId;
            break;

        case sfEvtTouchBegan :
        case sfEvtTouchMoved :
        case sfEvtTouchEnded :
            event->touch.finger = sfmlEvent.touch.finger;
            event->touch.x = sfmlEvent.touch.x;
            event->touch.y = sfmlEvent.touch.y;
            break;

        case sfEvtSensorChanged :
            event->sensor.sensorType = static_cast<sfSensorType>(sfmlEvent.sensor.type);
            event->sensor.x = sfmlEvent.sensor.x;
            event->sensor.y = sfmlEvent.sensor.y;
            event->sensor.z = sfmlEvent.sensor.z;
            break;

        default :
            break;
    }
}

#endif // SFML_CONVERTEVENT_H
