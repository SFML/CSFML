#include <SFML/System/Time.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[System] sfTime")
{
    CHECK(sfTime_Zero.microseconds == 0);

    sfTime time{};
    CHECK(time.microseconds == 0);
    CHECK(sfTime_asSeconds(time) == 0);
    CHECK(sfTime_asMilliseconds(time) == 0);
    CHECK(sfTime_asMicroseconds(time) == 0);

    time.microseconds = 1'234'567;
    CHECK(sfTime_asSeconds(time) == 1.234567f);
    CHECK(sfTime_asMilliseconds(time) == 1234);
    CHECK(sfTime_asMicroseconds(time) == 1'234'567);

    CHECK(sfSeconds(0).microseconds == 0);
    CHECK(sfMilliseconds(0).microseconds == 0);
    CHECK(sfMicroseconds(0).microseconds == 0);

    CHECK(sfSeconds(1).microseconds == 1'000'000);
    CHECK(sfMilliseconds(1).microseconds == 1'000);
    CHECK(sfMicroseconds(1).microseconds == 1);

    CHECK(sfSeconds(10).microseconds == 10'000'000);
    CHECK(sfMilliseconds(10).microseconds == 10'000);
    CHECK(sfMicroseconds(10).microseconds == 10);
}
