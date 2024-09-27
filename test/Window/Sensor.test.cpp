#include <CSFML/Window/Sensor.h>

#include <SFML/Window/Sensor.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Window] sfSensor")
{
    SECTION("sfSensorType")
    {
        STATIC_CHECK(sfSensorAccelerometer == static_cast<int>(sf::Sensor::Type::Accelerometer));
        STATIC_CHECK(sfSensorGyroscope == static_cast<int>(sf::Sensor::Type::Gyroscope));
        STATIC_CHECK(sfSensorMagnetometer == static_cast<int>(sf::Sensor::Type::Magnetometer));
        STATIC_CHECK(sfSensorGravity == static_cast<int>(sf::Sensor::Type::Gravity));
        STATIC_CHECK(sfSensorUserAcceleration == static_cast<int>(sf::Sensor::Type::UserAcceleration));
        STATIC_CHECK(sfSensorOrientation == static_cast<int>(sf::Sensor::Type::Orientation));
        CHECK(sfSensorCount == sf::Sensor::Count);
    }
}
