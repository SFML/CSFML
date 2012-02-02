////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
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
#include <SFML/Network/Http.h>
#include <SFML/Network/HttpStruct.h>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
sfHttpRequest* sfHttpRequest_Create(void)
{
    return new sfHttpRequest;
}


////////////////////////////////////////////////////////////
void sfHttpRequest_Destroy(sfHttpRequest* httpRequest)
{
    delete httpRequest;
}


////////////////////////////////////////////////////////////
void sfHttpRequest_SetField(sfHttpRequest* httpRequest, const char* field, const char* value)
{
    CSFML_CHECK(httpRequest);
    if (field)
        httpRequest->This.SetField(field, value);
}


////////////////////////////////////////////////////////////
void sfHttpRequest_SetMethod(sfHttpRequest* httpRequest, sfHttpMethod method)
{
    CSFML_CALL(httpRequest, SetMethod(static_cast<sf::Http::Request::Method>(method)));
}


////////////////////////////////////////////////////////////
void sfHttpRequest_SetUri(sfHttpRequest* httpRequest, const char* uri)
{
    CSFML_CALL(httpRequest, SetUri(uri ? uri : ""));
}


////////////////////////////////////////////////////////////
void sfHttpRequest_SetHttpVersion(sfHttpRequest* httpRequest, unsigned int major, unsigned int minor)
{
    CSFML_CALL(httpRequest, SetHttpVersion(major, minor));
}


////////////////////////////////////////////////////////////
void sfHttpRequest_SetBody(sfHttpRequest* httpRequest, const char* body)
{
    CSFML_CALL(httpRequest, SetBody(body ? body : ""));
}


////////////////////////////////////////////////////////////
void sfHttpResponse_Destroy(sfHttpResponse* httpResponse)
{
    delete httpResponse;
}


////////////////////////////////////////////////////////////
const char* sfHttpResponse_GetField(const sfHttpResponse* httpResponse, const char* field)
{
    CSFML_CHECK_RETURN(httpResponse, NULL);
    if (!field)
        return NULL;

    return httpResponse->This.GetField(field).c_str();
}


////////////////////////////////////////////////////////////
sfHttpStatus sfHttpResponse_GetStatus(const sfHttpResponse* httpResponse)
{
    CSFML_CHECK_RETURN(httpResponse, sfHttpInvalidResponse);

    return static_cast<sfHttpStatus>(httpResponse->This.GetStatus());
}


////////////////////////////////////////////////////////////
unsigned int sfHttpResponse_GetMajorVersion(const sfHttpResponse* httpResponse)
{
    CSFML_CALL_RETURN(httpResponse, GetMajorHttpVersion(), 0);
}


////////////////////////////////////////////////////////////
unsigned int sfHttpResponse_GetMinorVersion(const sfHttpResponse* httpResponse)
{
    CSFML_CALL_RETURN(httpResponse, GetMinorHttpVersion(), 0);
}


////////////////////////////////////////////////////////////
const char* sfHttpResponse_GetBody(const sfHttpResponse* httpResponse)
{
    CSFML_CHECK_RETURN(httpResponse, NULL);

    return httpResponse->This.GetBody().c_str();
}


////////////////////////////////////////////////////////////
sfHttp* sfHttp_Create(void)
{
    return new sfHttp;
}


////////////////////////////////////////////////////////////
void sfHttp_Destroy(sfHttp* http)
{
    delete http;
}


////////////////////////////////////////////////////////////
void sfHttp_SetHost(sfHttp* http, const char* host, unsigned short port)
{
    CSFML_CALL(http, SetHost(host ? host : "", port));
}


////////////////////////////////////////////////////////////
sfHttpResponse* sfHttp_SendRequest(sfHttp* http, const sfHttpRequest* request, sfTime timeout)
{
    CSFML_CHECK_RETURN(http,    NULL);
    CSFML_CHECK_RETURN(request, NULL);

    sfHttpResponse* response = new sfHttpResponse;
    response->This = http->This.SendRequest(request->This, sf::Microseconds(timeout.Microseconds));

    return response;
}
