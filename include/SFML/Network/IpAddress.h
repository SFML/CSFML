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

#ifndef SFML_IPADDRESS_H
#define SFML_IPADDRESS_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>


////////////////////////////////////////////////////////////
/// \brief Encapsulate an IPv4 network address
///
////////////////////////////////////////////////////////////
typedef struct
{
    char Address[16];
} sfIpAddress;


////////////////////////////////////////////////////////////
/// \brief Create an address from a string
///
/// Here \a address can be either a decimal address
/// (ex: "192.168.1.56") or a network name (ex: "localhost").
///
/// \param address IP address or network name
///
/// \return Resulting address
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_FromString(const char* address);

////////////////////////////////////////////////////////////
/// \brief Create an address from 4 bytes
///
/// Calling sfIpAddress_FromBytes(a, b, c, d) is equivalent
/// to calling sfIpAddress_FromString("a.b.c.d"), but safer
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
CSFML_API sfIpAddress sfIpAddress_FromBytes(sfUint8 byte0, sfUint8 byte1, sfUint8 byte2, sfUint8 byte3);

////////////////////////////////////////////////////////////
/// \brief Construct an address from a 32-bits integer
///
/// This function uses the internal representation of
/// the address directly. It should be used for optimization
/// purposes, and only if you got that representation from
/// sfIpAddress_ToInteger.
///
/// \param address 4 bytes of the address packed into a 32-bits integer
///
/// \return Resulting address
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_FromInteger(sfUint32 address);

////////////////////////////////////////////////////////////
/// \brief Get a string representation of an address
///
/// The returned string is the decimal representation of the
/// IP address (like "192.168.1.56"), even if it was constructed
/// from a host name.
///
/// \param address Address object
///
/// \return String representation of the address
///
////////////////////////////////////////////////////////////
CSFML_API void sfIpAddress_ToString(sfIpAddress address, char* string);

////////////////////////////////////////////////////////////
/// \brief Get an integer representation of the address
///
/// The returned number is the internal representation of the
/// address, and should be used for optimization purposes only
/// (like sending the address through a socket).
/// The integer produced by this function can then be converted
/// back to a sfIpAddress with sfIpAddress_FromInteger.
///
/// \param address Address object
///
/// \return 32-bits unsigned integer representation of the address
///
////////////////////////////////////////////////////////////
CSFML_API sfUint32 sfIpAddress_ToInteger(sfIpAddress address);

////////////////////////////////////////////////////////////
/// \brief Get the computer's local address
///
/// The local address is the address of the computer from the
/// LAN point of view, i.e. something like 192.168.1.56. It is
/// meaningful only for communications over the local network.
/// Unlike sfIpAddress_GetPublicAddress, this function is fast
/// and may be used safely anywhere.
///
/// \return Local IP address of the computer
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_GetLocalAddress(void);

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
/// \param timeout Maximum time to wait, in milliseconds
///
/// \return Public IP address of the computer
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_GetPublicAddress(sfUint32 timeout);

////////////////////////////////////////////////////////////
/// \brief Get the empty/invalid address
///
/// \return Empty object that represents invalid addresses
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_None(void);

////////////////////////////////////////////////////////////
/// \brief Get the computer's loopback address
///
/// \return Local host IP address (127.0.0.1, or "localhost")
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_LocalHost(void);

////////////////////////////////////////////////////////////
/// \brief Get the UDP broadcast address
///
/// \return Broadcast IP address (255.255.255.255)
///
////////////////////////////////////////////////////////////
CSFML_API sfIpAddress sfIpAddress_Broadcast(void);


#endif // SFML_IPADDRESS_H
