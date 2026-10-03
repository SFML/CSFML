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
#include <CSFML/Network/Dns.h>
#include <CSFML/Network/DnsStruct.hpp>

#include <SFML/Network/Dns.hpp>
#include <SFML/System/String.hpp>

#include <cassert>
#include <cstdlib>
#include <cstring>


namespace
{
////////////////////////////////////////////////////////////
[[nodiscard]] sf::String fromUtf8(const char* string)
{
    return sf::String::fromUtf8(string, string + std::strlen(string));
}


////////////////////////////////////////////////////////////
[[nodiscard]] std::string toUtf8(const sf::String& string)
{
    const auto utf8 = string.toUtf8();
    return {utf8.begin(), utf8.end()};
}


////////////////////////////////////////////////////////////
[[nodiscard]] std::vector<sf::IpAddress> convertServers(const sfIpAddress* servers, size_t serverCount)
{
    std::vector<sf::IpAddress> result;

    if (!servers)
        return result;

    result.reserve(serverCount);
    for (size_t i = 0; i < serverCount; ++i)
    {
        if (const auto address = convertIpAddress(servers[i]))
            result.push_back(*address);
    }

    return result;
}


////////////////////////////////////////////////////////////
[[nodiscard]] std::optional<sf::Time> convertTimeout(sfTime timeout)
{
    if (timeout.microseconds == 0)
        return std::nullopt;

    return sf::microseconds(timeout.microseconds);
}
} // namespace


////////////////////////////////////////////////////////////
sfIpAddress* sfDns_resolve(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout, size_t* count)
{
    assert(hostname);
    assert(count);

    *count = 0;

    const auto addresses = sf::Dns::resolve(fromUtf8(hostname), convertServers(servers, serverCount), convertTimeout(timeout));
    if (!addresses || addresses->empty())
        return nullptr;

    auto* result = static_cast<sfIpAddress*>(std::malloc(addresses->size() * sizeof(sfIpAddress)));
    if (!result)
        return nullptr;

    for (std::size_t i = 0; i < addresses->size(); ++i)
        result[i] = convertIpAddress((*addresses)[i]);

    *count = addresses->size();
    return result;
}


////////////////////////////////////////////////////////////
sfDnsNsRecords* sfDns_queryNs(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout)
{
    assert(hostname);

    auto* records = new sfDnsNsRecords;
    for (const auto& record :
         sf::Dns::queryNs(fromUtf8(hostname), convertServers(servers, serverCount), convertTimeout(timeout)))
        records->Records.push_back(toUtf8(record));

    return records;
}


////////////////////////////////////////////////////////////
sfDnsMxRecords* sfDns_queryMx(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout)
{
    assert(hostname);

    auto* records = new sfDnsMxRecords;
    for (const auto& record :
         sf::Dns::queryMx(fromUtf8(hostname), convertServers(servers, serverCount), convertTimeout(timeout)))
        records->Records.push_back({toUtf8(record.exchange), record.preference});

    return records;
}


////////////////////////////////////////////////////////////
sfDnsSrvRecords* sfDns_querySrv(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout)
{
    assert(hostname);

    auto* records = new sfDnsSrvRecords;
    for (const auto& record :
         sf::Dns::querySrv(fromUtf8(hostname), convertServers(servers, serverCount), convertTimeout(timeout)))
        records->Records.push_back({toUtf8(record.target), record.port, record.weight, record.priority});

    return records;
}


////////////////////////////////////////////////////////////
sfDnsTxtRecords* sfDns_queryTxt(const char* hostname, const sfIpAddress* servers, size_t serverCount, sfTime timeout)
{
    assert(hostname);

    auto* records = new sfDnsTxtRecords;
    for (const auto& record :
         sf::Dns::queryTxt(fromUtf8(hostname), convertServers(servers, serverCount), convertTimeout(timeout)))
    {
        auto& strings = records->Records.emplace_back();
        for (const auto& string : record)
            strings.push_back(toUtf8(string));
    }

    return records;
}


////////////////////////////////////////////////////////////
sfIpAddress sfDns_getPublicAddress(sfTime timeout, sfIpAddressType type)
{
    return convertIpAddress(sf::Dns::getPublicAddress(convertTimeout(timeout), static_cast<sf::IpAddress::Type>(type)));
}


////////////////////////////////////////////////////////////
void sfDnsNsRecords_destroy(const sfDnsNsRecords* records)
{
    delete records;
}


////////////////////////////////////////////////////////////
size_t sfDnsNsRecords_getCount(const sfDnsNsRecords* records)
{
    assert(records);
    return records->Records.size();
}


////////////////////////////////////////////////////////////
const char* sfDnsNsRecords_getRecord(const sfDnsNsRecords* records, size_t index)
{
    assert(records);
    assert(index < records->Records.size());
    return records->Records[index].c_str();
}


////////////////////////////////////////////////////////////
void sfDnsMxRecords_destroy(const sfDnsMxRecords* records)
{
    delete records;
}


////////////////////////////////////////////////////////////
size_t sfDnsMxRecords_getCount(const sfDnsMxRecords* records)
{
    assert(records);
    return records->Records.size();
}


////////////////////////////////////////////////////////////
sfDnsMxRecord sfDnsMxRecords_getRecord(const sfDnsMxRecords* records, size_t index)
{
    assert(records);
    assert(index < records->Records.size());

    const auto& record = records->Records[index];
    return {record.exchange.c_str(), record.preference};
}


////////////////////////////////////////////////////////////
void sfDnsSrvRecords_destroy(const sfDnsSrvRecords* records)
{
    delete records;
}


////////////////////////////////////////////////////////////
size_t sfDnsSrvRecords_getCount(const sfDnsSrvRecords* records)
{
    assert(records);
    return records->Records.size();
}


////////////////////////////////////////////////////////////
sfDnsSrvRecord sfDnsSrvRecords_getRecord(const sfDnsSrvRecords* records, size_t index)
{
    assert(records);
    assert(index < records->Records.size());

    const auto& record = records->Records[index];
    return {record.target.c_str(), record.port, record.weight, record.priority};
}


////////////////////////////////////////////////////////////
void sfDnsTxtRecords_destroy(const sfDnsTxtRecords* records)
{
    delete records;
}


////////////////////////////////////////////////////////////
size_t sfDnsTxtRecords_getCount(const sfDnsTxtRecords* records)
{
    assert(records);
    return records->Records.size();
}


////////////////////////////////////////////////////////////
size_t sfDnsTxtRecords_getStringCount(const sfDnsTxtRecords* records, size_t index)
{
    assert(records);
    assert(index < records->Records.size());
    return records->Records[index].size();
}


////////////////////////////////////////////////////////////
const char* sfDnsTxtRecords_getString(const sfDnsTxtRecords* records, size_t index, size_t stringIndex)
{
    assert(records);
    assert(index < records->Records.size());
    assert(stringIndex < records->Records[index].size());
    return records->Records[index][stringIndex].c_str();
}
