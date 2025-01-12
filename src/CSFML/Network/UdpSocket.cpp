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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Network/PacketStruct.hpp>
#include <CSFML/Network/UdpSocket.h>
#include <CSFML/Network/UdpSocketStruct.hpp>

#include <SFML/Network/IpAddress.hpp>

#include <cstring>


////////////////////////////////////////////////////////////
sfUdpSocket* sfUdpSocket_create()
{
    return new sfUdpSocket;
}


////////////////////////////////////////////////////////////
void sfUdpSocket_destroy(const sfUdpSocket* socket)
{
    delete socket;
}


////////////////////////////////////////////////////////////
void sfUdpSocket_setBlocking(sfUdpSocket* socket, bool blocking)
{
    assert(socket);
    socket->setBlocking(blocking);
}

////////////////////////////////////////////////////////////
bool sfUdpSocket_isBlocking(const sfUdpSocket* socket)
{
    assert(socket);
    return socket->isBlocking();
}


////////////////////////////////////////////////////////////
unsigned short sfUdpSocket_getLocalPort(const sfUdpSocket* socket)
{
    assert(socket);
    return socket->getLocalPort();
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_bind(sfUdpSocket* socket, unsigned short port, sfIpAddress address)
{
    assert(socket);

    std::optional<sf::IpAddress> sfmlAddress = sf::IpAddress::resolve(address.address);

    if (!sfmlAddress)
    {
        return sfSocketError;
    }

    return static_cast<sfSocketStatus>(socket->bind(port, *sfmlAddress));
}


////////////////////////////////////////////////////////////
void sfUdpSocket_unbind(sfUdpSocket* socket)
{
    assert(socket);
    socket->unbind();
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_send(sfUdpSocket* socket, const void* data, size_t size, sfIpAddress remoteAddress, unsigned short remotePort)
{
    assert(socket);

    // Convert the address
    std::optional<sf::IpAddress> address = sf::IpAddress::resolve(remoteAddress.address);

    if (!address)
    {
        return sfSocketError;
    }

    return static_cast<sfSocketStatus>(socket->send(data, size, *address, remotePort));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_receive(sfUdpSocket*    socket,
                                   void*           data,
                                   size_t          size,
                                   size_t*         received,
                                   sfIpAddress*    remoteAddress,
                                   unsigned short* remotePort)
{
    assert(socket);

    std::optional<sf::IpAddress> address;
    unsigned short               port         = 0;
    std::size_t                  sizeReceived = 0;

    sf::Socket::Status status = socket->receive(data, size, sizeReceived, address, port);
    if (status != sf::Socket::Status::Done)
        return static_cast<sfSocketStatus>(status);

    if (received)
        *received = sizeReceived;

    if (remoteAddress)
    {
        *remoteAddress = sfIpAddress_None;

        if (address)
        {
            std::strncpy(remoteAddress->address, address->toString().c_str(), 15);
        }
    }

    if (remotePort)
        *remotePort = port;

    return sfSocketDone;
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_sendPacket(sfUdpSocket* socket, sfPacket* packet, sfIpAddress remoteAddress, unsigned short remotePort)
{
    assert(socket);
    assert(packet);

    // Convert the address
    std::optional<sf::IpAddress> address = sf::IpAddress::resolve(remoteAddress.address);

    if (!address)
    {
        return sfSocketError;
    }

    return static_cast<sfSocketStatus>(socket->send(*packet, *address, remotePort));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfUdpSocket_receivePacket(sfUdpSocket* socket, sfPacket* packet, sfIpAddress* remoteAddress, unsigned short* remotePort)
{
    assert(socket);
    assert(packet);

    std::optional<sf::IpAddress> address;
    unsigned short               port = 0;

    sf::Socket::Status status = socket->receive(*packet, address, port);
    if (status != sf::Socket::Status::Done)
        return static_cast<sfSocketStatus>(status);

    if (remoteAddress)
    {
        *remoteAddress = sfIpAddress_None;

        if (address)
        {
            std::strncpy(remoteAddress->address, address->toString().c_str(), 15);
        }
    }

    if (remotePort)
        *remotePort = port;

    return sfSocketDone;
}


////////////////////////////////////////////////////////////
unsigned int sfUdpSocket_maxDatagramSize()
{
    return sf::UdpSocket::MaxDatagramSize;
}


////////////////////////////////////////////////////////////
unsigned short sfUdpSocket_anyPort()
{
    return 0;
}
