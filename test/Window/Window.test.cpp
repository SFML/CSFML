#include <CSFML/Window/Window.h>

#include <SFML/Window/Window.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Window] sfWindow")
{
    SECTION("sfContextAttribute")
    {
        STATIC_CHECK(sfContextDefault == static_cast<int>(sf::ContextSettings::Attribute::Default));
        STATIC_CHECK(sfContextCore == static_cast<int>(sf::ContextSettings::Attribute::Core));
        STATIC_CHECK(sfContextDebug == static_cast<int>(sf::ContextSettings::Attribute::Debug));
    }
}
