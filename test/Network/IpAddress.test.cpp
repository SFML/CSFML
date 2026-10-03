#include <CSFML/Network/IpAddress.h>

#include <SFML/Network/IpAddress.hpp>

#include <catch2/catch_test_macros.hpp>

#include <cstring>

TEST_CASE("[Network] sfIpAddress")
{
    SECTION("Constants")
    {
        CHECK(sfIpAddress_toInteger(sfIpAddress_None) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_Any) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_LocalHost) == 0x7F000001);
        CHECK(sfIpAddress_toInteger(sfIpAddress_Broadcast) == 0xFFFFFFFF);

        CHECK(std::strcmp(sfIpAddress_None.address, "") == 0);
        CHECK(std::strcmp(sfIpAddress_Any.address, "0.0.0.0") == 0);
        CHECK(std::strcmp(sfIpAddress_LocalHost.address, "127.0.0.1") == 0);
        CHECK(std::strcmp(sfIpAddress_Broadcast.address, "255.255.255.255") == 0);

        CHECK(std::strcmp(sfIpAddress_AnyV4.address, "0.0.0.0") == 0);
        CHECK(std::strcmp(sfIpAddress_LocalHostV4.address, "127.0.0.1") == 0);
        CHECK(std::strcmp(sfIpAddress_BroadcastV4.address, "255.255.255.255") == 0);
        CHECK(std::strcmp(sfIpAddress_AnyV6.address, "::") == 0);
        CHECK(std::strcmp(sfIpAddress_LocalHostV6.address, "::1") == 0);
    }

    SECTION("sfIpAddressType")
    {
        STATIC_CHECK(sfIpAddressV4 == static_cast<int>(sf::IpAddress::Type::IpV4));
        STATIC_CHECK(sfIpAddressV6 == static_cast<int>(sf::IpAddress::Type::IpV6));
    }

    SECTION("sfIpAddress_fromString")
    {
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromString("")) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromString("256.256.256.256")) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromString("localhost")) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromString("192.168.0.1")) == 0xC0A80001);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromString("8.8.8.8")) == 0x08080808);
        CHECK(std::strcmp(sfIpAddress_fromString("2606:4700:4700::1111").address, "2606:4700:4700::1111") == 0);
        CHECK(std::strcmp(sfIpAddress_fromString("ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff").address,
                          "ffff:ffff:ffff:ffff:ffff:ffff:ffff:ffff") == 0);
    }

    SECTION("sfIpAddress_resolve")
    {
        CHECK(sfIpAddress_toInteger(sfIpAddress_resolve("")) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_resolve("localhost")) == 0x7F000001);
        CHECK(sfIpAddress_toInteger(sfIpAddress_resolve("192.168.0.1")) == 0xC0A80001);
    }

    SECTION("Type")
    {
        CHECK(sfIpAddress_isV4(sfIpAddress_LocalHostV4));
        CHECK(!sfIpAddress_isV6(sfIpAddress_LocalHostV4));
        CHECK(sfIpAddress_getType(sfIpAddress_LocalHostV4) == sfIpAddressV4);
        CHECK(!sfIpAddress_isV4(sfIpAddress_LocalHostV6));
        CHECK(sfIpAddress_isV6(sfIpAddress_LocalHostV6));
        CHECK(sfIpAddress_getType(sfIpAddress_LocalHostV6) == sfIpAddressV6);
        CHECK(!sfIpAddress_isV4(sfIpAddress_None));
        CHECK(!sfIpAddress_isV6(sfIpAddress_None));
    }

    SECTION("sfIpAddress_fromV6Bytes")
    {
        const uint8_t     bytes[16] = {0x26, 0x06, 0x47, 0x00, 0x47, 0x00, 0, 0, 0, 0, 0, 0, 0, 0, 0x11, 0x11};
        const sfIpAddress address   = sfIpAddress_fromV6Bytes(bytes);
        CHECK(std::strcmp(address.address, "2606:4700:4700::1111") == 0);
        CHECK(sfIpAddress_toInteger(address) == 0);

        uint8_t result[16] = {};
        CHECK(sfIpAddress_toV6Bytes(address, result));
        CHECK(std::memcmp(bytes, result, sizeof(bytes)) == 0);
        CHECK(!sfIpAddress_toV6Bytes(sfIpAddress_LocalHostV4, result));
    }

    SECTION("sfIpAddress_fromBytes")
    {
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromBytes(0, 0, 0, 0)) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromBytes(192, 168, 0, 1)) == 0xC0A80001);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromBytes(8, 8, 8, 8)) == 0x08080808);
    }

    SECTION("sfIpAddress_fromInteger")
    {
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromInteger(0)) == 0);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromInteger(0xC0A80001)) == 0xC0A80001);
        CHECK(sfIpAddress_toInteger(sfIpAddress_fromInteger(0x08080808)) == 0x08080808);
    }
}
