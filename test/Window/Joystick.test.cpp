#include <CSFML/Window/Joystick.h>

#include <SFML/Window/Joystick.hpp>

#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators_range.hpp>

TEST_CASE("[Window] sfJoystick")
{
    SECTION("Constants")
    {
        STATIC_CHECK(sfJoystickCount == 8);
        STATIC_CHECK(sfJoystickButtonCount == 32);
        STATIC_CHECK(sfJoystickAxisCount == 8);
    }

    SECTION("sfJoystickAxis")
    {
        STATIC_CHECK(sfJoystickX == static_cast<int>(sf::Joystick::Axis::X));
        STATIC_CHECK(sfJoystickY == static_cast<int>(sf::Joystick::Axis::Y));
        STATIC_CHECK(sfJoystickZ == static_cast<int>(sf::Joystick::Axis::Z));
        STATIC_CHECK(sfJoystickR == static_cast<int>(sf::Joystick::Axis::R));
        STATIC_CHECK(sfJoystickU == static_cast<int>(sf::Joystick::Axis::U));
        STATIC_CHECK(sfJoystickV == static_cast<int>(sf::Joystick::Axis::V));
        STATIC_CHECK(sfJoystickPovX == static_cast<int>(sf::Joystick::Axis::PovX));
        STATIC_CHECK(sfJoystickPovY == static_cast<int>(sf::Joystick::Axis::PovY));
    }

    // By avoiding calling sfJoystick_update() we can guarantee that
    // no joysticks will be detected. This is how we can ensure these
    // tests are portable and reliable.

    const auto joystick = GENERATE(range(0u, unsigned{sfJoystickCount - 1}));

    SECTION("sfJoystick_isConnected()")
    {
        CHECK(!sfJoystick_isConnected(joystick));
    }

    SECTION("sfJoystick_getButtonCount()")
    {
        CHECK(sfJoystick_getButtonCount(joystick) == 0);
    }

    SECTION("sfJoystick_hasAxis()")
    {
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickX));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickY));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickZ));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickR));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickU));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickV));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickPovX));
        CHECK(!sfJoystick_hasAxis(joystick, sfJoystickPovY));
    }

    SECTION("sfJoystick_isButtonPressed()")
    {
        const auto button = GENERATE(range(0u, unsigned{sfJoystickButtonCount - 1}));
        CHECK(!sfJoystick_isButtonPressed(joystick, button));
    }

    SECTION("sfJoystick_getAxisPosition")
    {
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickX) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickY) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickZ) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickR) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickU) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickV) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickPovX) == 0);
        CHECK(sfJoystick_getAxisPosition(joystick, sfJoystickPovY) == 0);
    }

    SECTION("getIdentification()")
    {
        const auto identification = sfJoystick_getIdentification(joystick);
        CHECK(identification.name == std::string("No Joystick"));
        CHECK(identification.vendorId == 0);
        CHECK(identification.productId == 0);
    }
}
