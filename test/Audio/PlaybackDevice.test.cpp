#include <CSFML/Audio/PlaybackDevice.h>

#include <SFML/Audio/PlaybackDevice.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Audio] sfPlaybackDevice")
{
    SECTION("sfPlaybackDeviceNotification")
    {
        STATIC_CHECK(sfPlaybackDeviceStarted == static_cast<int>(sf::PlaybackDevice::Notification::DeviceStarted));
        STATIC_CHECK(sfPlaybackDeviceStopped == static_cast<int>(sf::PlaybackDevice::Notification::DeviceStopped));
        STATIC_CHECK(sfPlaybackDeviceRerouted == static_cast<int>(sf::PlaybackDevice::Notification::DeviceRerouted));
        STATIC_CHECK(sfPlaybackDeviceInterruptionBegan ==
                     static_cast<int>(sf::PlaybackDevice::Notification::DeviceInterruptionBegan));
        STATIC_CHECK(sfPlaybackDeviceInterruptionEnded ==
                     static_cast<int>(sf::PlaybackDevice::Notification::DeviceInterruptionEnded));
        STATIC_CHECK(sfPlaybackDeviceUnlocked == static_cast<int>(sf::PlaybackDevice::Notification::DeviceUnlocked));
    }

    SECTION("sfPlaybackDevice_setNotificationCallback")
    {
        sfPlaybackDevice_setNotificationCallback([](sfPlaybackDeviceNotification, void*) {}, nullptr);
        sfPlaybackDevice_setNotificationCallback(nullptr, nullptr);
    }
}
