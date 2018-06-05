////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
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

#ifndef SFML_SOCKETSELECTOR_H
#define SFML_SOCKETSELECTOR_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Export.h>
#include <SFML/Network/Types.h>
#include <SFML/System/Time.h>


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
CSFML_NETWORK_API void sfSocketSelector_destroy(sfSocketSelector* selector);

////////////////////////////////////////////////////////////
/// \brief Add a new socket to a socket selector
///
/// This function keeps a weak pointer to the socket,
/// so you have to make sure that the socket is not destroyed
/// while it is stored in the selector.
///
/// \param selector Socket selector object
/// \param socket   Pointer to the socket to add
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSocketSelector_addTcpListener(sfSocketSelector* selector, sfTcpListener* socket);
CSFML_NETWORK_API void sfSocketSelector_addTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket);
CSFML_NETWORK_API void sfSocketSelector_addUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Remove a socket from a socket selector
///
/// This function doesn't destroy the socket, it simply
/// removes the pointer that the selector has to it.
///
/// \param selector Socket selector object
/// \param socket   POointer to the socket to remove
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSocketSelector_removeTcpListener(sfSocketSelector* selector, sfTcpListener* socket);
CSFML_NETWORK_API void sfSocketSelector_removeTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket);
CSFML_NETWORK_API void sfSocketSelector_removeUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket);

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
/// \brief Wait until one or more sockets are ready to receive
///
/// This function returns as soon as at least one socket has
/// some data available to be received. To know which sockets are
/// ready, use the sfSocketSelector_isXxxReady functions.
/// If you use a timeout and no socket is ready before the timeout
/// is over, the function returns sfFalse.
///
/// \param selector Socket selector object
/// \param timeout  Maximum time to wait (use sfTimeZero for infinity)
///
/// \return sfTrue if there are sockets ready, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfSocketSelector_wait(sfSocketSelector* selector, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Test a socket to know if it is ready to receive data
///
/// This function must be used after a call to
/// sfSocketSelector_wait, to know which sockets are ready to
/// receive data. If a socket is ready, a call to Receive will
/// never block because we know that there is data available to read.
/// Note that if this function returns sfTrue for a sfTcpListener,
/// this means that it is ready to accept a new connection.
///
/// \param selector Socket selector object
/// \param socket   Socket to test
///
/// \return sfTrue if the socket is ready to read, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfSocketSelector_isTcpListenerReady(const sfSocketSelector* selector, sfTcpListener* socket);
CSFML_NETWORK_API sfBool sfSocketSelector_isTcpSocketReady(const sfSocketSelector* selector, sfTcpSocket* socket);
CSFML_NETWORK_API sfBool sfSocketSelector_isUdpSocketReady(const sfSocketSelector* selector, sfUdpSocket* socket);


#endif // SFML_SOCKETSELECTOR_H
