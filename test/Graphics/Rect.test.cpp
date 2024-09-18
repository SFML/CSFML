#include <CSFML/Graphics/Rect.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfRect")
{
    SECTION("Construction")
    {
        SECTION("float")
        {
            const sfFloatRect rect{};
            CHECK(rect.position.x == 0.f);
            CHECK(rect.position.y == 0.f);
            CHECK(rect.size.x == 0.f);
            CHECK(rect.size.y == 0.f);
        }

        SECTION("int")
        {
            const sfFloatRect rect{};
            CHECK(rect.position.x == 0);
            CHECK(rect.position.y == 0);
            CHECK(rect.size.x == 0);
            CHECK(rect.size.y == 0);
        }
    }

    SECTION("contains(Vector2)")
    {
        SECTION("float")
        {
            const sfFloatRect rect{{0, 0}, {10, 10}};
            CHECK(sfFloatRect_contains(&rect, {0, 0}));
            CHECK(sfFloatRect_contains(&rect, {9, 0}));
            CHECK(sfFloatRect_contains(&rect, {0, 9}));
            CHECK(sfFloatRect_contains(&rect, {9, 9}));
            CHECK(!sfFloatRect_contains(&rect, {9, 10}));
            CHECK(!sfFloatRect_contains(&rect, {10, 9}));
            CHECK(!sfFloatRect_contains(&rect, {10, 10}));
            CHECK(!sfFloatRect_contains(&rect, {15, 15}));
        }

        SECTION("int")
        {
            const sfIntRect rect{{0, 0}, {10, 10}};
            CHECK(sfIntRect_contains(&rect, {0, 0}));
            CHECK(sfIntRect_contains(&rect, {9, 0}));
            CHECK(sfIntRect_contains(&rect, {0, 9}));
            CHECK(sfIntRect_contains(&rect, {9, 9}));
            CHECK(!sfIntRect_contains(&rect, {9, 10}));
            CHECK(!sfIntRect_contains(&rect, {10, 9}));
            CHECK(!sfIntRect_contains(&rect, {10, 10}));
            CHECK(!sfIntRect_contains(&rect, {15, 15}));
        }
    }
}
