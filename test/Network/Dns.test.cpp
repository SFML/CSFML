#include <CSFML/Network/Dns.h>
#include <CSFML/System/Alloc.h>

#include <catch2/catch_test_macros.hpp>

#include <cstring>

TEST_CASE("[Network] sfDns")
{
    SECTION("sfDns_resolve")
    {
        size_t       count     = 0;
        sfIpAddress* addresses = sfDns_resolve("127.0.0.1", nullptr, 0, sfSeconds(1), &count);
        REQUIRE(addresses != nullptr);
        REQUIRE(count == 1);
        CHECK(std::strcmp(addresses[0].address, "127.0.0.1") == 0);
        sfFree(addresses);

        addresses = sfDns_resolve("::1", nullptr, 0, sfSeconds(1), &count);
        REQUIRE(addresses != nullptr);
        REQUIRE(count == 1);
        CHECK(std::strcmp(addresses[0].address, "::1") == 0);
        sfFree(addresses);
    }
}
