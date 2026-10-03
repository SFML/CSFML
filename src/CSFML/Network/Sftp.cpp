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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/Network/ConvertIpAddress.hpp>
#include <CSFML/Network/Sftp.h>
#include <CSFML/Network/SftpStruct.hpp>
#include <CSFML/System/ConvertTimeoutWithPredicate.hpp>

#include <algorithm>
#include <cassert>
#include <chrono>
#include <filesystem>


namespace
{
////////////////////////////////////////////////////////////
[[nodiscard]] std::filesystem::path toPath(const char* path)
{
    return std::filesystem::u8path(path ? path : "");
}


////////////////////////////////////////////////////////////
[[nodiscard]] std::string fromPath(const std::filesystem::path& path)
{
    const auto string = path.u8string();
    return {string.begin(), string.end()};
}


////////////////////////////////////////////////////////////
[[nodiscard]] sfSftpFileType convertFileType(std::filesystem::file_type type)
{
    switch (type)
    {
        case std::filesystem::file_type::none:
            return sfSftpFileNone;
        case std::filesystem::file_type::not_found:
            return sfSftpFileNotFound;
        case std::filesystem::file_type::regular:
            return sfSftpFileRegular;
        case std::filesystem::file_type::directory:
            return sfSftpFileDirectory;
        case std::filesystem::file_type::symlink:
            return sfSftpFileSymlink;
        case std::filesystem::file_type::block:
            return sfSftpFileBlock;
        case std::filesystem::file_type::character:
            return sfSftpFileCharacter;
        case std::filesystem::file_type::fifo:
            return sfSftpFileFifo;
        case std::filesystem::file_type::socket:
            return sfSftpFileSocket;
        default:
            return sfSftpFileUnknown;
    }
}


////////////////////////////////////////////////////////////
// SFML stores the seconds since the Unix epoch in the file time
[[nodiscard]] std::int64_t convertFileTime(std::filesystem::file_time_type time)
{
    return std::chrono::duration_cast<std::chrono::seconds>(time.time_since_epoch()).count();
}


////////////////////////////////////////////////////////////
[[nodiscard]] sfSftpAttributes convertAttributes(const sf::Sftp::Attributes& attributes, const std::string& path)
{
    sfSftpAttributes result{};
    result.path = path.c_str();

    if (attributes.type)
    {
        result.hasType = true;
        result.type    = convertFileType(*attributes.type);
    }

    if (attributes.size)
    {
        result.hasSize = true;
        result.size    = *attributes.size;
    }

    if (attributes.permissions)
    {
        result.hasPermissions = true;
        result.permissions    = static_cast<std::uint32_t>(*attributes.permissions);
    }

    if (attributes.userId)
    {
        result.hasUserId = true;
        result.userId    = *attributes.userId;
    }

    if (attributes.groupId)
    {
        result.hasGroupId = true;
        result.groupId    = *attributes.groupId;
    }

    if (attributes.accessTime)
    {
        result.hasAccessTime = true;
        result.accessTime    = convertFileTime(*attributes.accessTime);
    }

    if (attributes.modificationTime)
    {
        result.hasModificationTime = true;
        result.modificationTime    = convertFileTime(*attributes.modificationTime);
    }

    return result;
}


////////////////////////////////////////////////////////////
[[nodiscard]] sfSftpResult* createResult(const sf::Sftp::Result& result)
{
    return new sfSftpResult{result};
}


////////////////////////////////////////////////////////////
[[nodiscard]] sfSftpPathResult* createResult(const sf::Sftp::PathResult& result)
{
    return new sfSftpPathResult{result, fromPath(result.getPath())};
}


////////////////////////////////////////////////////////////
[[nodiscard]] sfSftpAttributesResult* createResult(const sf::Sftp::AttributesResult& result)
{
    return new sfSftpAttributesResult{result, fromPath(result.getAttributes().path)};
}


////////////////////////////////////////////////////////////
[[nodiscard]] sfSftpListingResult* createResult(const sf::Sftp::ListingResult& result)
{
    std::vector<std::string> paths;
    paths.reserve(result.getListing().size());
    for (const auto& attributes : result.getListing())
        paths.push_back(fromPath(attributes.path));

    return new sfSftpListingResult{result, std::move(paths)};
}
} // namespace


////////////////////////////////////////////////////////////
void sfSftpResult_destroy(const sfSftpResult* result)
{
    delete result;
}


////////////////////////////////////////////////////////////
bool sfSftpResult_isOk(const sfSftpResult* result)
{
    assert(result);
    return result->isOk();
}


