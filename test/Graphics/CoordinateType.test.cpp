#include <CSFML/Graphics/CoordinateType.h>

#include <SFML/Graphics/CoordinateType.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfCoordinateType")
{
    STATIC_CHECK(sfCoordinateTypeNormalized == static_cast<int>(sf::CoordinateType::Normalized));
    STATIC_CHECK(sfCoordinateTypePixels == static_cast<int>(sf::CoordinateType::Pixels));
}
