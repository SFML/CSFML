////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
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

#ifndef SFML_HTTP_H
#define SFML_HTTP_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Export.h>
#include <SFML/Network/Types.h>
#include <SFML/System/Time.h>


////////////////////////////////////////////////////////////
/// \brief Enumerate the available HTTP methods for a request
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfHttpGet,   ///< Request in get mode, standard method to retrieve a page
    sfHttpPost,  ///< Request in post mode, usually to send data to a page
    sfHttpHead,  ///< Request a page's header only
    sfHttpPut,   ///< Request in put mode, useful for a REST API
    sfHttpDelete ///< Request in delete mode, useful for a REST API
} sfHttpMethod;


////////////////////////////////////////////////////////////
/// \brief Enumerate all the valid status codes for a response
///
////////////////////////////////////////////////////////////
typedef enum
{
    // 2xx: success
    sfHttpOk             = 200, ///< Most common code returned when operation was successful
    sfHttpCreated        = 201, ///< The resource has successfully been created
    sfHttpAccepted       = 202, ///< The request has been accepted, but will be processed later by the server
    sfHttpNoContent      = 204, ///< Sent when the server didn't send any data in return
    sfHttpResetContent   = 205, ///< The server informs the client that it should clear the view (form) that caused the request to be sent
    sfHttpPartialContent = 206, ///< The server has sent a part of the resource, as a response to a partial GET request

    // 3xx: redirection
    sfHttpMultipleChoices  = 300, ///< The requested page can be accessed from several locations
    sfHttpMovedPermanently = 301, ///< The requested page has permanently moved to a new location
    sfHttpMovedTemporarily = 302, ///< The requested page has temporarily moved to a new location
    sfHttpNotModified      = 304, ///< For conditional requests, means the requested page hasn't changed and doesn't need to be refreshed

    // 4xx: client error
    sfHttpBadRequest          = 400, ///< The server couldn't understand the request (syntax error)
    sfHttpUnauthorized        = 401, ///< The requested page needs an authentication to be accessed
    sfHttpForbidden           = 403, ///< The requested page cannot be accessed at all, even with authentication
    sfHttpNotFound            = 404, ///< The requested page doesn't exist
    sfHttpRangeNotSatisfiable = 407, ///< The server can't satisfy the partial GET request (with a "Range" header field)

    // 5xx: server error
    sfHttpInternalServerError = 500, ///< The server encountered an unexpected error
    sfHttpNotImplemented      = 501, ///< The server doesn't implement a requested feature
    sfHttpBadGateway          = 502, ///< The gateway server has received an error from the source server
    sfHttpServiceNotAvailable = 503, ///< The server is temporarily unavailable (overloaded, in maintenance, ...)
    sfHttpGatewayTimeout      = 504, ///< The gateway server couldn't receive a response from the source server
    sfHttpVersionNotSupported = 505, ///< The server doesn't support the requested HTTP version

    // 10xx: SFML custom codes
    sfHttpInvalidResponse  = 1000, ///< Response is not a valid HTTP one
    sfHttpConnectionFailed = 1001  ///< Connection with server failed
} sfHttpStatus;


////////////////////////////////////////////////////////////
/// \brief Create a new HTTP request
///
/// \return A new sfHttpRequest object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfHttpRequest* sfHttpRequest_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy a HTTP request
///
/// \param httpRequest HTTP request to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpRequest_destroy(sfHttpRequest* httpRequest);

////////////////////////////////////////////////////////////
/// \brief Set the value of a header field of a HTTP request
///
/// The field is created if it doesn't exist. The name of
/// the field is case insensitive.
/// By default, a request doesn't contain any field (but the
/// mandatory fields are added later by the HTTP client when
/// sending the request).
///
/// \param httpRequest HTTP request
/// \param field       Name of the field to set
/// \param value       Value of the field
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpRequest_setField(sfHttpRequest* httpRequest, const char* field, const char* value);

////////////////////////////////////////////////////////////
/// \brief Set a HTTP request method
///
/// See the sfHttpMethod enumeration for a complete list of all
/// the availale methods.
/// The method is sfHttpGet by default.
///
/// \param httpRequest HTTP request
/// \param method      Method to use for the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpRequest_setMethod(sfHttpRequest* httpRequest, sfHttpMethod method);

////////////////////////////////////////////////////////////
/// \brief Set a HTTP request URI
///
/// The URI is the resource (usually a web page or a file)
/// that you want to get or post.
/// The URI is "/" (the root page) by default.
///
/// \param httpRequest HTTP request
/// \param uri         URI to request, relative to the host
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpRequest_setUri(sfHttpRequest* httpRequest, const char* uri);

