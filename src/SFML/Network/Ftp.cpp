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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Ftp.h>
#include <SFML/Network/FtpStruct.h>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
void sfFtpListingResponse_destroy(sfFtpListingResponse* ftpListingResponse)
{
    delete ftpListingResponse;
}


////////////////////////////////////////////////////////////
sfBool sfFtpListingResponse_isOk(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CALL_RETURN(ftpListingResponse, isOk(), sfFalse);
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpListingResponse_getStatus(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CHECK_RETURN(ftpListingResponse, sfFtpInvalidResponse);

    return static_cast<sfFtpStatus>(ftpListingResponse->This.getStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpListingResponse_getMessage(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CHECK_RETURN(ftpListingResponse, NULL);

    return ftpListingResponse->This.getMessage().c_str();
}


////////////////////////////////////////////////////////////
size_t sfFtpListingResponse_getCount(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CHECK_RETURN(ftpListingResponse, 0);

    return ftpListingResponse->This.getListing().size();
}


////////////////////////////////////////////////////////////
const char* sfFtpListingResponse_getName(const sfFtpListingResponse* ftpListingResponse, size_t index)
{
    CSFML_CHECK_RETURN(ftpListingResponse, NULL);

    return ftpListingResponse->This.getListing()[index].c_str();
}


////////////////////////////////////////////////////////////
void sfFtpDirectoryResponse_destroy(sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    delete ftpDirectoryResponse;
}


////////////////////////////////////////////////////////////
sfBool sfFtpDirectoryResponse_isOk(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CALL_RETURN(ftpDirectoryResponse, isOk(), sfFalse);
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpDirectoryResponse_getStatus(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CHECK_RETURN(ftpDirectoryResponse, sfFtpInvalidResponse);

    return static_cast<sfFtpStatus>(ftpDirectoryResponse->This.getStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpDirectoryResponse_getMessage(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CHECK_RETURN(ftpDirectoryResponse, NULL);

    return ftpDirectoryResponse->This.getMessage().c_str();
}


////////////////////////////////////////////////////////////
const char* sfFtpDirectoryResponse_getDirectory(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CHECK_RETURN(ftpDirectoryResponse, NULL);

    return ftpDirectoryResponse->This.getDirectory().c_str();
}


////////////////////////////////////////////////////////////
void sfFtpResponse_destroy(sfFtpResponse* ftpResponse)
{
    delete ftpResponse;
}


////////////////////////////////////////////////////////////
sfBool sfFtpResponse_isOk(const sfFtpResponse* ftpResponse)
{
    CSFML_CALL_RETURN(ftpResponse, isOk(), sfFalse);
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpResponse_getStatus(const sfFtpResponse* ftpResponse)
{
    CSFML_CHECK_RETURN(ftpResponse, sfFtpInvalidResponse);

    return static_cast<sfFtpStatus>(ftpResponse->This.getStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpResponse_getMessage(const sfFtpResponse* ftpResponse)
{
    CSFML_CHECK_RETURN(ftpResponse, NULL);

    return ftpResponse->This.getMessage().c_str();
}


////////////////////////////////////////////////////////////
sfFtp* sfFtp_create(void)
{
    return new sfFtp;
}


////////////////////////////////////////////////////////////
void sfFtp_destroy(sfFtp* ftp)
{
    delete ftp;
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_connect(sfFtp* ftp, sfIpAddress server, unsigned short port, sfTime timeout)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    sf::IpAddress SFMLServer(server.address);

    return new sfFtpResponse(ftp->This.connect(SFMLServer, port, sf::microseconds(timeout.microseconds)));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_loginAnonymous(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.login());
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_login(sfFtp* ftp, const char* name, const char* password)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.login(name ? name : "", password ? password : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_disconnect(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.disconnect());
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_keepAlive(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.keepAlive());
}


////////////////////////////////////////////////////////////
sfFtpDirectoryResponse* sfFtp_getWorkingDirectory(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpDirectoryResponse(ftp->This.getWorkingDirectory());
}


////////////////////////////////////////////////////////////
sfFtpListingResponse* sfFtp_getDirectoryListing(sfFtp* ftp, const char* directory)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpListingResponse(ftp->This.getDirectoryListing(directory ? directory : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_changeDirectory(sfFtp* ftp, const char* directory)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.changeDirectory(directory ? directory : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_parentDirectory(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.parentDirectory());
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_createDirectory(sfFtp* ftp, const char* name)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.createDirectory(name ? name : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_deleteDirectory(sfFtp* ftp, const char* name)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.deleteDirectory(name ? name : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_renameFile(sfFtp* ftp, const char* file, const char* newName)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.renameFile(file ? file : "", newName ? newName : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_deleteFile(sfFtp* ftp, const char* name)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.deleteFile(name ? name : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_download(sfFtp* ftp, const char* remoteFile, const char* localPath, sfFtpTransferMode mode)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.download(remoteFile ? remoteFile : "",
                                                localPath ? localPath : "",
                                                static_cast<sf::Ftp::TransferMode>(mode)));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_upload(sfFtp* ftp, const char* localFile, const char* remotePath, sfFtpTransferMode mode, sfBool append)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.upload(localFile ? localFile : "",
                                              remotePath ? remotePath : "",
                                              static_cast<sf::Ftp::TransferMode>(mode),
                                              append == sfTrue));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_sendCommand(sfFtp* ftp, const char* command, const char* parameter)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.sendCommand(command ? command : "", parameter ? parameter : ""));
}
