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

#include <CSFML/Network/IpAddress.h>
#include <CSFML/Network/Types.h>
#include <CSFML/System/Time.h>

#include <stddef.h>
#include <stdint.h>


////////////////////////////////////////////////////////////
/// \brief A DNS MX record
///
////////////////////////////////////////////////////////////
typedef struct
{
    const char* exchange;   ///< Host willing to act as mail exchange
    uint16_t    preference; ///< Preference of this record among others, lower values are preferred
} sfDnsMxRecord;

////////////////////////////////////////////////////////////
/// \brief A DNS SRV record
///
////////////////////////////////////////////////////////////
typedef struct
{
    const char* target; ///< The domain name of the target host
    uint16_t    port;   ///< The port on the target host of the service
    uint16_t weight; ///< Server selection mechanism, larger weights should be given a proportionately higher probability of being selected
    uint16_t priority; ///< The priority of the target host, a client must attempt to contact the target host with the lowest-numbered priority it can reach
} sfDnsSrvRecord;


////////////////////////////////////////////////////////////
/// \brief Resolve a hostname into a list of IP addresses
///
/// The returned array must be freed with sfFree.
///
/// \param hostname    Hostname to resolve, encoded in UTF-8
/// \param servers     The list of servers to query, NULL to use the default servers
/// \param serverCount Number of servers in \a servers
/// \param timeout     Query timeout if using a provided list of servers, use 0 to wait forever
/// \param count       Pointer to a variable that will be filled with the number of addresses
///
/// \return Array of IP addresses the given hostname resolves to, NULL if name resolution fails or no address was found
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress* sfDns_resolve(
    const char*        hostname,
    const sfIpAddress* servers,
    size_t             serverCount,
    sfTime             timeout,
    size_t*            count);

////////////////////////////////////////////////////////////
/// \brief Query NS records for a hostname
///
/// \param hostname    Hostname to query NS records for, encoded in UTF-8
/// \param servers     The list of servers to query, NULL to use the default servers
/// \param serverCount Number of servers in \a servers
/// \param timeout     Query timeout if using a provided list of servers, use 0 to wait forever
///
/// \return New list of NS records, which can be empty
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfDnsNsRecords* sfDns_queryNs(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Query MX records for a hostname
///
/// \param hostname    Hostname to query MX records for, encoded in UTF-8
/// \param servers     The list of servers to query, NULL to use the default servers
/// \param serverCount Number of servers in \a servers
/// \param timeout     Query timeout if using a provided list of servers, use 0 to wait forever
///
/// \return New list of MX records, which can be empty
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfDnsMxRecords* sfDns_queryMx(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Query SRV records for a hostname
///
/// \param hostname    Hostname to query SRV records for, encoded in UTF-8
/// \param servers     The list of servers to query, NULL to use the default servers
/// \param serverCount Number of servers in \a servers
/// \param timeout     Query timeout if using a provided list of servers, use 0 to wait forever
///
/// \return New list of SRV records, which can be empty
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfDnsSrvRecords* sfDns_querySrv(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Query TXT records for a hostname
///
/// \param hostname    Hostname to query TXT records for, encoded in UTF-8
/// \param servers     The list of servers to query, NULL to use the default servers
/// \param serverCount Number of servers in \a servers
/// \param timeout     Query timeout if using a provided list of servers, use 0 to wait forever
///
/// \return New list of TXT records, which can be empty
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfDnsTxtRecords* sfDns_queryTxt(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Get the computer's public address via DNS
///
/// The public address is the address of the computer from the
/// point of view of the internet, i.e. something like 89.54.1.169
/// or 2600:1901:0:13e0::1 as opposed to a private or local address
/// like 192.168.1.56 or fe80::1234:5678:9abc.
///
/// This function depends on both your network connection and
/// the server, and may be very slow. You should try to use it
/// as little as possible.
///
/// \param timeout Maximum time to wait, use 0 to wait forever
/// \param type    The type of public address to get
///
/// \return Public IP address of the computer on success, sfIpAddress_None otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfIpAddress sfDns_getPublicAddress(sfTime timeout, sfIpAddressType type);

////////////////////////////////////////////////////////////
/// \brief Destroy a list of NS records
///
/// \param records List of NS records to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfDnsNsRecords_destroy(const sfDnsNsRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get the number of NS records in a list
///
/// \param records List of NS records
///
/// \return Number of NS records
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfDnsNsRecords_getCount(const sfDnsNsRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get a NS record of a list
///
/// \param records List of NS records
/// \param index   Index of the NS record to get
///
/// \return The NS record, encoded in UTF-8
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfDnsNsRecords_getRecord(const sfDnsNsRecords* records, size_t index);

////////////////////////////////////////////////////////////
/// \brief Destroy a list of MX records
///
/// \param records List of MX records to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfDnsMxRecords_destroy(const sfDnsMxRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get the number of MX records in a list
///
/// \param records List of MX records
///
/// \return Number of MX records
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfDnsMxRecords_getCount(const sfDnsMxRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get a MX record of a list
///
/// The strings of the record stay valid until the list
/// is destroyed.
///
/// \param records List of MX records
/// \param index   Index of the MX record to get
///
/// \return The MX record
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfDnsMxRecord sfDnsMxRecords_getRecord(const sfDnsMxRecords* records, size_t index);

////////////////////////////////////////////////////////////
/// \brief Destroy a list of SRV records
///
/// \param records List of SRV records to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfDnsSrvRecords_destroy(const sfDnsSrvRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get the number of SRV records in a list
///
/// \param records List of SRV records
///
/// \return Number of SRV records
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfDnsSrvRecords_getCount(const sfDnsSrvRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get a SRV record of a list
///
/// The strings of the record stay valid until the list
/// is destroyed.
///
/// \param records List of SRV records
/// \param index   Index of the SRV record to get
///
/// \return The SRV record
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfDnsSrvRecord sfDnsSrvRecords_getRecord(const sfDnsSrvRecords* records, size_t index);

////////////////////////////////////////////////////////////
/// \brief Destroy a list of TXT records
///
/// \param records List of TXT records to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfDnsTxtRecords_destroy(const sfDnsTxtRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get the number of TXT records in a list
///
/// \param records List of TXT records
///
/// \return Number of TXT records
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfDnsTxtRecords_getCount(const sfDnsTxtRecords* records);

////////////////////////////////////////////////////////////
/// \brief Get the number of strings in a TXT record
///
/// \param records List of TXT records
/// \param index   Index of the TXT record
///
/// \return Number of strings in the TXT record
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfDnsTxtRecords_getStringCount(const sfDnsTxtRecords* records, size_t index);

////////////////////////////////////////////////////////////
/// \brief Get a string of a TXT record
///
/// \param records     List of TXT records
/// \param index       Index of the TXT record
/// \param stringIndex Index of the string within the TXT record
///
/// \return The string, encoded in UTF-8
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfDnsTxtRecords_getString(const sfDnsTxtRecords* records, size_t index, size_t stringIndex);
