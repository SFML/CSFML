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

#ifndef SFML_FTP_H
#define SFML_FTP_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Network/Export.h>
#include <SFML/Network/IpAddress.h>
#include <SFML/Network/Types.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Enumeration of transfer modes
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfFtpBinary, ///< Binary mode (file is transfered as a sequence of bytes)
    sfFtpAscii,  ///< Text mode using ASCII encoding
    sfFtpEbcdic  ///< Text mode using EBCDIC encoding
} sfFtpTransferMode;


////////////////////////////////////////////////////////////
/// \brief Status codes possibly returned by a FTP response
///
////////////////////////////////////////////////////////////
typedef enum
{
    // 1xx: the requested action is being initiated,
    // expect another reply before proceeding with a new command
    sfFtpRestartMarkerReply          = 110, ///< Restart marker reply
    sfFtpServiceReadySoon            = 120, ///< Service ready in N minutes
    sfFtpDataConnectionAlreadyOpened = 125, ///< Data connection already opened, transfer starting
    sfFtpOpeningDataConnection       = 150, ///< File status ok, about to open data connection

    // 2xx: the requested action has been successfully completed
    sfFtpOk                    = 200, ///< Command ok
    sfFtpPointlessCommand      = 202, ///< Command not implemented
    sfFtpSystemStatus          = 211, ///< System status, or system help reply
    sfFtpDirectoryStatus       = 212, ///< Directory status
    sfFtpFileStatus            = 213, ///< File status
    sfFtpHelpMessage           = 214, ///< Help message
    sfFtpSystemType            = 215, ///< NAME system type, where NAME is an official system name from the list in the Assigned Numbers document
    sfFtpServiceReady          = 220, ///< Service ready for new user
    sfFtpClosingConnection     = 221, ///< Service closing control connection
    sfFtpDataConnectionOpened  = 225, ///< Data connection open, no transfer in progress
    sfFtpClosingDataConnection = 226, ///< Closing data connection, requested file action successful
    sfFtpEnteringPassiveMode   = 227, ///< Entering passive mode
    sfFtpLoggedIn              = 230, ///< User logged in, proceed. Logged out if appropriate
    sfFtpFileActionOk          = 250, ///< Requested file action ok
    sfFtpDirectoryOk           = 257, ///< PATHNAME created

    // 3xx: the command has been accepted, but the requested action
    // is dormant, pending receipt of further information
    sfFtpNeedPassword       = 331, ///< User name ok, need password
    sfFtpNeedAccountToLogIn = 332, ///< Need account for login
    sfFtpNeedInformation    = 350, ///< Requested file action pending further information

    // 4xx: the command was not accepted and the requested action did not take place,
    // but the error condition is temporary and the action may be requested again
    sfFtpServiceUnavailable        = 421, ///< Service not available, closing control connection
    sfFtpDataConnectionUnavailable = 425, ///< Can't open data connection
    sfFtpTransferAborted           = 426, ///< Connection closed, transfer aborted
    sfFtpFileActionAborted         = 450, ///< Requested file action not taken
    sfFtpLocalError                = 451, ///< Requested action aborted, local error in processing
    sfFtpInsufficientStorageSpace  = 452, ///< Requested action not taken; insufficient storage space in system, file unavailable

    // 5xx: the command was not accepted and
    // the requested action did not take place
    sfFtpCommandUnknown          = 500, ///< Syntax error, command unrecognized
    sfFtpParametersUnknown       = 501, ///< Syntax error in parameters or arguments
    sfFtpCommandNotImplemented   = 502, ///< Command not implemented
    sfFtpBadCommandSequence      = 503, ///< Bad sequence of commands
    sfFtpParameterNotImplemented = 504, ///< Command not implemented for that parameter
    sfFtpNotLoggedIn             = 530, ///< Not logged in
    sfFtpNeedAccountToStore      = 532, ///< Need account for storing files
    sfFtpFileUnavailable         = 550, ///< Requested action not taken, file unavailable
    sfFtpPageTypeUnknown         = 551, ///< Requested action aborted, page type unknown
    sfFtpNotEnoughMemory         = 552, ///< Requested file action aborted, exceeded storage allocation
    sfFtpFilenameNotAllowed      = 553, ///< Requested action not taken, file name not allowed

    // 10xx: SFML custom codes
    sfFtpInvalidResponse  = 1000, ///< Response is not a valid FTP one
    sfFtpConnectionFailed = 1001, ///< Connection with server failed
    sfFtpConnectionClosed = 1002, ///< Connection with server closed
    sfFtpInvalidFile      = 1003  ///< Invalid file to upload / download
} sfFtpStatus;


////////////////////////////////////////////////////////////
/// \brief Destroy a FTP listing response
///
/// \param ftpListingResponse Ftp listing response to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfFtpListingResponse_destroy(sfFtpListingResponse* ftpListingResponse);

