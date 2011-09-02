////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
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
sfTcpSocket* sfTcpSocket_Create(void)
{
    return new sfTcpSocket;
}


////////////////////////////////////////////////////////////
void sfTcpSocket_Destroy(sfTcpSocket* socket)
{
    delete socket;
}


////////////////////////////////////////////////////////////
void sfTcpSocket_SetBlocking(sfTcpSocket* socket, sfBool blocking)
{
    CSFML_CALL(socket, SetBlocking(blocking == sfTrue));
}


////////////////////////////////////////////////////////////
sfBool sfTcpSocket_IsBlocking(const sfTcpSocket* socket)
{
    CSFML_CALL_RETURN(socket, IsBlocking(), sfFalse);
}


////////////////////////////////////////////////////////////
unsigned short sfTcpSocket_GetLocalPort(const sfTcpSocket* socket)
{
    CSFML_CALL_RETURN(socket, GetLocalPort(), 0);
}


////////////////////////////////////////////////////////////
sfIpAddress sfTcpSocket_GetRemoteAddress(const sfTcpSocket* socket)
{
    sfIpAddress result;
    CSFML_CHECK_RETURN(socket, result);

    sf::IpAddress address = socket->This.GetRemoteAddress();
    strncpy(result.Address, address.ToString().c_str(), 16);

    return result;
}


////////////////////////////////////////////////////////////
unsigned short sfTcpSocket_GetRemotePort(const sfTcpSocket* socket)
{
    CSFML_CALL_RETURN(socket, GetRemotePort(), 0);
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_Connect(sfTcpSocket* socket, sfIpAddress host, unsigned short port, sfUint32 timeout)
{
    sf::IpAddress address(host.Address);

    CSFML_CHECK_RETURN(socket, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.Connect(address, port, timeout));
}


////////////////////////////////////////////////////////////
void sfTcpSocket_Disconnect(sfTcpSocket* socket)
{
    CSFML_CALL(socket, Disconnect());
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_Send(sfTcpSocket* socket, const char* data, size_t size)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.Send(data, size));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_Receive(sfTcpSocket* socket, char* data, size_t maxSize, size_t* sizeReceived)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);

    if (sizeReceived)
    {
        return static_cast<sfSocketStatus>(socket->This.Receive(data, maxSize, *sizeReceived));
    }
    else
    {
        std::size_t size = 0;
        return static_cast<sfSocketStatus>(socket->This.Receive(data, maxSize, size));
    }
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_SendPacket(sfTcpSocket* socket, sfPacket* packet)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);
    CSFML_CHECK_RETURN(packet, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.Send(packet->This));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpSocket_ReceivePacket(sfTcpSocket* socket, sfPacket* packet)
{
    CSFML_CHECK_RETURN(socket, sfSocketError);
    CSFML_CHECK_RETURN(packet, sfSocketError);

    return static_cast<sfSocketStatus>(socket->This.Receive(packet->This));
}
