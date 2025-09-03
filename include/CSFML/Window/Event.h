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
#include <CSFML/Window/Export.h>

#include <CSFML/Window/Joystick.h>
#include <CSFML/Window/Keyboard.h>
#include <CSFML/Window/Mouse.h>
#include <CSFML/Window/Sensor.h>


////////////////////////////////////////////////////////////
/// \brief Definition of all the event types
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfEvtClosed,                 ///< The window requested to be closed (no data)
    sfEvtResized,                ///< The window was resized (data in event.size)
    sfEvtFocusLost,              ///< The window lost the focus (no data)
    sfEvtFocusGained,            ///< The window gained the focus (no data)
    sfEvtTextEntered,            ///< A character was entered (data in event.text)
    sfEvtKeyPressed,             ///< A key was pressed (data in event.key)
    sfEvtKeyReleased,            ///< A key was released (data in event.key)
    sfEvtMouseWheelScrolled,     ///< The mouse wheel was scrolled (data in event.mouseWheelScroll)
    sfEvtMouseButtonPressed,     ///< A mouse button was pressed (data in event.mouseButton)
    sfEvtMouseButtonReleased,    ///< A mouse button was released (data in event.mouseButton)
    sfEvtMouseMoved,             ///< The mouse cursor moved (data in event.mouseMove)
    sfEvtMouseMovedRaw,          ///< The mouse cursor moved (data in event.mouseMove)
    sfEvtMouseEntered,           ///< The mouse cursor entered the area of the window (no data)
    sfEvtMouseLeft,              ///< The mouse cursor left the area of the window (no data)
    sfEvtJoystickButtonPressed,  ///< A joystick button was pressed (data in event.joystickButton)
    sfEvtJoystickButtonReleased, ///< A joystick button was released (data in event.joystickButton)
    sfEvtJoystickMoved,          ///< The joystick moved along an axis (data in event.joystickMove)
    sfEvtJoystickConnected,      ///< A joystick was connected (data in event.joystickConnect)
    sfEvtJoystickDisconnected,   ///< A joystick was disconnected (data in event.joystickConnect)
    sfEvtTouchBegan,             ///< A touch event began (data in event.touch)
    sfEvtTouchMoved,             ///< A touch moved (data in event.touch)
    sfEvtTouchEnded,             ///< A touch event ended (data in event.touch)
    sfEvtSensorChanged,          ///< A sensor value changed (data in event.sensor)

    sfEvtCount ///< Keep last -- the total number of event types
} sfEventType;


////////////////////////////////////////////////////////////
/// \brief Keyboard event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType type;
    sfKeyCode   code;
    sfScancode  scancode;
    bool        alt;
    bool        control;
    bool        shift;
    bool        system;
} sfKeyEvent;

////////////////////////////////////////////////////////////
/// \brief Text event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType type;
    uint32_t    unicode;
} sfTextEvent;

////////////////////////////////////////////////////////////
/// \brief Mouse move event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType type;
    sfVector2i  position;
} sfMouseMoveEvent;

////////////////////////////////////////////////////////////
/// \brief Mouse move raw event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType type;
    sfVector2i  delta;
} sfMouseMoveRawEvent;

////////////////////////////////////////////////////////////
/// \brief Mouse buttons events parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType   type;
    sfMouseButton button;
    sfVector2i    position;
} sfMouseButtonEvent;

////////////////////////////////////////////////////////////
/// \brief Mouse wheel events parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType  type;
    sfMouseWheel wheel;
    float        delta;
    sfVector2i   position;
} sfMouseWheelScrollEvent;

////////////////////////////////////////////////////////////
/// \brief Joystick axis move event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType    type;
    unsigned int   joystickId;
    sfJoystickAxis axis;
    float          position;
} sfJoystickMoveEvent;

////////////////////////////////////////////////////////////
/// \brief Joystick buttons events parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType  type;
    unsigned int joystickId;
    unsigned int button;
} sfJoystickButtonEvent;

////////////////////////////////////////////////////////////
/// \brief Joystick connection/disconnection event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType  type;
    unsigned int joystickId;
} sfJoystickConnectEvent;

////////////////////////////////////////////////////////////
/// \brief Size events parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType type;
    sfVector2u  size;
} sfSizeEvent;

////////////////////////////////////////////////////////////
/// \brief Touch events parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType  type;
    unsigned int finger;
    sfVector2i   position;
} sfTouchEvent;

////////////////////////////////////////////////////////////
/// \brief Sensor event parameters
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfEventType  type;
    sfSensorType sensorType;
    sfVector3f   value;
} sfSensorEvent;

////////////////////////////////////////////////////////////
/// \brief sfEvent defines a system event and its parameters
///
////////////////////////////////////////////////////////////
typedef union
{
    sfEventType             type;             ///< Type of the event
    sfSizeEvent             size;             ///< Size event parameters
    sfKeyEvent              key;              ///< Key event parameters
    sfTextEvent             text;             ///< Text event parameters
    sfMouseMoveEvent        mouseMove;        ///< Mouse move event parameters
    sfMouseMoveRawEvent     mouseMoveRaw;     ///< Mouse move raw event parameters
    sfMouseButtonEvent      mouseButton;      ///< Mouse button event parameters
    sfMouseWheelScrollEvent mouseWheelScroll; ///< Mouse wheel event parameters
    sfJoystickMoveEvent     joystickMove;     ///< Joystick move event parameters
    sfJoystickButtonEvent   joystickButton;   ///< Joystick button event parameters
    sfJoystickConnectEvent  joystickConnect;  ///< Joystick (dis)connect event parameters
    sfTouchEvent            touch;            ///< Touch events parameters
    sfSensorEvent           sensor;           ///< Sensor event parameters
} sfEvent;