////////////////////////////////////////////////////////////
/// \brief Check if a FTP listing response status code means a success
///
/// This function is defined for convenience, it is
/// equivalent to testing if the status code is < 400.
///
/// \param ftpListingResponse Ftp listing response
///
/// \return sfTrue if the status is a success, sfFalse if it is a failure
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfFtpListingResponse_isOk(const sfFtpListingResponse* ftpListingResponse);

////////////////////////////////////////////////////////////
/// \brief Get the status code of a FTP listing response
///
/// \param ftpListingResponse Ftp listing response
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpStatus sfFtpListingResponse_getStatus(const sfFtpListingResponse* ftpListingResponse);

////////////////////////////////////////////////////////////
/// \brief Get the full message contained in a FTP listing response
///
/// \param ftpListingResponse Ftp listing response
///
/// \return The response message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfFtpListingResponse_getMessage(const sfFtpListingResponse* ftpListingResponse);

////////////////////////////////////////////////////////////
/// \brief Return the number of directory/file names contained in a FTP listing response
///
/// \param ftpListingResponse Ftp listing response
///
/// \return Total number of names available
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfFtpListingResponse_getCount(const sfFtpListingResponse* ftpListingResponse);

////////////////////////////////////////////////////////////
/// \brief Return a directory/file name contained in a FTP listing response
///
/// \param ftpListingResponse Ftp listing response
/// \param index              Index of the name to get (in range [0 .. getCount])
///
/// \return The requested name
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfFtpListingResponse_getName(const sfFtpListingResponse* ftpListingResponse, size_t index);

////////////////////////////////////////////////////////////
/// \brief Destroy a FTP directory response
///
/// \param ftpDirectoryResponse Ftp directory response to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfFtpDirectoryResponse_destroy(sfFtpDirectoryResponse* ftpDirectoryResponse);

////////////////////////////////////////////////////////////
/// \brief Check if a FTP directory response status code means a success
///
/// This function is defined for convenience, it is
/// equivalent to testing if the status code is < 400.
///
/// \param ftpDirectoryResponse Ftp directory response
///
/// \return sfTrue if the status is a success, sfFalse if it is a failure
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfFtpDirectoryResponse_isOk(const sfFtpDirectoryResponse* ftpDirectoryResponse);

////////////////////////////////////////////////////////////
/// \brief Get the status code of a FTP directory response
///
/// \param ftpDirectoryResponse Ftp directory response
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpStatus sfFtpDirectoryResponse_getStatus(const sfFtpDirectoryResponse* ftpDirectoryResponse);

////////////////////////////////////////////////////////////
/// \brief Get the full message contained in a FTP directory response
///
/// \param ftpDirectoryResponse Ftp directory response
///
/// \return The response message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfFtpDirectoryResponse_getMessage(const sfFtpDirectoryResponse* ftpDirectoryResponse);

////////////////////////////////////////////////////////////
/// \brief Get the directory returned in a FTP directory response
///
/// \param ftpDirectoryResponse Ftp directory response
///
/// \return Directory name
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfFtpDirectoryResponse_getDirectory(const sfFtpDirectoryResponse* ftpDirectoryResponse);


////////////////////////////////////////////////////////////
/// \brief Destroy a FTP response
///
/// \param ftpResponse Ftp response to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfFtpResponse_destroy(sfFtpResponse* ftpResponse);

////////////////////////////////////////////////////////////
/// \brief Check if a FTP response status code means a success
///
/// This function is defined for convenience, it is
/// equivalent to testing if the status code is < 400.
///
/// \param ftpResponse Ftp response object
///
/// \return sfTrue if the status is a success, sfFalse if it is a failure
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfBool sfFtpResponse_isOk(const sfFtpResponse* ftpResponse);

////////////////////////////////////////////////////////////
/// \brief Get the status code of a FTP response
///
/// \param ftpResponse Ftp response object
///
/// \return Status code
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpStatus sfFtpResponse_getStatus(const sfFtpResponse* ftpResponse);

////////////////////////////////////////////////////////////
/// \brief Get the full message contained in a FTP response
///
/// \param ftpResponse Ftp response object
///
/// \return The response message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfFtpResponse_getMessage(const sfFtpResponse* ftpResponse);

////////////////////////////////////////////////////////////
/// \brief Create a new Ftp object
///
/// \return A new sfFtp object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtp* sfFtp_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy a Ftp object
///
/// \param ftp Ftp object to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfFtp_destroy(sfFtp* ftp);

////////////////////////////////////////////////////////////
/// \brief Connect to the specified FTP server
///
/// The port should be 21, which is the standard
/// port used by the FTP protocol. You shouldn't use a different
/// value, unless you really know what you do.
/// This function tries to connect to the server so it may take
/// a while to complete, especially if the server is not
/// reachable. To avoid blocking your application for too long,
/// you can use a timeout. Using 0 means that the
/// system timeout will be used (which is usually pretty long).
///
/// \param ftp     Ftp object
/// \param server  Name or address of the FTP server to connect to
/// \param port    Port used for the connection
/// \param timeout Maximum time to wait
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_connect(sfFtp* ftp, sfIpAddress server, unsigned short port, sfTime timeout);

