#include <CSFML/System/Version.h>

#include <catch2/catch_test_macros.hpp>

#include <string>

TEST_CASE("[System] sfGetVersion")
{
    const sfVersion version = sfGetVersion();
    CHECK(version.major == 3);
    CHECK(version.minor >= 1);
    CHECK(version.patch >= 0);
    REQUIRE(version.string != nullptr);
    CHECK(std::string(version.string).rfind(std::to_string(version.major) + "." + std::to_string(version.minor), 0) == 0);
}
