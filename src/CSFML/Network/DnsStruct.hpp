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
#include <cstdint>
#include <string>
#include <vector>


////////////////////////////////////////////////////////////
// Internal structure of sfDnsNsRecords
////////////////////////////////////////////////////////////
struct sfDnsNsRecords
{
    std::vector<std::string> Records;
};


////////////////////////////////////////////////////////////
// Internal structure of sfDnsMxRecords
////////////////////////////////////////////////////////////
struct sfDnsMxRecords
{
    struct Record
    {
        std::string   exchange;
        std::uint16_t preference{};
    };

    std::vector<Record> Records;
};


////////////////////////////////////////////////////////////
// Internal structure of sfDnsSrvRecords
////////////////////////////////////////////////////////////
struct sfDnsSrvRecords
{
    struct Record
    {
        std::string   target;
        std::uint16_t port{};
        std::uint16_t weight{};
        std::uint16_t priority{};
    };

    std::vector<Record> Records;
};


////////////////////////////////////////////////////////////
// Internal structure of sfDnsTxtRecords
////////////////////////////////////////////////////////////
struct sfDnsTxtRecords
{
    std::vector<std::vector<std::string>> Records;
};
