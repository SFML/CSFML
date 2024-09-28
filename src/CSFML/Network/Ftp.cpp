////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2024 Laurent Gomila (laurent@sfml-dev.org)
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
#include <CSFML/Network/Ftp.h>
#include <CSFML/Network/FtpStruct.hpp>

#include <SFML/Network/IpAddress.hpp>
#include <SFML/System/String.hpp>

#include <cstring>


namespace
{
////////////////////////////////////////////////////////////
// Ensure char32_t has the same size as sfChar32 (uint32_t)
// Identical alignment and size is required because we're type punning
// when doing sfChar32* <-> char32_t* casts
////////////////////////////////////////////////////////////
static_assert(sizeof(sfChar32) == sizeof(char32_t));
static_assert(alignof(sfChar32) == alignof(char32_t));

////////////////////////////////////////////////////////////
// Define utils to copy to sfChar32
////////////////////////////////////////////////////////////
[[nodiscard]] sfChar32* copyToChar32(const sf::String& str)
{
    const std::size_t byteCount = sizeof(sfChar32) * str.getSize();
    auto*             utf32     = static_cast<sfChar32*>(std::malloc(byteCount + sizeof(sfChar32)));
    if (!utf32)
        return nullptr;
    std::memcpy(utf32, str.getData(), byteCount);
    utf32[str.getSize()] = 0;

    return utf32;
}
} // namespace


////////////////////////////////////////////////////////////
void sfFtpListingResponse_destroy(const sfFtpListingResponse* ftpListingResponse)
{
    delete ftpListingResponse;
}


