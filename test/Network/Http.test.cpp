#include <CSFML/Network/Http.h>

#include <SFML/Network/Http.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Network] sfHttp")
{
    SECTION("sfHttpMethod")
    {
        STATIC_CHECK(sfHttpGet == static_cast<int>(sf::Http::Request::Method::Get));
        STATIC_CHECK(sfHttpPost == static_cast<int>(sf::Http::Request::Method::Post));
        STATIC_CHECK(sfHttpHead == static_cast<int>(sf::Http::Request::Method::Head));
        STATIC_CHECK(sfHttpPut == static_cast<int>(sf::Http::Request::Method::Put));
        STATIC_CHECK(sfHttpDelete == static_cast<int>(sf::Http::Request::Method::Delete));
    }

    SECTION("sfHttpStatus")
    {
        STATIC_CHECK(sfHttpOk == static_cast<int>(sf::Http::Response::Status::Ok));
        STATIC_CHECK(sfHttpCreated == static_cast<int>(sf::Http::Response::Status::Created));
        STATIC_CHECK(sfHttpAccepted == static_cast<int>(sf::Http::Response::Status::Accepted));
        STATIC_CHECK(sfHttpNoContent == static_cast<int>(sf::Http::Response::Status::NoContent));
        STATIC_CHECK(sfHttpResetContent == static_cast<int>(sf::Http::Response::Status::ResetContent));
        STATIC_CHECK(sfHttpPartialContent == static_cast<int>(sf::Http::Response::Status::PartialContent));

        STATIC_CHECK(sfHttpMultipleChoices == static_cast<int>(sf::Http::Response::Status::MultipleChoices));
        STATIC_CHECK(sfHttpMovedPermanently == static_cast<int>(sf::Http::Response::Status::MovedPermanently));
        STATIC_CHECK(sfHttpMovedTemporarily == static_cast<int>(sf::Http::Response::Status::MovedTemporarily));
        STATIC_CHECK(sfHttpNotModified == static_cast<int>(sf::Http::Response::Status::NotModified));

        STATIC_CHECK(sfHttpBadRequest == static_cast<int>(sf::Http::Response::Status::BadRequest));
        STATIC_CHECK(sfHttpUnauthorized == static_cast<int>(sf::Http::Response::Status::Unauthorized));
        STATIC_CHECK(sfHttpForbidden == static_cast<int>(sf::Http::Response::Status::Forbidden));
        STATIC_CHECK(sfHttpNotFound == static_cast<int>(sf::Http::Response::Status::NotFound));
        STATIC_CHECK(sfHttpRangeNotSatisfiable == static_cast<int>(sf::Http::Response::Status::RangeNotSatisfiable));

        STATIC_CHECK(sfHttpInternalServerError == static_cast<int>(sf::Http::Response::Status::InternalServerError));
        STATIC_CHECK(sfHttpNotImplemented == static_cast<int>(sf::Http::Response::Status::NotImplemented));
        STATIC_CHECK(sfHttpBadGateway == static_cast<int>(sf::Http::Response::Status::BadGateway));
        STATIC_CHECK(sfHttpServiceNotAvailable == static_cast<int>(sf::Http::Response::Status::ServiceNotAvailable));
        STATIC_CHECK(sfHttpGatewayTimeout == static_cast<int>(sf::Http::Response::Status::GatewayTimeout));
        STATIC_CHECK(sfHttpVersionNotSupported == static_cast<int>(sf::Http::Response::Status::VersionNotSupported));

        STATIC_CHECK(sfHttpInvalidResponse == static_cast<int>(sf::Http::Response::Status::InvalidResponse));
        STATIC_CHECK(sfHttpConnectionFailed == static_cast<int>(sf::Http::Response::Status::ConnectionFailed));
    }
}
