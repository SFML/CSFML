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

#ifndef SFML_WINDOWBASE_H
#define SFML_WINDOWBASE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Export.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Vulkan.h>
#include <SFML/System/Vector2.h>


////////////////////////////////////////////////////////////
/// \brief Enumeration of window creation styles
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfNone         = 0,      ///< No border / title bar (this flag and all others are mutually exclusive)
    sfTitlebar     = 1 << 0, ///< Title bar + fixed border
    sfResize       = 1 << 1, ///< Titlebar + resizable border + maximize button
    sfClose        = 1 << 2, ///< Titlebar + close button
    sfFullscreen   = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)
    sfDefaultStyle = sfTitlebar | sfResize | sfClose ///< Default window style
} sfWindowStyle;


////////////////////////////////////////////////////////////
/// \brief Construct a new window
///
/// This function creates the window with the size and pixel
/// depth defined in \a mode. An optional style can be passed to
/// customize the look and behaviour of the window (borders,
/// title bar, resizable, closable, ...). If \a style contains
/// sfFullscreen, then \a mode must be a valid video mode.
///
/// \param mode     Video mode to use (defines the width, height and depth of the rendering area of the windowBase)
/// \param title    Title of the window
/// \param style    Window style
///
/// \return A new sfWindow object
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfWindowBase* sfWindowBase_create(sfVideoMode mode, const char* title, sfUint32 style);

////////////////////////////////////////////////////////////
/// \brief Construct a new window (with a UTF-32 title)
///
/// This function creates the window with the size and pixel
/// depth defined in \a mode. An optional style can be passed to
/// customize the look and behaviour of the window (borders,
/// title bar, resizable, closable, ...). If \a style contains
/// sfFullscreen, then \a mode must be a valid video mode.
///
/// \param mode     Video mode to use (defines the width, height and depth of the rendering area of the windowBase)
/// \param title    Title of the window (UTF-32)
/// \param style    Window style
///
/// \return A new sfWindow object
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfWindowBase* sfWindowBase_createUnicode(sfVideoMode mode, const sfUint32* title, sfUint32 style);

////////////////////////////////////////////////////////////
/// \brief Construct a window from an existing control
///
/// \param handle   Platform-specific handle of the control
///
/// \return A new sfWindow object
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfWindowBase* sfWindowBase_createFromHandle(sfWindowHandle handle);

