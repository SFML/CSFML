#include <CSFML/Network/Sftp.h>

#include <SFML/Network/Sftp.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Network] sfSftp")
{
    SECTION("sfSftpResultValue")
    {
        STATIC_CHECK(sfSftpSuccess == static_cast<int>(sf::Sftp::Result::Value::Success));
        STATIC_CHECK(sfSftpDisconnected == static_cast<int>(sf::Sftp::Result::Value::Disconnected));
        STATIC_CHECK(sfSftpTimeout == static_cast<int>(sf::Sftp::Result::Value::Timeout));
        STATIC_CHECK(sfSftpRefused == static_cast<int>(sf::Sftp::Result::Value::Refused));
        STATIC_CHECK(sfSftpError == static_cast<int>(sf::Sftp::Result::Value::Error));
        STATIC_CHECK(sfSftpBannerReceive == static_cast<int>(sf::Sftp::Result::Value::BannerReceive));
        STATIC_CHECK(sfSftpBannerSend == static_cast<int>(sf::Sftp::Result::Value::BannerSend));
        STATIC_CHECK(sfSftpInvalidMac == static_cast<int>(sf::Sftp::Result::Value::InvalidMac));
        STATIC_CHECK(sfSftpAllocationFailure == static_cast<int>(sf::Sftp::Result::Value::AllocationFailure));
        STATIC_CHECK(sfSftpSocketSend == static_cast<int>(sf::Sftp::Result::Value::SocketSend));
        STATIC_CHECK(sfSftpKeyExchangeFailure == static_cast<int>(sf::Sftp::Result::Value::KeyExchangeFailure));
        STATIC_CHECK(sfSftpHostKeyInitialization == static_cast<int>(sf::Sftp::Result::Value::HostKeyInitialization));
        STATIC_CHECK(sfSftpHostKeySign == static_cast<int>(sf::Sftp::Result::Value::HostKeySign));
        STATIC_CHECK(sfSftpDecryptError == static_cast<int>(sf::Sftp::Result::Value::DecryptError));
        STATIC_CHECK(sfSftpProtocolError == static_cast<int>(sf::Sftp::Result::Value::ProtocolError));
        STATIC_CHECK(sfSftpPasswordExpired == static_cast<int>(sf::Sftp::Result::Value::PasswordExpired));
        STATIC_CHECK(sfSftpFileError == static_cast<int>(sf::Sftp::Result::Value::FileError));
        STATIC_CHECK(sfSftpMethodNone == static_cast<int>(sf::Sftp::Result::Value::MethodNone));
        STATIC_CHECK(sfSftpAuthenticationFailed == static_cast<int>(sf::Sftp::Result::Value::AuthenticationFailed));
        STATIC_CHECK(sfSftpPublicKeyUnverified == static_cast<int>(sf::Sftp::Result::Value::PublicKeyUnverified));
        STATIC_CHECK(sfSftpChannelOutOfOrder == static_cast<int>(sf::Sftp::Result::Value::ChannelOutOfOrder));
        STATIC_CHECK(sfSftpChannelFailure == static_cast<int>(sf::Sftp::Result::Value::ChannelFailure));
        STATIC_CHECK(sfSftpChannelRequestDenied == static_cast<int>(sf::Sftp::Result::Value::ChannelRequestDenied));
        STATIC_CHECK(sfSftpChannelUnknown == static_cast<int>(sf::Sftp::Result::Value::ChannelUnknown));
        STATIC_CHECK(sfSftpChannelWindowExceeded == static_cast<int>(sf::Sftp::Result::Value::ChannelWindowExceeded));
        STATIC_CHECK(sfSftpChannelPacketExceeded == static_cast<int>(sf::Sftp::Result::Value::ChannelPacketExceeded));
        STATIC_CHECK(sfSftpChannelClosed == static_cast<int>(sf::Sftp::Result::Value::ChannelClosed));
        STATIC_CHECK(sfSftpChannelEofSent == static_cast<int>(sf::Sftp::Result::Value::ChannelEofSent));
        STATIC_CHECK(sfSftpScpProtocol == static_cast<int>(sf::Sftp::Result::Value::ScpProtocol));
        STATIC_CHECK(sfSftpZlibError == static_cast<int>(sf::Sftp::Result::Value::ZlibError));
        STATIC_CHECK(sfSftpRequestDenied == static_cast<int>(sf::Sftp::Result::Value::RequestDenied));
        STATIC_CHECK(sfSftpMethodNotSupported == static_cast<int>(sf::Sftp::Result::Value::MethodNotSupported));
        STATIC_CHECK(sfSftpInvalidData == static_cast<int>(sf::Sftp::Result::Value::InvalidData));
        STATIC_CHECK(sfSftpPublicKeyProtocol == static_cast<int>(sf::Sftp::Result::Value::PublicKeyProtocol));
        STATIC_CHECK(sfSftpBufferTooSmall == static_cast<int>(sf::Sftp::Result::Value::BufferTooSmall));
        STATIC_CHECK(sfSftpBadUse == static_cast<int>(sf::Sftp::Result::Value::BadUse));
        STATIC_CHECK(sfSftpCompressError == static_cast<int>(sf::Sftp::Result::Value::CompressError));
        STATIC_CHECK(sfSftpOutOfBoundary == static_cast<int>(sf::Sftp::Result::Value::OutOfBoundary));
        STATIC_CHECK(sfSftpAgentProtocol == static_cast<int>(sf::Sftp::Result::Value::AgentProtocol));
        STATIC_CHECK(sfSftpSocketRecv == static_cast<int>(sf::Sftp::Result::Value::SocketRecv));
        STATIC_CHECK(sfSftpEncryptError == static_cast<int>(sf::Sftp::Result::Value::EncryptError));
        STATIC_CHECK(sfSftpBadSocket == static_cast<int>(sf::Sftp::Result::Value::BadSocket));
        STATIC_CHECK(sfSftpKnownHosts == static_cast<int>(sf::Sftp::Result::Value::KnownHosts));
        STATIC_CHECK(sfSftpChannelWindowFull == static_cast<int>(sf::Sftp::Result::Value::ChannelWindowFull));
        STATIC_CHECK(sfSftpKeyFileAuthenticationFailed ==
                     static_cast<int>(sf::Sftp::Result::Value::KeyFileAuthenticationFailed));
        STATIC_CHECK(sfSftpEndOfFile == static_cast<int>(sf::Sftp::Result::Value::EndOfFile));
        STATIC_CHECK(sfSftpNoSuchFile == static_cast<int>(sf::Sftp::Result::Value::NoSuchFile));
        STATIC_CHECK(sfSftpPermissionDenied == static_cast<int>(sf::Sftp::Result::Value::PermissionDenied));
        STATIC_CHECK(sfSftpFailure == static_cast<int>(sf::Sftp::Result::Value::Failure));
        STATIC_CHECK(sfSftpBadMessage == static_cast<int>(sf::Sftp::Result::Value::BadMessage));
        STATIC_CHECK(sfSftpNoConnection == static_cast<int>(sf::Sftp::Result::Value::NoConnection));
        STATIC_CHECK(sfSftpConnectionLost == static_cast<int>(sf::Sftp::Result::Value::ConnectionLost));
        STATIC_CHECK(sfSftpOperationUnsupported == static_cast<int>(sf::Sftp::Result::Value::OperationUnsupported));
        STATIC_CHECK(sfSftpInvalidHandle == static_cast<int>(sf::Sftp::Result::Value::InvalidHandle));
        STATIC_CHECK(sfSftpNoSuchPath == static_cast<int>(sf::Sftp::Result::Value::NoSuchPath));
        STATIC_CHECK(sfSftpFileAlreadyExists == static_cast<int>(sf::Sftp::Result::Value::FileAlreadyExists));
        STATIC_CHECK(sfSftpWriteProtect == static_cast<int>(sf::Sftp::Result::Value::WriteProtect));
        STATIC_CHECK(sfSftpNoMedia == static_cast<int>(sf::Sftp::Result::Value::NoMedia));
        STATIC_CHECK(sfSftpNoSpaceOnFileSystem == static_cast<int>(sf::Sftp::Result::Value::NoSpaceOnFileSystem));
        STATIC_CHECK(sfSftpQuotaExceeded == static_cast<int>(sf::Sftp::Result::Value::QuotaExceeded));
        STATIC_CHECK(sfSftpUnknownPrincipal == static_cast<int>(sf::Sftp::Result::Value::UnknownPrincipal));
        STATIC_CHECK(sfSftpLockConflict == static_cast<int>(sf::Sftp::Result::Value::LockConflict));
        STATIC_CHECK(sfSftpDirectoryNotEmpty == static_cast<int>(sf::Sftp::Result::Value::DirectoryNotEmpty));
        STATIC_CHECK(sfSftpNotADirectory == static_cast<int>(sf::Sftp::Result::Value::NotADirectory));
        STATIC_CHECK(sfSftpInvalidFilename == static_cast<int>(sf::Sftp::Result::Value::InvalidFilename));
        STATIC_CHECK(sfSftpLinkLoop == static_cast<int>(sf::Sftp::Result::Value::LinkLoop));
        STATIC_CHECK(sfSftpSftpError == static_cast<int>(sf::Sftp::Result::Value::SftpError));
    }

    SECTION("sfSftpHostKeyType")
    {
        using HostKeyType = sf::Sftp::SessionInfo::HostKey::Type;
        STATIC_CHECK(sfSftpHostKeyUnknown == static_cast<int>(HostKeyType::Unknown));
        STATIC_CHECK(sfSftpHostKeyRsa == static_cast<int>(HostKeyType::Rsa));
        STATIC_CHECK(sfSftpHostKeyDsa == static_cast<int>(HostKeyType::Dsa));
        STATIC_CHECK(sfSftpHostKeyEcdsa256 == static_cast<int>(HostKeyType::Ecdsa256));
        STATIC_CHECK(sfSftpHostKeyEcdsa384 == static_cast<int>(HostKeyType::Ecdsa384));
        STATIC_CHECK(sfSftpHostKeyEcdsa521 == static_cast<int>(HostKeyType::Ecdsa521));
        STATIC_CHECK(sfSftpHostKeyEd25519 == static_cast<int>(HostKeyType::Ed25519));
    }

    SECTION("Unconnected")
    {
        sfSftp*           sftp = sfSftp_create();
        sfSftpSessionInfo info{};
        CHECK(!sfSftp_getSessionInfo(sftp, &info));

        sfSftpResult* result = sfSftp_connect(sftp, sfIpAddress_None, 22, {});
        CHECK(!sfSftpResult_isOk(result));
        CHECK(sfSftpResult_getValue(result) == sfSftpError);
        sfSftpResult_destroy(result);

        sfSftp_destroy(sftp);
    }
}
