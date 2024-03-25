#include <SFML/System/Vector2.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[System] sfVector2")
{
    SECTION("sfVector2i")
    {
        const sfVector2i vector{};
        CHECK(vector.x == 0);
        CHECK(vector.y == 0);
    }

    SECTION("sfVector2u")
    {
        const sfVector2u vector{};
        CHECK(vector.x == 0);
        CHECK(vector.y == 0);
    }

    SECTION("sfVector2f")
    {
        const sfVector2f vector{};
        CHECK(vector.x == 0);
        CHECK(vector.y == 0);
    }
}
