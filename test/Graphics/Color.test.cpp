#include <CSFML/Graphics/Color.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfColor")
{
    SECTION("Construction")
    {
        constexpr sfColor color{};
        STATIC_CHECK(color.r == 0);
        STATIC_CHECK(color.g == 0);
        STATIC_CHECK(color.b == 0);
        STATIC_CHECK(color.a == 0);
    }

    SECTION("Constants")
    {
        SECTION("sfBlack")
        {
            CHECK(sfBlack.r == 0);
            CHECK(sfBlack.g == 0);
            CHECK(sfBlack.b == 0);
            CHECK(sfBlack.a == 255);
        }

        SECTION("sfWhite")
        {
            CHECK(sfWhite.r == 255);
            CHECK(sfWhite.g == 255);
            CHECK(sfWhite.b == 255);
            CHECK(sfWhite.a == 255);
        }

        SECTION("sfRed")
        {
            CHECK(sfRed.r == 255);
            CHECK(sfRed.g == 0);
            CHECK(sfRed.b == 0);
            CHECK(sfRed.a == 255);
        }

        SECTION("sfGreen")
        {
            CHECK(sfGreen.r == 0);
            CHECK(sfGreen.g == 255);
            CHECK(sfGreen.b == 0);
            CHECK(sfGreen.a == 255);
        }

        SECTION("sfBlue")
        {
            CHECK(sfBlue.r == 0);
            CHECK(sfBlue.g == 0);
            CHECK(sfBlue.b == 255);
            CHECK(sfBlue.a == 255);
        }

        SECTION("sfYellow")
        {
            CHECK(sfYellow.r == 255);
            CHECK(sfYellow.g == 255);
            CHECK(sfYellow.b == 0);
            CHECK(sfYellow.a == 255);
        }

        SECTION("sfMagenta")
        {
            CHECK(sfMagenta.r == 255);
            CHECK(sfMagenta.g == 0);
            CHECK(sfMagenta.b == 255);
            CHECK(sfMagenta.a == 255);
        }

        SECTION("sfCyan")
        {
            CHECK(sfCyan.r == 0);
            CHECK(sfCyan.g == 255);
            CHECK(sfCyan.b == 255);
            CHECK(sfCyan.a == 255);
        }

        SECTION("sfTransparent")
        {
            CHECK(sfTransparent.r == 0);
            CHECK(sfTransparent.g == 0);
            CHECK(sfTransparent.b == 0);
            CHECK(sfTransparent.a == 0);
        }
    }

    SECTION("sfColor_fromRGB")
    {
        const sfColor color = sfColor_fromRGB(1, 2, 3);
        CHECK(color.r == 1);
        CHECK(color.g == 2);
        CHECK(color.b == 3);
        CHECK(color.a == 255);
    }

    SECTION("sfColor_fromRGBA")
    {
        const sfColor color = sfColor_fromRGBA(4, 5, 6, 7);
        CHECK(color.r == 4);
        CHECK(color.g == 5);
        CHECK(color.b == 6);
        CHECK(color.a == 7);
    }

    SECTION("sfColor_fromInteger")
    {
        sfColor color = sfColor_fromInteger(0);
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_fromInteger(1'000);
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 3);
        CHECK(color.a == 232);

        color = sfColor_fromInteger(1'000'000);
        CHECK(color.r == 0);
        CHECK(color.g == 15);
        CHECK(color.b == 66);
        CHECK(color.a == 64);

        color = sfColor_fromInteger(1'000'000'000);
        CHECK(color.r == 59);
        CHECK(color.g == 154);
        CHECK(color.b == 202);
        CHECK(color.a == 0);

        color = sfColor_fromInteger(std::numeric_limits<std::uint32_t>::max());
        CHECK(color.r == 255);
        CHECK(color.g == 255);
        CHECK(color.b == 255);
        CHECK(color.a == 255);
    }

    SECTION("sfColor_toInteger")
    {
        CHECK(sfColor_toInteger(sfBlack) == 255);
        CHECK(sfColor_toInteger(sfWhite) == 4'294'967'295);
        CHECK(sfColor_toInteger(sfRed) == 4'278'190'335);
        CHECK(sfColor_toInteger(sfGreen) == 16'711'935);
        CHECK(sfColor_toInteger(sfBlue) == 65'535);
        CHECK(sfColor_toInteger(sfYellow) == 4'294'902'015);
        CHECK(sfColor_toInteger(sfMagenta) == 4'278'255'615);
        CHECK(sfColor_toInteger(sfYellow) == 4'294'902'015);
        CHECK(sfColor_toInteger(sfTransparent) == 0);
    }

    SECTION("sfColor_add")
    {
        sfColor color = sfColor_add({}, {});
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_add({1, 2, 3, 4}, {5, 6, 7, 8});
        CHECK(color.r == 6);
        CHECK(color.g == 8);
        CHECK(color.b == 10);
        CHECK(color.a == 12);

        color = sfColor_add({10, 20, 30, 40}, {200, 210, 220, 230});
        CHECK(color.r == 210);
        CHECK(color.g == 230);
        CHECK(color.b == 250);
        CHECK(color.a == 255);

        color = sfColor_add({255, 255, 255, 255}, {255, 255, 255, 25});
        CHECK(color.r == 255);
        CHECK(color.g == 255);
        CHECK(color.b == 255);
        CHECK(color.a == 255);
    }

    SECTION("sfColor_subtract")
    {
        sfColor color = sfColor_subtract({}, {});
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_subtract({}, {10, 20, 30, 40});
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_subtract({100, 90, 80, 70}, {30, 40, 50, 60});
        CHECK(color.r == 70);
        CHECK(color.g == 50);
        CHECK(color.b == 30);
        CHECK(color.a == 10);
    }

    SECTION("sfColor_modulate")
    {
        sfColor color = sfColor_modulate({}, {});
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_modulate({}, {1, 2, 3, 4});
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_modulate({5, 6, 7, 8}, {1, 2, 3, 4});
        CHECK(color.r == 0);
        CHECK(color.g == 0);
        CHECK(color.b == 0);
        CHECK(color.a == 0);

        color = sfColor_modulate({128, 196, 216, 255}, {0, 128, 255, 128});
        CHECK(color.r == 0);
        CHECK(color.g == 98);
        CHECK(color.b == 216);
        CHECK(color.a == 128);
    }
}
