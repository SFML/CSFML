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

#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <CSFML/System/InputStream.h>

#include <SFML/System/InputStream.hpp>


////////////////////////////////////////////////////////////
/// \brief Adapts a CSFML input stream to a SFML input stream
///
////////////////////////////////////////////////////////////
class CallbackStream : public sf::InputStream
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Default constructor
    ///
    ////////////////////////////////////////////////////////////
    CallbackStream() = default;

    ////////////////////////////////////////////////////////////
    /// \brief Constructor
    ///
    /// \param stream CSFML input stream callbacks
    ///
    ////////////////////////////////////////////////////////////
    CallbackStream(sfInputStream* stream) : myStream(*stream)
    {
    }

    ////////////////////////////////////////////////////////////
    /// \brief Read data from the stream
    ///
    /// \param data Buffer where to copy the read data
    /// \param size Desired number of bytes to read
    ///
    /// \return The number of bytes actually read, or `std::nullopt` on error
    ///
    ////////////////////////////////////////////////////////////
    std::optional<std::size_t> read(void* data, std::size_t size) override
    {
        if (!myStream.read)
            return std::nullopt;

        const auto bytesRead = myStream.read(data, size, myStream.userData);
        if (bytesRead != -1)
            return static_cast<std::size_t>(bytesRead);

        return std::nullopt;
    }

    ////////////////////////////////////////////////////////////
    /// \brief Change the current reading position
    ///
    /// \param position The position to seek to, from the beginning
    ///
    /// \return The position actually seeked to, or `std::nullopt` on error
    ///
    ////////////////////////////////////////////////////////////
    std::optional<std::size_t> seek(std::size_t position) override
    {
        if (!myStream.seek)
            return std::nullopt;

        const auto actualPosition = myStream.seek(position, myStream.userData);
        if (actualPosition != -1)
            return static_cast<std::size_t>(actualPosition);

        return std::nullopt;
    }

    ////////////////////////////////////////////////////////////
    /// \brief Return the current reading position in the stream
    ///
    /// \return The current position, or `std::nullopt` on error
    ///
    ////////////////////////////////////////////////////////////
    std::optional<std::size_t> tell() override
    {
        if (!myStream.tell)
            return std::nullopt;

        const auto position = myStream.tell(myStream.userData);
        if (position != -1)
            return static_cast<std::size_t>(position);

        return std::nullopt;
    }

    ////////////////////////////////////////////////////////////
    /// \brief Return the size of the stream
    ///
    /// \return The total number of bytes available in the stream, or `std::nullopt` on error
    ///
    ////////////////////////////////////////////////////////////
    std::optional<std::size_t> getSize() override
    {
        if (!myStream.getSize)
            return std::nullopt;

        const auto bytesAvailable = myStream.getSize(myStream.userData);
        if (bytesAvailable != -1)
            return static_cast<std::size_t>(bytesAvailable);

        return std::nullopt;
    }

private:
    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    sfInputStream myStream{}; ///< The source CSFML input stream
};
