#include <CSFML/Graphics/Texture.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

TEST_CASE("[Graphics] sfTexture")
{
    SECTION("sfTexture_create")
    {
        const sfTexture* texture = sfTexture_create({100, 100});
        REQUIRE(texture);
        CHECK(sfTexture_getSize(texture).x == 100);
        CHECK(sfTexture_getSize(texture).y == 100);
        CHECK(!sfTexture_isSmooth(texture));
        CHECK(!sfTexture_isSrgb(texture));
        CHECK(!sfTexture_isRepeated(texture));
        CHECK(sfTexture_getNativeHandle(texture) != 0);
        sfTexture_destroy(texture);
    }

    SECTION("sfTexture_createSrgb")
    {
        const sfTexture* texture = sfTexture_createSrgb({100, 100});
        REQUIRE(texture);
        CHECK(sfTexture_getSize(texture).x == 100);
        CHECK(sfTexture_getSize(texture).y == 100);
        CHECK(!sfTexture_isSmooth(texture));
        CHECK(sfTexture_isSrgb(texture));
        CHECK(!sfTexture_isRepeated(texture));
        CHECK(sfTexture_getNativeHandle(texture) != 0);
        sfTexture_destroy(texture);
    }

    SECTION("sfTexture_createFromFile")
    {
        const char* fileExtension = GENERATE("bmp", "gif", "jpg", "png", "psd");
        const auto  filename      = std::string("Graphics/sfml-logo-big.") + fileExtension;
        INFO("Filename: " << filename);
        const sfTexture* texture = sfTexture_createFromFile(filename.c_str(), nullptr);
        REQUIRE(texture);
        CHECK(sfTexture_getSize(texture).x > 0);
        CHECK(sfTexture_getSize(texture).y > 0);
        CHECK(!sfTexture_isSmooth(texture));
        CHECK(!sfTexture_isSrgb(texture));
        CHECK(!sfTexture_isRepeated(texture));
        CHECK(sfTexture_getNativeHandle(texture) != 0);
        sfTexture_destroy(texture);
    }

    SECTION("sfTexture_createSrgbFromFile")
    {
        const char* fileExtension = GENERATE("bmp", "gif", "jpg", "png", "psd");
        const auto  filename      = std::string("Graphics/sfml-logo-big.") + fileExtension;
        INFO("Filename: " << filename);
        const sfTexture* texture = sfTexture_createSrgbFromFile(filename.c_str(), nullptr);
        REQUIRE(texture);
        CHECK(sfTexture_getSize(texture).x > 0);
        CHECK(sfTexture_getSize(texture).y > 0);
        CHECK(!sfTexture_isSmooth(texture));
        CHECK(sfTexture_isSrgb(texture));
        CHECK(!sfTexture_isRepeated(texture));
        CHECK(sfTexture_getNativeHandle(texture) != 0);
        sfTexture_destroy(texture);
    }
}
