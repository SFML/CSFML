
set(INCROOT ${CMAKE_SOURCE_DIR}/include/SFML/Window)
set(SRCROOT ${CMAKE_SOURCE_DIR}/src/SFML/Window)

# all source files
set(SRC
    ${INCROOT}/Export.h
    ${INCROOT}/Clipboard.h
    ${SRCROOT}/Clipboard.cpp
    ${INCROOT}/Cursor.h
    ${SRCROOT}/Cursor.cpp
    ${SRCROOT}/CursorStruct.h
    ${SRCROOT}/Context.cpp
    ${SRCROOT}/ContextSettingsInternal.h
    ${SRCROOT}/ContextStruct.h
    ${INCROOT}/Context.h
    ${INCROOT}/Event.h
    ${SRCROOT}/Joystick.cpp
    ${INCROOT}/Joystick.h
    ${INCROOT}/JoystickIdentification.h
    ${SRCROOT}/Keyboard.cpp
    ${INCROOT}/Keyboard.h
    ${SRCROOT}/Mouse.cpp
    ${INCROOT}/Mouse.h
    ${SRCROOT}/Sensor.cpp
    ${INCROOT}/Sensor.h
    ${SRCROOT}/Touch.cpp
    ${INCROOT}/Touch.h
    ${INCROOT}/Types.h
    ${SRCROOT}/VideoMode.cpp
    ${INCROOT}/VideoMode.h
    ${SRCROOT}/Window.cpp
    ${SRCROOT}/WindowStruct.h
    ${INCROOT}/Window.h
    ${INCROOT}/WindowHandle.h
)

# define the csfml-window target
csfml_add_library(csfml-window
                  SOURCES ${SRC}
                  DEPENDS sfml-window)
