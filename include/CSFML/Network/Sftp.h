////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2026 Laurent Gomila (laurent@sfml-dev.org)
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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Network/Export.h>

#include <CSFML/Network/IpAddress.h>
#include <CSFML/Network/Types.h>
#include <CSFML/System/TimeoutWithPredicate.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


////////////////////////////////////////////////////////////
/// \brief Values of a SFTP result
///
////////////////////////////////////////////////////////////
typedef enum
{
    // General result values
    sfSftpSuccess,      ///< Operation completed successfully
    sfSftpDisconnected, ///< The TCP socket has been disconnected
    sfSftpTimeout,      ///< Operation timed out
    sfSftpRefused,      ///< Connection refused
    sfSftpError,        ///< Generic error

    // SSH result values
    sfSftpBannerReceive,               ///< Error during banner receive
    sfSftpBannerSend,                  ///< Error during banner send
    sfSftpInvalidMac,                  ///< Invalid message authentication code
    sfSftpAllocationFailure,           ///< Allocation failure
    sfSftpSocketSend,                  ///< Error sending on socket
    sfSftpKeyExchangeFailure,          ///< Key exchange failed
    sfSftpHostKeyInitialization,       ///< Host key initialization failed
    sfSftpHostKeySign,                 ///< Host key signing failed
    sfSftpDecryptError,                ///< Decryption failed
    sfSftpProtocolError,               ///< SSH protocol error
    sfSftpPasswordExpired,             ///< Password expired
    sfSftpFileError,                   ///< File error
    sfSftpMethodNone,                  ///< No method found
    sfSftpAuthenticationFailed,        ///< Authentication failed
    sfSftpPublicKeyUnverified,         ///< Public key unverified
    sfSftpChannelOutOfOrder,           ///< Channel out of order
    sfSftpChannelFailure,              ///< Channel failure
    sfSftpChannelRequestDenied,        ///< Channel request denied
    sfSftpChannelUnknown,              ///< Channel unknown
    sfSftpChannelWindowExceeded,       ///< Channel window exceeded
    sfSftpChannelPacketExceeded,       ///< Channel packet exceeded
    sfSftpChannelClosed,               ///< Channel closed
    sfSftpChannelEofSent,              ///< Channel EOF sent
    sfSftpScpProtocol,                 ///< SCP protocol error
    sfSftpZlibError,                   ///< Zlib error
    sfSftpRequestDenied,               ///< Request denied
    sfSftpMethodNotSupported,          ///< Method not supported
    sfSftpInvalidData,                 ///< Invalid data
    sfSftpPublicKeyProtocol,           ///< Public key protocol error
    sfSftpBufferTooSmall,              ///< Buffer too small
    sfSftpBadUse,                      ///< Bad usage
    sfSftpCompressError,               ///< Compression error
    sfSftpOutOfBoundary,               ///< Out of boundary
    sfSftpAgentProtocol,               ///< Agent protocol error
    sfSftpSocketRecv,                  ///< Socket receive error
    sfSftpEncryptError,                ///< Encryption failed
    sfSftpBadSocket,                   ///< Bad socket
    sfSftpKnownHosts,                  ///< Known hosts error
    sfSftpChannelWindowFull,           ///< Channel window full
    sfSftpKeyFileAuthenticationFailed, ///< Key file authentication failed

    // SFTP result values
    sfSftpEndOfFile,            ///< End of file
    sfSftpNoSuchFile,           ///< No such file
    sfSftpPermissionDenied,     ///< Permission denied
    sfSftpFailure,              ///< Failure
    sfSftpBadMessage,           ///< Bad message
    sfSftpNoConnection,         ///< No connection
    sfSftpConnectionLost,       ///< Connection lost
    sfSftpOperationUnsupported, ///< Operation unsupported
    sfSftpInvalidHandle,        ///< Invalid handle
    sfSftpNoSuchPath,           ///< No such path
    sfSftpFileAlreadyExists,    ///< File already exists
    sfSftpWriteProtect,         ///< Write protect
    sfSftpNoMedia,              ///< No media
    sfSftpNoSpaceOnFileSystem,  ///< No space on filesystem
    sfSftpQuotaExceeded,        ///< Quota exceeded
    sfSftpUnknownPrincipal,     ///< Unknown principal
    sfSftpLockConflict,         ///< Lock conflict
    sfSftpDirectoryNotEmpty,    ///< Directory not empty
    sfSftpNotADirectory,        ///< Not a directory
    sfSftpInvalidFilename,      ///< Invalid filename
    sfSftpLinkLoop,             ///< Link loop
    sfSftpSftpError             ///< Generic SFTP error
} sfSftpResultValue;

