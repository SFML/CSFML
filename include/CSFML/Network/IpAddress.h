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
#include <CSFML/Network/Export.h>

#include <CSFML/System/Time.h>

#include <stdbool.h>
#include <stdint.h>


////////////////////////////////////////////////////////////
/// \brief Encapsulate an IPv4 or IPv6 network address
///
/// The address is stored as its string representation,
/// which is large enough to hold any IPv6 address.
///
////////////////////////////////////////////////////////////
typedef struct
{
    char address[46];
} sfIpAddress;


////////////////////////////////////////////////////////////
/// \brief Type of an IP address
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfIpAddressV4, ///< IPv4 address
    sfIpAddressV6  ///< IPv6 address
} sfIpAddressType;


////////////////////////////////////////////////////////////
/// \brief Empty object that represents invalid addresses
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_None;

////////////////////////////////////////////////////////////
/// \brief The same as sfIpAddress_AnyV4
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_Any;

////////////////////////////////////////////////////////////
/// \brief The same as sfIpAddress_LocalHostV4
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_LocalHost;

////////////////////////////////////////////////////////////
/// \brief The same as sfIpAddress_BroadcastV4
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_Broadcast;

////////////////////////////////////////////////////////////
/// \brief Value representing any IPv4 address (0.0.0.0)
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_AnyV4;

////////////////////////////////////////////////////////////
/// \brief Local host IPv4 address (127.0.0.1)
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_LocalHostV4;

////////////////////////////////////////////////////////////
/// \brief UDP broadcast IPv4 address (255.255.255.255)
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_BroadcastV4;

////////////////////////////////////////////////////////////
/// \brief Value representing any IPv6 address (::)
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_AnyV6;

////////////////////////////////////////////////////////////
/// \brief Local host IPv6 address (::1)
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const sfIpAddress sfIpAddress_LocalHostV6;

////////////////////////////////////////////////////////////
/// \brief Create an address from a string representation
///
/// Here \a address can be either an IPv4 address in
/// dotted-decimal notation (ex: "192.168.1.56") or an IPv6
/// address in standard notation (ex: "2606:4700:4700::1111").
/// Network names are not resolved, use sfDns_resolve or
/// sfIpAddress_resolve for that.
///
/// \param address IP address string
///
/// \return Resulting address or sfIpAddress_None if the string is not a valid address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_fromString(const char* address);

////////////////////////////////////////////////////////////
/// \brief Create an IPv4 address from a string or by resolving a network name
///
/// Here \a address can be either a decimal address
/// (ex: "192.168.1.56") or a network name (ex: "localhost").
/// Only IPv4 addresses are returned.
///
/// \param address IP address or network name
///
/// \return Resulting address or sfIpAddress_None if the address could not be resolved
///
/// \deprecated Use sfDns_resolve instead
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API CSFML_DEPRECATED sfIpAddress sfIpAddress_resolve(const char* address);

////////////////////////////////////////////////////////////
/// \brief Create an address from 4 bytes
///
/// Calling sfIpAddress_fromBytes(a, b, c, d) is equivalent
/// to calling sfIpAddress_fromString("a.b.c.d"), but safer
/// as it doesn't have to parse a string to get the address
/// components.
///
/// \param byte0 First byte of the address
/// \param byte1 Second byte of the address
/// \param byte2 Third byte of the address
/// \param byte3 Fourth byte of the address
///
/// \return Resulting address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_fromBytes(uint8_t byte0, uint8_t byte1, uint8_t byte2, uint8_t byte3);

////////////////////////////////////////////////////////////
/// \brief Construct an address from a 32-bits integer
///
/// This function uses the internal representation of
/// the address directly. It should be used for optimization
/// purposes, and only if you got that representation from
/// sfIpAddress_toInteger.
///
/// \param address 4 bytes of the address packed into a 32-bits integer
///
/// \return Resulting address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_fromInteger(uint32_t address);

////////////////////////////////////////////////////////////
/// \brief Create an IPv6 address from 16 bytes
///
/// \param bytes Array of 16 bytes containing the address
///
/// \return Resulting address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_fromV6Bytes(const uint8_t bytes[16]);

////////////////////////////////////////////////////////////
/// \brief Get a string representation of an address
///
/// The returned string is the decimal representation of the
/// IPv4 address (like "192.168.1.56") or the standard
/// representation of the IPv6 address (like "2606:4700:4700::1111"),
/// even if it was constructed from a host name.
/// The string must be able to hold at least 46 characters.
///
/// \param address Address object
/// \param string  String where the string representation will be stored
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfIpAddress_toString(sfIpAddress address, char* string);

