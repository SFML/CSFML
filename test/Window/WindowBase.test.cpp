#include <CSFML/Window/WindowBase.h>

#include <SFML/Window/WindowBase.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Window] sfWindowBase")
{
    SECTION("sfWindowStyle")
    {
        STATIC_CHECK(sfNone == static_cast<int>(sf::Style::None));
        STATIC_CHECK(sfTitlebar == static_cast<int>(sf::Style::Titlebar));
        STATIC_CHECK(sfResize == static_cast<int>(sf::Style::Resize));
        STATIC_CHECK(sfClose == static_cast<int>(sf::Style::Close));
        STATIC_CHECK(sfDefaultStyle == static_cast<int>(sf::Style::Default));
    }

    SECTION("sfWindowState")
    {
        STATIC_CHECK(sfWindowed == static_cast<int>(sf::State::Windowed));
        STATIC_CHECK(sfFullscreen == static_cast<int>(sf::State::Fullscreen));
    }
}