////////////////////////////////////////////////////////////
/// \brief Type of a remote file system entry
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfSftpFileNone,      ///< No type
    sfSftpFileNotFound,  ///< The file does not exist
    sfSftpFileRegular,   ///< Regular file
    sfSftpFileDirectory, ///< Directory
    sfSftpFileSymlink,   ///< Symbolic link
    sfSftpFileBlock,     ///< Block special file
    sfSftpFileCharacter, ///< Character special file
    sfSftpFileFifo,      ///< FIFO or pipe
    sfSftpFileSocket,    ///< Socket
    sfSftpFileUnknown    ///< Unknown type
} sfSftpFileType;

////////////////////////////////////////////////////////////
/// \brief Attributes of a remote file system entry
///
/// Each attribute is only valid if the corresponding
/// has-flag is set.
///
/// Permissions use the POSIX permission bits, e.g. 0755.
/// Times are given in seconds since the Unix epoch.
///
////////////////////////////////////////////////////////////
typedef struct
{
    const char*    path;                ///< Path to the entry, encoded in UTF-8
    uint64_t       size;                ///< Size of the entry
    uint64_t       userId;              ///< Owner user ID
    uint64_t       groupId;             ///< Group ID
    int64_t        accessTime;          ///< Last access time
    int64_t        modificationTime;    ///< Last modification time
    sfSftpFileType type;                ///< Type of the entry
    uint32_t       permissions;         ///< Permissions
    bool           hasType;             ///< Whether the type is available
    bool           hasSize;             ///< Whether the size is available
    bool           hasPermissions;      ///< Whether the permissions are available
    bool           hasUserId;           ///< Whether the owner user ID is available
    bool           hasGroupId;          ///< Whether the group ID is available
    bool           hasAccessTime;       ///< Whether the last access time is available
    bool           hasModificationTime; ///< Whether the last modification time is available
} sfSftpAttributes;

////////////////////////////////////////////////////////////
/// \brief Type of a SSH host key
///
////////////////////////////////////////////////////////////
typedef enum
{
    sfSftpHostKeyUnknown,  ///< Unknown key type
    sfSftpHostKeyRsa,      ///< RSA
    sfSftpHostKeyDsa,      ///< DSA
    sfSftpHostKeyEcdsa256, ///< NIST P-256 ECDSA
    sfSftpHostKeyEcdsa384, ///< NIST P-384 ECDSA
    sfSftpHostKeyEcdsa521, ///< NIST P-521 ECDSA
    sfSftpHostKeyEd25519   ///< ED25519
} sfSftpHostKeyType;

////////////////////////////////////////////////////////////
/// \brief SSH session information
///
/// The algorithm identifiers follow the RFC 4253 specification.
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfSftpHostKeyType hostKeyType;                       ///< Host key type
    const uint8_t*    hostKeyData;                       ///< Host key data
    size_t            hostKeySize;                       ///< Size of the host key data
    uint8_t           hostKeySha1[20];                   ///< Host key SHA1 hash
    uint8_t           hostKeySha256[32];                 ///< Host key SHA256 hash
    const char*       keyExchangeAlgorithm;              ///< Key exchange algorithm used in the session
    const char*       hostKeyAlgorithm;                  ///< Host key algorithm used in the session
    const char*       clientToServerEncryptionAlgorithm; ///< Client to server encryption algorithm used in the session
    const char*       serverToClientEncryptionAlgorithm; ///< Server to client encryption algorithm used in the session
    const char* clientToServerMacAlgorithm; ///< Client to server message authentication code algorithm used in the session
    const char* serverToClientMacAlgorithm; ///< Server to client message authentication code algorithm used in the session
    const char* clientToServerCompressionAlgorithm; ///< Client to server compression algorithm used in the session
    const char* serverToClientCompressionAlgorithm; ///< Server to client compression algorithm used in the session
} sfSftpSessionInfo;

////////////////////////////////////////////////////////////
/// \brief Callback receiving the data of a downloaded file
///
/// The data is transferred in sequential blocks. The size of
/// the blocks can change over time.
///
/// \param data     Pointer to the received data block
/// \param size     Size of the received data block
/// \param userData User data passed to sfSftp_download
///
/// \return True to continue the transfer, false to abort it
///
////////////////////////////////////////////////////////////
typedef bool (*sfSftpDownloadCallback)(const void* data, size_t size, void* userData);

