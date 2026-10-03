////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2026 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Audio/PlaybackDevice.h>

#include <SFML/Audio/PlaybackDevice.hpp>

#include <cassert>
#include <optional>
#include <string>
#include <vector>


namespace
{
// Helper function for returning optional strings
[[nodiscard]] const char* toCString(std::string& storage, const std::optional<std::string>& string)
{
    if (!string)
        return nullptr;

    storage = *string;
    return storage.c_str();
}
} // namespace


////////////////////////////////////////////////////////////
const char* const* sfPlaybackDevice_getAvailableDevices(size_t* count)
{
    static std::vector<std::string> stringDevices;
    static std::vector<const char*> devices;

    stringDevices = sf::PlaybackDevice::getAvailableDevices();
    devices.clear();
    devices.reserve(stringDevices.size());
    for (const auto& stringDevice : stringDevices)
        devices.push_back(stringDevice.c_str());

    if (count)
        *count = devices.size();

    return !devices.empty() ? devices.data() : nullptr;
}


////////////////////////////////////////////////////////////
const char* sfPlaybackDevice_getDefaultDevice()
{
    static std::string defaultDevice;
    return toCString(defaultDevice, sf::PlaybackDevice::getDefaultDevice());
}


////////////////////////////////////////////////////////////
bool sfPlaybackDevice_setDevice(const char* name)
{
    assert(name);
    return sf::PlaybackDevice::setDevice(name);
}


////////////////////////////////////////////////////////////
bool sfPlaybackDevice_setDeviceToDefault()
{
    return sf::PlaybackDevice::setDeviceToDefault();
}


////////////////////////////////////////////////////////////
bool sfPlaybackDevice_setDeviceToNull()
{
    return sf::PlaybackDevice::setDeviceToNull();
}


////////////////////////////////////////////////////////////
const char* sfPlaybackDevice_getDevice()
{
    static std::string device;
    return toCString(device, sf::PlaybackDevice::getDevice());
}


////////////////////////////////////////////////////////////
uint32_t sfPlaybackDevice_getDeviceSampleRate()
{
    return sf::PlaybackDevice::getDeviceSampleRate().value_or(0);
}


////////////////////////////////////////////////////////////
bool sfPlaybackDevice_isDefaultDevice()
{
    return sf::PlaybackDevice::isDefaultDevice();
}


////////////////////////////////////////////////////////////
void sfPlaybackDevice_setNotificationCallback(sfPlaybackDeviceNotificationCallback callback, void* userData)
{
    if (!callback)
    {
        sf::PlaybackDevice::setNotificationCallback({});
        return;
    }

    sf::PlaybackDevice::setNotificationCallback(
        [callback, userData](sf::PlaybackDevice::Notification notification)
        { callback(static_cast<sfPlaybackDeviceNotification>(notification), userData); });
}
