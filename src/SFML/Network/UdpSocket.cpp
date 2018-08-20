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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/UdpSocket.h>
#include <SFML/Network/UdpSocketStruct.h>
#include <SFML/Network/PacketStruct.h>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Internal.h>
#include <string.h>


////////////////////////////////////////////////////////////
sfUdpSocket* sfUdpSocket_create(void)
{
    return new sfUdpSocket;
}


////////////////////////////////////////////////////////////
void sfUdpSocket_destroy(sfUdpSocket* socket)
{
    delete socket;
}


////////////////////////////////////////////////////////////
void sfUdpSocket_setBlocking(sfUdpSocket* socket, sfBool blocking)
{
    CSFML_CALL(socket, setBlocking(blocking == sfTrue));
}

////////////////////////////////////////////////////////////
sfBool sfUdpSocket_isBlocking(const sfUdpSocket* socket)
{
    CSFML_CALL_RETURN(socket, isBlocking(), sfFalse);
}


////////////////////////////////////////////////////////////
unsigned short sfUdpSocket_getLocalPort(const sfUdpSocket* socket)
{
    CSFML_CALL_RETURN(socket, getLocalPort(), 0);
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_bind(sfUdpSocket* socket, unsigned short port, sfIpAddress address)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    sf::IpAddress sfmlAddress(address.address);
    return static_cast<sfSocketStatus>(socket->This.bind(port, sfmlAddress));
}


////////////////////////////////////////////////////////////
void sfUdpSocket_unbind(sfUdpSocket* socket)
{
    CSFML_CALL(socket, unbind());
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_send(sfUdpSocket* socket, const void* data, size_t size, sfIpAddress remoteAddress, unsigned short remotePort)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    // Convert the address
    sf::IpAddress address(remoteAddress.address);

    return static_cast<sfSocketStatus>(socket->This.send(data, size, address, remotePort));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_receive(sfUdpSocket* socket, void* data, size_t size, size_t* received, sfIpAddress* remoteAddress, unsigned short* remotePort)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    sf::IpAddress address;
    unsigned short port;
    std::size_t sizeReceived;

    sf::Socket::Status status = socket->This.receive(data, size, sizeReceived, address, port);
    if (status != sf::Socket::Done)
        return static_cast<sfSocketStatus>(status);

    if (received)
        *received = sizeReceived;

    if (remoteAddress)
        strncpy(remoteAddress->address, address.toString().c_str(), 16);

    if (remotePort)
        *remotePort = port;

    return sfSocketDone;
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_sendPacket(sfUdpSocket* socket, sfPacket* packet, sfIpAddress remoteAddress, unsigned short remotePort)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);
    CSFML_CHECK_RETURN(packet, sfSocketError);

    // Convert the address
    sf::IpAddress address(remoteAddress.address);

    return static_cast<sfSocketStatus>(socket->This.send(packet->This, address, remotePort));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_receivePacket(sfUdpSocket* socket, sfPacket* packet, sfIpAddress* remoteAddress, unsigned short* remotePort)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);
    CSFML_CHECK_RETURN(packet, sfSocketError);

    sf::IpAddress address;
    unsigned short port;

    sf::Socket::Status status = socket->This.receive(packet->This, address, port);
    if (status != sf::Socket::Done)
        return static_cast<sfSocketStatus>(status);

    if (remoteAddress)
        strncpy(remoteAddress->address, address.toString().c_str(), 16);

    if (remotePort)
        *remotePort = port;

    return sfSocketDone;
}


////////////////////////////////////////////////////////////
unsigned int sfUdpSocket_maxDatagramSize()
{
    return sf::UdpSocket::MaxDatagramSize;
}
