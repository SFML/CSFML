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
        STATIC_CHECK(sfKeyCount == sf::Keyboard::KeyCount);
    }

    SECTION("sfScancode")
    {
        STATIC_CHECK(sfScanUnknown == static_cast<int>(sf::Keyboard::Scan::Unknown));
        STATIC_CHECK(sfScanA == static_cast<int>(sf::Keyboard::Scan::A));
        STATIC_CHECK(sfScanB == static_cast<int>(sf::Keyboard::Scan::B));
        STATIC_CHECK(sfScanC == static_cast<int>(sf::Keyboard::Scan::C));
        STATIC_CHECK(sfScanD == static_cast<int>(sf::Keyboard::Scan::D));
        STATIC_CHECK(sfScancodeCount == sf::Keyboard::ScancodeCount);
    }

    SECTION("sfKeyboard_isKeyPressed")
    {
        CHECK(!sfKeyboard_isKeyPressed(sfKeyW));
        CHECK(!sfKeyboard_isKeyPressed(sfKeyA));
        CHECK(!sfKeyboard_isKeyPressed(sfKeyS));
        CHECK(!sfKeyboard_isKeyPressed(sfKeyD));
    }

    SECTION("sfKeyboard_isScancodePressed")
    {
        CHECK(!sfKeyboard_isScancodePressed(sfScanW));
        CHECK(!sfKeyboard_isScancodePressed(sfScanA));
        CHECK(!sfKeyboard_isScancodePressed(sfScanS));
        CHECK(!sfKeyboard_isScancodePressed(sfScanD));
    }

    SECTION("sfKeyboard_localize")
    {
        CHECK(sfKeyboard_localize(sfScanSpace) == sfKeySpace);
    }

    SECTION("sfKeyboard_delocalize")
    {
        CHECK(sfKeyboard_delocalize(sfKeySpace) == sfScanSpace);
    }

    SECTION("sfKeyboard_getDescription")
    {
        using namespace std::string_literals;
        CHECK(sfKeyboard_getDescription(sfScanF1) == "F1"s);
        CHECK(sfKeyboard_getDescription(sfScanF2) == "F2"s);
        CHECK(sfKeyboard_getDescription(sfScanF3) == "F3"s);
        CHECK(sfKeyboard_getDescription(sfScanF4) == "F4"s);
        CHECK(sfKeyboard_getDescription(sfScanF5) == "F5"s);
        CHECK(sfKeyboard_getDescription(sfScanF6) == "F6"s);
        CHECK(sfKeyboard_getDescription(sfScanF7) == "F7"s);
        CHECK(sfKeyboard_getDescription(sfScanF8) == "F8"s);
        CHECK(sfKeyboard_getDescription(sfScanF9) == "F9"s);
        CHECK(sfKeyboard_getDescription(sfScanF10) == "F10"s);
        CHECK(sfKeyboard_getDescription(sfScanF11) == "F11"s);
        CHECK(sfKeyboard_getDescription(sfScanF12) == "F12"s);
    }
}
