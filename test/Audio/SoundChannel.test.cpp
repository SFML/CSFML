#include <CSFML/Audio/SoundChannel.h>

#include <SFML/Audio/SoundChannel.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Audio] sfSoundChannel")
{
    STATIC_CHECK(sfSoundChannelUnspecified == static_cast<int>(sf::SoundChannel::Unspecified));
    STATIC_CHECK(sfSoundChannelMono == static_cast<int>(sf::SoundChannel::Mono));
    STATIC_CHECK(sfSoundChannelFrontLeft == static_cast<int>(sf::SoundChannel::FrontLeft));
    STATIC_CHECK(sfSoundChannelFrontRight == static_cast<int>(sf::SoundChannel::FrontRight));
    STATIC_CHECK(sfSoundChannelFrontCenter == static_cast<int>(sf::SoundChannel::FrontCenter));
    STATIC_CHECK(sfSoundChannelFrontLeftOfCenter == static_cast<int>(sf::SoundChannel::FrontLeftOfCenter));
    STATIC_CHECK(sfSoundChannelFrontRightOfCenter == static_cast<int>(sf::SoundChannel::FrontRightOfCenter));
    STATIC_CHECK(sfSoundChannelLowFrequencyEffects == static_cast<int>(sf::SoundChannel::LowFrequencyEffects));
    STATIC_CHECK(sfSoundChannelBackLeft == static_cast<int>(sf::SoundChannel::BackLeft));
    STATIC_CHECK(sfSoundChannelBackRight == static_cast<int>(sf::SoundChannel::BackRight));
    STATIC_CHECK(sfSoundChannelBackCenter == static_cast<int>(sf::SoundChannel::BackCenter));
    STATIC_CHECK(sfSoundChannelSideLeft == static_cast<int>(sf::SoundChannel::SideLeft));
    STATIC_CHECK(sfSoundChannelSideRight == static_cast<int>(sf::SoundChannel::SideRight));
    STATIC_CHECK(sfSoundChannelTopCenter == static_cast<int>(sf::SoundChannel::TopCenter));
    STATIC_CHECK(sfSoundChannelTopFrontLeft == static_cast<int>(sf::SoundChannel::TopFrontLeft));
    STATIC_CHECK(sfSoundChannelTopFrontRight == static_cast<int>(sf::SoundChannel::TopFrontRight));
    STATIC_CHECK(sfSoundChannelTopFrontCenter == static_cast<int>(sf::SoundChannel::TopFrontCenter));
    STATIC_CHECK(sfSoundChannelTopBackLeft == static_cast<int>(sf::SoundChannel::TopBackLeft));
    STATIC_CHECK(sfSoundChannelTopBackRight == static_cast<int>(sf::SoundChannel::TopBackRight));
    STATIC_CHECK(sfSoundChannelTopBackCenter == static_cast<int>(sf::SoundChannel::TopBackCenter));
}
