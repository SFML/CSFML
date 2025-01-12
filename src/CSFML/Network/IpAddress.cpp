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
#include <CSFML/Network/IpAddress.h>

#include <SFML/Network/IpAddress.hpp>

#include <cstring>


namespace
{
// Helper function for converting a SFML address to a CSFML one
[[nodiscard]] sfIpAddress fromSFMLAddress(std::optional<sf::IpAddress> address)
{
    if (!address)
        return sfIpAddress_None;

    sfIpAddress result{};
    std::strncpy(result.address, address->toString().c_str(), 15);
    return result;
}
} // namespace


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_None = {{0}};


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_Any = sfIpAddress_fromBytes(0, 0, 0, 0);


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_LocalHost = sfIpAddress_fromBytes(127, 0, 0, 1);


////////////////////////////////////////////////////////////
const sfIpAddress sfIpAddress_Broadcast = sfIpAddress_fromBytes(255, 255, 255, 255);


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromString(const char* address)
{
    assert(address);
    return fromSFMLAddress(sf::IpAddress::resolve(address));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromBytes(uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3)
{
    return fromSFMLAddress(sf::IpAddress(byte0, byte1, byte2, byte3));
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_fromInteger(uint32_t address)
{
    return fromSFMLAddress(sf::IpAddress(address));
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
    const auto sfmlAddress = sf::IpAddress::resolve(address.address);
    return sfmlAddress ? sfmlAddress->toInteger() : 0;
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_getLocalAddress()
{
    return fromSFMLAddress(sf::IpAddress::getLocalAddress());
}


////////////////////////////////////////////////////////////
sfIpAddress sfIpAddress_getPublicAddress(sfTime timeout)
{
    return fromSFMLAddress(sf::IpAddress::getPublicAddress(sf::microseconds(timeout.microseconds)));
}
