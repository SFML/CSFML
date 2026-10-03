#include <CSFML/Graphics/Font.h>

#include <catch2/catch_test_macros.hpp>

#include <string>

TEST_CASE("[Graphics] sfFont")
{
    SECTION("sfFont_createFromFile")
    {
        CHECK(sfFont_createFromFile("does/not/exist.ttf") == nullptr);

        sfFont* font = sfFont_createFromFile("Graphics/tuffy.ttf");
        REQUIRE(font != nullptr);

        const sfFontInfo info = sfFont_getInfo(font);
        CHECK(info.id != 0);
        CHECK(std::string(info.family) == "Tuffy");
        CHECK(!info.hasVerticalMetrics);

        CHECK(sfFont_getAscent(font, 10) > 0);
        CHECK(sfFont_getDescent(font, 10) < 0);
        CHECK(sfFont_getAscent(font, 20) > sfFont_getAscent(font, 10));

        sfFont_destroy(font);
    }
}
