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
#include <CSFML/Network/IpAddress.h>

#include <SFML/Network/IpAddress.hpp>

#include <cstring>
#include <optional>


////////////////////////////////////////////////////////////
// Convert sf::IpAddress to sfIpAddress
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfIpAddress convertIpAddress(const sf::IpAddress& address)
{
    sfIpAddress result{};
    std::strncpy(result.address, address.toString().c_str(), sizeof(result.address) - 1);
    return result;
}


////////////////////////////////////////////////////////////
// Convert std::optional<sf::IpAddress> to sfIpAddress
////////////////////////////////////////////////////////////
[[nodiscard]] inline sfIpAddress convertIpAddress(const std::optional<sf::IpAddress>& address)
{
    return address ? convertIpAddress(*address) : sfIpAddress_None;
}


////////////////////////////////////////////////////////////
// Convert sfIpAddress to std::optional<sf::IpAddress>
////////////////////////////////////////////////////////////
[[nodiscard]] inline std::optional<sf::IpAddress> convertIpAddress(const sfIpAddress& address)
{
    return sf::IpAddress::fromString(address.address);
}


////////////////////////////////////////////////////////////
// Convert an optional sfIpAddressType to std::optional<sf::IpAddress::Type>
////////////////////////////////////////////////////////////
[[nodiscard]] inline std::optional<sf::IpAddress::Type> convertIpAddressType(const sfIpAddressType* type)
{
    if (!type)
        return std::nullopt;

    return static_cast<sf::IpAddress::Type>(*type);
}
