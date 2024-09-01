#include <CSFML/System/Clock.h>

#include <catch2/catch_test_macros.hpp>

#include <thread>

TEST_CASE("[System] sfClock")
{
    sfClock* clock = sfClock_create();

    CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= 1'000);

    sfClock_restart(clock);
    CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= 0);
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= 1'000);

    sfClock* anotherClock = sfClock_copy(clock);
    CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(anotherClock)) >= 1'000);

    sfClock_destroy(anotherClock);
    sfClock_destroy(clock);
}