////////////////////////////////////////////////////////////
/// \brief Destroy a window
///
/// \param windowBase Window to destroy
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_destroy(sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Close a window and destroy all the attached resources
///
/// After calling this function, the sfWindow object remains
/// valid, you must call sfWindowBase_destroy to actually delete it.
/// All other functions such as sfWindowBase_pollEvent or sfWindowBase_display
/// will still work (i.e. you don't have to test sfWindowBase_isOpen
/// every time), and will have no effect on closed windows.
///
/// \param windowBase Window object
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_close(sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a window is opened
///
/// This function returns whether or not the window exists.
/// Note that a hidden window (sfWindowBase_setVisible(sfFalse)) will return
/// sfTrue.
///
/// \param windowBase Window object
///
/// \return sfTrue if the window is opened, sfFalse if it has been closed
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfWindowBase_isOpen(const sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Pop the event on top of event queue, if any, and return it
///
/// This function is not blocking: if there's no pending event then
/// it will return false and leave \a event unmodified.
/// Note that more than one event may be present in the event queue,
/// thus you should always call this function in a loop
/// to make sure that you process every pending event.
///
/// \param windowBase Window object
/// \param event      Event to be returned
///
/// \return sfTrue if an event was returned, or sfFalse if the event queue was empty
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfWindowBase_pollEvent(sfWindowBase* windowBase, sfEvent* event);

////////////////////////////////////////////////////////////
/// \brief Wait for an event and return it
///
/// This function is blocking: if there's no pending event then
/// it will wait until an event is received.
/// After this function returns (and no error occured),
/// the \a event object is always valid and filled properly.
/// This function is typically used when you have a thread that
/// is dedicated to events handling: you want to make this thread
/// sleep as long as no new event is received.
///
/// \param windowBase Window object
/// \param event      Event to be returned
///
/// \return sfFalse if any error occured
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfWindowBase_waitEvent(sfWindowBase* windowBase, sfEvent* event);

////////////////////////////////////////////////////////////
/// \brief Get the position of a window
///
/// \param windowBase Window object
///
/// \return Position in pixels
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfVector2i sfWindowBase_getPosition(const sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Change the position of a window on screen
///
/// This function only works for top-level windows
/// (i.e. it will be ignored for windows created from
/// the handle of a child window/control).
///
/// \param windowBase Window object
/// \param position   New position of the windowBase, in pixels
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setPosition(sfWindowBase* windowBase, sfVector2i position);

////////////////////////////////////////////////////////////
/// \brief Get the size of the rendering region of a window
///
/// The size doesn't include the titlebar and borders
/// of the window.
///
/// \param windowBase Window object
///
/// \return Size in pixels
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfVector2u sfWindowBase_getSize(const sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Change the size of the rendering region of a window
///
/// \param windowBase Window object
/// \param size       New size, in pixels
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setSize(sfWindowBase* windowBase, sfVector2u size);

////////////////////////////////////////////////////////////
/// \brief Change the title of a window
///
/// \param windowBase Window object
/// \param title      New title
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setTitle(sfWindowBase* windowBase, const char* title);

////////////////////////////////////////////////////////////
/// \brief Change the title of a window (with a UTF-32 string)
///
/// \param windowBase Window object
/// \param title      New title
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setUnicodeTitle(sfWindowBase* windowBase, const sfUint32* title);

////////////////////////////////////////////////////////////
/// \brief Change a window's icon
///
/// \a pixels must be an array of \a width x \a height pixels
/// in 32-bits RGBA format.
///
/// \param windowBase Window object
/// \param width      Icon's width, in pixels
/// \param height     Icon's height, in pixels
/// \param pixels     Pointer to the array of pixels in memory
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setIcon(sfWindowBase* windowBase, unsigned int width, unsigned int height, const sfUint8* pixels);

////////////////////////////////////////////////////////////
/// \brief Show or hide a window
///
/// \param windowBase Window object
/// \param visible    sfTrue to show the windowBase, sfFalse to hide it
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setVisible(sfWindowBase* windowBase, sfBool visible);

////////////////////////////////////////////////////////////
/// \brief Show or hide the mouse cursor
///
/// \param windowBase Window object
/// \param visible    sfTrue to show, sfFalse to hide
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setMouseCursorVisible(sfWindowBase* windowBase, sfBool visible);

////////////////////////////////////////////////////////////
/// \brief Grab or release the mouse cursor
///
/// If set, grabs the mouse cursor inside this window's client
/// area so it may no longer be moved outside its bounds.
/// Note that grabbing is only active while the window has
/// focus and calling this function for fullscreen windows
/// won't have any effect (fullscreen windows always grab the
/// cursor).
///
/// \param grabbed sfTrue to enable, sfFalse to disable
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setMouseCursorGrabbed(sfWindowBase* windowBase, sfBool grabbed);

////////////////////////////////////////////////////////////
/// \brief Set the displayed cursor to a native system cursor
///
/// Upon window creation, the arrow cursor is used by default.
///
/// \warning The cursor must not be destroyed while in use by
///          the window.
///
/// \warning Features related to Cursor are not supported on
///          iOS and Android.
///
/// \param windowBase Window object
/// \param cursor     Native system cursor type to display
///
/// \see sfCursor_createFromSystem
/// \see sfCursor_createFromPixels
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setMouseCursor(sfWindowBase* windowBase, const sfCursor* cursor);

////////////////////////////////////////////////////////////
/// \brief Enable or disable automatic key-repeat
///
/// If key repeat is enabled, you will receive repeated
/// KeyPress events while keeping a key pressed. If it is disabled,
/// you will only get a single event when the key is pressed.
///
/// Key repeat is enabled by default.
///
/// \param windowBase Window object
/// \param enabled    sfTrue to enable, sfFalse to disable
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setKeyRepeatEnabled(sfWindowBase* windowBase, sfBool enabled);

////////////////////////////////////////////////////////////
/// \brief Change the joystick threshold
///
/// The joystick threshold is the value below which
/// no JoystickMoved event will be generated.
///
/// \param windowBase Window object
/// \param threshold  New threshold, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_setJoystickThreshold(sfWindowBase* windowBase, float threshold);

////////////////////////////////////////////////////////////
/// \brief Request the current window to be made the active
/// foreground window
///
/// At any given time, only one window may have the input focus
/// to receive input events such as keystrokes or mouse events.
/// If a window requests focus, it only hints to the operating
/// system, that it would like to be focused. The operating system
/// is free to deny the request.
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API void sfWindowBase_requestFocus(sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Check whether the window has the input focus
///
/// At any given time, only one window may have the input focus
/// to receive input events such as keystrokes or most mouse
/// events.
///
/// \return True if window has focus, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfWindowBase_hasFocus(const sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Get the OS-specific handle of the window
///
/// The type of the returned handle is sfWindowHandle,
/// which is a typedef to the handle type defined by the OS.
/// You shouldn't need to use this function, unless you have
/// very specific stuff to implement that SFML doesn't support,
/// or implement a temporary workaround until a bug is fixed.
///
/// \param windowBase Window object
///
/// \return System handle of the window
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfWindowHandle sfWindowBase_getSystemHandle(const sfWindowBase* windowBase);

////////////////////////////////////////////////////////////
/// \brief Create a Vulkan rendering surface
///
/// \param windowBase Window object
/// \param instance  Vulkan instance
/// \param surface   Created surface
/// \param allocator Allocator to use
///
/// \return True if surface creation was successful, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_WINDOW_API sfBool sfWindowBase_createVulkanSurface(sfWindowBase* windowBase, const VkInstance* instance, VkSurfaceKHR* surface, const VkAllocationCallbacks* allocator);

#endif // SFML_WINDOWBASE_H
