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
#include <CSFML/Network/Export.h>

#include <CSFML/Network/Types.h>

#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Create a new packet
///
/// \return A new sfPacket object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfPacket* sfPacket_create(void);

////////////////////////////////////////////////////////////
/// \brief Create a new packet by copying an existing one
///
/// \param packet Packet to copy
///
/// \return A new sfPacket object which is a copy of \a packet
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API sfPacket* sfPacket_copy(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Destroy a packet
///
/// \param packet Packet to destroy
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_destroy(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Append data to the end of a packet
///
/// \param packet      Packet object
/// \param data        Pointer to the sequence of bytes to append
/// \param sizeInBytes Number of bytes to append
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_append(sfPacket* packet, const void* data, size_t sizeInBytes);

////////////////////////////////////////////////////////////
/// \brief Get the current reading position in the packet
///
/// The next read operation will read data from this position
///
/// \param packet Packet object
///
/// \return The byte offset of the current read position
///
/// \see append
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfPacket_getReadPosition(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Clear a packet
///
/// After calling Clear, the packet is empty.
///
/// \param packet Packet object
///
///////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_clear(sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Get a pointer to the data contained in a packet
///
/// Warning: the returned pointer may become invalid after
/// you append data to the packet, therefore it should never
/// be stored.
/// The return pointer is NULL if the packet is empty.
///
/// \param packet Packet object
///
/// \return Pointer to the data
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API const void* sfPacket_getData(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Get the size of the data contained in a packet
///
/// This function returns the number of bytes pointed to by
/// what sfPacket_getData returns.
///
/// \param packet Packet object
///
/// \return Data size, in bytes
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API size_t sfPacket_getDataSize(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Tell if the reading position has reached the
///        end of a packet
///
/// This function is useful to know if there is some data
/// left to be read, without actually reading it.
///
/// \param packet Packet object
///
/// \return true if all data was read, false otherwise
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfPacket_endOfPacket(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Test the validity of a packet, for reading
///
/// This function allows for testing the packet, to check if
/// a reading operation was successful.
///
/// A packet will be in an invalid state if it has no more
/// data to read.
///
/// \param packet Packet object
///
/// \return true if last data extraction from packet was successful
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool sfPacket_canRead(const sfPacket* packet);

////////////////////////////////////////////////////////////
/// \brief Functions to extract data from a packet
///
/// \param packet Packet object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API bool     sfPacket_readBool(sfPacket* packet);
CSFML_NETWORK_API int8_t   sfPacket_readInt8(sfPacket* packet);
CSFML_NETWORK_API uint8_t  sfPacket_readUint8(sfPacket* packet);
CSFML_NETWORK_API int16_t  sfPacket_readInt16(sfPacket* packet);
CSFML_NETWORK_API uint16_t sfPacket_readUint16(sfPacket* packet);
CSFML_NETWORK_API int32_t  sfPacket_readInt32(sfPacket* packet);
CSFML_NETWORK_API uint32_t sfPacket_readUint32(sfPacket* packet);
CSFML_NETWORK_API int64_t  sfPacket_readInt64(sfPacket* packet);
CSFML_NETWORK_API uint64_t sfPacket_readUint64(sfPacket* packet);
CSFML_NETWORK_API float    sfPacket_readFloat(sfPacket* packet);
CSFML_NETWORK_API double   sfPacket_readDouble(sfPacket* packet);
CSFML_NETWORK_API void     sfPacket_readString(sfPacket* packet, char* string);
CSFML_NETWORK_API void     sfPacket_readWideString(sfPacket* packet, wchar_t* string);

////////////////////////////////////////////////////////////
/// \brief Functions to insert data into a packet
///
/// \param packet Packet object
///
////////////////////////////////////////////////////////////
CSFML_NETWORK_API void sfPacket_writeBool(sfPacket* packet, bool);
CSFML_NETWORK_API void sfPacket_writeInt8(sfPacket* packet, int8_t);
CSFML_NETWORK_API void sfPacket_writeUint8(sfPacket* packet, uint8_t);
CSFML_NETWORK_API void sfPacket_writeInt16(sfPacket* packet, int16_t);
CSFML_NETWORK_API void sfPacket_writeUint16(sfPacket* packet, uint16_t);
CSFML_NETWORK_API void sfPacket_writeInt32(sfPacket* packet, int32_t);
CSFML_NETWORK_API void sfPacket_writeUint32(sfPacket* packet, uint32_t);
CSFML_NETWORK_API void sfPacket_writeInt64(sfPacket* packet, int64_t);
CSFML_NETWORK_API void sfPacket_writeUint64(sfPacket* packet, uint64_t);
CSFML_NETWORK_API void sfPacket_writeFloat(sfPacket* packet, float);
CSFML_NETWORK_API void sfPacket_writeDouble(sfPacket* packet, double);
CSFML_NETWORK_API void sfPacket_writeString(sfPacket* packet, const char* string);
CSFML_NETWORK_API void sfPacket_writeWideString(sfPacket* packet, const wchar_t* string);