////////////////////////////////////////////////////////////
/// \brief Get an integer representation of the address
///
/// The returned number is the internal representation of the
/// address, and should be used for optimization purposes only
/// (like sending the address through a socket).
/// The integer produced by this function can then be converted
/// back to a sfIpAddress with sfIpAddress_fromInteger.
///
/// Only IPv4 addresses can be converted to an integer, 0 is
/// returned for IPv6 addresses.
///
/// \param address Address object
///
/// \return 32-bits unsigned integer representation of the address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API uint32_t sfIpAddress_toInteger(sfIpAddress address);

////////////////////////////////////////////////////////////
/// \brief Get a 16-byte representation of an IPv6 address
///
/// The bytes produced by this function can then be converted
/// back to a sfIpAddress with sfIpAddress_fromV6Bytes.
///
/// \param address Address object
/// \param bytes   Array of 16 bytes that will be filled with the address
///
/// \return True if the address is a valid IPv6 address and the bytes have been written, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfIpAddress_toV6Bytes(sfIpAddress address, uint8_t bytes[16]);

////////////////////////////////////////////////////////////
/// \brief Get the type of an address
///
/// \param address Address object
///
/// \return The type of the address, sfIpAddressV4 is returned for invalid addresses
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddressType sfIpAddress_getType(sfIpAddress address);

////////////////////////////////////////////////////////////
/// \brief Check if an address is a valid IPv4 address
///
/// \param address Address object
///
/// \return True if the address is a valid IPv4 address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfIpAddress_isV4(sfIpAddress address);

////////////////////////////////////////////////////////////
/// \brief Check if an address is a valid IPv6 address
///
/// \param address Address object
///
/// \return True if the address is a valid IPv6 address
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfIpAddress_isV6(sfIpAddress address);

////////////////////////////////////////////////////////////
/// \brief Get the computer's local address
///
/// The local address is the address of the computer from the
/// LAN point of view, i.e. something like 192.168.1.56. It is
/// meaningful only for communications over the local network.
/// Unlike sfIpAddress_getPublicAddress, this function is fast
/// and may be used safely anywhere.
///
/// This returns the local IPv4 address.
///
/// \return Local IP address of the computer
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_getLocalAddress(void);

////////////////////////////////////////////////////////////
/// \brief Get the computer's local address of a given type
///
/// The local address is the address of the computer from the
/// LAN point of view, i.e. something like 192.168.1.56 or
/// fe80::1234:5678:9abc. It is meaningful only for
/// communications over the local network.
///
/// \param type The type of local address to get
///
/// \return Local IP address of the computer or sfIpAddress_None if there is none
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_getLocalAddressOfType(sfIpAddressType type);

////////////////////////////////////////////////////////////
/// \brief Get the computer's public address
///
/// The public address is the address of the computer from the
/// internet point of view, i.e. something like 89.54.1.169.
/// It is necessary for communications over the world wide web.
/// The only way to get a public address is to ask it to a
/// distant website; as a consequence, this function depends on
/// both your network connection and the server, and may be
/// very slow. You should use it as few as possible. Because
/// this function depends on the network connection and on a distant
/// server, you may use a time limit if you don't want your program
/// to be possibly stuck waiting in case there is a problem; use
/// 0 to deactivate this limit.
///
/// This returns the public IPv4 address.
///
/// \param timeout Maximum time to wait
///
/// \return Public IP address of the computer
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_getPublicAddress(sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Get the computer's public address of a given type
///
/// The public address is the address of the computer from the
/// internet point of view, i.e. something like 89.54.1.169 or
/// 2600:1901:0:13e0::1. See sfIpAddress_getPublicAddress for
/// details.
///
/// If tamper resistance is required, setting \a secure to true
/// will make use of verified HTTPS connections to get the address.
///
/// \param timeout Maximum time to wait, use 0 to deactivate the limit
/// \param type    The type of public address to get, NULL to specify no preference
/// \param secure  True to retrieve the public address via a secure HTTPS connection, false to retrieve via DNS or an insecure connection
///
/// \return Public IP address of the computer or sfIpAddress_None on failure
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfIpAddress_getPublicAddressOfType(sfTime timeout, const sfIpAddressType* type, bool secure);
