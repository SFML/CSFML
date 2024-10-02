#include <CSFML/Window/Mouse.h>

#include <SFML/Window/Mouse.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Window] sfMouse")
{
    SECTION("sfMouseButton")
    {
        STATIC_CHECK(sfMouseLeft == static_cast<int>(sf::Mouse::Button::Left));
        STATIC_CHECK(sfMouseRight == static_cast<int>(sf::Mouse::Button::Right));
        STATIC_CHECK(sfMouseMiddle == static_cast<int>(sf::Mouse::Button::Middle));
        STATIC_CHECK(sfMouseButtonExtra1 == static_cast<int>(sf::Mouse::Button::Extra1));
        STATIC_CHECK(sfMouseButtonExtra2 == static_cast<int>(sf::Mouse::Button::Extra2));
        STATIC_CHECK(sfMouseButtonCount == sf::Mouse::ButtonCount);
    }

    SECTION("sfMouseWheel")
    {
        STATIC_CHECK(sfMouseHorizontalWheel == static_cast<int>(sf::Mouse::Wheel::Horizontal));
        STATIC_CHECK(sfMouseVerticalWheel == static_cast<int>(sf::Mouse::Wheel::Vertical));
    }
}
