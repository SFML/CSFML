#include <CSFML/Audio/Listener.h>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Audio] sfListener")
{
    SECTION("sfListenerCone")
    {
        constexpr sfListenerCone cone{};
        STATIC_CHECK(cone.innerAngle == 0);
        STATIC_CHECK(cone.outerAngle == 0);
        STATIC_CHECK(cone.outerGain == 0);
    }

    SECTION("Set/get global volume")
    {
        CHECK(sfListener_getGlobalVolume() == 100);
        sfListener_setGlobalVolume(42);
        CHECK(sfListener_getGlobalVolume() == 42);
    }

    SECTION("Set/get position")
    {
        sfVector3f position = sfListener_getPosition();
        CHECK(position.x == 0);
        CHECK(position.y == 0);
        CHECK(position.z == 0);
        sfListener_setPosition({3, 4, 5});
        position = sfListener_getPosition();
        CHECK(position.x == 3);
        CHECK(position.y == 4);
        CHECK(position.z == 5);
    }

    SECTION("Set/get direction")
    {
        sfVector3f direction = sfListener_getDirection();
        CHECK(direction.x == 0);
        CHECK(direction.y == 0);
        CHECK(direction.z == -1);
        sfListener_setDirection({6, 7, 8});
        direction = sfListener_getDirection();
        CHECK(direction.x == 6);
        CHECK(direction.y == 7);
        CHECK(direction.z == 8);
    }

    SECTION("Set/get velocity")
    {
        sfVector3f velocity = sfListener_getVelocity();
        CHECK(velocity.x == 0);
        CHECK(velocity.y == 0);
        CHECK(velocity.z == 0);
        sfListener_setVelocity({9, 10, 11});
        velocity = sfListener_getVelocity();
        CHECK(velocity.x == 9);
        CHECK(velocity.y == 10);
        CHECK(velocity.z == 11);
    }

    SECTION("Set/get cone")
    {
        sfListenerCone cone = sfListener_getCone();
        CHECK(cone.innerAngle == 360);
        CHECK(cone.outerAngle == 360);
        CHECK(cone.outerGain == 1);
        sfListener_setCone({15, 30, 0.5f});
        cone = sfListener_getCone();
        CHECK(cone.innerAngle == 15);
        CHECK(cone.outerAngle == 30);
        CHECK(cone.outerGain == 0.5f);
    }

    SECTION("Set/get up vector")
    {
        sfVector3f upVector = sfListener_getUpVector();
        CHECK(upVector.x == 0);
        CHECK(upVector.y == 1);
        CHECK(upVector.z == 0);
        sfListener_setUpVector({12, 13, 14});
        upVector = sfListener_getUpVector();
        CHECK(upVector.x == 12);
        CHECK(upVector.y == 13);
        CHECK(upVector.z == 14);
    }
}
