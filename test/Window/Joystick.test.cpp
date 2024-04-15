#include <SFML/Window/Joystick.h>

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

    // By avoiding calling sfJoystick_update() we can guarantee that
    // no joysticks will be detected. This is how we can ensure these
    // tests are portable and reliable.

    const auto joystick = GENERATE(range(0u, static_cast<unsigned int>(sfJoystickCount - 1)));

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
        const auto button = GENERATE(range(0u, static_cast<unsigned int>(sfJoystickButtonCount - 1)));
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
