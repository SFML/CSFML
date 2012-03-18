////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2012 Laurent Gomila (laurent.gom@gmail.com)//
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

#ifndef SFML_EVENT_H
#define SFML_EVENT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Export.h>
#include <SFML/Window/Joystick.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Mouse.h>


////////////////////////////////////////////////////////////
/// \brief Definition of all the event types
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfEvtClosed,
    sfEvtResized,
    sfEvtLostFocus,
    sfEvtGainedFocus,
    sfEvtTextEntered,
    sfEvtKeyPressed,
    sfEvtKeyReleased,
    sfEvtMouseWheelMoved,
    sfEvtMouseButtonPressed,
    sfEvtMouseButtonReleased,
    sfEvtMouseMoved,
    sfEvtMouseEntered,
    sfEvtMouseLeft,
    sfEvtJoystickButtonPressed,
    sfEvtJoystickButtonReleased,
    sfEvtJoystickMoved,
    sfEvtJoystickConnected,
    sfEvtJoystickDisconnected
} sfEventType;


////////////////////////////////////////////////////////////
/// \brief Keyboard event parameters
///
////////////////////////////////////////////////////////////
struct sfKeyEvent
{
    sfEventType type;
    sfKeyCode   code;
    sfBool      alt;
    sfBool      control;
    sfBool      shift;
    sfBool      system;
};

////////////////////////////////////////////////////////////
/// \brief Text event parameters
///
////////////////////////////////////////////////////////////
struct sfTextEvent
{
    sfEventType type;
    sfUint32    unicode;
};

////////////////////////////////////////////////////////////
/// \brief Mouse move event parameters
///
////////////////////////////////////////////////////////////
struct sfMouseMoveEvent
{
    sfEventType type;
    int         x;
    int         y;
};

////////////////////////////////////////////////////////////
/// \brief Mouse buttons events parameters
///
////////////////////////////////////////////////////////////
struct sfMouseButtonEvent
{
    sfEventType   type;
    sfMouseButton button;
    int           x;
    int           y;
};

////////////////////////////////////////////////////////////
/// \brief Mouse wheel events parameters
///
////////////////////////////////////////////////////////////
struct sfMouseWheelEvent
{
    sfEventType type;
    int         delta;
    int         x;
    int         y;
};

////////////////////////////////////////////////////////////
/// \brief Joystick axis move event parameters
///
////////////////////////////////////////////////////////////
struct sfJoystickMoveEvent
{
    sfEventType    type;
    unsigned int   joystickId;
    sfJoystickAxis axis;
    float          position;
};

////////////////////////////////////////////////////////////
/// \brief Joystick buttons events parameters
///
////////////////////////////////////////////////////////////
struct sfJoystickButtonEvent
{
    sfEventType  type;
    unsigned int joystickId;
    unsigned int button;
};

////////////////////////////////////////////////////////////
/// \brief Joystick connection/disconnection event parameters
///
////////////////////////////////////////////////////////////
struct sfJoystickConnectEvent
{
    sfEventType  type;
    unsigned int joystickId;
};

////////////////////////////////////////////////////////////
/// \brief Size events parameters
///
////////////////////////////////////////////////////////////
struct sfSizeEvent
{
    sfEventType  type;
    unsigned int width;
    unsigned int height;
};


////////////////////////////////////////////////////////////
/// \brief sfEvent defines a system event and its parameters
///
////////////////////////////////////////////////////////////
typedef union
{
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    sfEventType                   type; ///< Type of the event
    struct sfSizeEvent            size;
    struct sfKeyEvent             key;
    struct sfTextEvent            text;
    struct sfMouseMoveEvent       mouseMove;
    struct sfMouseButtonEvent     mouseButton;
    struct sfMouseWheelEvent      mouseWheel;
    struct sfJoystickMoveEvent    joystickMove;
    struct sfJoystickButtonEvent  joystickButton;
    struct sfJoystickConnectEvent joystickConnect;
} sfEvent;


#endif // SFML_EVENT_H
