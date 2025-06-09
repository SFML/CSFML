#include <CSFML/Graphics/Image.h>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>

TEST_CASE("[Graphics] sfImage")
{
    SECTION("sfImage_create")
    {
        const sfImage* image = sfImage_create({100, 100});
        REQUIRE(image);
        const auto size = sfImage_getSize(image);
        CHECK(size.x == 100);
        CHECK(size.y == 100);
        const auto pixel = sfImage_getPixel(image, {50, 50});
        CHECK(pixel.r == sfBlack.r);
        CHECK(pixel.g == sfBlack.g);
        CHECK(pixel.b == sfBlack.b);
        CHECK(pixel.a == sfBlack.a);
        CHECK(sfImage_getPixelsPtr(image));
        sfImage_destroy(image);
    }

    SECTION("sfImage_createFromColor")
    {
        const sfImage* image = sfImage_createFromColor({100, 100}, sfMagenta);
        REQUIRE(image);
        const auto size = sfImage_getSize(image);
        CHECK(size.x == 100);
        CHECK(size.y == 100);
        const auto pixel = sfImage_getPixel(image, {50, 50});
        CHECK(pixel.r == sfMagenta.r);
        CHECK(pixel.g == sfMagenta.g);
        CHECK(pixel.b == sfMagenta.b);
        CHECK(pixel.a == sfMagenta.a);
        CHECK(sfImage_getPixelsPtr(image));
        sfImage_destroy(image);
    }

    SECTION("sfImage_createFromFile")
    {
        const auto filename = std::string("Graphics/sfml-logo-big.") + GENERATE("bmp", "gif", "jpg", "png", "psd");
        INFO("Filename: " << filename);
        const sfImage* image = sfImage_createFromFile(filename.c_str());
        REQUIRE(image);
        const auto size = sfImage_getSize(image);
        CHECK(size.x == 1001);
        CHECK(size.y == 304);
        const auto pixel = sfImage_getPixel(image, {0, 0});
        CHECK(pixel.r == sfWhite.r);
        CHECK(pixel.g == sfWhite.g);
        CHECK(pixel.b == sfWhite.b);
        CHECK(sfImage_getPixelsPtr(image));
        sfImage_destroy(image);
    }
}