////////////////////////////////////////////////////////////
sfSftpResultValue sfSftpResult_getValue(const sfSftpResult* result)
{
    assert(result);
    return static_cast<sfSftpResultValue>(result->getValue());
}


////////////////////////////////////////////////////////////
const char* sfSftpResult_getMessage(const sfSftpResult* result)
{
    assert(result);
    return result->getMessage().c_str();
}


////////////////////////////////////////////////////////////
void sfSftpPathResult_destroy(const sfSftpPathResult* result)
{
    delete result;
}


////////////////////////////////////////////////////////////
bool sfSftpPathResult_isOk(const sfSftpPathResult* result)
{
    assert(result);
    return result->isOk();
}


////////////////////////////////////////////////////////////
sfSftpResultValue sfSftpPathResult_getValue(const sfSftpPathResult* result)
{
    assert(result);
    return static_cast<sfSftpResultValue>(result->getValue());
}


////////////////////////////////////////////////////////////
const char* sfSftpPathResult_getMessage(const sfSftpPathResult* result)
{
    assert(result);
    return result->getMessage().c_str();
}


////////////////////////////////////////////////////////////
const char* sfSftpPathResult_getPath(const sfSftpPathResult* result)
{
    assert(result);
    return result->Path.c_str();
}


////////////////////////////////////////////////////////////
void sfSftpAttributesResult_destroy(const sfSftpAttributesResult* result)
{
    delete result;
}


////////////////////////////////////////////////////////////
bool sfSftpAttributesResult_isOk(const sfSftpAttributesResult* result)
{
    assert(result);
    return result->isOk();
}


////////////////////////////////////////////////////////////
sfSftpResultValue sfSftpAttributesResult_getValue(const sfSftpAttributesResult* result)
{
    assert(result);
    return static_cast<sfSftpResultValue>(result->getValue());
}


////////////////////////////////////////////////////////////
const char* sfSftpAttributesResult_getMessage(const sfSftpAttributesResult* result)
{
    assert(result);
    return result->getMessage().c_str();
}


////////////////////////////////////////////////////////////
sfSftpAttributes sfSftpAttributesResult_getAttributes(const sfSftpAttributesResult* result)
{
    assert(result);
    return convertAttributes(result->getAttributes(), result->Path);
}


////////////////////////////////////////////////////////////
void sfSftpListingResult_destroy(const sfSftpListingResult* result)
{
    delete result;
}


////////////////////////////////////////////////////////////
bool sfSftpListingResult_isOk(const sfSftpListingResult* result)
{
    assert(result);
    return result->isOk();
}


////////////////////////////////////////////////////////////
sfSftpResultValue sfSftpListingResult_getValue(const sfSftpListingResult* result)
{
    assert(result);
    return static_cast<sfSftpResultValue>(result->getValue());
}


////////////////////////////////////////////////////////////
const char* sfSftpListingResult_getMessage(const sfSftpListingResult* result)
{
    assert(result);
    return result->getMessage().c_str();
}


////////////////////////////////////////////////////////////
size_t sfSftpListingResult_getCount(const sfSftpListingResult* result)
{
    assert(result);
    return result->getListing().size();
}


////////////////////////////////////////////////////////////
sfSftpAttributes sfSftpListingResult_getAttributes(const sfSftpListingResult* result, size_t index)
{
    assert(result);
    assert(index < result->getListing().size());
    return convertAttributes(result->getListing()[index], result->Paths[index]);
}


////////////////////////////////////////////////////////////
sfSftp* sfSftp_create()
{
    return new sfSftp;
}


