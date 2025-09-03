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
#include <CSFML/Network/Export.h>

#include <CSFML/Network/IpAddress.h>
#include <CSFML/Network/SocketStatus.h>
#include <CSFML/Network/Types.h>


////////////////////////////////////////////////////////////
/// \brief Create a new TCP listener
///
/// \return A new sfTcpListener object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfTcpListener* sfTcpListener_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy a TCP listener
///
/// \param listener TCP listener to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpListener_destroy(const sfTcpListener* listener);

////////////////////////////////////////////////////////////
/// \brief Set the blocking state of a TCP listener
///
/// In blocking mode, calls will not return until they have
/// completed their task. For example, a call to
/// sfTcpListener_accept in blocking mode won't return until
/// a new connection was actually received.
/// In non-blocking mode, calls will always return immediately,
/// using the return code to signal whether there was data
/// available or not.
/// By default, all sockets are blocking.
///
/// \param listener TCP listener object
/// \param blocking true to set the socket as blocking, false for non-blocking
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpListener_setBlocking(sfTcpListener* listener, bool blocking);

////////////////////////////////////////////////////////////
/// \brief Tell whether a TCP listener is in blocking or non-blocking mode
///
/// \param listener TCP listener object
///
/// \return true if the socket is blocking, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfTcpListener_isBlocking(const sfTcpListener* listener);

////////////////////////////////////////////////////////////
/// \brief Get the port to which a TCP listener is bound locally
///
/// If the socket is not listening to a port, this function
/// returns 0.
///
/// \param listener TCP listener object
///
/// \return Port to which the TCP listener is bound
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API unsigned short sfTcpListener_getLocalPort(const sfTcpListener* listener);

////////////////////////////////////////////////////////////
/// \brief Start listening for connections
///
/// This functions makes the socket listen to the specified
/// port, waiting for new connections.
/// If the socket was previously listening to another port,
/// it will be stopped first and bound to the new port.
///
/// When providing `sfTcpListener_anyPort()` as port, the listener
/// will request an available port from the system.
/// The chosen port can be retrieved by calling `sfTcpListener_getLocalPort()`.
///
/// If there is no specific address to listen to, pass sfIpAddress_Any
///
/// \param listener TCP listener object
/// \param port     Port to listen for new connections
/// \param address  Address of the interface to listen on
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpListener_listen(sfTcpListener* listener, unsigned short port, sfIpAddress address);

////////////////////////////////////////////////////////////
/// \brief Stop listening and close the socket
///
/// This function gracefully stops the listener. If the
/// socket is not listening, this function has no effect.
///
/// \param listener  TCP listener object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpListener_close(sfTcpListener* listener);

////////////////////////////////////////////////////////////
/// \brief Accept a new connection
///
/// If the socket is in blocking mode, this function will
/// not return until a connection is actually received.
///
/// The \a connected argument points to a valid sfTcpSocket pointer
/// in case of success (the function returns sfSocketDone), it points
/// to a NULL pointer otherwise.
///
/// \param listener  TCP listener object
/// \param connected Socket that will hold the new connection
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpListener_accept(sfTcpListener* listener, sfTcpSocket** connected);

////////////////////////////////////////////////////////////
/// \brief Return the special value that tells the system
///        to pick any available port
///
/// \return The value to use for any port
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API unsigned short sfTcpListener_anyPort(void);
