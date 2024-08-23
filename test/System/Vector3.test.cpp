#include <CSFML/System/Vector3.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[System] sfVector3")
{
    SECTION("sfVector3f")
    {
        const sfVector3f vector{};
        CHECK(vector.x == 0);
        CHECK(vector.y == 0);
    }
}
