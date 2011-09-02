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
#include <SFML/Network/TcpListener.h>
#include <SFML/Network/TcpListenerStruct.h>
#include <SFML/Network/TcpSocketStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfTcpListener* sfTcpListener_Create(void)
{
    return new sfTcpListener;
}


////////////////////////////////////////////////////////////
void sfTcpListener_Destroy(sfTcpListener* listener)
{
    delete listener;
}


////////////////////////////////////////////////////////////
void sfTcpListener_SetBlocking(sfTcpListener* listener, sfBool blocking)
{
    CSFML_CALL(listener, SetBlocking(blocking == sfTrue));
}


////////////////////////////////////////////////////////////
sfBool sfTcpListener_IsBlocking(const sfTcpListener* listener)
{
    CSFML_CALL_RETURN(listener, IsBlocking(), sfFalse);
}


////////////////////////////////////////////////////////////
unsigned short sfTcpListener_GetLocalPort(const sfTcpListener* listener)
{
    CSFML_CALL_RETURN(listener, GetLocalPort(), 0);
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpListener_Listen(sfTcpListener* listener, unsigned short port)
{
    CSFML_CHECK_RETURN(listener, sfSocketError);

    return static_cast<sfSocketStatus>(listener->This.Listen(port));
}


////////////////////////////////////////////////////////////
sfSocketStatus sfTcpListener_Accept(sfTcpListener* listener, sfTcpSocket** connected)
{
    CSFML_CHECK_RETURN(listener, sfSocketError);
    CSFML_CHECK_RETURN(connected, sfSocketError);

    *connected = new sfTcpSocket;
    return static_cast<sfSocketStatus>(listener->This.Accept((*connected)->This));
}
