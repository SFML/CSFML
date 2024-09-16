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
#include <CSFML/Network/SocketSelector.h>
#include <CSFML/Network/SocketSelectorStruct.hpp>
#include <CSFML/Network/TcpListenerStruct.hpp>
#include <CSFML/Network/TcpSocketStruct.hpp>
#include <CSFML/Network/UdpSocketStruct.hpp>


////////////////////////////////////////////////////////////
sfSocketSelector* sfSocketSelector_create()
{
    return new sfSocketSelector;
}


////////////////////////////////////////////////////////////
sfSocketSelector* sfSocketSelector_copy(const sfSocketSelector* selector)
{
    assert(selector);
    return new sfSocketSelector(*selector);
}


////////////////////////////////////////////////////////////
void sfSocketSelector_destroy(const sfSocketSelector* selector)
{
    delete selector;
}


////////////////////////////////////////////////////////////
void sfSocketSelector_addTcpListener(sfSocketSelector* selector, sfTcpListener* socket)
{
    assert(selector);
    assert(socket);
    selector->add(*socket);
}
void sfSocketSelector_addTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket)
{
    assert(selector);
    assert(socket);
    selector->add(*socket);
}
void sfSocketSelector_addUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket)
{
    assert(selector);
    assert(socket);
    selector->add(*socket);
}


////////////////////////////////////////////////////////////
void sfSocketSelector_removeTcpListener(sfSocketSelector* selector, sfTcpListener* socket)
{
    assert(selector);
    assert(socket);
    selector->remove(*socket);
}
void sfSocketSelector_removeTcpSocket(sfSocketSelector* selector, sfTcpSocket* socket)
{
    assert(selector);
    assert(socket);
    selector->remove(*socket);
}
void sfSocketSelector_removeUdpSocket(sfSocketSelector* selector, sfUdpSocket* socket)
{
    assert(selector);
    assert(socket);
    selector->remove(*socket);
}


////////////////////////////////////////////////////////////
void sfSocketSelector_clear(sfSocketSelector* selector)
{
    assert(selector);
    selector->clear();
}


////////////////////////////////////////////////////////////
bool sfSocketSelector_wait(sfSocketSelector* selector, sfTime timeout)
{
    assert(selector);
    return selector->wait(sf::microseconds(timeout.microseconds));
}


////////////////////////////////////////////////////////////
bool sfSocketSelector_isTcpListenerReady(const sfSocketSelector* selector, sfTcpListener* socket)
{
    assert(selector);
    assert(socket);
    return selector->isReady(*socket);
}
bool sfSocketSelector_isTcpSocketReady(const sfSocketSelector* selector, sfTcpSocket* socket)
{
    assert(selector);
    assert(socket);
    return selector->isReady(*socket);
}
bool sfSocketSelector_isUdpSocketReady(const sfSocketSelector* selector, sfUdpSocket* socket)
{
    assert(selector);
    assert(socket);
    return selector->isReady(*socket);
}
