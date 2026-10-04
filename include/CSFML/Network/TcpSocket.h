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

#include <CSFML/Network/IpAddress.h>
#include <CSFML/Network/SocketStatus.h>
#include <CSFML/Network/Types.h>
#include <CSFML/System/Time.h>

#include <stdbool.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Transport layer security status codes
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfTlsNotConnected,      ///< TCP connection not yet connected
    sfTlsHandshakeStarted,  ///< TLS handshake has been started
    sfTlsHandshakeComplete, ///< TLS handshake is complete, stream is encrypted
    sfTlsError              ///< An unexpected error happened
} sfTlsStatus;


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
CSFML_NETWORK_API void sfTcpSocket_destroy(const sfTcpSocket* socket);

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
/// \param blocking true to set the socket as blocking, false for non-blocking
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfTcpSocket_setBlocking(sfTcpSocket* socket, bool blocking);

////////////////////////////////////////////////////////////
/// \brief Tell whether a TCP socket is in blocking or non-blocking mode
///
/// \param socket TCP socket object
///
/// \return true if the socket is blocking, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfTcpSocket_isBlocking(const sfTcpSocket* socket);

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
/// If the socket is not connected, this function returns
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
CSFML_NETWORK_API sfSocketStatus
    sfTcpSocket_connect(sfTcpSocket* socket, sfIpAddress remoteAddress, unsigned short remotePort, sfTime timeout);

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
/// sockets, use the sfTcpSocket_sendPartial(sfTcpSocket*, const void*, size_t, size_t*)
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

////////////////////////////////////////////////////////////
/// \brief Set up transport layer security as a client
///
/// Once the TCP connection is connected, transport layer
/// security can be set up.
///
/// If this function is called before the TCP connection is
/// connected, it will return sfTlsNotConnected and must be
/// called again once the TCP connection is connected.
///
/// If this function started TLS setup but could not finish
/// it within this call e.g. because this socket was set to
/// non-blocking, it will return sfTlsHandshakeStarted and
/// this function will have to be called repeatedly until
/// sfTlsHandshakeComplete is returned. If this socket is
/// blocking, sfTlsHandshakeComplete should be returned
/// within the same function call if TLS setup was successful.
///
/// If sfTlsError is returned, something went wrong with TLS
/// setup and the connection must be reconnected and TLS setup
/// reattempted after it is connected again.
///
/// If verification is enabled, this function verifies the peer
/// using the system provided certificate store. If the peer
/// does not have a certificate that was signed by a certificate
/// authority i.e. a self-signed certificate, the entire certificate
/// chain can be provided using sfTcpSocket_setupTlsClientWithCertificate.
///
/// The hostname is sent to the server via server name indication
/// (SNI) and used to verify the certificate chain returned by the
/// server.
///
/// \param socket     TCP socket object
/// \param hostname   Hostname of the remote peer, encoded in UTF-8, used for verification
/// \param verifyPeer True to enable peer verification, false to disable it
///
/// \return TLS status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfTlsStatus sfTcpSocket_setupTlsClient(sfTcpSocket* socket, const char* hostname, bool verifyPeer);

////////////////////////////////////////////////////////////
/// \brief Set up transport layer security as a client with a given certificate chain
///
/// When calling this function, the certificate chain to verify
/// the host with has to be provided. Verification is always
/// enabled when calling this function.
///
/// The certificate data can be provided in PEM or DER format.
///
/// See sfTcpSocket_setupTlsClient for details on the returned
/// status codes.
///
/// \param socket               TCP socket object
/// \param hostname             Hostname of the remote peer, encoded in UTF-8, used for verification
/// \param certificateChainData Certificate chain data in PEM or DER encoding
/// \param certificateChainSize Size of the certificate chain data
///
/// \return TLS status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfTlsStatus sfTcpSocket_setupTlsClientWithCertificate(
    sfTcpSocket* socket,
    const char*  hostname,
    const void*  certificateChainData,
    size_t       certificateChainSize);

////////////////////////////////////////////////////////////
/// \brief Set up transport layer security as a server
///
/// Once the TCP connection is connected, transport layer
/// security can be set up.
///
/// As a server, a certificate chain as well as a private key
/// must be provided. The certificate and private key data can
/// be provided in PEM or DER format. If the private key is
/// secured by a password, the password must be provided.
///
/// If sfTlsError is returned, something went wrong with TLS
/// setup and the connection must be disconnected. The client
/// must reconnect and reattempt TLS setup again.
///
/// See sfTcpSocket_setupTlsClient for details on the other
/// returned status codes.
///
/// \param socket                 TCP socket object
/// \param certificateChainData   Certificate chain data in PEM or DER encoding
/// \param certificateChainSize   Size of the certificate chain data
/// \param privateKeyData         Private key data in PEM or DER encoding
/// \param privateKeySize         Size of the private key data
/// \param privateKeyPasswordData Private key password data, can be NULL if there is no password
/// \param privateKeyPasswordSize Size of the private key password data
///
/// \return TLS status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfTlsStatus sfTcpSocket_setupTlsServer(
    sfTcpSocket* socket,
    const void*  certificateChainData,
    size_t       certificateChainSize,
    const void*  privateKeyData,
    size_t       privateKeySize,
    const void*  privateKeyPasswordData,
    size_t       privateKeyPasswordSize);

////////////////////////////////////////////////////////////
/// \brief Get the name of the TLS ciphersuite currently in use
///
/// The returned string stays valid until the next call to
/// this function or until the socket is destroyed.
///
/// \param socket TCP socket object
///
/// \return TLS ciphersuite currently in use or NULL if TLS is not set up
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfTcpSocket_getCurrentCiphersuiteName(const sfTcpSocket* socket);