////////////////////////////////////////////////////////////
/// \brief Set the HTTP version of a HTTP request
///
/// The HTTP version is 1.0 by default.
///
/// \param httpRequest HTTP request
/// \param major       Major HTTP version number
/// \param minor       Minor HTTP version number
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpRequest_setHttpVersion(sfHttpRequest* httpRequest, unsigned int major, unsigned int minor);

////////////////////////////////////////////////////////////
/// \brief Set the body of a HTTP request
///
/// The body of a request is optional and only makes sense
/// for POST requests. It is ignored for all other methods.
/// The body is empty by default.
///
/// \param httpRequest HTTP request
/// \param body        Content of the body
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpRequest_setBody(sfHttpRequest* httpRequest, const char* body);

////////////////////////////////////////////////////////////
/// \brief Destroy a HTTP response
///
/// \param httpResponse HTTP response to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttpResponse_destroy(sfHttpResponse* httpResponse);

////////////////////////////////////////////////////////////
/// \brief Get the value of a field of a HTTP response
///
/// If the field \a field is not found in the response header,
/// the empty string is returned. This function uses
/// case-insensitive comparisons.
///
/// \param httpResponse HTTP response
/// \param field        Name of the field to get
///
/// \return Value of the field, or empty string if not found
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfHttpResponse_getField(const sfHttpResponse* httpResponse, const char* field);

////////////////////////////////////////////////////////////
/// \brief Get the status code of a HTTP reponse
///
/// The status code should be the first thing to be checked
/// after receiving a response, it defines whether it is a
/// success, a failure or anything else (see the sfHttpStatus
/// enumeration).
///
/// \param httpResponse HTTP response
///
/// \return Status code of the response
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfHttpStatus sfHttpResponse_getStatus(const sfHttpResponse* httpResponse);

////////////////////////////////////////////////////////////
/// \brief Get the major HTTP version number of a HTTP response
///
/// \param httpResponse HTTP response
///
/// \return Major HTTP version number
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API unsigned int sfHttpResponse_getMajorVersion(const sfHttpResponse* httpResponse);

////////////////////////////////////////////////////////////
/// \brief Get the minor HTTP version number of a HTTP response
///
/// \param httpResponse HTTP response
///
/// \return Minor HTTP version number
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API unsigned int sfHttpResponse_getMinorVersion(const sfHttpResponse* httpResponse);

////////////////////////////////////////////////////////////
/// \brief Get the body of a HTTP response
///
/// The body of a response may contain:
/// \li the requested page (for GET requests)
/// \li a response from the server (for POST requests)
/// \li nothing (for HEAD requests)
/// \li an error message (in case of an error)
///
/// \param httpResponse HTTP response
///
/// \return The response body
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfHttpResponse_getBody(const sfHttpResponse* httpResponse);

////////////////////////////////////////////////////////////
/// \brief Create a new Http object
///
/// \return A new sfHttp object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfHttp* sfHttp_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy a Http object
///
/// \param http Http object to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttp_destroy(sfHttp* http);

////////////////////////////////////////////////////////////
/// \brief Set the target host of a HTTP object
///
/// This function just stores the host address and port, it
/// doesn't actually connect to it until you send a request.
/// If the port is 0, it means that the HTTP client will use
/// the right port according to the protocol used
/// (80 for HTTP, 443 for HTTPS). You should
/// leave it like this unless you really need a port other
/// than the standard one, or use an unknown protocol.
///
/// \param http Http object
/// \param host Web server to connect to
/// \param port Port to use for connection
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfHttp_setHost(sfHttp* http, const char* host, unsigned short port);

////////////////////////////////////////////////////////////
/// \brief Send a HTTP request and return the server's response.
///
/// You must have a valid host before sending a request (see sfHttp_setHost).
/// Any missing mandatory header field in the request will be added
/// with an appropriate value.
/// Warning: this function waits for the server's response and may
/// not return instantly; use a thread if you don't want to block your
/// application, or use a timeout to limit the time to wait. A value
/// of 0 means that the client will use the system defaut timeout
/// (which is usually pretty long).
///
/// \param http    Http object
/// \param request Request to send
/// \param timeout Maximum time to wait
///
/// \return Server's response
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfHttpResponse* sfHttp_sendRequest(sfHttp* http, const sfHttpRequest* request, sfTime timeout);


#endif // SFML_HTTP_H
