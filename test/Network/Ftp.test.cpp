#include <CSFML/Network/Ftp.h>

#include <SFML/Network/Ftp.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("[Network] sfFtp")
{
    SECTION("sfFtpTransferMode")
    {
        STATIC_CHECK(sfFtpBinary == static_cast<int>(sf::Ftp::TransferMode::Binary));
        STATIC_CHECK(sfFtpAscii == static_cast<int>(sf::Ftp::TransferMode::Ascii));
        STATIC_CHECK(sfFtpEbcdic == static_cast<int>(sf::Ftp::TransferMode::Ebcdic));
    }

    SECTION("sfFtpStatus")
    {
        STATIC_CHECK(sfFtpRestartMarkerReply == static_cast<int>(sf::Ftp::Response::Status::RestartMarkerReply));
        STATIC_CHECK(sfFtpServiceReadySoon == static_cast<int>(sf::Ftp::Response::Status::ServiceReadySoon));
        STATIC_CHECK(sfFtpDataConnectionAlreadyOpened ==
                     static_cast<int>(sf::Ftp::Response::Status::DataConnectionAlreadyOpened));
        STATIC_CHECK(sfFtpOpeningDataConnection == static_cast<int>(sf::Ftp::Response::Status::OpeningDataConnection));

        STATIC_CHECK(sfFtpOk == static_cast<int>(sf::Ftp::Response::Status::Ok));
        STATIC_CHECK(sfFtpPointlessCommand == static_cast<int>(sf::Ftp::Response::Status::PointlessCommand));
        STATIC_CHECK(sfFtpSystemStatus == static_cast<int>(sf::Ftp::Response::Status::SystemStatus));
        STATIC_CHECK(sfFtpDirectoryStatus == static_cast<int>(sf::Ftp::Response::Status::DirectoryStatus));
        STATIC_CHECK(sfFtpFileStatus == static_cast<int>(sf::Ftp::Response::Status::FileStatus));
        STATIC_CHECK(sfFtpHelpMessage == static_cast<int>(sf::Ftp::Response::Status::HelpMessage));
        STATIC_CHECK(sfFtpSystemType == static_cast<int>(sf::Ftp::Response::Status::SystemType));
        STATIC_CHECK(sfFtpServiceReady == static_cast<int>(sf::Ftp::Response::Status::ServiceReady));
        STATIC_CHECK(sfFtpClosingConnection == static_cast<int>(sf::Ftp::Response::Status::ClosingConnection));
        STATIC_CHECK(sfFtpDataConnectionOpened == static_cast<int>(sf::Ftp::Response::Status::DataConnectionOpened));
        STATIC_CHECK(sfFtpClosingDataConnection == static_cast<int>(sf::Ftp::Response::Status::ClosingDataConnection));
        STATIC_CHECK(sfFtpEnteringPassiveMode == static_cast<int>(sf::Ftp::Response::Status::EnteringPassiveMode));
        STATIC_CHECK(sfFtpLoggedIn == static_cast<int>(sf::Ftp::Response::Status::LoggedIn));
        STATIC_CHECK(sfFtpFileActionOk == static_cast<int>(sf::Ftp::Response::Status::FileActionOk));
        STATIC_CHECK(sfFtpDirectoryOk == static_cast<int>(sf::Ftp::Response::Status::DirectoryOk));

        STATIC_CHECK(sfFtpNeedPassword == static_cast<int>(sf::Ftp::Response::Status::NeedPassword));
        STATIC_CHECK(sfFtpNeedAccountToLogIn == static_cast<int>(sf::Ftp::Response::Status::NeedAccountToLogIn));
        STATIC_CHECK(sfFtpNeedInformation == static_cast<int>(sf::Ftp::Response::Status::NeedInformation));

        STATIC_CHECK(sfFtpServiceUnavailable == static_cast<int>(sf::Ftp::Response::Status::ServiceUnavailable));
        STATIC_CHECK(sfFtpDataConnectionUnavailable ==
                     static_cast<int>(sf::Ftp::Response::Status::DataConnectionUnavailable));
        STATIC_CHECK(sfFtpTransferAborted == static_cast<int>(sf::Ftp::Response::Status::TransferAborted));
        STATIC_CHECK(sfFtpFileActionAborted == static_cast<int>(sf::Ftp::Response::Status::FileActionAborted));
        STATIC_CHECK(sfFtpLocalError == static_cast<int>(sf::Ftp::Response::Status::LocalError));
        STATIC_CHECK(sfFtpInsufficientStorageSpace == static_cast<int>(sf::Ftp::Response::Status::InsufficientStorageSpace));

        STATIC_CHECK(sfFtpCommandUnknown == static_cast<int>(sf::Ftp::Response::Status::CommandUnknown));
        STATIC_CHECK(sfFtpParametersUnknown == static_cast<int>(sf::Ftp::Response::Status::ParametersUnknown));
        STATIC_CHECK(sfFtpCommandNotImplemented == static_cast<int>(sf::Ftp::Response::Status::CommandNotImplemented));
        STATIC_CHECK(sfFtpBadCommandSequence == static_cast<int>(sf::Ftp::Response::Status::BadCommandSequence));
        STATIC_CHECK(sfFtpParameterNotImplemented == static_cast<int>(sf::Ftp::Response::Status::ParameterNotImplemented));
        STATIC_CHECK(sfFtpNotLoggedIn == static_cast<int>(sf::Ftp::Response::Status::NotLoggedIn));
        STATIC_CHECK(sfFtpNeedAccountToStore == static_cast<int>(sf::Ftp::Response::Status::NeedAccountToStore));
        STATIC_CHECK(sfFtpFileUnavailable == static_cast<int>(sf::Ftp::Response::Status::FileUnavailable));
        STATIC_CHECK(sfFtpPageTypeUnknown == static_cast<int>(sf::Ftp::Response::Status::PageTypeUnknown));
        STATIC_CHECK(sfFtpNotEnoughMemory == static_cast<int>(sf::Ftp::Response::Status::NotEnoughMemory));
        STATIC_CHECK(sfFtpFilenameNotAllowed == static_cast<int>(sf::Ftp::Response::Status::FilenameNotAllowed));

        STATIC_CHECK(sfFtpInvalidResponse == static_cast<int>(sf::Ftp::Response::Status::InvalidResponse));
        STATIC_CHECK(sfFtpConnectionFailed == static_cast<int>(sf::Ftp::Response::Status::ConnectionFailed));
        STATIC_CHECK(sfFtpConnectionClosed == static_cast<int>(sf::Ftp::Response::Status::ConnectionClosed));
        STATIC_CHECK(sfFtpInvalidFile == static_cast<int>(sf::Ftp::Response::Status::InvalidFile));
    }
}
