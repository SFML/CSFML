#include <CSFML/Network/SocketSelector.h>
#include <CSFML/Network/TcpListener.h>
#include <CSFML/Network/TcpSocket.h>

#include <SFML/Network/SocketSelector.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Network] sfSocketSelector")
{
    SECTION("sfSocketSelectorReadiness")
    {
        STATIC_CHECK(sfSocketSelectorReceive == static_cast<int>(sf::SocketSelector::Receive));
        STATIC_CHECK(sfSocketSelectorSend == static_cast<int>(sf::SocketSelector::Send));
    }

    SECTION("Ready callbacks")
    {
        sfTcpListener* listener = sfTcpListener_create();
        REQUIRE(sfTcpListener_listen(listener, 0, sfIpAddress_LocalHost) == sfSocketDone);

        sfTcpSocket* client = sfTcpSocket_create();
        REQUIRE(sfTcpSocket_connect(client, sfIpAddress_LocalHost, sfTcpListener_getLocalPort(listener), sfSeconds(1)) ==
                sfSocketDone);

        sfSocketSelector* selector = sfSocketSelector_create();

        uint32_t   readiness = 0;
        const auto callback  = [](uint32_t ready, void* userData) { *static_cast<uint32_t*>(userData) |= ready; };
        CHECK(sfSocketSelector_addTcpListenerWithReadiness(selector, listener, sfSocketSelectorReceive, callback, &readiness));

        REQUIRE(sfSocketSelector_wait(selector, sfSeconds(1)));
        CHECK(sfSocketSelector_isTcpListenerReady(selector, listener));
        CHECK(sfSocketSelector_isTcpListenerReadyFor(selector, listener, sfSocketSelectorReceive));
        sfSocketSelector_dispatchReadyCallbacks(selector);
        CHECK(readiness == sfSocketSelectorReceive);

        CHECK(sfSocketSelector_removeTcpListener(selector, listener));

        sfSocketSelector_destroy(selector);
        sfTcpSocket_destroy(client);
        sfTcpListener_destroy(listener);
    }
}
