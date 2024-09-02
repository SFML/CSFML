#include <CSFML/Network/SocketStatus.h>

#include <SFML/Network/Socket.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Network] sfSocketStatus")
{
    STATIC_CHECK(sfSocketDone == static_cast<int>(sf::Socket::Status::Done));
    STATIC_CHECK(sfSocketNotReady == static_cast<int>(sf::Socket::Status::NotReady));
    STATIC_CHECK(sfSocketPartial == static_cast<int>(sf::Socket::Status::Partial));
    STATIC_CHECK(sfSocketDisconnected == static_cast<int>(sf::Socket::Status::Disconnected));
    STATIC_CHECK(sfSocketError == static_cast<int>(sf::Socket::Status::Error));
}
