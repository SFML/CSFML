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
#include <CSFML/Network/TcpSocket.h>
#include <CSFML/Network/TcpSocketStruct.hpp>

#include <SFML/Network/IpAddress.hpp>

#include <cstring>


////////////////////////////////////////////////////////////
sfTcpSocket* sfTcpSocket_create()
{
    return new sfTcpSocket;
}


////////////////////////////////////////////////////////////
void sfTcpSocket_destroy(const sfTcpSocket* socket)
{
    delete socket;
}


////////////////////////////////////////////////////////////
void sfTcpSocket_setBlocking(sfTcpSocket* socket, bool blocking)
{
    assert(socket);
    socket->setBlocking(blocking);
}


////////////////////////////////////////////////////////////
bool sfTcpSocket_isBlocking(const sfTcpSocket* socket)
{
    assert(socket);
    return socket->isBlocking();
}


////////////////////////////////////////////////////////////
unsigned short sfTcpSocket_getLocalPort(const sfTcpSocket* socket)
{
    assert(socket);
    return socket->getLocalPort();
}


////////////////////////////////////////////////////////////
sfIpAddress sfTcpSocket_getRemoteAddress(const sfTcpSocket* socket)
{
    assert(socket);

    std::optional<sf::IpAddress> address = socket->getRemoteAddress();

    sfIpAddress result = sfIpAddress_None;
    if (address)
    {
        std::strncpy(result.address, address->toString().c_str(), 15);
    }

    return result;
}


////////////////////////////////////////////////////////////
unsigned short sfTcpSocket_getRemotePort(const sfTcpSocket* socket)
{
    assert(socket);
    return socket->getRemotePort();
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_connect(sfTcpSocket* socket, sfIpAddress remoteAddress, unsigned short remotePort, sfTime timeout)
{
    std::optional<sf::IpAddress> address = sf::IpAddress::resolve(remoteAddress.address);

    if (!address)
    {
        return sfSocketError;
    }

    assert(socket);
    return static_cast<sfSocketStatus>(socket->connect(*address, remotePort, sf::microseconds(timeout.microseconds)));
}


////////////////////////////////////////////////////////////
void sfTcpSocket_disconnect(sfTcpSocket* socket)
{
    assert(socket);
    socket->disconnect();
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_send(sfTcpSocket* socket, const void* data, size_t size)
{
    assert(socket);
    return static_cast<sfSocketStatus>(socket->send(data, size));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_sendPartial(sfTcpSocket* socket, const void* data, size_t size, size_t* sent)
{
    assert(socket);
    return static_cast<sfSocketStatus>(socket->send(data, size, *sent));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_receive(sfTcpSocket* socket, void* data, size_t size, size_t* received)
{
    assert(socket);

    if (received)
    {
        return static_cast<sfSocketStatus>(socket->receive(data, size, *received));
    }
    else
    {
        std::size_t tempReceived = 0;
        return static_cast<sfSocketStatus>(socket->receive(data, size, tempReceived));
    }
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_sendPacket(sfTcpSocket* socket, sfPacket* packet)
{
    assert(socket);
    assert(packet);
    return static_cast<sfSocketStatus>(socket->send(*packet));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_receivePacket(sfTcpSocket* socket, sfPacket* packet)
{
    assert(socket);
    assert(packet);
    return static_cast<sfSocketStatus>(socket->receive(*packet));
}