////////////////////////////////////////////////////////////
void sfSftp_destroy(const sfSftp* sftp)
{
    delete sftp;
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_connect(sfSftp* sftp, sfIpAddress server, unsigned short port, sfTimeoutWithPredicate timeout)
{
    assert(sftp);

    const auto address = convertIpAddress(server);
    if (!address)
        return createResult(sf::Sftp::Result(sf::Sftp::Result::Value::Error, "Invalid server address"));

    return createResult(sftp->connect(*address, port, convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_disconnect(sfSftp* sftp, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->disconnect(convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
bool sfSftp_getSessionInfo(const sfSftp* sftp, sfSftpSessionInfo* info)
{
    assert(sftp);
    assert(info);

    sftp->SessionInfo = sftp->getSessionInfo();
    if (!sftp->SessionInfo)
        return false;

    const auto& sessionInfo = *sftp->SessionInfo;
    const auto& hostKey     = sessionInfo.hostKey;

    *info             = {};
    info->hostKeyType = static_cast<sfSftpHostKeyType>(hostKey.type);
    info->hostKeyData = reinterpret_cast<const std::uint8_t*>(hostKey.data.data());
    info->hostKeySize = hostKey.data.size();
    std::transform(hostKey.sha1.begin(),
                   hostKey.sha1.end(),
                   info->hostKeySha1,
                   [](std::byte b) { return std::to_integer<std::uint8_t>(b); });
    std::transform(hostKey.sha256.begin(),
                   hostKey.sha256.end(),
                   info->hostKeySha256,
                   [](std::byte b) { return std::to_integer<std::uint8_t>(b); });
    info->keyExchangeAlgorithm               = sessionInfo.keyExchangeAlgorithm.c_str();
    info->hostKeyAlgorithm                   = sessionInfo.hostKeyAlgorithm.c_str();
    info->clientToServerEncryptionAlgorithm  = sessionInfo.clientToServerEncryptionAlgorithm.c_str();
    info->serverToClientEncryptionAlgorithm  = sessionInfo.serverToClientEncryptionAlgorithm.c_str();
    info->clientToServerMacAlgorithm         = sessionInfo.clientToServerMacAlgorithm.c_str();
    info->serverToClientMacAlgorithm         = sessionInfo.serverToClientMacAlgorithm.c_str();
    info->clientToServerCompressionAlgorithm = sessionInfo.clientToServerCompressionAlgorithm.c_str();
    info->serverToClientCompressionAlgorithm = sessionInfo.serverToClientCompressionAlgorithm.c_str();
    return true;
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_login(sfSftp* sftp, const char* name, const char* password, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->login(name ? name : "", password ? password : "", convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_loginWithKey(
    sfSftp*                sftp,
    const char*            name,
    const char*            publicKeyData,
    size_t                 publicKeyLength,
    const char*            privateKeyData,
    size_t                 privateKeyLength,
    const char*            privateKeyPassphrase,
    sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    assert(publicKeyData);
    assert(privateKeyData);
    return createResult(
        sftp->login(name ? name : "",
                    publicKeyData,
                    publicKeyLength,
                    privateKeyData,
                    privateKeyLength,
                    privateKeyPassphrase ? privateKeyPassphrase : "",
                    convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpPathResult* sfSftp_resolvePath(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->resolvePath(toPath(path), convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpPathResult* sfSftp_getWorkingDirectory(sfSftp* sftp, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->getWorkingDirectory(convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpAttributesResult* sfSftp_getAttributes(sfSftp* sftp, const char* path, bool followLinks, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->getAttributes(toPath(path), followLinks, convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpListingResult* sfSftp_getDirectoryListing(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->getDirectoryListing(toPath(path), convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_createDirectory(sfSftp* sftp, const char* path, uint32_t permissions, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->createDirectory(toPath(path),
                                              static_cast<std::filesystem::perms>(permissions),
                                              convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_deleteDirectory(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->deleteDirectory(toPath(path), convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_rename(sfSftp* sftp, const char* oldPath, const char* newPath, bool overwrite, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->rename(toPath(oldPath), toPath(newPath), overwrite, convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_deleteFile(sfSftp* sftp, const char* path, sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    return createResult(sftp->deleteFile(toPath(path), convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_download(sfSftp*                sftp,
                              const char*            remotePath,
                              sfSftpDownloadCallback callback,
                              void*                  userData,
                              uint64_t               offset,
                              sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    assert(callback);
    return createResult(sftp->download(
        toPath(remotePath),
        [callback, userData](const void* data, std::size_t size) { return callback(data, size, userData); },
        offset,
        convertTimeoutWithPredicate(timeout)));
}


////////////////////////////////////////////////////////////
sfSftpResult* sfSftp_upload(
    sfSftp*                sftp,
    const char*            remotePath,
    sfSftpUploadCallback   callback,
    void*                  userData,
    uint32_t               permissions,
    bool                   truncate,
    bool                   append,
    uint64_t               offset,
    sfTimeoutWithPredicate timeout)
{
    assert(sftp);
    assert(callback);
    return createResult(sftp->upload(
        toPath(remotePath),
        [callback, userData](void* data, std::size_t& size) { return callback(data, &size, userData); },
        static_cast<std::filesystem::perms>(permissions),
        truncate,
        append,
        offset,
        convertTimeoutWithPredicate(timeout)));
}
