////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2026 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Network/Export.h>

#include <CSFML/Network/Types.h>
#include <CSFML/System/Time.h>

#include <stdbool.h>
#include <stdint.h>


////////////////////////////////////////////////////////////
/// \brief Readiness types a socket selector can check for
///
/// The values can be combined with a bitwise OR.
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfSocketSelectorReceive = 1 << 0, ///< Check if sockets are ready to be received from
    sfSocketSelectorSend    = 1 << 1  ///< Check if sockets are ready to be sent to
} sfSocketSelectorReadiness;

////////////////////////////////////////////////////////////
/// \brief Callback that is called when a socket is ready
///
/// \param readiness Readiness of the socket, a combination of sfSocketSelectorReadiness values
/// \param userData  User data passed when adding the socket
///
////////////////////////////////////////////////////////////
typedef void (*sfSocketSelectorCallback)(uint32_t readiness, void* userData);


////////////////////////////////////////////////////////////
/// \brief Create a new selector
///
/// \return A new sfSocketSelector object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketSelector* sfSocketSelector_create(void);

////////////////////////////////////////////////////////////
/// \brief Create a new socket selector by copying an existing one
///
/// \param selector Socket selector to copy
///
/// \return A new sfSocketSelector object which is a copy of \a selector
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketSelector* sfSocketSelector_copy(const sfSocketSelector* selector);

////////////////////////////////////////////////////////////
/// \brief Destroy a socket selector
///
/// \param selector Socket selector to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSocketSelector_destroy(const sfSocketSelector* selector);

////////////////////////////////////////////////////////////
/// \brief Add a new socket to a socket selector
///
/// This function keeps a weak pointer to the socket,
/// so you have to make sure that the socket is not destroyed
/// while it is stored in the selector.
///
/// The socket is checked for being ready to receive.
///
/// \param selector Socket selector object
/// \param socket   Pointer to the socket to add
///
/// \return True if the socket was successfully added
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSocketSelector_addTcpListener(sfSocketSelector* selector, sfTcpListener* socket);
CSFML_NETWORK_API bool sfSocketSelector_addTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket);
CSFML_NETWORK_API bool sfSocketSelector_addUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Add a new socket to a socket selector with the readiness to check for and an optional callback
///
/// This function keeps a weak pointer to the socket,
/// so you have to make sure that the socket is not destroyed
/// while it is stored in the selector.
///
/// The readiness to wait for can be specified as a combination
/// of sfSocketSelectorReceive and sfSocketSelectorSend.
///
/// If a callback is provided, it will be called with the
/// readiness of the socket when sfSocketSelector_dispatchReadyCallbacks
/// is called after sfSocketSelector_wait returned true. Using
/// callbacks scales better than checking every socket with
/// sfSocketSelector_isXxxReadyFor.
///
/// Adding a socket that has already been added updates its
/// readiness and callback.
///
/// \param selector  Socket selector object
/// \param socket    Pointer to the socket to add
/// \param readiness Readiness to wait for, combination of sfSocketSelectorReadiness values
/// \param callback  Callback to call when the socket is ready, can be NULL
/// \param userData  User data that will be passed to the callback
///
/// \return True if the socket was successfully added
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSocketSelector_addTcpListenerWithReadiness(
    sfSocketSelector*        selector,
    sfTcpListener*           socket,
    uint32_t                 readiness,
    sfSocketSelectorCallback callback,
    void*                    userData);
CSFML_NETWORK_API bool sfSocketSelector_addTcpSocketWithReadiness(
    sfSocketSelector*        selector,
    sfTcpSocket*             socket,
    uint32_t                 readiness,
    sfSocketSelectorCallback callback,
    void*                    userData);
CSFML_NETWORK_API bool sfSocketSelector_addUdpSocketWithReadiness(
    sfSocketSelector*        selector,
    sfUdpSocket*             socket,
    uint32_t                 readiness,
    sfSocketSelectorCallback callback,
    void*                    userData);

////////////////////////////////////////////////////////////
/// \brief Remove a socket from a socket selector
///
/// This function doesn't destroy the socket, it simply
/// removes the pointer that the selector has to it.
///
/// \param selector Socket selector object
/// \param socket   Pointer to the socket to remove
///
/// \return True if the socket was successfully removed
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSocketSelector_removeTcpListener(sfSocketSelector* selector, sfTcpListener* socket);
CSFML_NETWORK_API bool sfSocketSelector_removeTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket);
CSFML_NETWORK_API bool sfSocketSelector_removeUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Remove all the sockets stored in a selector
///
/// This function doesn't destroy any instance, it simply
/// removes all the pointers that the selector has to
/// external sockets.
///
/// \param selector Socket selector object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSocketSelector_clear(sfSocketSelector* selector);

////////////////////////////////////////////////////////////
/// \brief Wait until one or more sockets are ready
///
/// This function returns as soon as at least one socket is
/// ready for the readiness it was added with (by default
/// having some data available to be received). To know which
/// sockets are ready, use the sfSocketSelector_isXxxReady
/// functions or sfSocketSelector_dispatchReadyCallbacks.
/// If you use a timeout and no socket is ready before the timeout
/// is over, the function returns false.
///
/// \param selector Socket selector object
/// \param timeout  Maximum time to wait (use sfTimeZero for infinity)
///
/// \return true if there are sockets ready, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSocketSelector_wait(sfSocketSelector* selector, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Test a socket to know if it is ready to receive data
///
/// This function must be used after a call to
/// sfSocketSelector_wait, to know which sockets are ready to
/// receive data. If a socket is ready, a call to Receive will
/// never block because we know that there is data available to read.
/// Note that if this function returns true for a sfTcpListener,
/// this means that it is ready to accept a new connection.
///
/// \param selector Socket selector object
/// \param socket   Socket to test
///
/// \return true if the socket is ready to read, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSocketSelector_isTcpListenerReady(const sfSocketSelector* selector, sfTcpListener* socket);
CSFML_NETWORK_API bool sfSocketSelector_isTcpSocketReady(const sfSocketSelector* selector, sfTcpSocket* socket);
CSFML_NETWORK_API bool sfSocketSelector_isUdpSocketReady(const sfSocketSelector* selector, sfUdpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Test a socket to know if it is ready for the given readiness
///
/// This function must be used after a call to
/// sfSocketSelector_wait, to know which sockets are ready.
///
/// \param selector  Socket selector object
/// \param socket    Socket to test
/// \param readiness Readiness to check for, combination of sfSocketSelectorReadiness values
///
/// \return true if the socket is ready, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSocketSelector_isTcpListenerReadyFor(const sfSocketSelector* selector,
                                                              sfTcpListener*          socket,
                                                              uint32_t                readiness);
CSFML_NETWORK_API bool sfSocketSelector_isTcpSocketReadyFor(const sfSocketSelector* selector,
                                                            sfTcpSocket*            socket,
                                                            uint32_t                readiness);
CSFML_NETWORK_API bool sfSocketSelector_isUdpSocketReadyFor(const sfSocketSelector* selector,
                                                            sfUdpSocket*            socket,
                                                            uint32_t                readiness);

////////////////////////////////////////////////////////////
/// \brief Call the callbacks of all sockets that are ready
///
/// After sfSocketSelector_wait returned true, at least one
/// socket is ready. Calling this function will call the
/// callbacks of all the sockets that became ready during
/// the wait. Calling this function multiple times after a
/// single call to sfSocketSelector_wait will run the callbacks
/// multiple times.
///
/// \param selector Socket selector object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSocketSelector_dispatchReadyCallbacks(sfSocketSelector* selector);
