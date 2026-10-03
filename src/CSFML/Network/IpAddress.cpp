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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Network/ConvertIpAddress.hpp>
#include <CSFML/Network/IpAddress.h>

#include <SFML/Network/IpAddress.hpp>

#include <algorithm>
#include <array>
#include <cstring>


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_None = {{0}};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_Any = {"0.0.0.0"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_LocalHost = {"127.0.0.1"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_Broadcast = {"255.255.255.255"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_AnyV4 = {"0.0.0.0"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_LocalHostV4 = {"127.0.0.1"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_BroadcastV4 = {"255.255.255.255"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_AnyV6 = {"::"};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_LocalHostV6 = {"::1"};


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromString(const char* address)
{
    assert(address);
    return convertIpAddress(sf::IpAddress::fromString(address));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_resolve(const char* address)
{
    assert(address);
    return convertIpAddress(sf::IpAddress::resolve(address));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromBytes(uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3)
{
    return convertIpAddress(sf::IpAddress(byte0, byte1, byte2, byte3));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromInteger(uint32_t address)
{
    return convertIpAddress(sf::IpAddress(address));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromV6Bytes(const uint8_t bytes[16])
{
    assert(bytes);

    std::array<std::uint8_t, 16> array{};
    std::copy(bytes, bytes + array.size(), array.begin());
    return convertIpAddress(sf::IpAddress(array));
}


////////////////////////////////////////////////////////////
void sfIpAddress_toString(sfIpAddress address, char* string)
{
    if (string)
        std::strcpy(string, address.address);
}


////////////////////////////////////////////////////////////
uint32_t sfIpAddress_toInteger(sfIpAddress address)
{
    const auto sfmlAddress = convertIpAddress(address);
    return sfmlAddress && sfmlAddress->isV4() ? sfmlAddress->toInteger() : 0;
}


////////////////////////////////////////////////////////////
bool sfIpAddress_toV6Bytes(sfIpAddress address, uint8_t bytes[16])
{
    assert(bytes);

    const auto sfmlAddress = convertIpAddress(address);
    if (!sfmlAddress || !sfmlAddress->isV6())
        return false;

    const auto array = sfmlAddress->toBytes();
    std::copy(array.begin(), array.end(), bytes);
    return true;
}


////////////////////////////////////////////////////////////
sfIpAddressType sfIpAddress_getType(sfIpAddress address)
{
    const auto sfmlAddress = convertIpAddress(address);
    return sfmlAddress ? static_cast<sfIpAddressType>(sfmlAddress->getType()) : sfIpAddressV4;
}


////////////////////////////////////////////////////////////
bool sfIpAddress_isV4(sfIpAddress address)
{
    const auto sfmlAddress = convertIpAddress(address);
    return sfmlAddress && sfmlAddress->isV4();
}


////////////////////////////////////////////////////////////
bool sfIpAddress_isV6(sfIpAddress address)
{
    const auto sfmlAddress = convertIpAddress(address);
    return sfmlAddress && sfmlAddress->isV6();
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_getLocalAddress()
{
    return convertIpAddress(sf::IpAddress::getLocalAddress());
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_getLocalAddressOfType(sfIpAddressType type)
{
    return convertIpAddress(sf::IpAddress::getLocalAddress(static_cast<sf::IpAddress::Type>(type)));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_getPublicAddress(sfTime timeout)
{
    return convertIpAddress(sf::IpAddress::getPublicAddress(sf::microseconds(timeout.microseconds)));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_getPublicAddressOfType(sfTime timeout, const sfIpAddressType* type, bool secure)
{
    return convertIpAddress(
        sf::IpAddress::getPublicAddress(sf::microseconds(timeout.microseconds), convertIpAddressType(type), secure));
}
