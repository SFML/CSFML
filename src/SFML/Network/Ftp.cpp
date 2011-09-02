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
#include <SFML/Network/Ftp.h>
#include <SFML/Network/FtpStruct.h>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Internal.h>


////////////////////////////////////////////////////////////
void sfFtpListingResponse_Destroy(sfFtpListingResponse* ftpListingResponse)
{
    delete ftpListingResponse;
}


////////////////////////////////////////////////////////////
sfBool sfFtpListingResponse_IsOk(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CALL_RETURN(ftpListingResponse, IsOk(), sfFalse);
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpListingResponse_GetStatus(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CHECK_RETURN(ftpListingResponse, sfFtpInvalidResponse);

    return static_cast<sfFtpStatus>(ftpListingResponse->This.GetStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpListingResponse_GetMessage(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CHECK_RETURN(ftpListingResponse, NULL);

    return ftpListingResponse->This.GetMessage().c_str();
}


////////////////////////////////////////////////////////////
size_t sfFtpListingResponse_GetCount(const sfFtpListingResponse* ftpListingResponse)
{
    CSFML_CHECK_RETURN(ftpListingResponse, 0);

    return ftpListingResponse->This.GetFilenames().size();
}


////////////////////////////////////////////////////////////
const char* sfFtpListingResponse_GetFilename(const sfFtpListingResponse* ftpListingResponse, size_t index)
{
    CSFML_CHECK_RETURN(ftpListingResponse, NULL);

    return ftpListingResponse->This.GetFilenames()[index].c_str();
}


////////////////////////////////////////////////////////////
void sfFtpDirectoryResponse_Destroy(sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    delete ftpDirectoryResponse;
}


////////////////////////////////////////////////////////////
sfBool sfFtpDirectoryResponse_IsOk(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CALL_RETURN(ftpDirectoryResponse, IsOk(), sfFalse);
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpDirectoryResponse_GetStatus(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CHECK_RETURN(ftpDirectoryResponse, sfFtpInvalidResponse);

    return static_cast<sfFtpStatus>(ftpDirectoryResponse->This.GetStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpDirectoryResponse_GetMessage(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CHECK_RETURN(ftpDirectoryResponse, NULL);

    return ftpDirectoryResponse->This.GetMessage().c_str();
}


////////////////////////////////////////////////////////////
const char* sfFtpDirectoryResponse_GetDirectory(const sfFtpDirectoryResponse* ftpDirectoryResponse)
{
    CSFML_CHECK_RETURN(ftpDirectoryResponse, NULL);

    return ftpDirectoryResponse->This.GetDirectory().c_str();
}


////////////////////////////////////////////////////////////
void sfFtpResponse_Destroy(sfFtpResponse* ftpResponse)
{
    delete ftpResponse;
}


////////////////////////////////////////////////////////////
sfBool sfFtpResponse_IsOk(const sfFtpResponse* ftpResponse)
{
    CSFML_CALL_RETURN(ftpResponse, IsOk(), sfFalse);
}


////////////////////////////////////////////////////////////
sfFtpStatus sfFtpResponse_GetStatus(const sfFtpResponse* ftpResponse)
{
    CSFML_CHECK_RETURN(ftpResponse, sfFtpInvalidResponse);

    return static_cast<sfFtpStatus>(ftpResponse->This.GetStatus());
}


////////////////////////////////////////////////////////////
const char* sfFtpResponse_GetMessage(const sfFtpResponse* ftpResponse)
{
    CSFML_CHECK_RETURN(ftpResponse, NULL);

    return ftpResponse->This.GetMessage().c_str();
}


////////////////////////////////////////////////////////////
sfFtp* sfFtp_Create(void)
{
    return new sfFtp;
}


////////////////////////////////////////////////////////////
void sfFtp_Destroy(sfFtp* ftp)
{
    delete ftp;
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_Connect(sfFtp* ftp, sfIpAddress server, unsigned short port, sfUint32 timeout)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    sf::IpAddress SFMLServer(server.Address);

    return new sfFtpResponse(ftp->This.Connect(SFMLServer, port, timeout));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_LoginAnonymous(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.Login());
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_Login(sfFtp* ftp, const char* userName, const char* password)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.Login(userName ? userName : "", password ? password : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_Disconnect(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.Disconnect());
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_KeepAlive(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.KeepAlive());
}


////////////////////////////////////////////////////////////
sfFtpDirectoryResponse* sfFtp_GetWorkingDirectory(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpDirectoryResponse(ftp->This.GetWorkingDirectory());
}


////////////////////////////////////////////////////////////
sfFtpListingResponse* sfFtp_GetDirectoryListing(sfFtp* ftp, const char* directory)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpListingResponse(ftp->This.GetDirectoryListing(directory ? directory : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_ChangeDirectory(sfFtp* ftp, const char* directory)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.ChangeDirectory(directory ? directory : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_ParentDirectory(sfFtp* ftp)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.ParentDirectory());
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_CreateDirectory(sfFtp* ftp, const char* name)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.CreateDirectory(name ? name : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_DeleteDirectory(sfFtp* ftp, const char* name)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.DeleteDirectory(name ? name : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_RenameFile(sfFtp* ftp, const char* file, const char* newName)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.RenameFile(file ? file : "", newName ? newName : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_DeleteFile(sfFtp* ftp, const char* name)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.DeleteFile(name ? name : ""));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_Download(sfFtp* ftp, const char* distantFile, const char* destPath, sfFtpTransferMode mode)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.Download(distantFile ? distantFile : "",
                                                destPath ? destPath : "",
                                                static_cast<sf::Ftp::TransferMode>(mode)));
}


////////////////////////////////////////////////////////////
sfFtpResponse* sfFtp_Upload(sfFtp* ftp, const char* localFile, const char* destPath, sfFtpTransferMode mode)
{
    CSFML_CHECK_RETURN(ftp, NULL);

    return new sfFtpResponse(ftp->This.Upload(localFile ? localFile : "",
                                              destPath ? destPath : "",
                                              static_cast<sf::Ftp::TransferMode>(mode)));
}
