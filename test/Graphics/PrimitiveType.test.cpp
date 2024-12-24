#include <CSFML/Graphics/PrimitiveType.h>

#include <SFML/Graphics/PrimitiveType.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Graphics] sfPrimitiveType")
{
    STATIC_CHECK(sfPoints == static_cast<int>(sf::PrimitiveType::Points));
    STATIC_CHECK(sfLines == static_cast<int>(sf::PrimitiveType::Lines));
    STATIC_CHECK(sfLineStrip == static_cast<int>(sf::PrimitiveType::LineStrip));
    STATIC_CHECK(sfTriangles == static_cast<int>(sf::PrimitiveType::Triangles));
    STATIC_CHECK(sfTriangleStrip == static_cast<int>(sf::PrimitiveType::TriangleStrip));
    STATIC_CHECK(sfTriangleFan == static_cast<int>(sf::PrimitiveType::TriangleFan));
}