////////////////////////////////////////////////////////////
bool sfFtpListingResponse_isOk(const sfFtpListingResponse* ftpListingResponse)
{
    assert(ftpListingResponse);
    return ftpListingResponse->isOk();
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpListingResponse_getStatus(const sfFtpListingResponse* ftpListingResponse)
{
    assert(ftpListingResponse);
    return static_cast<sfFtpStatus>(ftpListingResponse->getStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpListingResponse_getMessage(const sfFtpListingResponse* ftpListingResponse)
{
    assert(ftpListingResponse);
    return ftpListingResponse->getMessage().c_str();
}


////////////////////////////////////////////////////////////
size_t sfFtpListingResponse_getCount(const sfFtpListingResponse* ftpListingResponse)
{
    assert(ftpListingResponse);
    return ftpListingResponse->getListing().size();
}


////////////////////////////////////////////////////////////
const char* sfFtpListingResponse_getName(const sfFtpListingResponse* ftpListingResponse, size_t index)
{
    assert(ftpListingResponse);
    return ftpListingResponse->getListing()[index].c_str();
}


////////////////////////////////////////////////////////////
void sfFtpDirectoryResponse_destroy(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    delete ftpDirectoryResponse;
}


////////////////////////////////////////////////////////////
bool sfFtpDirectoryResponse_isOk(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    assert(ftpDirectoryResponse);
    return ftpDirectoryResponse->isOk();
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpDirectoryResponse_getStatus(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    assert(ftpDirectoryResponse);
    return static_cast<sfFtpStatus>(ftpDirectoryResponse->getStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpDirectoryResponse_getMessage(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    assert(ftpDirectoryResponse);
    return ftpDirectoryResponse->getMessage().c_str();
}


////////////////////////////////////////////////////////////
const char* sfFtpDirectoryResponse_getDirectory(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    assert(ftpDirectoryResponse);
    return strdup(ftpDirectoryResponse->getDirectory().string().c_str());
}


////////////////////////////////////////////////////////////
const sfChar32* sfFtpDirectoryResponse_getDirectoryUnicode(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    assert(ftpDirectoryResponse);
    return copyToChar32(sf::String(ftpDirectoryResponse->getDirectory().string()));
}


////////////////////////////////////////////////////////////
void sfFtpResponse_destroy(const sfFtpResponse* ftpResponse)
{
    delete ftpResponse;
}


////////////////////////////////////////////////////////////
bool sfFtpResponse_isOk(const sfFtpResponse* ftpResponse)
{
    assert(ftpResponse);
    return ftpResponse->isOk();
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpResponse_getStatus(const sfFtpResponse* ftpResponse)
{
    assert(ftpResponse);
    return static_cast<sfFtpStatus>(ftpResponse->getStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpResponse_getMessage(const sfFtpResponse* ftpResponse)
{
    assert(ftpResponse);
    return ftpResponse->getMessage().c_str();
}


////////////////////////////////////////////////////////////
sfFtp* sfFtp_create()
{
    return new sfFtp;
}


////////////////////////////////////////////////////////////
void sfFtp_destroy(const sfFtp* ftp)
{
    delete ftp;
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_connect(sfFtp* ftp, sfIpAddress server, unsigned short port, sfTime timeout)
{
    assert(ftp);

    std::optional<sf::IpAddress> sfmlServer = sf::IpAddress::resolve(server.address);

    if (!sfmlServer)
        return nullptr;

    return new sfFtpResponse{ftp->connect(*sfmlServer, port, sf::microseconds(timeout.microseconds))};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_loginAnonymous(sfFtp* ftp)
{
    assert(ftp);
    return new sfFtpResponse{ftp->login()};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_login(sfFtp* ftp, const char* name, const char* password)
{
    assert(ftp);
    return new sfFtpResponse{ftp->login(name ? name : "", password ? password : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_disconnect(sfFtp* ftp)
{
    assert(ftp);
    return new sfFtpResponse{ftp->disconnect()};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_keepAlive(sfFtp* ftp)
{
    assert(ftp);
    return new sfFtpResponse{ftp->keepAlive()};
}


////////////////////////////////////////////////////////////
sfFtpDirectoryResponse* sfFtp_getWorkingDirectory(sfFtp* ftp)
{
    assert(ftp);
    return new sfFtpDirectoryResponse{ftp->getWorkingDirectory()};
}


////////////////////////////////////////////////////////////
sfFtpListingResponse* sfFtp_getDirectoryListing(sfFtp* ftp, const char* directory)
{
    assert(ftp);
    return new sfFtpListingResponse{ftp->getDirectoryListing(directory ? directory : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_changeDirectory(sfFtp* ftp, const char* directory)
{
    assert(ftp);
    return new sfFtpResponse{ftp->changeDirectory(directory ? directory : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_parentDirectory(sfFtp* ftp)
{
    assert(ftp);
    return new sfFtpResponse{ftp->parentDirectory()};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_createDirectory(sfFtp* ftp, const char* name)
{
    assert(ftp);
    return new sfFtpResponse{ftp->createDirectory(name ? name : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_deleteDirectory(sfFtp* ftp, const char* name)
{
    assert(ftp);
    return new sfFtpResponse{ftp->deleteDirectory(name ? name : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_renameFile(sfFtp* ftp, const char* file, const char* newName)
{
    assert(ftp);
    return new sfFtpResponse{ftp->renameFile(file ? file : "", newName ? newName : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_deleteFile(sfFtp* ftp, const char* name)
{
    assert(ftp);
    return new sfFtpResponse{ftp->deleteFile(name ? name : "")};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_download(sfFtp* ftp, const char* remoteFile, const char* localPath, sfFtpTransferMode mode)
{
    assert(ftp);
    return new sfFtpResponse{
        ftp->download(remoteFile ? remoteFile : "", localPath ? localPath : "", static_cast<sf::Ftp::TransferMode>(mode))};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_upload(sfFtp* ftp, const char* localFile, const char* remotePath, sfFtpTransferMode mode, bool append)
{
    assert(ftp);
    return new sfFtpResponse{
        ftp->upload(localFile ? localFile : "", remotePath ? remotePath : "", static_cast<sf::Ftp::TransferMode>(mode), append)};
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_sendCommand(sfFtp* ftp, const char* command, const char* parameter)
{
    assert(ftp);
    return new sfFtpResponse{ftp->sendCommand(command ? command : "", parameter ? parameter : "")};
}
