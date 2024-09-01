#include <CSFML/System/Sleep.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[System] sfSleep")
{
    const auto startTime = std::chrono::steady_clock::now();
    sfSleep(sfMilliseconds(10));
    const auto elapsed = std::chrono::steady_clock::now() - startTime;
    CHECK(elapsed >= std::chrono::milliseconds(10));
}
