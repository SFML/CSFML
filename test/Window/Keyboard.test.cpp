#include <CSFML/Window/Keyboard.h>

#include <SFML/Window/Keyboard.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Window] sfKeyboard")
{
    SECTION("sfKeyCode")
    {
        STATIC_CHECK(sfKeyUnknown == static_cast<int>(sf::Keyboard::Key::Unknown));
        STATIC_CHECK(sfKeyA == static_cast<int>(sf::Keyboard::Key::A));
        STATIC_CHECK(sfKeyB == static_cast<int>(sf::Keyboard::Key::B));
        STATIC_CHECK(sfKeyC == static_cast<int>(sf::Keyboard::Key::C));
        STATIC_CHECK(sfKeyD == static_cast<int>(sf::Keyboard::Key::D));
        STATIC_CHECK(sfKeyPause == static_cast<int>(sf::Keyboard::Key::Pause));
        CHECK(sfKeyCount == sf::Keyboard::KeyCount);
    }

    SECTION("sfScancode")
    {
        STATIC_CHECK(sfScanUnknown == static_cast<int>(sf::Keyboard::Scan::Unknown));
        STATIC_CHECK(sfScanA == static_cast<int>(sf::Keyboard::Scan::A));
        STATIC_CHECK(sfScanB == static_cast<int>(sf::Keyboard::Scan::B));
        STATIC_CHECK(sfScanC == static_cast<int>(sf::Keyboard::Scan::C));
        STATIC_CHECK(sfScanD == static_cast<int>(sf::Keyboard::Scan::D));
        CHECK(sfScancodeCount == sf::Keyboard::ScancodeCount);
    }
}
