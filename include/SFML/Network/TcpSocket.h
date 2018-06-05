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

#ifndef SFML_TCPSOCKET_H
#define SFML_TCPSOCKET_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Export.h>
#include <SFML/Network/IpAddress.h>
#include <SFML/Network/SocketStatus.h>
#include <SFML/Network/Types.h>
#include <SFML/System/Time.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Create a new TCP socket
///
/// \return A new sfTcpSocket object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfTcpSocket* sfTcpSocket_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy a TCP socket
///
/// \param socket TCP socket to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpSocket_destroy(sfTcpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Set the blocking state of a TCP listener
///
/// In blocking mode, calls will not return until they have
/// completed their task. For example, a call to
/// sfTcpSocket_receive in blocking mode won't return until
/// new data was actually received.
/// In non-blocking mode, calls will always return immediately,
/// using the return code to signal whether there was data
/// available or not.
/// By default, all sockets are blocking.
///
/// \param socket   TCP socket object
/// \param blocking sfTrue to set the socket as blocking, sfFalse for non-blocking
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpSocket_setBlocking(sfTcpSocket* socket, sfBool blocking);

////////////////////////////////////////////////////////////
/// \brief Tell whether a TCP socket is in blocking or non-blocking mode
///
/// \param socket TCP socket object
///
/// \return sfTrue if the socket is blocking, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfTcpSocket_isBlocking(const sfTcpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Get the port to which a TCP socket is bound locally
///
/// If the socket is not connected, this function returns 0.
///
/// \param socket TCP socket object
///
/// \return Port to which the socket is bound
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API unsigned short sfTcpSocket_getLocalPort(const sfTcpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Get the address of the connected peer of a TCP socket
///
/// It the socket is not connected, this function returns
/// sfIpAddress_None.
///
/// \param socket TCP socket object
///
/// \return Address of the remote peer
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfTcpSocket_getRemoteAddress(const sfTcpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Get the port of the connected peer to which
///        a TCP socket is connected
///
/// If the socket is not connected, this function returns 0.
///
/// \param socket TCP socket object
///
/// \return Remote port to which the socket is connected
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API unsigned short sfTcpSocket_getRemotePort(const sfTcpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Connect a TCP socket to a remote peer
///
/// In blocking mode, this function may take a while, especially
/// if the remote peer is not reachable. The last parameter allows
/// you to stop trying to connect after a given timeout.
/// If the socket was previously connected, it is first disconnected.
///
/// \param socket        TCP socket object
/// \param remoteAddress Address of the remote peer
/// \param remotePort    Port of the remote peer
/// \param timeout       Maximum time to wait
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpSocket_connect(sfTcpSocket* socket, sfIpAddress remoteAddress, unsigned short remotePort, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Disconnect a TCP socket from its remote peer
///
/// This function gracefully closes the connection. If the
/// socket is not connected, this function has no effect.
///
/// \param socket TCP socket object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpSocket_disconnect(sfTcpSocket* socket);

////////////////////////////////////////////////////////////
/// \brief Send raw data to the remote peer of a TCP socket
///
/// To be able to handle partial sends over non-blocking
/// sockets, use the sfTcpSocket_sendPartial(sfTcpSocket*, const void*, std::size_t, size_t*)
/// overload instead.
/// This function will fail if the socket is not connected.
///
/// \param socket TCP socket object
/// \param data   Pointer to the sequence of bytes to send
/// \param size   Number of bytes to send
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpSocket_send(sfTcpSocket* socket, const void* data, size_t size);

////////////////////////////////////////////////////////////
/// \brief Send raw data to the remote peer
///
/// This function will fail if the socket is not connected.
///
/// \param socket TCP socket object
/// \param data   Pointer to the sequence of bytes to send
/// \param size   Number of bytes to send
/// \param sent   The number of bytes sent will be written here
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpSocket_sendPartial(sfTcpSocket* socket, const void* data, size_t size, size_t* sent);

////////////////////////////////////////////////////////////
/// \brief Receive raw data from the remote peer of a TCP socket
///
/// In blocking mode, this function will wait until some
/// bytes are actually received.
/// This function will fail if the socket is not connected.
///
/// \param socket   TCP socket object
/// \param data     Pointer to the array to fill with the received bytes
/// \param size     Maximum number of bytes that can be received
/// \param received This variable is filled with the actual number of bytes received
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpSocket_receive(sfTcpSocket* socket, void* data, size_t size, size_t* received);

////////////////////////////////////////////////////////////
/// \brief Send a formatted packet of data to the remote peer of a TCP socket
///
/// In non-blocking mode, if this function returns sfSocketPartial,
/// you must retry sending the same unmodified packet before sending
/// anything else in order to guarantee the packet arrives at the remote
/// peer uncorrupted.
/// This function will fail if the socket is not connected.
///
/// \param socket TCP socket object
/// \param packet Packet to send
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpSocket_sendPacket(sfTcpSocket* socket, sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Receive a formatted packet of data from the remote peer
///
/// In blocking mode, this function will wait until the whole packet
/// has been received.
/// This function will fail if the socket is not connected.
///
/// \param socket TCP socket object
/// \param packet Packet to fill with the received data
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSocketStatus sfTcpSocket_receivePacket(sfTcpSocket* socket, sfPacket* packet);


#endif // SFML_TCPSOCKET_H
