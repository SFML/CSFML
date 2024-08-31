#include <CSFML/Window/VideoMode.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Window] sfVideoMode")
{
    SECTION("Construction")
    {
        const sfVideoMode videoMode{};
        CHECK(videoMode.size.x == 0);
        CHECK(videoMode.size.y == 0);
        CHECK(videoMode.bitsPerPixel == 0);
    }

    SECTION("sfVideoMode_getDesktopMode()")
    {
        const sfVideoMode videoMode = sfVideoMode_getDesktopMode();
        CHECK(videoMode.size.x != 0);
        CHECK(videoMode.size.y != 0);
        CHECK(videoMode.bitsPerPixel != 0);
    }

    SECTION("sfVideoMode_getFullscreenModes()")
    {
        std::size_t        count      = 0;
        const sfVideoMode* videoModes = sfVideoMode_getFullscreenModes(&count);
        REQUIRE(count > 0);
        const sfVideoMode& videoMode = videoModes[0];
        CHECK(videoMode.size.x != 0);
        CHECK(videoMode.size.y != 0);
        CHECK(videoMode.bitsPerPixel != 0);
    }

    SECTION("sfVideoMode_isValid")
    {
        CHECK(!sfVideoMode_isValid({}));
    }
}