////////////////////////////////////////////////////////////
/// \brief Callback providing the data of a file to upload
///
/// Data to be sent should be copied into the data block and
/// \a size set to the actual number of bytes copied. When
/// called, \a size contains the size of the data block, which
/// can change over time.
///
/// \param data     Pointer to the data block to fill
/// \param size     Size of the data block, to be set to the number of bytes copied
/// \param userData User data passed to sfSftp_upload
///
/// \return True to continue the transfer, false to stop it e.g. because there is no more data to send
///
////////////////////////////////////////////////////////////
typedef bool (*sfSftpUploadCallback)(void* data, size_t* size, void* userData);


////////////////////////////////////////////////////////////
/// \brief Destroy a SFTP result
///
/// \param result SFTP result to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSftpResult_destroy(const sfSftpResult* result);

////////////////////////////////////////////////////////////
/// \brief Check if a SFTP result is a success
///
/// \param result SFTP result
///
/// \return True if the result is sfSftpSuccess
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSftpResult_isOk(const sfSftpResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the value of a SFTP result
///
/// \param result SFTP result
///
/// \return Result value
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResultValue sfSftpResult_getValue(const sfSftpResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the message of a SFTP result
///
/// \param result SFTP result
///
/// \return The result message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfSftpResult_getMessage(const sfSftpResult* result);

////////////////////////////////////////////////////////////
/// \brief Destroy a SFTP path result
///
/// \param result SFTP path result to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSftpPathResult_destroy(const sfSftpPathResult* result);

////////////////////////////////////////////////////////////
/// \brief Check if a SFTP path result is a success
///
/// \param result SFTP path result
///
/// \return True if the result is sfSftpSuccess
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSftpPathResult_isOk(const sfSftpPathResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the value of a SFTP path result
///
/// \param result SFTP path result
///
/// \return Result value
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResultValue sfSftpPathResult_getValue(const sfSftpPathResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the message of a SFTP path result
///
/// \param result SFTP path result
///
/// \return The result message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfSftpPathResult_getMessage(const sfSftpPathResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the path of a SFTP path result
///
/// \param result SFTP path result
///
/// \return The path, encoded in UTF-8
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfSftpPathResult_getPath(const sfSftpPathResult* result);

////////////////////////////////////////////////////////////
/// \brief Destroy a SFTP attributes result
///
/// \param result SFTP attributes result to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSftpAttributesResult_destroy(const sfSftpAttributesResult* result);

////////////////////////////////////////////////////////////
/// \brief Check if a SFTP attributes result is a success
///
/// \param result SFTP attributes result
///
/// \return True if the result is sfSftpSuccess
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSftpAttributesResult_isOk(const sfSftpAttributesResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the value of a SFTP attributes result
///
/// \param result SFTP attributes result
///
/// \return Result value
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResultValue sfSftpAttributesResult_getValue(const sfSftpAttributesResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the message of a SFTP attributes result
///
/// \param result SFTP attributes result
///
/// \return The result message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfSftpAttributesResult_getMessage(const sfSftpAttributesResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the attributes of a SFTP attributes result
///
/// The strings of the attributes stay valid until the
/// result is destroyed.
///
/// \param result SFTP attributes result
///
/// \return The attributes
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpAttributes sfSftpAttributesResult_getAttributes(const sfSftpAttributesResult* result);

////////////////////////////////////////////////////////////
/// \brief Destroy a SFTP listing result
///
/// \param result SFTP listing result to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSftpListingResult_destroy(const sfSftpListingResult* result);

////////////////////////////////////////////////////////////
/// \brief Check if a SFTP listing result is a success
///
/// \param result SFTP listing result
///
/// \return True if the result is sfSftpSuccess
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSftpListingResult_isOk(const sfSftpListingResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the value of a SFTP listing result
///
/// \param result SFTP listing result
///
/// \return Result value
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResultValue sfSftpListingResult_getValue(const sfSftpListingResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the message of a SFTP listing result
///
/// \param result SFTP listing result
///
/// \return The result message
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const char* sfSftpListingResult_getMessage(const sfSftpListingResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the number of entries in a SFTP listing result
///
/// \param result SFTP listing result
///
/// \return Number of directory entries
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfSftpListingResult_getCount(const sfSftpListingResult* result);

////////////////////////////////////////////////////////////
/// \brief Get the attributes of an entry in a SFTP listing result
///
/// The strings of the attributes stay valid until the
/// result is destroyed.
///
/// \param result SFTP listing result
/// \param index  Index of the entry to get
///
/// \return The attributes of the entry
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpAttributes sfSftpListingResult_getAttributes(const sfSftpListingResult* result, size_t index);

////////////////////////////////////////////////////////////
/// \brief Create a new SFTP object
///
/// \return A new sfSftp object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftp* sfSftp_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing SFTP object
///
/// \param sftp SFTP object to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfSftp_destroy(const sfSftp* sftp);

////////////////////////////////////////////////////////////
/// \brief Connect to the specified SFTP server
///
/// \param sftp    SFTP object
/// \param server  Address of the server to connect to
/// \param port    Port used for the connection, the default SFTP port is 22
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of the connection attempt
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_connect(sfSftp* sftp, sfIpAddress server, unsigned short port, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Disconnect the connection with the server
///
/// \param sftp    SFTP object
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of disconnecting the connection with the server
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_disconnect(sfSftp* sftp, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Get SSH session information
///
/// After connecting to the server and before actually
/// logging in the SSH session information of the underlying
/// connection will be available.
///
/// The session information contains among other things the
/// public key identifying the remote host and the connection
/// parameters such as encryption and compression used.
///
/// Relying on the user to check the authenticity of the host
/// key is the typical method used to verify the connection
/// to the legitimate host. If connection security is a high
/// priority, examining the parameters and aborting the
/// connection if any weak algorithms are used is also possible.
///
/// The pointers in the session information stay valid until
/// the next call to this function or until the SFTP object
/// is destroyed.
///
/// \param sftp SFTP object
/// \param info Session information to fill
///
/// \return True if the session information is available, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfSftp_getSessionInfo(const sfSftp* sftp, sfSftpSessionInfo* info);

////////////////////////////////////////////////////////////
/// \brief Log in using a username and a password
///
/// Logging in is mandatory after connecting to the server.
/// Users that are not logged in cannot perform any operation.
///
/// \param sftp     SFTP object
/// \param name     User name
/// \param password Password
/// \param timeout  Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of attempting to log in to the server
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_login(sfSftp* sftp, const char* name, const char* password, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Log in using a public/private key pair
///
/// Logging in is mandatory after connecting to the server.
/// Users that are not logged in cannot perform any operation.
///
/// The public and private key data should be provided in PEM
/// format. Even though it is technically possible to derive
/// the public key from the private key, due to backend
/// limitations, providing a pre-generated public key as well
/// is necessary for this function to be able to succeed.
///
/// If the private key is not protected by a passphrase the
/// passphrase should be set to the empty string or NULL.
///
/// \param sftp                 SFTP object
/// \param name                 User name
/// \param publicKeyData        Public key data
/// \param publicKeyLength      Public key data length
/// \param privateKeyData       Private key data
/// \param privateKeyLength     Private key data length
/// \param privateKeyPassphrase Private key passphrase, NULL terminated
/// \param timeout              Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of attempting to log in to the server
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_loginWithKey(
    sfSftp*                sftp,
    const char*            name,
    const char*            publicKeyData,
    size_t                 publicKeyLength,
    const char*            privateKeyData,
    size_t                 privateKeyLength,
    const char*            privateKeyPassphrase,
    sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Resolve a remote path into an absolute remote path
///
/// Paths can contain links and other reserved path identifiers
/// such as . and .. referring to the current directory and
/// parent directory respectively. This function determines
/// the absolute path, which does not contain links or . or ..
///
/// Resolving "." will return the absolute path to the current
/// working directory of the user after logging in to the SFTP
/// server.
///
/// \param sftp    SFTP object
/// \param path    Path to convert into an absolute path, encoded in UTF-8
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of converting the path into an absolute path
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpPathResult* sfSftp_resolvePath(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Get the current working directory on the server
///
/// This is an alias for calling sfSftp_resolvePath with ".".
///
/// \param sftp    SFTP object
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of getting the current working directory
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpPathResult* sfSftp_getWorkingDirectory(sfSftp* sftp, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Get the attributes of a remote file or directory
///
/// Depending on whether \a path refers to a file or directory,
/// the attributes can contain e.g. the type of file, the file
/// owner, group, file size, modification and access times.
///
/// If links are not to be followed, \a followLinks can be set
/// to false. In this case the attributes of the link itself
/// will be returned.
///
/// \param sftp        SFTP object
/// \param path        Path to the remote file or directory whose attributes to get, encoded in UTF-8
/// \param followLinks True to follow links, false to return attributes of the link itself
/// \param timeout     Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of getting the attributes
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpAttributesResult* sfSftp_getAttributes(
    sfSftp*                sftp,
    const char*            path,
    bool                   followLinks,
    sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Get the contents of the given directory
///
/// This function retrieves the sub-directories and files
/// contained in the given directory. It is not recursive.
///
/// \param sftp    SFTP object
/// \param path    Path of the directory whose contents to list, encoded in UTF-8
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of getting the contents of the given directory
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpListingResult* sfSftp_getDirectoryListing(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Create a new directory
///
/// The new directory is created as a child of the current
/// working directory.
///
/// A common permissions value is 0755 (rwxr-xr-x).
///
/// \param sftp        SFTP object
/// \param path        Path of the directory to create, encoded in UTF-8
/// \param permissions POSIX permissions of the directory to create
/// \param timeout     Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of creating the directory
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_createDirectory(sfSftp*                sftp,
                                                       const char*            path,
                                                       uint32_t               permissions,
                                                       sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Remove an existing directory
///
/// Use this function with caution, the directory will
/// be removed permanently!
///
/// \param sftp    SFTP object
/// \param path    Path of the directory to remove, encoded in UTF-8
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of removing the directory
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_deleteDirectory(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Rename an existing file or directory
///
/// In POSIX renaming and moving are synonymous. If you want
/// to move a file or directory from one place to another
/// you rename it from an old to a new path.
///
/// If a file exists at the specified new path, depending
/// on whether \a overwrite is set to true, the rename operation
/// will overwrite it or not. Non-empty directories cannot be
/// overwritten by this operation.
///
/// \param sftp      SFTP object
/// \param oldPath   Old path to the file or directory, encoded in UTF-8
/// \param newPath   New path to the file or directory, encoded in UTF-8
/// \param overwrite True to allow overwriting a file that exists at \a newPath
/// \param timeout   Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of the operation
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_rename(
    sfSftp*                sftp,
    const char*            oldPath,
    const char*            newPath,
    bool                   overwrite,
    sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Remove an existing file
///
/// Use this function with caution, the file will be
/// removed permanently!
///
/// \param sftp    SFTP object
/// \param path    Path to the file to remove, encoded in UTF-8
/// \param timeout Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of removing the file
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_deleteFile(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Download a file from the server
///
/// The file data is transferred in sequential blocks. For
/// every block of data transferred, the provided callback
/// is called.
///
/// The function returns once all the data in the remote file
/// has been transferred or an error occurs or the function
/// times out.
///
/// \param sftp       SFTP object
/// \param remotePath Path of the remote file whose data to download, encoded in UTF-8
/// \param callback   Callback to be called for every available data block
/// \param userData   User data that will be passed to the callback
/// \param offset     Byte offset into the remote file at which reading should start
/// \param timeout    Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of downloading the file
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_download(
    sfSftp*                sftp,
    const char*            remotePath,
    sfSftpDownloadCallback callback,
    void*                  userData,
    uint64_t               offset,
    sfTimeoutWithPredicate timeout);

////////////////////////////////////////////////////////////
/// \brief Upload a file to the server
///
/// The file data is transferred in sequential blocks. Every
/// time the function wants to send a new block of data the
/// provided callback is called.
///
/// The function returns once all the data has been sent or
/// an error occurs or the function times out.
///
/// If a file does not exist at the remote path yet, it will
/// be created with the provided permissions. A common
/// permissions value is 0644 (rw-r--r--).
///
/// \param sftp        SFTP object
/// \param remotePath  Path of the remote file in which to upload the data, encoded in UTF-8
/// \param callback    Callback to be called for every data block to send
/// \param userData    User data that will be passed to the callback
/// \param permissions POSIX permissions of the remote file if it has to be created
/// \param truncate    True to truncate the remote file if it already exists
/// \param append      True to append to the remote file if it already exists
/// \param offset      Byte offset into the remote file at which writing should start
/// \param timeout     Maximum time to wait, optionally a predicate can be provided for more fine-grained control
///
/// \return Result of uploading the file
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfSftpResult* sfSftp_upload(
    sfSftp*                sftp,
    const char*            remotePath,
    sfSftpUploadCallback   callback,
    void*                  userData,
    uint32_t               permissions,
    bool                   truncate,
    bool                   append,
    uint64_t               offset,
    sfTimeoutWithPredicate timeout);
