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
#include <SFML/Network/TcpSocket.h>
#include <SFML/Network/TcpSocketStruct.h>
#include <SFML/Network/PacketStruct.h>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Internal.h>
#include <string.h>


////////////////////////////////////////////////////////////
sfTcpSocket* sfTcpSocket_create(void)
{
    return new sfTcpSocket;
}


////////////////////////////////////////////////////////////
void sfTcpSocket_destroy(sfTcpSocket* socket)
{
    delete socket;
}


////////////////////////////////////////////////////////////
void sfTcpSocket_setBlocking(sfTcpSocket* socket, sfBool blocking)
{
    CSFML_CALL(socket, setBlocking(blocking == sfTrue));
}


////////////////////////////////////////////////////////////
sfBool sfTcpSocket_isBlocking(const sfTcpSocket* socket)
{
    CSFML_CALL_RETURN(socket, isBlocking(), sfFalse);
}


////////////////////////////////////////////////////////////
unsigned short sfTcpSocket_getLocalPort(const sfTcpSocket* socket)
{
    CSFML_CALL_RETURN(socket, getLocalPort(), 0);
}


////////////////////////////////////////////////////////////
sfIpAddress sfTcpSocket_getRemoteAddress(const sfTcpSocket* socket)
{
    sfIpAddress result = sfIpAddress_None;
    CSFML_CHECK_RETURN(socket, result);

    sf::IpAddress address = socket->This.getRemoteAddress();
    strncpy(result.address, address.toString().c_str(), 16);

    return result;
}


////////////////////////////////////////////////////////////
unsigned short sfTcpSocket_getRemotePort(const sfTcpSocket* socket)
{
    CSFML_CALL_RETURN(socket, getRemotePort(), 0);
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_connect(sfTcpSocket* socket, sfIpAddress remoteAddress, unsigned short remotePort, sfTime timeout)
{
    sf::IpAddress address(remoteAddress.address);

    CSFML_CHECK_RETURN(socket, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.connect(address, remotePort, sf::microseconds(timeout.microseconds)));
}


////////////////////////////////////////////////////////////
void sfTcpSocket_disconnect(sfTcpSocket* socket)
{
    CSFML_CALL(socket, disconnect());
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_send(sfTcpSocket* socket, const void* data, size_t size)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.send(data, size));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_sendPartial(sfTcpSocket* socket, const void* data, size_t size, size_t* sent)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.send(data, size, *sent));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_receive(sfTcpSocket* socket, void* data, size_t size, size_t* received)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    if (received)
    {
        return static_cast<sfSocketStatus>(socket->This.receive(data, size, *received));
    }
    else
    {
        std::size_t tempReceived = 0;
        return static_cast<sfSocketStatus>(socket->This.receive(data, size, tempReceived));
    }
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_sendPacket(sfTcpSocket* socket, sfPacket* packet)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);
    CSFML_CHECK_RETURN(packet, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.send(packet->This));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_receivePacket(sfTcpSocket* socket, sfPacket* packet)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);
    CSFML_CHECK_RETURN(packet, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.receive(packet->This));
}