////////////////////////////////////////////////////////////
/// \brief Log in using an anonymous account
///
/// Logging in is mandatory after connecting to the server.
/// Users that are not logged in cannot perform any operation.
///
/// \param ftp Ftp object
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_loginAnonymous(sfFtp* ftp);

////////////////////////////////////////////////////////////
/// \brief Log in using a username and a password
///
/// Logging in is mandatory after connecting to the server.
/// Users that are not logged in cannot perform any operation.
///
/// \param ftp      Ftp object
/// \param name     User name
/// \param password Password
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_login(sfFtp* ftp, const char* name, const char* password);

////////////////////////////////////////////////////////////
/// \brief Close the connection with the server
///
/// \param ftp Ftp object
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_disconnect(sfFtp* ftp);

////////////////////////////////////////////////////////////
/// \brief Send a null command to keep the connection alive
///
/// This command is useful because the server may close the
/// connection automatically if no command is sent.
///
/// \param ftp Ftp object
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_keepAlive(sfFtp* ftp);

////////////////////////////////////////////////////////////
/// \brief Get the current working directory
///
/// The working directory is the root path for subsequent
/// operations involving directories and/or filenames.
///
/// \param ftp Ftp object
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpDirectoryResponse* sfFtp_getWorkingDirectory(sfFtp* ftp);

////////////////////////////////////////////////////////////
/// \brief Get the contents of the given directory
///
/// This function retrieves the sub-directories and files
/// contained in the given directory. It is not recursive.
/// The \a directory parameter is relative to the current
/// working directory.
///
/// \param ftp       Ftp object
/// \param directory Directory to list
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpListingResponse* sfFtp_getDirectoryListing(sfFtp* ftp, const char* directory);

////////////////////////////////////////////////////////////
/// \brief Change the current working directory
///
/// The new directory must be relative to the current one.
///
/// \param ftp       Ftp object
/// \param directory New working directory
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_changeDirectory(sfFtp* ftp, const char* directory);

////////////////////////////////////////////////////////////
/// \brief Go to the parent directory of the current one
///
/// \param ftp Ftp object
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_parentDirectory(sfFtp* ftp);

////////////////////////////////////////////////////////////
/// \brief Create a new directory
///
/// The new directory is created as a child of the current
/// working directory.
///
/// \param ftp  Ftp object
/// \param name Name of the directory to create
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_createDirectory(sfFtp* ftp, const char* name);

////////////////////////////////////////////////////////////
/// \brief Remove an existing directory
///
/// The directory to remove must be relative to the
/// current working directory.
/// Use this function with caution, the directory will
/// be removed permanently!
///
/// \param ftp  Ftp object
/// \param name Name of the directory to remove
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_deleteDirectory(sfFtp* ftp, const char* name);

////////////////////////////////////////////////////////////
/// \brief Rename an existing file
///
/// The filenames must be relative to the current working
/// directory.
///
/// \param ftp     Ftp object
/// \param file    File to rename
/// \param newName New name of the file
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_renameFile(sfFtp* ftp, const char* file, const char* newName);

////////////////////////////////////////////////////////////
/// \brief Remove an existing file
///
/// The file name must be relative to the current working
/// directory.
/// Use this function with caution, the file will be
/// removed permanently!
///
/// \param ftp  Ftp object
/// \param name File to remove
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_deleteFile(sfFtp* ftp, const char* name);

////////////////////////////////////////////////////////////
/// \brief Download a file from a FTP server
///
/// The filename of the distant file is relative to the
/// current working directory of the server, and the local
/// destination path is relative to the current directory
/// of your application.
///
/// \param ftp        Ftp object
/// \param remoteFile Filename of the distant file to download
/// \param localPath  Where to put to file on the local computer
/// \param mode       Transfer mode
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_download(sfFtp* ftp, const char* remoteFile, const char* localPath, sfFtpTransferMode mode);

////////////////////////////////////////////////////////////
/// \brief Upload a file to a FTP server
///
/// The name of the local file is relative to the current
/// working directory of your application, and the
/// remote path is relative to the current directory of the
/// FTP server.
///
/// \param ftp        Ftp object
/// \param localFile  Path of the local file to upload
/// \param remotePath Where to put to file on the server
/// \param mode       Transfer mode
/// \param append     Pass sfTrue to append to or sfFalse to overwrite the remote file if it already exists
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_upload(sfFtp* ftp, const char* localFile, const char* remotePath, sfFtpTransferMode mode, sfBool append);

////////////////////////////////////////////////////////////
/// \brief Send a command to the FTP server
///
/// While the most often used commands are provided as
/// specific functions, this function can be used to send
/// any FTP command to the server. If the command requires
/// one or more parameters, they can be specified in
/// \a parameter. Otherwise you should pass NULL.
/// If the server returns information, you can extract it
/// from the response using sfResponse_getMessage().
///
/// \param ftp       Ftp object
/// \param command   Command to send
/// \param parameter Command parameter
///
/// \return Server response to the request
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfFtpResponse* sfFtp_sendCommand(sfFtp* ftp, const char* command, const char* parameter);


#endif // SFML_FTP_H
