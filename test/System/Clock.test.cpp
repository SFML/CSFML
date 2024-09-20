#include <CSFML/System/Clock.h>

#include <catch2/catch_test_macros.hpp>

#include <thread>

TEST_CASE("[System] sfClock")
{
    using namespace std::chrono_literals;

    SECTION("sfClock_create/sfClock_copy")
    {
        const sfClock* clock1 = sfClock_create();
        CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock1)) >= 0);
        CHECK(sfClock_isRunning(clock1));

        const auto     elapsed = sfClock_getElapsedTime(clock1);
        const sfClock* clock2  = sfClock_copy(clock1);
        CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock2)) >= sfTime_asMicroseconds(elapsed));
        CHECK(sfClock_isRunning(clock2));

        sfClock_destroy(clock2);
        sfClock_destroy(clock1);
    }

    SECTION("sfClock_getElapsedTime")
    {
        const sfClock* clock = sfClock_create();
        CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= 0);
        const auto elapsed = sfClock_getElapsedTime(clock);
        std::this_thread::sleep_for(1ms);
        CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= sfTime_asMicroseconds(elapsed));
        sfClock_destroy(clock);
    }

    SECTION("sfClock_start/sfClock_stop")
    {
        sfClock* clock = sfClock_create();
        sfClock_stop(clock);
        CHECK(!sfClock_isRunning(clock));
        const auto elapsed = sfClock_getElapsedTime(clock);
        std::this_thread::sleep_for(1ms);
        CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) == sfTime_asMicroseconds(elapsed));

        sfClock_start(clock);
        CHECK(sfTime_asMicroseconds(sfClock_getElapsedTime(clock)) >= sfTime_asMicroseconds(elapsed));
        CHECK(sfClock_isRunning(clock));
        sfClock_destroy(clock);
    }

    SECTION("sfClock_restart")
    {
        sfClock* clock = sfClock_create();
        CHECK(sfTime_asMicroseconds(sfClock_restart(clock)) >= 0);
        CHECK(sfClock_isRunning(clock));
        std::this_thread::sleep_for(1ms);
        const auto elapsed = sfClock_restart(clock);
        CHECK(sfTime_asMicroseconds(sfClock_restart(clock)) < sfTime_asMicroseconds(elapsed));
        sfClock_destroy(clock);
    }

    SECTION("sfClock_reset")
    {
        sfClock* clock = sfClock_create();
        CHECK(sfTime_asMicroseconds(sfClock_reset(clock)) >= 0);
        CHECK(!sfClock_isRunning(clock));
        sfClock_destroy(clock);
    }
}
