#include <CSFML/Network/TcpSocket.h>

#include <SFML/Network/TcpSocket.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Network] sfTcpSocket")
{
    SECTION("sfTlsStatus")
    {
        STATIC_CHECK(sfTlsNotConnected == static_cast<int>(sf::TcpSocket::TlsStatus::NotConnected));
        STATIC_CHECK(sfTlsHandshakeStarted == static_cast<int>(sf::TcpSocket::TlsStatus::HandshakeStarted));
        STATIC_CHECK(sfTlsHandshakeComplete == static_cast<int>(sf::TcpSocket::TlsStatus::HandshakeComplete));
        STATIC_CHECK(sfTlsError == static_cast<int>(sf::TcpSocket::TlsStatus::Error));
    }

    SECTION("TLS on unconnected socket")
    {
        sfTcpSocket* socket = sfTcpSocket_create();
        CHECK(sfTcpSocket_setupTlsClient(socket, "localhost", true) == sfTlsNotConnected);
        CHECK(sfTcpSocket_getCurrentCiphersuiteName(socket) == nullptr);
        sfTcpSocket_destroy(socket);
    }
}
